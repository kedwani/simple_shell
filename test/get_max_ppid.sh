#!/bin/bash

max_pid=$(cat /proc/sys/kernel/pid_max)

echo "The maximum PID value on this system is: $max_pid"
