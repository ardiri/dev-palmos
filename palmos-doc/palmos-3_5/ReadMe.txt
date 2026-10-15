Read Me Palm OS SDK 3.5

IMPORTANT:  Read Before Using The Accompanying Software

= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
P a l m   O S   S o f t w a r e   D e v e l o p m e n t   K i t
= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 

Installation Instructions:

Macintosh (Manual)

1.  Locate the CodeWarrior Support folder which is in the SDK folder.

2.  Move the contents of the (Project Stationery) folder, the "Palm OS 3.5", into the (Project Stationery) folder where you CodeWarrior resides on your local drive.

3.  Move the items located inside the Codewarrior plugins folder on the SDK into their respective folders where your CodeWarrior resides on your local drive.  This will include the following:

	- Move the "PalmRez Post Linker" from the Linkers folder on the SDK to the Linkers folder inside "CodeWarrior Plugins" folder where you CodeWarrior resides on your local drive.  This will replace the old "PalmRez Post Linker".

	- Move the "PalmRez Panel" from the Preference Panels folder on the SDK to the Preference Panels folder inside "CodeWarrior Plugins" folder where you CodeWarrior resides on your local drive.  This will replace the old "PalmRez Panel".
	Note: If you are doing development on a Japanese system replace the PalmRez Panel with PalmRez-J Panel.  You can have only one PalmRez Panel in your system at a time.

	- Move the "Support" folder from the SDK to the Codewarrior Plugins folder on your local system.  If a Support folder already exists, copy only the "PalmRez Japanese Support" file to your existing Support folder.
Copy the  "Palm OS 3.5 Support" folder from the SDK into the directory where your "CodeWarrior IDE" resides on your local drive.
Manually copy any other files located on the SDK or downloaded from the web to your local drive.


Macintosh (Installer)


Windows (Manual)

1.  Locate the CodeWarrior Support folder which is in the SDK folder.

2.  Move the contents of the (Project Stationery) folder, the "Palm OS 3.5", into the (Project Stationery) folder where you CodeWarrior resides on your local drive.

3.  Move the items located inside the plugins folder on the SDK into their respective folders where your CodeWarrior resides on your local drive. This will include the following:

	- Move the "PalmRez Post Linker" from the Linkers folder on the SDK to the Linkers folder inside the "CodeWarrior Plugins" folder where your CodeWarrior resides on your local drive.  This will replace the old "PalmRez Post Linker".

	- Move the "PalmRez Panel" from the Preference Panels folder on the SDK to the Preference Panels folder inside "CodeWarrior Plugins" folder where you CodeWarrior resides on your local drive. This will replace the old "PalmRez Panel".
	Note: If you are doing development on a Japanese system replace the PalmRez Panel with PalmRez-J Panel. You can have only one PalmRez Panel in your system at a time.

	- Move the "Support" folder from the SDK to the Codewarrior Plugins folder on your local system.  If a Support folder already exists, copy only the "PalmRez Japanese Support" file to your existing Support folder.
Copy the  "Palm OS 3.5 Support" folder from the SDK into the directory where your "CodeWarrior IDE" resides on your local drive.
Manually copy any other files located on the SDK or downloaded from the web to your local drive.


Windows (Installer)

This installer will only install the components needed by CodeWarrior to your local drive.  For all other items you can drag the folder to the necessary place.  Note: the "Palm OS 3.5 SDK" should only be installed over CodeWarrior for Palm OS R6.

1.  Launch "PalmOS 3.5 SDK.exe".  This will unarchive and launch the installer.

2.  Locate the version of CodeWarrior for Palm OS that you want updated, and install.

3.  The following items will be installed by this installer:
	"Palm OS 3.5" project stationary folder will be added to your "Project Stationery" folder.
	"PalmPlugin.dll" will be added to your bin\plugins\Debugger folder.
	"PalmRezPostLinker.dll" will be added to your bin\plugins\Linker folder.
	"PPalmRez.dll" will be added to your bin\plugins\Preference Panel folder.
	"PalmRez Japanese Support" will be added to your bin\plugins\Support folder.
	"Constructor for Palm OS.exe" and "CONSTRUCTOR FOR PALM OS.HLP" will be added into your bin folder.
	"Palm OS 3.5 Support" folder will be added to your Metrowerks\CW for Palm OS R6 folder.
	"PPalmRez-J.dll" will be installed to your "Palm OS Extras\Japanese Support" folder.


GCC
ADDING THIS SDK TO A GCC TOOL CHAIN

* prc-tools 0.5.0, based on GCC 2.7.2.2

Depending on how you have set things up, you want to add the header files from this SDK to a "PalmOS35" directory alongside your old SDK headers.  This is complicated a little by the fact that most of the files in "Palm OS 3.5 Support/Incs" are now down in a "Core" subdirectory.

1.  Create a "PalmOS35" directory wherever you have put your "PalmOS1", "PalmOS2", etc, directories.

2.  Copy the directory tree under "Palm OS 3.5 Support/Incs/Core" to your new "PalmOS35" directory.

3.  Copy all the files in the top level "Palm OS 3.5 Support/Incs" directory and all the files under "Palm OS 3.5 Support/Incs/Dynamic" and "Palm OS 3.5 Support/Incs/Libraries" to your "PalmOS35" directory.
These files won't be in their official proper places, but at least you will be able to get work done.

4.  Again depending on how you have things set up, you can instruct GCC to use these header files by changing the "PalmOS" symbolic link to point to your "PalmOS35" directory.

