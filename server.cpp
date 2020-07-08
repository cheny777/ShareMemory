#include "comm.h"
#include <csignal>
#include <cstdlib>


char *addrg;
int shmidg;

void sighander(int sig)
{
    shmdt(addrg);
    DestroyShm(shmidg);
    cout<<"signal:"<<sig<<endl;
    exit(sig);
}


int main()
{
    /*关闭信号*/
    signal(SIGINT,sighander);

    /*创建共享内存 shmget()*/
    int shmid = CreateShm(4096);
    /*映射供共享内存*/
    char *addr = (char *)shmat(shmid,NULL,0);
    shmidg = shmid;
    addrg = addr;

    union CharInt I;

    while (1)
    {
        I.str[0] = addr[0];
        I.str[1] = addr[1];
        I.str[2] = addr[2];
        I.str[3] = addr[3];
        cout<<"client:"<<I.value<<endl;
        sleep(1);
    }
    /*当不需要对此共享内存进行操作时候，调用shmdt函数进行分离，不是删除此共享存储空间*/
    shmdt(addr);
    /*关闭共享内存  shmctl()*/
    DestroyShm(shmid);
    return 0;
}
