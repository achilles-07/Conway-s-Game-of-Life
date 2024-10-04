#ifndef GRID_H_
#define GRID_H_

#include <string>
#include <vector>
#include <cstdlib>

#include "cell.h"

class grid {
    // We have a border of inactive cells.
    // These are used for calculation of  next gen but not displayed
    cell cells[rowmax + 2][colmax + 2];
public:
    // Create a cell at (row, col)
    void create(int row, int col);

    // Draw all the cells
    void draw();

    // Populate the grid with cells, at random
    void randomize();

    // Will the cell at (row, col) survive to the next gen
    bool will_survive(int row, int col);

    // Will the cell be born at (row, col) in the next gen
    bool will_create(int row, int col);

    // Update the grid to next gen
    void update(const grid& next);
};

// Non-member funciton
// Calculate which cells survive to the next generation and which are born
void calculate(grid& old_generation, grid& new_generation);

#endif // GRID_H_