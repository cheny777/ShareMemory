#ifndef COMM_H
#define COMM_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>

using namespace std;

#define PATHNAME "."
#define PROJ_ID 0x6666
/*创建*/
int CreateShm(int size);
/*销毁*/
int DestroyShm(int shmid);
/*获取*/
int GetShm(int size);

union CharInt
{
        unsigned char str[4];
        int value;
};



#endif // COMM_H
