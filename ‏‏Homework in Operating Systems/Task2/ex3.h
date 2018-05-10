#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

using namespace std;

#define SEMPERM 0600

int initsem(key_t semkey, int initval)
{
	int status = 0;
	int semid;

	union semun 
	{
		int val;
		struct semid_ds *stat;
		ushort *array;
	} ctl_arg;

	if ((semid = semget(semkey, 1, SEMPERM | IPC_CREAT | IPC_EXCL)) == -1)
	{
		if (errno == EEXIST)
		{
			semid = semget(semkey, 1, 0);
		}
	}
	else
	{
		union semun arg;
		arg.val = initval;
		status = semctl(semid, 0, SETVAL, arg);
	}

	ctl_arg.val = initval;

	if (semid == -1 )
	{
		cerr << "Initsem failed" << endl;
		exit(-1);
	}

	status = semctl(semid, 0, SETVAL, ctl_arg);

	if(status == -1)
	{
		perror("initsem failed");
		exit(0);
	}
	


	return semid;
}

int getSemVal(int semid, int semnum)
{
	return (semctl(semid, semnum, GETVAL, 0));
}

void removesem(int sid)
{
	semctl(sid, 0, IPC_RMID, 0);
}

int down(int semid) // p
{
	struct sembuf sops;
	sops.sem_num = 0;
	sops.sem_op = -1;

	if (semop(semid, &sops, 1) == -1)
	{
		cerr << "Error operation p(semid)" << endl;
		exit(1);
	}
	return (0);
}

int up(int semid) // v
{
	struct sembuf sops;
	sops.sem_num = 0;
	sops.sem_op = 1;
	//sops.sem_flg = SEM_UNDO;

	if (semop(semid, &sops, 1) == -1)
	{
		cerr << "Error operation v(semid)" << endl;
		exit(1);
	}
	return (0);
}
