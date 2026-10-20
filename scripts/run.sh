#!/bin/bash

if [ "$1" = "release" ]
then
    ./build/release/hero
else
    ./build/debug/hero
fi