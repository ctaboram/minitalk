#include <signal.h>   // Señales
#include <unistd.h>   // write(), getpid(), pause()
#include <stdlib.h>   // NULL
#include "../include/minitalk.h"  // tus funciones: ft_putstr_fd, ft_putnbr_fd

static void signal_handler(int signal_number, siginfo_t *info, void *context)
{
	static int bit;
	static unsigned char str;
	bit = 8;
	str = 0;
    (void)info;
    (void)context;

    if(signal_number == SIGUSR2)
	{
        str |= (1 << (7 - bit));
	}
	bit++;
	if(bit == 8)
	{
		write(1,&str,1);
		bit = 0;
		str = 0;	
	}
}

int main(void)
{
    struct sigaction sa;

    ft_putstr_fd("PID SERVER : ", 1);
    ft_putnbr_fd(getpid(), 1);
    write(1, "\n", 1);

    sa.sa_sigaction = &signal_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
        pause();

    return (0); // buena práctica
}
