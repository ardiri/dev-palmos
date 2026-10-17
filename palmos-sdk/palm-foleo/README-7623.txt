README Falcon SDK

The Falcon SDK and Falcon Core ROM are developed in parallel.  The Core ROM is installed into the Falcon device via external media.  Please refer to the document Flashing_Instructions.doc. The Falcon OS is provided as a new ROM image that can be identified by its branch version and build number seen in the filename of the package.

The Falcon SDK has libraries and interfaces that correspond to a particular version of the ROM so it can be used to develop programs for that specific version of the ROM.  To indicate this, the SDK is named with the same branch and build number as the ROM that it corresponds to.  Once installed the SDK version number can be discerned by inspecting the file /opt/holly/sysroot/i386-linux/MANIFEST.  The first few lines indicate the build information.

The Falcon SDK is shipped as a tar file. The first step to installing the Falcon SDK is to download it and untar it.

tar xzf SDK_filename.tar.gz

The untarred SDK contains this README file, tools to build both arm and i386 versions of Falcon software, and separate libraries and header files to build software that can either be run natively on the arm-based Falcon or simulated on the i386-based development system.  Plus there is a folder of sample code that is installed in the main SDK directory, but which may be relocated elsewhere for development purposes. There is also a docs folder with instructions on how to develop for Falcon.  Finally, there is the installer script to install this SDK, sdk-installer.sh.  Please navigate to the Getting Started Guide (Falcon_GettingStarted.pdf) and proceed from there.

