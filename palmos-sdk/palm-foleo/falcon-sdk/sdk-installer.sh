#!/bin/bash 

# SDK installer:

# Checks for the right environment and installs the components into
# the right location
# This assumes that the script is run from the same level as the 
# various tarballs for the SDK (this is done automatically when the
# sdk is built).
# Can skip installation of fusion module by using -NO_FUSION:
# sdk-installer.sh -NO_FUSION
# Any simple command that fails will immediately abort the install

INSTALL_DIR="$(cd $(dirname $0); pwd)"
LOG_DIR=${INSTALL_DIR}
INSTALL_LOG="${LOG_DIR}/installation.log"
ERROR_LOG="${LOG_DIR}/error.log"
TARGET_DIR=/opt/holly
TOOLROOT="${TARGET_DIR}/toolroot"
SYSROOT="${TARGET_DIR}/sysroot"
USERROOT="${TARGET_DIR}/userroot"
ARM_TARGET=arm-linux
INTEL_TARGET=i386-linux
ARM_TOOLROOT="${TOOLROOT}/${ARM_TARGET}"
INTEL_TOOLROOT="${TOOLROOT}/${INTEL_TARGET}"
ARM_SYSROOT="${SYSROOT}/${ARM_TARGET}"
INTEL_SYSROOT="${SYSROOT}/${INTEL_TARGET}"
FUSION_SRCROOT="${INTEL_SYSROOT}/src"
ARM_USERROOT="${USERROOT}/${ARM_TARGET}"
INTEL_USERROOT="${USERROOT}/${INTEL_TARGET}"
DOCSROOT="${TARGET_DIR}/docs"

echo "Starting SDK installation..."

# test if the targets exists, if not create them.
echo "A user executing this script must have sudo (be included "
echo "in the /etc/sudoers file correctly).  The user should "
echo "also have write access to /opt"

sudo -v

if [ ! -w /opt ] ; then
    echo "Can't write into /opt directory..."
    echo "Please make sure that this account can create files inside /opt"
    echo "e.g.: sudo chmod 777 /opt"
    exit 1
fi

echo "Create target directories (under /opt/holly)..."

# But don't clobber existing work!
if [ -d /opt/holly ] ; then
    echo "Don't destroy existing work in /opt/holly directory..."
    echo "Please rename or remove existing /opt/holly directory"
    echo "and re-run sdk-installer.sh."
    exit 2
fi

function Fusion_May_Be_Running
{
	echo "If you receive an error \"fusion: Device or resource busy\","
	echo "The fusion module might be active, please shut down/terminate"
	echo "any Maguffin applications and re-run sdk-installer.sh.  Thanks." 
	echo ""
}

mkdir -p "${TARGET_DIR}"
mkdir -p "${TOOLROOT}"
mkdir -p "${SYSROOT}"
mkdir -p "${USERROOT}"
mkdir -p "${ARM_TOOLROOT}"
mkdir -p "${INTEL_TOOLROOT}"
mkdir -p "${ARM_SYSROOT}"
mkdir -p "${INTEL_SYSROOT}"
mkdir -p "${ARM_USERROOT}"
mkdir -p "${INTEL_USERROOT}"

pushd "${TARGET_DIR}" > /dev/null

# install basic tools
echo "Install the toolchains (i386, arm)..."
tar xvjf "${INSTALL_DIR}/toolroot-arm.tar.bz2" > "${INSTALL_LOG}"
tar xvjf "${INSTALL_DIR}/toolroot-i386.tar.bz2" >> "${INSTALL_LOG}"


# install basic sysroot
echo "Install the system root (i386, arm)..."
tar xvjf "${INSTALL_DIR}/sysroot-arm.tar.bz2" >> "${INSTALL_LOG}"
tar xvjf "${INSTALL_DIR}/sysroot-i386.tar.bz2" >> "${INSTALL_LOG}"


# install the SDK libraries and headers
echo "Install the SDK libraries (i386, arm)..."
tar xvjf "${INSTALL_DIR}/sdk_i386-sysroot.tar.bz2" >> "${INSTALL_LOG}"
tar xvjf "${INSTALL_DIR}/sdk_arm-sysroot.tar.bz2" >> "${INSTALL_LOG}"
tar xvjf "${INSTALL_DIR}/sdk_i386-userroot.tar.bz2" >> "${INSTALL_LOG}"
tar xvjf "${INSTALL_DIR}/sdk_arm-userroot.tar.bz2" >> "${INSTALL_LOG}"

# Everything above is not optional. If you don't have tools, 
# includes, and libraries, you don't have an SDK.
# Samples and documentation are not so serious if missing though.
# So check for existance before installing.
# Likewise optional libraries.

if [ -f "${INSTALL_DIR}/sdk_i386-release-sysroot.tar.bz2" ]; then
    echo "Install the optional i386 release libraries"
    tar xvjf "${INSTALL_DIR}/sdk_i386-release-sysroot.tar.bz2" >> "${INSTALL_LOG}"
fi

if [ -f "${INSTALL_DIR}/sdk_arm-debug-sysroot.tar.bz2" ]; then
    echo "Install the optional arm debug libraries"
    tar xvjf "${INSTALL_DIR}/sdk_arm-debug-sysroot.tar.bz2" >> "${INSTALL_LOG}"
fi

if [ -f "${INSTALL_DIR}/samples.tar.bz2" ]; then
    echo "Install the SDK samples"
    tar xvjf "${INSTALL_DIR}/samples.tar.bz2" >> "${INSTALL_LOG}"
fi

if [ -f "${INSTALL_DIR}/docs.tar.bz2" ]; then
    echo "Install the SDK documentation"
    tar xvjf "${INSTALL_DIR}/docs.tar.bz2" >> "${INSTALL_LOG}"
fi

popd > /dev/null

# Install the documentation

# Can't imagine these files being missing, but allow for it in case.
if [ -f "${INSTALL_DIR}/README" ]; then
    cp "${INSTALL_DIR}/README" "${TARGET_DIR}"
fi
if [ -f "${INSTALL_DIR}/RELEASE_NOTES" ]; then
    cp "${INSTALL_DIR}/RELEASE_NOTES" "${TARGET_DIR}"
fi

FILE=/tmp/tmpmountfile

more /proc/mounts | grep shm > $FILE 

if [ -f $FILE ] ; then
    for i in $FILE
    do
        sudo umount /dev/shm > /dev/null
    done
    rm $FILE > /dev/null 
fi;

# Flag to allow bypass of fusion module installation.
# Can test first param inline here because it is the
# only parameter allowed.


if [ "$1" = -NO_FUSION ] ; then
    echo "Fusion module not to be installed."
else
    echo "Install the fusion module (i386)..."
    if (PATH=$PATH:/sbin lsmod | grep -q fusion) ; then
	Fusion_May_Be_Running	
	sudo rmmod fusion 
    fi
    # No fusion found, so build and install it.
    mkdir -p "${FUSION_SRCROOT}"
    pushd "${FUSION_SRCROOT}" >/dev/null
    # always copy sources for fusion module
    tar xvjf "${INSTALL_DIR}/i386-linux-fusion.tar.bz2" >> "${INSTALL_LOG}"
    # and finally try to build and install fusion module
    # (When we sent output to the log file, installers didn't see the 
    # prompt for where kernel sources were. Tried tee, but it clobbered
    # entire log file. So just not logging fusion install at all for now.)
    ./fusion-installer.sh all
    popd > /dev/null
fi

# the end
echo "SDK installation done!"
