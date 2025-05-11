#include "../include/minitalk.h"
#include <signal.h>

int main(int ac, char **av)
{
    if(ac < 3)
    {
        ft_putstr_fd("You have to introduce 3 arguments!!\n", 2);
        return EXIT_FAILURE;
    }
    else
    {
        int server_pid = atoi(av[1]);
        if (server_pid <= 0)
        {
            ft_putstr_fd("Invalid PID",2);
            EXIT_FAILURE;
        }
        
        int i = 0;
        int bit;
        while(av[2][i])
        {
            bit = 8;
            while(bit--)
            {
                if ((av[2][i] >> bit )& 1)
                {
                    kill(server_pid,SIGUSR1);
                }
                else
                {
                    kill(server_pid,SIGUSR2);
                }
                usleep(100);
            }
        }
    }
    return EXIT_SUCCESS;        
}