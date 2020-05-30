#!/bin/bash
cp config.def.h config.h
make
if [ $? -eq 0 ]; then
    rm ~/bin/dwm
    cp dwm ~/bin
fi

