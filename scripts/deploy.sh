#!/bin/bash

sh scripts/build.sh release 

rm -rf -d hro

mkdir hro

cp bin/release/hro hro
cp -r res hro

echo "Deploy build created."
echo "cd hro to find it"