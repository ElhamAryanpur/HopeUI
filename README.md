# HopeUIC

Custom UI for [HopeServer](https://github.com/BlueElham/HopeServer) project. But C version.

## Getting Started

To start using this library, first of all:

```bash
git clone https://github.com/BlueElham/HopeUIC
cd HopeUIC
mkdir build
mkdir bin
```

make sure to have all [dependecies](#dep) installed and then:

### Windows

```batch
start build.bat
```

### Linux

```bash
bash build.sh
```

This will take care of downloading and setting up. and will produce a binary at `bin` folder that is statically linked.

## Custom Tests

The original file that will get compiled is `Test.c`. To change and use your own file for compile, change the `CMakeLists.txt` line `33` column `32` the text `Test.c` to your own file name.

## Documentation

Currently Documentation is not provided. But soon enought it'll be written as soon as an alpha release comes.

## Dep

- [GCC](https://gcc.gnu.org/)
- [CMake](https://cmake.org/download/)
