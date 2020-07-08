#include "comm.h"
#include <string>

using namespace std;

int main()
{
    int shmid = GetShm(4096);
    char *addr = (char *)shmat(shmid,NULL,0);

    union CharInt I;

    while (1)
    {
        int str;
        cin>>str;

        I.value = str;
        addr[0] = I.str[0];
        addr[1] = I.str[1];
        addr[2] = I.str[2];
        addr[3] = I.str[3];

        sleep(1);
    }
    return 0;
}
