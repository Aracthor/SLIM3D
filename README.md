# SLIM3D

## Compilation

A script `build.sh` is provided. On Linux plateform, just run it and it shall create you three folders:

    build/bin
    build/debug
    build/release

The first one is empty. For now. Move to one of two others and run the following:

    make

You'll have your library waiting in the `build/bin` folder.

## Installation

Once you compiled everything, you can install it from `build/debug` or `build/release` directory with the following command:

    sudo make install
