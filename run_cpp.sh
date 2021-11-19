#!/bin/bash

_CMD_GPLUSPLUS=`which g++`;

$_CMD_GPLUSPLUS $1 -o task && ./task && rm task