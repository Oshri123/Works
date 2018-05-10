#include <iostream>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <vector>
#include <string>
#include <regex>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

#define MAX_SIZE 120

int exit_status = 0;
bool extCom = false; // running external commands in background

void executeCommands(string commands);
vector<string> splitInput(string commands);
void fixCommands(vector<string> &inputVec);
void changeDir(vector<string> &inputVec);
void transferVectorDataToArray(vector<string> inputVec, char **arr, int size);
string getDir();
void deleteArray(int size, char **arr);

int main()
{
    string commands;
    cout << "Welcome to OS SHell!\n";
    while (true)
    {
        cout << getDir();
        getline(cin, commands);

        if (commands == "exit" || cin.eof())
        {
            cout << "C ya!\n";
            break;
        }

        executeCommands(commands);
        extCom = false; // reset flag for running external commands
    }
    return 0;
}

void executeCommands(string commands) //This function executes the commands
{
    pid_t pid, pid_son;
    int status;
    vector<string> inputVec = splitInput(commands);

    fixCommands(inputVec);

    if (inputVec.front() == "cd") //execute 'cd' command
    {
        inputVec.erase(inputVec.begin());
        changeDir(inputVec);
    }
    else
    {
        int size = inputVec.size();
        char **arr = new char *[size + 1];
        transferVectorDataToArray(inputVec, arr, size);

        pid = fork();

        if (pid == -1)
        {
            cout << "Error in fork !!\n";
            deleteArray(size, arr); // delete allocated memory that was used for command 'execvp'
            exit(1);
        }
        else if (pid == 0) //if its the son's process
        {
            if (execvp(arr[0], arr) == -1)
            {
                cout << "OS SHell: " << arr[0] << ": command not found" << endl;
                deleteArray(size, arr); // delete allocated memory that was used for command 'execvp'
                exit(127);              //the child process terminated explicitly with exist status 127
            }
        }
        else //if its the father's process
        {
            if (extCom) // if there is a need to run background command
                cout << "[" << pid << "]" << endl;

            else // normal run (not background)
            {
                waitpid(pid, &status, 0);
                deleteArray(size, arr); // delete allocated memory that was used for command 'execvp'

                if (WIFEXITED(status))                 // normal exit
                    exit_status = WEXITSTATUS(status); // returns the exit status of the child

                else if (WIFSIGNALED(status)) // exit by signal
                    exit_status = WTERMSIG(status) + 128;
            }

            while ((pid_son = waitpid(-1, &status, WNOHANG)) > 0) // will check if any zombie-children exist
            {
                if (WIFSIGNALED(status)) // exit by signal
                    exit_status = WTERMSIG(status) + 128;

                cout << "[" << pid_son << "] : exited, status = " << exit_status << endl;
                exit_status = 0; // exit status is reset to 0
            }
        }
    }
}

vector<string> splitInput(string commands) //This function split the commands by 'space' and insert it to a Vector
{
    vector<string> inputVec;
    char *spacing, *temp = new char[commands.length() + 1];
    string tilda;
    strcpy(temp, commands.c_str());

    spacing = strtok(temp, " ");
    while (spacing != NULL)
    {
        tilda = spacing;
        if (signed(tilda.find('~')) != -1) /* this part replace the '~' to actual HOME directory if exists
                                            for example: the command: 'ls -l ~/ex2/test' will execute as 'ls -l $HOME/ex2/test' */
        {
            tilda.replace(tilda.find('~'), 1, getenv("HOME"));
            inputVec.push_back(tilda);
        }
        else
            inputVec.push_back(spacing);

        spacing = strtok(NULL, " ");
    }

    if (inputVec[inputVec.size() - 1] == "&") // check for running external commands in background by "&" after the last argument
    {
        extCom = true;
        inputVec.erase(inputVec.end());
    }

    delete[] temp;
    return inputVec;
}

void fixCommands(vector<string> &inputVec) // this function handles all the $ expressions
{
    smatch match;
    std::regex e("\\$[_a-zA-Z][_0-9a-zA-Z]*|\\$\\?");

    for (unsigned int i = 0; i < inputVec.size(); i++)
    {
        while (std::regex_search(inputVec[i], match, e))
        {
            string varName = match[0];              //get variable name from m
            int varLoc = inputVec[i].find(varName); //find first index of var in inputVec[i]
            int varLength = varName.length();       //find the variable length

            if (varName == "$?")
                inputVec[i].replace(varLoc, varLength, to_string(exit_status));
            else
            {
                varName.replace(0, 1, "");
                char *value = getenv(varName.data()); // get the value of the variable if exists

                if (value == NULL)
                    inputVec[i].replace(varLoc, varLength, "");
                else
                    inputVec[i].replace(varLoc, varLength, value);
            }
        }
    }
}

void changeDir(vector<string> &inputVec) //This function handles the 'cd' command
{
    int changeResult;
    if (inputVec.size() > 0)
    {
        string newDir = inputVec.front();
        changeResult = chdir(newDir.data()); //trying to change directory
        inputVec.erase(inputVec.begin());    //delete the command after using
    }
    else
        changeResult = chdir(getenv("HOME")); // if the command is only 'cd' - go to HOME

    if (changeResult < 0) //if No such file or directory exists
    {
        exit_status = 1;
        cout << "OS SHell: cd: No such file or directory\n";
    }
}

void transferVectorDataToArray(vector<string> inputVec, char **arr, int size)
{
    int length;

    for (int i = 0; i < size; i++) //copies the commands from the Vector to the Array
    {
        length = inputVec[i].length();
        arr[i] = new char[length + 1];
        inputVec[i].copy(arr[i], length);
        arr[i][length] = '\0';
    }
    arr[size] = NULL; // so the command 'execvp' could know when to stop
}

string getDir()
{
    char buf[MAX_SIZE];
    string currentDir = getcwd(buf, MAX_SIZE); //get current directory

    if (signed(currentDir.find(string(getenv("HOME")))) != -1)
        currentDir.replace(0, string(getenv("HOME")).size(), "~");

    return ("OS SHELL:" + currentDir + "> ");
}

void deleteArray(int size, char **arr)
{
    if (arr != NULL)
    {
        for (int i = 0; i < size; i++)
            if (arr[i] != NULL)
                delete arr[i];
        delete[] arr;
    }
}