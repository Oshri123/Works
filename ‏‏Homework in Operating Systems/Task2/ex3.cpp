#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>
#include <string>
#include <string.h>
#include <sys/time.h>
#include <iomanip>
#include <map>
#include "ex3.h"

using namespace std;

#define NAME_SIZE 16
#define AMOUNT_OF_FOODS 10
#define MAX_ARGUMENTS 5
#define simulationTime 0
#define DISHES 1
#define CUSTOMERS 2
#define WAITERS 3
#define AMOUNT_OF_SEMAPHORES 7

struct Menu
{
    int id;
    char name[NAME_SIZE];
    double price;
    int TotalOrdered;
};

struct Readers
{
    int MenuCount;
    int OrderCount;
};

struct Customer
{
    int CustomerId;
    int ItemId;
    int Amount;
    bool Done;
};

struct Process
{
    pid_t pid;
    int id;
    string type;
};

float getTime(timeval start)
{
    // function that return the value of current time //
    timeval now;

    gettimeofday(&now, 0);
    float value = (now.tv_sec - start.tv_sec) + (now.tv_usec - start.tv_usec) * (1.0 / 1000000);
    return value;
}

void printMenu(Menu *menu, int amoutDishes)
{
    // variables to print the menu like table //
    const int itemNameWidth = 15; // item name up to 15 chars
    const char separator = ' ';

    // print menu //
    cout << "===============Menu List================" << endl;
    cout << "Id\t" << left << setw(itemNameWidth) << setfill(separator) << "Name\t\tPrice\tOrders" << endl;
    for (int i = 0; i < amoutDishes; ++i)
        cout << menu[i].id << ')' << "\t" << left << setw(itemNameWidth) << setfill(separator)
             << menu[i].name << "\t" << menu[i].price << "\t" << menu[i].TotalOrdered << endl;
    cout << "========================================" << endl;
}

int drawRandom(int max, int min)
{
    return min + (rand() % (max - min + 1));
}

void readMenu(map<string, int> &semaphores, int &readCount, Menu *menuTable, const int &numOfDishes, timeval timer, string &dishName, int itemForCustomer)
{
    down(semaphores["serviceQueue_Menu"]);    // wait in line to be serviced
    down(semaphores["readCountAccess_Menu"]); // request exclusive access to readCount

    // <ENTER>
    if (readCount == 0)                          // if there are no readers already reading:
        down(semaphores["resourceAccess_Menu"]); // request resource access for readers (writers blocked)
    readCount++;                                 // update count of active readers
    // </ENTER>

    up(semaphores["serviceQueue_Menu"]);    // let next in line be serviced
    up(semaphores["readCountAccess_Menu"]); // release access to readCount

    // <READ>
    bool oneSec = false;
    int i = 0;

    if (itemForCustomer == 0) // if i came to read the menu //
    {
        float timeToRun = getTime(timer) + 1.0; // save the current time to know when 1 sec had passed
        while (!oneSec)                         //Read the menu (1 seconds)
        {                                       // reading menu //
            string read_dish = (menuTable[i]).name;
            float read_dishPrice = (menuTable[i]).price;
            read_dish = "No Warning: unused variable";
            read_dishPrice += 1;
            //////////////////
            if (i >= numOfDishes) // initialize i if done reading the menu
                i = -1;
            ++i;                            // promote i
            if (timeToRun < getTime(timer)) // if 1 sec has passed
                oneSec = true;
        }
    }
    else // if i came to get the name of a dish //
    {
        string temp((menuTable[itemForCustomer - 1]).name);
        dishName = temp;
    }
    // </READ>

    down(semaphores["readCountAccess_Menu"]); // request exclusive access to readCount

    // <EXIT>
    readCount--;                               // update count of active readers
    if (readCount == 0)                        // if there are no readers left:
        up(semaphores["resourceAccess_Menu"]); // release resource access for all
    // </EXIT>

    up(semaphores["readCountAccess_Menu"]);
}

