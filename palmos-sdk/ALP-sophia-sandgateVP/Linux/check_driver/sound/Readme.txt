Sophia-Systems

Sound Sample Program Explanation

・mic command
This plays the recorded data after 5 sec of recording.
Startup example: # mic

・mixer_ioctl command
This turns the speaker and receiver ON/OFF.
Startup example (setting): # mixer_ioctl <-O 0 to 3>
Startup example (display): # mixer_ioctl <-o>

This is used to select between the internal or external microphone.
Startup example (setting): # mixer_ioctl <-M 0|1>
Startup example (display): # mixer_ioctl <-m>

This displays the headphone jack status.
Startup example: # mixer_ioctl <-h>

・mixer_ioctl_oss command
This turns the speaker and receiver mute ON/OFF.
Startup example (setting): # mixer_ioctl_oss <-A 0|100>
Startup example (display): # mixer_ioctl_oss <-a>

This turns the headphone mute ON/OFF.
Startup example (setting): # mixer_ioctl_oss <-B 0|100>
Startup example (display): # mixer_ioctl_oss <-b>

This turns the microphone mute ON/OFF.
Startup example (setting): # mixer_ioctl_oss <-C 0|100>
Startup example (display): # mixer_ioctl_oss <-c>

This sets the volume.
Startup example (setting): # mixer_ioctl_oss <-D 0 to 25700>
Startup example (display): # mixer_ioctl_oss <-d>

・headphonejack command
This detects the headphone jack status change.
Startup example:  # headphonejack <-t timeout>

Execution Example 1
This is played by the speaker and headphones after recording the audio for 5 sec using the internal microphone.
The sound volume is speaker 100 and headphones Rch 100, Lch 100.

-bash-3.1# ./mixer_ioctl -O 1
SANDGATE_VP_SOUND_MIXER_WRITE_ODEVSEL: 1h
-bash-3.1# ./mixer_ioctl -M 0
SANDGATE_VP_SOUND_MIXER_WRITE_MICSEL: 0h
-bash-3.1# ./mixer_ioctl_oss -A 100
SOUND_MIXER_WRITE_VOLUME: 64h
-bash-3.1# ./mixer_ioctl_oss -B 100
SOUND_MIXER_WRITE_ALTPCM: 64h
-bash-3.1# ./mixer_ioctl_oss -C 100
SOUND_MIXER_WRITE_MIC: 64h
-bash-3.1# ./mixer_ioctl_oss -D 25700
SOUND_MIXER_WRITE_PCM: 6464h
-bash-3.1# ./mic

Execution Example 2
This is played by the receiver and headphones after recording the audio for 5 sec using the internal microphone.
The sound volume is receiver 100 and headphones Rch 100, Lch 100.

-bash-3.1# ./mixer_ioctl -O 2
SANDGATE_VP_SOUND_MIXER_WRITE_ODEVSEL: 2h
-bash-3.1# ./mixer_ioctl -M 0
SANDGATE_VP_SOUND_MIXER_WRITE_MICSEL: 0h
-bash-3.1# ./mixer_ioctl_oss -A 100
SOUND_MIXER_WRITE_VOLUME: 64h
-bash-3.1# ./mixer_ioctl_oss -B 100
SOUND_MIXER_WRITE_ALTPCM: 64h
-bash-3.1# ./mixer_ioctl_oss -C 100
SOUND_MIXER_WRITE_MIC: 64h
-bash-3.1# ./mixer_ioctl_oss -D 25700
SOUND_MIXER_WRITE_PCM: 6464h
-bash-3.1# ./mic

