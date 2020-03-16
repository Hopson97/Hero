#!/bin/bash

if [ "$1" = "release" ]
then
    ./bin/release/hero 
else
    ./bin/debug/hero 
fi