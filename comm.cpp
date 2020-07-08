#include "comm.h"

static int CommShm(int size,int flag)
{
    key_t key = ftok(PATHNAME,PROJ_ID);
    if(key<0)
    {
        cout<<"ftok"<<endl;
        return -1;
    }
    int shmid = 0;
    if((shmid = shmget(key,size,flag))<0)
    {
        cout<<"shmget"<<endl;
        return -2;
    }
    return shmid;
}


int CreateShm(int size)
{
    return CommShm(size,IPC_CREAT|IPC_EXCL|0666);
}

int DestroyShm(int shmid)
{
    if(shmctl(shmid,IPC_RMID,NULL)<0)
    {
        cout<<"shmctl"<<endl;
        return -1;
    }
    return 0;
}


int GetShm(int size)
{
    return CommShm(size,IPC_CREAT);
}
