/*
 * headphonejack.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/poll.h>
#include <linux/soundcard.h>
#include <linux/soundcard-sgvp.h>

#define	DEV_MIXER	"/dev/mixer"

static struct pollfd	pfd;

static void
usage(void)
{
	fprintf(stderr, "headphonejack [-t interval<sec>]\n");
	exit(1);
}

int
main(int argc, char *argv[])
{
	int	c, fd, ret, timeout;
	unsigned int	work;
	unsigned int	cnt = 0;

	timeout = 10000;			/* 10 sec */

	while ((c = getopt(argc, argv, "t:")) != EOF) {
		switch (c) {
		case 't':
			timeout = atoi(optarg);
			timeout *= 1000;
			break;
		default:
			usage();
			break;
		}
	}

	if ((fd = open(DEV_MIXER, O_RDWR)) == -1) {
		perror("open");
		exit(1);
	}

	pfd.fd = fd;
	pfd.events = POLLIN;

	printf("headset status:\n");
	if (ioctl(fd, SANDGATE_VP_SOUND_MIXER_READ_HDSET, &work) == -1) {
		perror("SANDGATE_VP_SOUND_MIXER_READ_HDSET");
		exit(1);
	}
	printf("<%d> %s\n", cnt++, (work == SANDGATE_VP_SOUND_HDSET_CONNECT) ? "connect" : "unconnect");
	
	for (;;) {
		ret = poll(&pfd, 1, timeout);
		if (ret >= 0) {
			if (ioctl(fd, SANDGATE_VP_SOUND_MIXER_READ_HDSET, &work) == -1) {
				perror("SANDGATE_VP_SOUND_MIXER_READ_HDSET");
				exit(1);
			}
			if(work == 1)
			  exit(1);
			printf("<%d> %s", cnt++, (work == SANDGATE_VP_SOUND_HDSET_CONNECT) ? "connect   " : "unconnect ");
			if (ret > 0) {
				printf("[%x] ", pfd.revents);
				if (pfd.revents & POLLIN)
					printf("POLLIN ");
				if (pfd.revents & POLLERR)
					printf("POLLERR ");
				if (pfd.revents & POLLHUP)
					printf("POLLHUP ");
				if (pfd.revents & POLLNVAL)
					printf("POLLNVAL ");
			} else {
				printf("TIMEOUT");
			}
			printf("\n");
		} else {
			perror("poll");
			break;
		}
	}

	close(fd);

	return 0;
}
