# Basic bootstrap kit
This is a very basic bootstrap kit for C/C++ build environments.

Example using CMake for standalone application, shared library (.so), static library (.a), and app using a library are provided as examples.  For the app using a library, the library needs to be built first.

Use CMakeLists.txt to customize the build environment.

## Execute a build:
    mkdir build && cd build
    cmake ..
    make


Other than the normal "make clean", the project can be cleaned by simply removing the contents in the build directory:
    cd <root directory of project>
    rm -r build/*


If new files are added, cmake needs to be run again to update the Makefiles accordingly.


