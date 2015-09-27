# SLIM3D

## Compilation

### Windows

You can use cmake to generate Visual Studio solution file by two ways: command line or cmake-gui.

By command line, just open a shell terminal (like git-bash), move to the SLIM3D folder, and run the following commands:

    mkdir build
    cd build
    cmake ..

You shall find in the `build` folder created a file `SLIM3D.sln`, wich is the solution file to load with Visual studio.

An alternative way is to create a directory `build`, open *cmake-gui* and fill the following fields:

 - Where is the source code:	`C:\your\path\to\slim\folder\SLIM3D`
 - Where to build the binaries:	`C:\your\path\to\slim\folder\SLIM3D\build`

### Linux

A script `build.sh` is provided. On Linux plateform, just run it and it shall create you two folders:

    build/debug
    build/release

The first one is empty. For now. Move to one of two others and run the following:

    make

You'll have your library waiting in the `~/lib` folder and your binary samples in `~/bin` folder at the project root.  
You can try to execute binaries in `~/bin` from wherever you want.

Once you compiled everything, you can install it from `build/debug` or `build/release` directory with the following command:

    sudo make install
