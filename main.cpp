/*

Programming Logic : 
-----------------------
-> Create a grid object to represent current generation.
-> Populate its cells at random.
-> Display the current generation grid.
-> Create another grid object to display the next generation.
-> Calculate the cell states for the next generation and populate the grid.
-> Copy the next generation grid over the curr gen grid.
-> Repeat.

*/

#include "grid.h"

// For windows only
// #include "ansi_escapes.h"

int main(int argc, char *argv[]) {
    std::cout << "Conway's Game of Life\n";
    std::cout << "Press the return key to display each generation\n";

    // Enable ANSI escape codes on Windows
    // setupConsole();

    // Wait for user to press the return key
    std::cin.get();

    // Grid for the first generation
    grid current_generation;

    // Populate the cells at random
    current_generation.randomize();

    while(true) {
        // Draw the current generation
        current_generation.draw();

        // Wait for user to press the return key
        std::cin.get();

        // Grid for the next generation
        grid next_generation;

        // Populate the cells in the next generation
        calculate(current_generation, next_generation);

        // Update to the next generation
        current_generation.update(next_generation);
    }

    // Move cursor to bottom of screen
    std::cout << "\x1b[" << 0 << ";" << rowmax - 1 << "H";

    //Windows Console Only
    // restoreConsole();
}