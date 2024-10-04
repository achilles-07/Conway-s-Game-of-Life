# Conway's Game of Life

- C++ doesn't have a standard Graphics Lib.
    - We are proceeding with text mode for implementation.

- Complete implementation requires an infinite grid.
    - We have limited memory, we need to restrict the grid size.
    - We will have a border of cells which are always unpopulated.
    - If any bordered becomes populated, ignore it.


# Implementation

- 2D array for representing Grid.
- Elements of array = Cell class.
- Game will be played in 80x24 terminal, text mode.
- "ANSI escape codes" to display cells on the terminal.


# ANSI escape codes

- ANSI defined a set of commands for controlling terminals.
- Programs can use these commands to change the way o/p is displayed.
- These begin with '0x1b['. {1b = hexadecimal for escape in ASCII}
- Move cursor to row n, col m => 0x1b[n;mH
- Clear screen and return cursor to home position(top left) => 0x1b[2J.


# ANSI Escape Code Support

- Our program needs to run in an env that emulates an ANSI terminal.
- Supported by OSX, Linux, Unix command Lines.
    - May need to set the "TERM" env variable.
- Windows
    - MinGW and Cygwin
    - \>= PowerShell 5.1
    - 3rd party : ANSICON, Cmder, ConEmu
    - Windows console in Win 10, but requires extra code.

