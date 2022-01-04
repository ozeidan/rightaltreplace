# rightaltreplace

A script to replace rightalt (actually altgr on the german keyboard) + hjkl presses with the corresponding arrow keys, to enable system wide navigation of programs in a vim-like manner. Can be easily adjusted for other modifier keys, though it will prevent the functioning of that specific modifier key.

This is a plugin for, and to be used with, [Interception Tools](https://gitlab.com/interception/linux/tools)

## building

    $ cmake -B build -DCMAKE_BUILD_TYPE=Release
    $ cmake --build build
    $ mv build/rightaltreplace /usr/bin
