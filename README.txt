BigInt is a repo for evaluating mathematical operations on big integers 

To use BigInt in your code

1. Clone github repo via  

git clone https://github.com/DavidSahakyan/BigInt

command in your terminal.

2. Add 

target_link_libraries(%YOUR PROJECT NAME% PUBLIC Bigint)
target_include_directories(%YOUR PROJECT NAME% PUBLIC src/Bigint/include/Bigint)

To your CmakeLists.txt

-----------------------------------------------------------------------------------

To test BigInt library 

1. UBUNTU
Run

 sudo apt install libgtest-dev
 mkdir build 
 cd build
 cmake ..
 make
 ctest

in your terminal.

2. On Windows
Install vcpkg
Install gtest via vcpkg

Run

 vcpkg install gtest

in your terminal.

Configure for vcpkg running

 cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=<path-to-vcpkg>/scripts/buildsystems/vcpkg.cmake
 cmake --build build
 ctest

in your terminal