void readOrders(map<string, int> &semaphores, int &readCount, bool &newOrders, bool &customerCanOrder, Customer *&ordersBoard, const Process &process, const int &numOfCustomers)
{
    down(semaphores["serviceQueue_Order"]);    // wait in line to be serviced
    down(semaphores["readCountAccess_Order"]); // request exclusive access to readCount

    // <ENTER>
    if (readCount == 0)                           // if there are no readers already reading:
        down(semaphores["resourceAccess_Order"]); // request resource access for readers (writers blocked)
    readCount++;                                  // update count of active readers
    // </ENTER>

    up(semaphores["serviceQueue_Order"]);    // let next in line be serviced
    up(semaphores["readCountAccess_Order"]); // release access to readCount

    // <READ>
    if (process.type == "Waiter")
    {
        for (int i = 0; i < numOfCustomers; ++i)
        {
            if (ordersBoard[i].Done == false)
            {
                newOrders = true;
                break;
            }
        }
    }
    else                                          // process type is Customer
        if (ordersBoard[process.id].Done == true) // If the previous order was done
        customerCanOrder = true;
    else
        customerCanOrder = false;
    // </READ>

    down(semaphores["readCountAccess_Order"]); // request exclusive access to readCount

    // <EXIT>
    readCount--;                                // update count of active readers
    if (readCount == 0)                         // if there are no readers left:
        up(semaphores["resourceAccess_Order"]); // release resource access for all
    // </EXIT>

    up(semaphores["readCountAccess_Order"]);
}

void writerMenu(map<string, int> &semaphores, const Process &process, timeval timer, Menu *&menuTable, const int &itemId, const int &amountOrdered, const int &customerId)
{
    down(semaphores["serviceQueue_Menu"]); // wait in line to be serviced
    // <ENTER>
    down(semaphores["resourceAccess_Menu"]); // request exclusive access to resource
                                             // </ENTER>
    up(semaphores["serviceQueue_Menu"]);     // let next in line be serviced

    // <WRITE>
    (menuTable[itemId - 1]).TotalOrdered += amountOrdered; // Add the amount ordered to the totals for the item in main menu
    // print
    down(semaphores["mutex"]);
    cout << getTime(timer) << " Waiter ID " << process.id << ": performs the order of customer ID " << customerId << " (" << amountOrdered << " " << (menuTable[itemId - 1]).name << ")" << endl;
    up(semaphores["mutex"]);
    // </WRITE>

    // <EXIT>
    up(semaphores["resourceAccess_Menu"]); // release resource access for next reader/writer
                                           // </EXIT>
}

void writerOrders(map<string, int> &semaphores, bool &newOrders, Customer *&ordersBoard, const int &numOfCustomers, const Process &process, timeval timer, int &amountOfItem, int &itemId, int &customerId, string dishName)
{
    down(semaphores["serviceQueue_Order"]); // wait in line to be serviced
    // <ENTER>
    down(semaphores["resourceAccess_Order"]); // request exclusive access to resource
                                              // </ENTER>
    up(semaphores["serviceQueue_Order"]);     // let next in line be serviced

    // <WRITE>
    if (process.type == "Waiter")
    {
        for (int i = 0; i < numOfCustomers; ++i)
        {
            if (ordersBoard[i].Done == false)
            {
                newOrders = false;
                // Mark the order as Done (set to true)
                ordersBoard[i].Done = true;
                amountOfItem = ordersBoard[i].Amount; // get the amount that the customer ordered
                itemId = ordersBoard[i].ItemId;
                customerId = ordersBoard[i].CustomerId;
                break;
            }
        }
    }
    else // process is Customer
    {
        // Write the order to the “orders board” under customer index and set value of Done to false.
        customerId = process.id;
        ordersBoard[customerId].ItemId = itemId;
        ordersBoard[customerId].Amount = amountOfItem;
        ordersBoard[customerId].Done = false;

        //print
        down(semaphores["mutex"]);
        cout << getTime(timer) << " Customer ID " << customerId << ": reads a menu about " << dishName << " (ordered, amount " << amountOfItem << ")" << endl;
        up(semaphores["mutex"]);
    }
    // </WRITE>

    // <EXIT>
    up(semaphores["resourceAccess_Order"]); // release resource access for next reader/writer
                                            // </EXIT>
}

void handleInputs(int numOfArgs, char *argv[], int *arg)
{
    if (numOfArgs != MAX_ARGUMENTS)
    {
        cout << "Number of arguments should be 4!" << endl;
        exit(1);
    }

    try
    {
        arg[simulationTime] = stoi(argv[1]);
        arg[DISHES] = stoi(argv[2]);
        arg[CUSTOMERS] = stoi(argv[3]);
        arg[WAITERS] = stoi(argv[4]);
    }
    catch (exception const &e)
    {
        cout << "Error: Parameters have to be integers!" << endl;
        exit(1);
    }

    if (arg[simulationTime] > 30 || arg[simulationTime] <= 0)
    {
        cout << "Total time running of simulation should be less than 30 seconds" << endl;
        exit(1);
    }
    if (arg[DISHES] > 10 || arg[DISHES] < 5)
    {
        cout << "Number of different dishes should be 5 to 7" << endl;
        exit(1);
    }
    if (arg[WAITERS] > 3 || arg[WAITERS] <= 0)
    {
        cout << "Number of waiters should be up to 3" << endl;
        exit(1);
    }
    if (arg[CUSTOMERS] > 10 || arg[CUSTOMERS] <= 0)
    {
        cout << "Number of customers should be up to 10" << endl;
        exit(1);
    }
}

