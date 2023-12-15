# README
---

![GitHub tag (with filter)](https://img.shields.io/github/v/tag/onsokumaru/daemon_prototyping?logo=github&logoColor=white)
![GitHub Workflow Status (with event)](https://img.shields.io/github/actions/workflow/status/onsokumaru/daemon_prototyping/cmake-single-platform.yml)



## How to build the programs 

- create a directory called *build*

        mkdir build

- call CMake to build the programs in the *build* directory

        cmake --build build


## How to run the programs

- from the root directory use:

        ./build/<program to run>

  example:

        ./build/create_pidfile


- from the *build* directory use:

        ./<program to run>

  example:

        ./create_pidfile
