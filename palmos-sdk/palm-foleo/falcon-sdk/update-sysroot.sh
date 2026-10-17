#!/bin/bash -e
set -e

# update script to facilitate the simulator

TOOLNAME=update-sysroot.sh
FILENAME=

echo "*********************************************************************"
echo "  This script facilitates update of the /opt/holly/sysroot/i386-linux" 
echo "  If found it will back up the current /opt/holly/sysroot/i386-linux"
echo "  in the current directory as i386-linux.bak.tar.bz2.      "
echo "  It will bunzip and untar a simulator dir into place" 
echo ""
echo ""

function DoHelp
{
    echo "  Usage: ${TOOLNAME} [-f FileName] [-d] [-h]"
    echo "  -f FileName:       FileName is the sysroot to untar that will be "
    echo "                     installed into /opt/holly/sysroot/i386-linux."
    echo "                     The current sysroot will be backed up"
    echo "  -h                 Will output this help menu"
    echo ""
    exit
}

function abort()
{
   echo $@
   exec false
}

if [ $# = 0 ]; then
    DoHelp
fi

while [ -n "$1" ]; do
    case $1 in
        -f) FILENAME=$2;  
		if [ -f $FILENAME ] ; then 
			if [ -d /opt/holly/sysroot/i386-linux ] ; then  	
				tar -cvjf i386-linux.bak.tar.bz2 /opt/holly/sysroot/i386-linux/ || abort "Couldn't back up dir" 
				rm -rf /opt/holly/sysroot/i386-linux	
			fi
			
			CURRENT_DIR=`pwd`
			echo "cwd $CURRENT_DIR"	
			pushd . > /dev/null
			cd /opt/holly
			tar -xjvf $CURRENT_DIR/$FILENAME			
			popd > /dev/null	
		else
        		abort "Invalid: $2"; DoHelp;
		fi
		shift 2 ;;
	-h) DoHelp; shift ;;
        *) echo "Invalid:  ${TOOLNAME} option: $1"; echo ""; DoHelp;
    esac
done

echo "done!"