void fillMenu(Menu *menu, int amoutDishes)
{
    string foods[AMOUNT_OF_FOODS] = {"Pie", "Pizza", "Hamburger", "Milkshake", "Potato Chips", "Salad", "Schnitzel", "Fish", "Spaghetti", "Spring Chicken"};
    bool location[AMOUNT_OF_FOODS] = {false, false, false, false, false, false, false, false, false, false};
    int locOfFood;
    srand(time(NULL));

    for (int i = 0; i < amoutDishes; i++)
    {
        menu[i].id = i + 1;

        do
        {
            locOfFood = drawRandom(10, 0);

        } while (location[locOfFood]);

        location[locOfFood] = true;
        foods[locOfFood].copy(menu[i].name, foods[locOfFood].length(), 0);
        menu[i].price = drawRandom(9999, 900);
        menu[i].price /= 100;
        menu[i].TotalOrdered = 0;
    }
    printMenu(menu, amoutDishes);
}

void PrintSimulation(int *arg)
{
    cout << "==========Simulation Arguments==========" << endl;
    cout << "Simulation time: " << arg[simulationTime] << endl;
    cout << "Menu items count: " << arg[DISHES] << endl;
    cout << "Customers count: " << arg[CUSTOMERS] << endl;
    cout << "Waiters count: " << arg[WAITERS] << endl;
    cout << "========================================" << endl;
}

void printSum(Menu *menu, int amoutDishes)
{
    int totalOrders = 0;
    float totalPrice = 0;

    for (int i = 0; i < amoutDishes; ++i)
    {
        int amount = (menu[i]).TotalOrdered;
        if (amount > 0)
        {
            totalOrders += amount;
            totalPrice += (menu[i]).price * amount;
        }
    }
    cout << "Total Orders " << totalOrders << ", for an amount of " << totalPrice << " NIS" << endl;
}

void PrintCurrentTime(timeval start)
{
    // function to print the current time //
    timeval now;

    gettimeofday(&now, 0);
    cout << setfill('0') << setw(2) << (now.tv_sec - start.tv_sec) << '.' << setfill('0') << setw(4) << (now.tv_usec - start.tv_usec) << "  ";
}

void *sharedMemory(int &shmid, char a, unsigned int size)
{
    key_t key = ftok(".", a); /* Create unique key via call to ftok() */

    /* Open the shared memory segment */
    if ((shmid = shmget(key, size, IPC_CREAT | IPC_EXCL | 0666)) == -1)
    {
        //cout<<"Shared memory segment exists - opening as client"<<endl;
        /* Segment probably already exists - try as a client */
        if ((shmid = shmget(key, size, 0)) == -1)
        {
            cerr << "Bad shmget" << endl;
            exit(1);
        }
    }
    //else
    //	cout<<"Creating new shared memory segment"<<endl;

    void *ptrToSHMEM;
    if ((ptrToSHMEM = shmat(shmid, 0, 0)) == NULL)
    {
        cerr << "Bad shmat" << endl;
        exit(1);
    }
    return ptrToSHMEM;
}

int getProcess(Process *processes, const int &size, const pid_t &pid)
{
    // function to return the ID of process //
    if (size < 1)
        return -1;
    for (int i = 0; i < size; ++i)
        if (pid == (processes[i]).pid)
            return i;
    cerr << "ERROR: something went wrong in 'getProcess'" << endl;
    return -1;
}

