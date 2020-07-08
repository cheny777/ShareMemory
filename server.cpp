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
    /*�ر��ź�*/
    signal(SIGINT,sighander);

    /*���������ڴ� shmget()*/
    int shmid = CreateShm(4096);
    /*ӳ�乩�����ڴ�*/
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
    /*������Ҫ�Դ˹����ڴ���в���ʱ�򣬵���shmdt�������з��룬����ɾ���˹���洢�ռ�*/
    shmdt(addr);
    /*�رչ����ڴ�  shmctl()*/
    DestroyShm(shmid);
    return 0;
}
