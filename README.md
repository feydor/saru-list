# libsaru-list
A simple C library containing list data structures:
* A generic doubly linked list

This library is part of the "saru-" family of C libraries written in order to provide well-tested data structures for use in my own projects. Each library is built using the Meson build system for easy dependency managment, with an emphasis on simplicity and modularity.

## Usage
Create a saru-list.wrap file in the subprojects directory of your project and paste the following into it.
```
[wrap-git]
directory = saru-list.git
url = https://github.com/feydor/saru-list
revision = master
```

## Development
Build, compile, and run the tests using:
```sh
meson build
ninja -C build
meson test -C build
```