5.  You may also want to add the libraries in "Palm OS 3.5 Support/GCC Libraries/m68k-palmos-coff" to somewhere in your linker search path.
Again, this depends on how you have set up the compiler; you may want to use a "-L" linker option to point to the libraries if you use them.

* newer prc-tools, based on GCC 2.95.2

You need to add the header files and libraries to your PalmDev directory, which (unless you have configured the tool chain differently) is "/usr/local/palmdev" on Unix and "C:\PalmDev" on Windows.

1.  In "/usr/local/palmdev" (or "C:\PalmDev"), create a directory "sdk-3.5" containing "include" and "lib" subdirectories.

2.  Copy the contents of "Palm OS 3.5 Support/Incs" to the new "include" directory.

3.  Copy the contents of "Palm OS 3.5 Support/GCC Libraries" to the new "lib" directory.

4.  You can now compile your programs using 3.5 headers and libraries by adding a "-palmos3.5" option to your compile and link commands.

$ m68k-palmos-gcc -O2 -o hello hello.c -palmos3.5

5. To use the 3.5 SDK by default, change the "sdk" symbolic link in PalmDev.

$ cd /usr/local/palmdev       [or wherever your PalmDev is]
$ rm sdk
$ ln -s sdk-3.5 sdk

The resulting directory structure should look like this:

/usr/local/palmdev/sdk-3.5
/usr/local/palmdev/sdk-3.5/include
/usr/local/palmdev/sdk-3.5/include/Core
/usr/local/palmdev/sdk-3.5/include/Core/System etc
/usr/local/palmdev/sdk-3.5/include/Dynamic etc
/usr/local/palmdev/sdk-3.5/lib
/usr/local/palmdev/sdk-3.5/lib/m68k-palmos-coff

What's New

Documentation

"Palm OS Companion.pdf" and "Palm OS Reference.pdf" have been updated to contain new color APIs and other UI APIs.  These documents are not yet final, please refer to the web to get updated documentation: http://www.palm.com/devzone
"Development Tools Guide.pdf" has been added. This document contains information on using Palm OS Simulator, Palm OS Emulator and PalmDebugger.


Examples

Built-in Application examples come complete with the resources for all languages.  However, the project files only have targets for a small sample:
	Address-English Only
	DateBook-English & Japanese only
	Expense-English & Japanese only
	HardBall-English Only
	Mail-English & Japanese only
	Memo-All Languages
	MineHunt-English Only
	Puzzle-English Only
	Reptiods-English Only
	SubHunt-English Only
	ToDo-English & Japanese only
	Formats-English Only
All samples that ship with the Palm OS 3.5 SDK have been updated to use the Palm OS 3.5 Support folder.
The Finger example is GCC compatible.


Constructor 1.5

New functionality in Constructor for Palm OS is located in the "Constructor for Palm OS.pdf" file.

Installation instructions

Macintosh

Windows

Installer
"Constructor for Palm OS.exe" and "CONSTRUCTOR FOR PALM OS.HLP" are installed by the PalmOS 3.5 SDK.exe installer.


What's New

Support for 8-Bit Color

Known Issues

When creating bitmaps, you must select the correct color level from the Color menu before saving.


General

The directory structure for the in the Palm OS Support/Incs folder has changed since the Palm OS 3.1/Palm VII SDK.  To assist in locating changed, deleted or added files, an HTML document has been added to the Documentation folder which outlines the differences. IncsFileChanges.html 

The "PalmPlugin" and "PalmPlugin.dll", which reside in your Debugger(s) folder, has been updated by Metrowerks since the release of CodeWarrior for Palm OS R6.  This update fixes the problem when using Palm OS Emulator and you receive the following error message. '"UIAppShell" (unknown version) reports "DataMgr.c, Line:2542, Records left locked in closed unprotected DB".'

The "68KLinker.dll" which is located in the Linker folder on Windows has been updated by Metrowerks since R6. This updated version fixes the BDMW Registry error sometimes received when attempting to debug.
Palm OS Simulator for 3.5 consists of adding only the following files to your project: SimulatorMac.lib and SimulatorMac.rsrc. 

Launching a Simulator application the first time will prompt you for the location of the "Sys.tres" resource files, which are located in the "Palm OS 3.5 Support:CodeWarrior Libraries:Simulator:System Resources:" folder.

The memory partition for CodeWarrior IDE should be > 15MB for projects that include the Simulator.

When using the Palm Debugger or the Simulator it is important to correctly enter your commands into the "console" or "debugger" windows.  Some commands if entered incorrectly can have unpredictable results.

If the Simulator window opens at (0, 0) appearing under the menu bar, delete the Palm OS Simulator Preferences file in the preferences folder and restart the simulator.

The Icon and Multibit Icon resource editors are there for backward compatability reasons.  They cannot create icons greater than 1-bit and 2-bit depth respectively. Use the new Bitmap Family editor or the App Icon Family
editor to create images in multiple bit-depths.

Known Issues

HostControl.h - The HostControl.h file that ships with the Palm OS 3.5 SDK is different from the HostControl.h that ships with Palm OS Emulator.  If you need to use the HostControl.h for use with the emulator you should use the HostControl.h that comes with the Palm OS Emulator.

Palm OS Constructor for Windows:

If you are editing an Icon resource, the "Colors" menu enables bit-depths other than 1-bit.  If you try and use any bit-depth other than 1, and save the resource, the image will be lost.

Similarly, for Multi-bit Icons the "Colors" menu  has 4- and 8-bit options enabled.  If you use either of these depths and save the resource, the resource image will be lost.


Palm Computing, Inc., a 3Com Corporation
5400 Bayfront Plaza
Santa Clara, California 95052
(408) 326-9000

