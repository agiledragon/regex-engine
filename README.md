# RegexEngine

## Introduction
Implemented a simple regular expression engine in c++11 based on specific semantic rules, without using the regular expression library of c++ language.

## Configuration
Build and test regex-engine needs gcc, cmake and gtest:
+ Make sure GCC version is 48 or above
+ Make sure cmake version is 2.8 or above
+ Add 'GTEST_HOME' to your environment variable
+ Make sure 'GTEST_HOME' include the folder 'gtest/include' and 'lib/libgtest.a'


## Build and Test

```cpp
$git clone https://github.com/agiledragon/regex-engine
cd regex-engine
mkdir build
cd build
cmake ..
make
./regex-engine-test
```







