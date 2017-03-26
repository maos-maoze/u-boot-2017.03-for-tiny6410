#!/bin/bash

make V=1 CROSS_COMPILE=arm-linux- ARCH=arm 2>&1 | tee mylog.log
