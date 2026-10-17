/*
 * mixer_ioctl.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/soundcard.h>
#include <linux/soundcard-sgvp.h>

#define	DEV_MIXER	"/dev/mixer"
#define	DEBUG


static void
usage(void)
{
	fprintf(stderr, "mixer_ioctl -o | -O value  speaker, reciever on/off\n");
	fprintf(stderr, "mixer_ioctl -m | -M value  mic select\n");
	fprintf(stderr, "mixer_ioctl -h             connection status of headphone\n");
	exit(1);
}

int
main(int argc, char *argv[])
{
	int	fd, c, work;


	if ((fd = open(DEV_MIXER, O_RDWR)) == -1) {
		perror("open");
		exit(1);
	}

	while ((c = getopt(argc, argv, "omhO:M:")) != EOF) {
		switch (c) {
		case 'o':
			if (ioctl(fd, SANDGATE_VP_SOUND_MIXER_READ_ODEVSEL, &work) == -1) {
				perror("SANDGATE_VP_SOUND_MIXER_READ_ODEVSEL");
				exit(1);
			}
#ifdef DEBUG
			printf("SANDGATE_VP_SOUND_MIXER_READ_ODEVSEL: %xh\n", work);
#endif
			if (work & SANDGATE_VP_SOUND_ODEV_SPK)
				printf("Speaker  ON\n");
			else
				printf("Speaker  OFF\n");
			if (work & SANDGATE_VP_SOUND_ODEV_RCV)
				printf("Reciever ON\n");
			else
				printf("Reciever OFF\n");
			break;
		case 'O':
			work = atoi(optarg);
			if (ioctl(fd, SANDGATE_VP_SOUND_MIXER_WRITE_ODEVSEL, work) == -1) {
				perror("SANDGATE_VP_SOUND_MIXER_WRITE_ODEVSEL");
				exit(1);
			}
#ifdef DEBUG
			printf("SANDGATE_VP_SOUND_MIXER_WRITE_ODEVSEL: %xh\n", work);
#endif
			break;
		case 'm':
			if (ioctl(fd, SANDGATE_VP_SOUND_MIXER_READ_MICSEL, &work) == -1) {
				perror("SANDGATE_VP_SOUND_MIXER_READ_MICSEL");
				exit(1);
			}
#ifdef DEBUG
			printf("SANDGATE_VP_SOUND_MIXER_READ_MICSEL: %xh\n", work);
#endif
			if (work == SANDGATE_VP_SOUND_MIC_INT)
				printf("MIC internal\n");
			else if (work == SANDGATE_VP_SOUND_MIC_EXT)
				printf("MIC external\n");
			else
				printf("MIC status unknown\n");
			break;
		case 'M':
			work = atoi(optarg);
			if (ioctl(fd, SANDGATE_VP_SOUND_MIXER_WRITE_MICSEL, work) == -1) {
				perror("SANDGATE_VP_SOUND_MIXER_WRITE_MICSEL");
				exit(1);
			}
#ifdef DEBUG
			printf("SANDGATE_VP_SOUND_MIXER_WRITE_MICSEL: %xh\n", work);
#endif
			break;
		case 'h':
			if (ioctl(fd, SANDGATE_VP_SOUND_MIXER_READ_HDSET, &work) == -1) {
				perror("SANDGATE_VP_SOUND_MIXER_READ_HDSET");
				exit(1);
			}
#ifdef DEBUG
			printf("SANDGATE_VP_SOUND_MIXER_READ_HDSET: %xh\n", work);
#endif
			if (work == SANDGATE_VP_SOUND_HDSET_CONNECT)
				printf("Headphone Jack connect\n");
			else if (work == SANDGATE_VP_SOUND_HDSET_UNCONNECT)
				printf("Headphone Jack unconnect\n");
			else
				printf("Headphone Jack status unknown\n");
			break;
		default:
			usage();
			break;
		}
	}

	close(fd);

	return 0;
}
