#include <stdio.h>
#include <sys/fcntl.h>

int main(void)
{

	int fd;
	if ( (fd=open("/dev/ttyS0",O_RDWR)) == -1 ) {
	//	perror("open");
		return 1;
		//exit(-1);
	}
	close(fd);

	return 0;
}