void start(int *arg)
{
    pid_t pid = -2;
    int status = 0;
    int numOfProcesses = arg[WAITERS] + arg[CUSTOMERS];
    timeval timer; // time variable
    Process *processes = new Process[numOfProcesses];

    ////////////////////////////////// Create Shared Memory //////////////////////////////////

    // define shared memory variables //
    Menu *menu = new Menu[7];
    Customer *ordersBoard = new Customer[arg[CUSTOMERS]];
    Readers *reader = new Readers[1];
    int *numOfCustomersLEFT;

    // Generate Shared Memory //
    int shmid_OrderBoard = 0, shmid_MenuTable = 0, shmid_Counter = 0, shmid_numOfCustomersLEFT = 0;

    menu = (Menu *)(sharedMemory(shmid_MenuTable, 'a', sizeof(menu)));
    ordersBoard = (Customer *)(sharedMemory(shmid_OrderBoard, 'b', sizeof(ordersBoard)));
    reader = (Readers *)(sharedMemory(shmid_Counter, 'c', sizeof(reader)));
    numOfCustomersLEFT = (int *)(sharedMemory(shmid_numOfCustomersLEFT, 'd', sizeof(numOfCustomersLEFT)));

    // initialize shared memory variables //
    for (int i = 0; i < arg[CUSTOMERS]; ++i) // initialize orderboard
    {
        ordersBoard[i].Done = true;
        ordersBoard[i].CustomerId = i;
    }

    numOfCustomersLEFT[0] = arg[CUSTOMERS];         // initialize numOfCustomersLEFT
    reader[0].OrderCount = reader[0].MenuCount = 0; // initialize counters for reader
    fillMenu(menu, arg[DISHES]);                    // initialize menu
                                                    //////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////// Create Semaphores ///////////////////////////////////
    string semaphoresNames[AMOUNT_OF_SEMAPHORES] = {"resourceAccess_Menu", "readCountAccess_Menu", "serviceQueue_Menu", "resourceAccess_Order", "readCountAccess_Order",
                                                    "serviceQueue_Order",
                                                    "mutex"};

    key_t semaphoreKeys[AMOUNT_OF_SEMAPHORES];//create array of semaphores
    map<string, int> semaphores;//create a dictonery-like for semaphores

    for (int i = 0; i < AMOUNT_OF_SEMAPHORES; i++)
    {
        semaphores.insert(std::pair<string, int>(semaphoresNames[i], -1));
        semaphoreKeys[i] = ftok(".", i + 1);

        if ((semaphores[semaphoresNames[i]] = initsem(semaphoreKeys[i], 1)) < 0)
        {
            cerr << "Error in initializing semaphores" << endl;
            exit(1);
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////

    gettimeofday(&timer, 0); // start timer

    PrintCurrentTime(timer); // print - start main process
    cout << "Main Proccess ID " << getpid() << " start" << endl;

    printMenu(menu, arg[DISHES]); // print menu

    cout << getTime(timer) << " Main Proccess start creating sub-processes" << endl;
    //////////////////// create waiters ////////////////////
    for (int i = 0; i < arg[WAITERS]; ++i)
    {
        if (pid != 0)
            pid = fork();
        if (pid < 0)
        {
            cerr << "No child created!" << endl;
            exit(1);
        }
        else if (pid == 0)
        {
            processes[i].pid = getpid();
            processes[i].id = i;
            processes[i].type.assign("Waiter");
            break;
        }
    } // done creating waiters //

    //////////////////// create customers ////////////////////
    for (int i = 0; i < arg[CUSTOMERS]; ++i)
    {
        // make sure all the waiter pid will not mess around here
        if (pid == 0)
            break;

        int realIndex = arg[WAITERS] + i;

        if (pid != 0)
            pid = fork();
        if (pid < 0)
        {
            cerr << "No child created!" << endl;
            exit(1);
        }
        else if (pid == 0)
        {
            processes[realIndex].pid = getpid();
            processes[realIndex].id = i;
            processes[realIndex].type.assign("Customer");
            break;
        }
    } // done creating customers //

    if (pid == 0) //child process
    {
        /* initialize random seed: */
        srand(time(NULL) + getpid() * getppid());

        int index = getProcess(processes, numOfProcesses, getpid());
        bool newOrders = false, customerCanOrder = true;

        down(semaphores["mutex"]);
        cout << getTime(timer) << " " << processes[index].type << " " << processes[index].id << ": created PID " << getpid() << " PPID " << getppid() << endl;
        up(semaphores["mutex"]);

        if (processes[index].type == "Waiter")
        {                               // process is Waiter
            bool allOrdersDone = false; // run at least one more time when the all customers are dead

            while (true)
            {
                // If simulation time has elapsed
                if ((int)getTime(timer) >= arg[simulationTime] && numOfCustomersLEFT[0] == 0)
                { // run at least one more time when the all customers are dead
                    if (allOrdersDone)
                        break;
                    allOrdersDone = true;
                }
                sleep(drawRandom(2, 1)); // Sleep for 1 to 2 seconds

                // Read orders from the “order board”
                readOrders(semaphores, reader->OrderCount, newOrders, customerCanOrder, ordersBoard, processes[index], arg[CUSTOMERS]);

                if (newOrders) // if there are new orders
                {
                    int amountOrdered = 0, itemId = 0, customerId = 0;

                    // Mark the order as Done
                    writerOrders(semaphores, newOrders, ordersBoard, arg[CUSTOMERS], processes[index], timer, amountOrdered, itemId, customerId, " ");
                    if (newOrders) // if process still has new orders=true: that means that more than 1 process saw the SAME order and both tried to handle it (but only one did)
                        newOrders = false;
                    else
                    {                          // if i am the process that handled the order
                        allOrdersDone = false; // run one more time

                        // Add the amount ordered to the totals for the item in main menu + print
                        writerMenu(semaphores, processes[index], timer, menu, itemId, amountOrdered, customerId);
                    }
                } // end if new orders
            }     // end while(true) loop
        }         // end Waiter process

        else // process is customer
        {
            while (true)
            {
                string dishName = "";

                // If simulation time has elapsed
                if ((int)getTime(timer) >= arg[simulationTime])
                {
                    --numOfCustomersLEFT[0];
                    break;
                }
                sleep(drawRandom(6, 3)); // Sleep for 3 to 6 seconds

                //Read the menu (1 seconds)
                readMenu(semaphores, reader->MenuCount, menu, arg[DISHES], timer, dishName, 0);

                // check if previous order is done
                readOrders(semaphores, reader->OrderCount, newOrders, customerCanOrder, ordersBoard, processes[index], arg[CUSTOMERS]);

                if (customerCanOrder) // If the previous order is done
                {
                    int itemId = drawRandom(arg[DISHES], 1); // Randomly choose an item
                    int amount = drawRandom(4, 1);           // randomly choose an amount (between 1 and 4)

                    // With the probability 0.5, the customer will order
                    int orderProbability = drawRandom(4, 1); // probability (1 or 2): order | probability (3 or 4): dont

                    // get the name of the dish that was randomly chosen
                    readMenu(semaphores, reader->MenuCount, menu, arg[DISHES], timer, dishName, itemId);

                    if (orderProbability < 3) // want to order
                    {
                        int customerId = 0; // only for function: 'writerOrders'

                        // Write the order to the “orders board” and set value of Done to false + print
                        writerOrders(semaphores, newOrders, ordersBoard, arg[CUSTOMERS], processes[index], timer, amount, itemId, customerId, dishName);
                    }
                    else // dont want to order
                    {
                        down(semaphores["mutex"]);
                        cout << getTime(timer) << " Customer ID " << (processes[index]).id << ": reads a menu about " << dishName << " (doesn't want to order)" << endl;
                        up(semaphores["mutex"]);
                    }
                } // end if previous order is done
            }     // end while(true) loop
        }         // end Customer process

        // print process end work
        down(semaphores["mutex"]);
        cout << getTime(timer) << " " << processes[index].type << " ID " << processes[index].id << ": PID " << processes[index].pid << " end work PPID " << getppid() << endl;
        up(semaphores["mutex"]);
    }

    else // parent
    {
        while (wait(&status) > 0)
            ; // the father waits for all the child processes

        printMenu(menu, arg[DISHES]); // end of simulation: print menu
        printSum(menu, arg[DISHES]);  // print summary
        cout << getTime(timer) << " Main ID " << getpid() << " end work" << endl;
        cout << getTime(timer) << " End of simulation" << endl;
        // Remove a shared memory section
        shmctl(shmid_MenuTable, IPC_RMID, 0);
        shmctl(shmid_OrderBoard, IPC_RMID, 0);
        shmctl(shmid_Counter, IPC_RMID, 0);
        shmctl(shmid_numOfCustomersLEFT, IPC_RMID, 0);
        // Remove semaphores
        removesem(semaphores["resourceAccess_Menu"]);
        removesem(semaphores["readCountAccess_Menu"]);
        removesem(semaphores["serviceQueue_Menu"]);
        removesem(semaphores["resourceAccess_Order"]);
        removesem(semaphores["readCountAccess_Order"]);
        removesem(semaphores["serviceQueue_Order"]);
        removesem(semaphores["mutex"]);
    }
}

int main(int argc, char *argv[])
{
    int arg[argc];
    handleInputs(argc, argv, arg);
    PrintSimulation(arg);
    start(arg);
    return 0;
}
