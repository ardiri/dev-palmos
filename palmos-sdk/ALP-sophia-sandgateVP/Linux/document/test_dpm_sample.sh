#!/bin/sh

# Example DPM setup script for Intel XScale PXA27x
#
# 2005 (c) MontaVista Software, Inc. This file is licensed under
# the terms of the GNU General Public License version 2. This program
# is licensed "as is" without any warranty of any kind, whether express
# or implied.

if [ ! -f /sys/dpm/control ]
then
   echo "$0: DPM sysfs filesystem not present."
   echo "May need to mount -t sysfs sysfs /sys"
   echo "or may need to enable CONFIG_DPM."
   exit
fi

echo terminate > /sys/dpm/control
echo init      > /sys/dpm/control

##
## set 'test_dpm' task
##

echo create task_dpm > /sys/dpm/op/control
echo -n 1300    > /sys/dpm/op/task_dpm/v
echo -n 16      > /sys/dpm/op/task_dpm/l
echo -n 3       > /sys/dpm/op/task_dpm/n
echo -n 1       > /sys/dpm/op/task_dpm/b
echo -n 0       > /sys/dpm/op/task_dpm/ht
echo -n 1       > /sys/dpm/op/task_dpm/a

### setting values
## clock
# run/turbo/sysbus/mem=104
#  : l=8, n= 2, a=1, b=1 ht = 0
# run/turbo/sysbus=208, mem=208
#  : l=8, n= 2, a=1, b=1 ht = 0
# run=208, turbo=312, sysbus=208, mem=208
#  : l=16, n= 3, a=1, b=1 ht = 0
# run=208, turbo=416, sysbus=208, mem=208
#  : l=16, n= 4, a=1, b=1 ht = 0
## voltage : v= 1100, 1200, 1300 ,1400 (mv) 


# sleep (standby mode)

echo create sleep > /sys/dpm/op/control
echo -n 1400      > /sys/dpm/op/sleep/v
echo -n 0         > /sys/dpm/op/sleep/l
echo -n 0         > /sys/dpm/op/sleep/n
echo -n 2         > /sys/dpm/op/sleep/sleep


##
## set 'dpm_test' policy
##
echo create dpm_test	 > /sys/dpm/policy/control 
echo -n task_dpm              > /sys/dpm/policy/dpm_test/task
echo -n task_dpm              > /sys/dpm/policy/dpm_test/task+1
echo -n task_dpm              > /sys/dpm/policy/dpm_test/task+2
echo -n task_dpm              > /sys/dpm/policy/dpm_test/task+3
echo -n task_dpm              > /sys/dpm/policy/dpm_test/task+4
echo -n task_dpm              > /sys/dpm/policy/dpm_test/task-1
echo -n task_dpm              > /sys/dpm/policy/dpm_test/task-2
echo -n task_dpm              > /sys/dpm/policy/dpm_test/task-3
echo -n task_dpm              > /sys/dpm/policy/dpm_test/task-4
echo -n task_dpm              > /sys/dpm/policy/dpm_test/idle
echo -n task_dpm              > /sys/dpm/policy/dpm_test/idle-task
echo -n sleep            > /sys/dpm/policy/dpm_test/sleep


##
## active 'dpm_test' policy
##
echo -n set dpm_test > /sys/dpm/policy/control
