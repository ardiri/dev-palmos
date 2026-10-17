#include <fcntl.h>
#include <linux/soundcard.h>
#include <stdio.h>
#include <sys/ioctl.h>

#define BUFSIZE 441000

static int setup_dsp(int fd);

int main(void)
{
	short buf[BUFSIZE];
	int   fd, rtn;

	if ((fd = open( "/dev/dsp", O_RDWR)) == -1)
	{
		perror("open()");
		exit(1);
	}

	if (setup_dsp(fd) != 0)
	{
		fprintf(stderr, "Setup /dev/dsp failed.\n");
		close(fd);
		exit(1);
	}


	printf( "########################################\n" );
	printf( "# Now speak to your mic for 5 seconds. #\n" );
	printf( "########################################\n" );

	if ((rtn = read(fd, buf, BUFSIZE)) == -1)
	{
		perror("read()");
		close(fd);
		exit(1);
	}


	printf( "\n" );
	printf( "########################################\n" );
	printf( "# Playing what you have said.          #\n" );
	printf( "########################################\n" );

	if (write(fd, buf, rtn) == -1)
	{
		perror("write()");
		close(fd);
		exit(1);
	}

	close(fd);
	return 0;
}


static int setup_dsp(int fd)
{
	int fmt     = AFMT_S16_LE;
	int freq    = 44100;
	int stereo  = 0;

	if (ioctl(fd, SOUND_PCM_SETFMT, &fmt) == -1)
	{
	  	perror("ioctl( SOUND_PCM_SETFMT )");
	  	perror("ioctl( SOUND_PCM_SETFMT )");
	}

	if (ioctl(fd, SNDCTL_DSP_STEREO, &stereo) == -1)
	{
		perror("ioctl( SNDCTL_DSP_STEREO )");
		return -1;
	}

	if (ioctl(fd, SOUND_PCM_WRITE_RATE, &freq) == -1)
	{
		perror("ioctl( SOUND_PCM_WRITE_RATE )");
		return -1;
	}

	return 0;
}
