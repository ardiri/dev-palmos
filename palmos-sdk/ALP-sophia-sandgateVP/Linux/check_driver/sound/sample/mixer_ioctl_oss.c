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
	fprintf(stderr, "mixer_ioctl_oss -a | -A value  speaker, reciever mute on/off\n");
	fprintf(stderr, "mixer_ioctl_oss -b | -B value  headphone mute on/off \n");
	fprintf(stderr, "mixer_ioctl_oss -c | -C value  mic mute on/off \n");
	fprintf(stderr, "mixer_ioctl_oss -d | -D value  volume set \n");
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

	while ((c = getopt(argc, argv, "abcdA:B:C:D:")) != EOF) {
		switch (c) {
		case 'a':
			if (ioctl(fd, SOUND_MIXER_READ_VOLUME, &work) == -1) {
				perror("SOUND_MIXER_READ_VOLUME");
				exit(1);
			}
#ifdef DEBUG
			printf("SOUND_MIXER_READ_VOLUME %xh\n", work);
#endif
			if (work == 0)
				printf("Speaker/Receive mute ON\n");
			else if (work == 100)
				printf("Speaker/Receive mute OFF\n");
			else	
				printf("Speaker/Receive mute val = %d\n", work);
			break;
		case 'A':
			work = atoi(optarg);
			if (ioctl(fd, SOUND_MIXER_WRITE_VOLUME, &work) == -1) {
				perror("SOUND_MIXER_WRITE_VOLUME");
				exit(1);
			}
#ifdef DEBUG
			printf("SOUND_MIXER_WRITE_VOLUME: %xh\n", work);
#endif
			break;
		case 'b':
			if (ioctl(fd, SOUND_MIXER_READ_ALTPCM, &work) == -1) {
				perror("SOUND_MIXER_READ_ALTPCM");
				exit(1);
			}
#ifdef DEBUG
			printf("SOUND_MIXER_READ_ALTPCM: %xh\n", work);
#endif
			if (work == 0)
				printf("headphone mute ON \n");
			else if (work == 100)
				printf("headphone mute OFF\n");
			else
				printf("headphone mute val = %d\n", work);
			break;
		case 'B':
			work = atoi(optarg);
			if (ioctl(fd, SOUND_MIXER_WRITE_ALTPCM, &work) == -1) {
				perror("SOUND_MIXER_WRITE_ALTPCM");
				exit(1);
			}
#ifdef DEBUG
			printf("SOUND_MIXER_WRITE_ALTPCM: %xh\n", work);
#endif
			break;
		case 'c':
                        if (ioctl(fd, SOUND_MIXER_READ_MIC, &work) == -1) {
                                perror("SOUND_MIXER_READ_MIC");
                                exit(1);
                        }
#ifdef DEBUG
                        printf("SOUND_MIXER_READ_MIC: %xh\n", work);
#endif
                        if (work == 0)
                                printf("mic mute ON \n");
                        else if (work == 100)
                                printf("mic mute OFF\n");
                        else
                                printf("mic mute val = %d\n", work);
                        break;
		case 'C':
                        work = atoi(optarg);
                        if (ioctl(fd, SOUND_MIXER_WRITE_MIC, &work) == -1) {
                                perror("SOUND_MIXER_WRITE_MIC");
                                exit(1);
                        }
#ifdef DEBUG
                        printf("SOUND_MIXER_WRITE_MIC: %xh\n", work);
#endif
                        break;
		case 'd':
                        if (ioctl(fd, SOUND_MIXER_READ_PCM, &work) == -1) {
                                perror("SOUND_MIXER_READ_PCM");
                                exit(1);
                        }
#ifdef DEBUG
                        printf("SOUND_MIXER_READ_PCM: %xh\n", work);
#endif
                        printf("volume val = %d\n", work);
                        break;
		case 'D':
                        work = atoi(optarg);
                        if (ioctl(fd, SOUND_MIXER_WRITE_PCM, &work) == -1) {
                                perror("SOUND_MIXER_WRITE_PCM");
                                exit(1);
                        }
#ifdef DEBUG
                        printf("SOUND_MIXER_WRITE_PCM: %xh\n", work);
#endif
                        break;
		default:
			usage();
			break;
		}
	}

	close(fd);

	return 0;
}
