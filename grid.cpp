#include "grid.h"

void grid::create(int row, int col)
{
	cells[row][col].create();
}

void grid::draw()
{
	std::cout << "\x1b[2"; // return to home position

	for (int row = 0; row < rowmax; row++) {
		for (int col = 0; col < colmax; col++) {
			cells[row][col].draw(row, col);
		}
	}
}

void grid::randomize()
{
	const int factor = 5; // Prob = 1/5 or 20%
	const int cutoff = RAND_MAX / factor;
	// time_t now;
	// time(&now);
	// srand(now);

	for (int row = 1; row < rowmax; row++) {
		for (int col = 1; col < colmax; col++) {
			if (rand() / cutoff == 0)
				create(row, col);
		}
	}
}

bool grid::will_survive(int row, int col)
{
	if(!cells[row][col].is_alive())
		return false;

	int neighbours  =	cells[row - 1][col - 1].is_alive() +
						cells[row - 1][col].is_alive() +
						cells[row - 1][col + 1].is_alive() +
						cells[row][col - 1].is_alive() +
						cells[row][col + 1].is_alive() +
						cells[row + 1][col - 1].is_alive() +
						cells[row + 1][col].is_alive() +
						cells[row + 1][col + 1].is_alive();

	if (neighbours < min_neighbours or neighbours > max_neighbours)
		return false;

	return true;

}

bool grid::will_create(int row, int col)
{
	if (!cells[row][col].is_alive())
		return false;

	int neighbours = cells[row - 1][col - 1].is_alive() +
		cells[row - 1][col].is_alive() +
		cells[row - 1][col + 1].is_alive() +
		cells[row][col - 1].is_alive() +
		cells[row][col + 1].is_alive() +
		cells[row + 1][col - 1].is_alive() +
		cells[row + 1][col].is_alive() +
		cells[row + 1][col + 1].is_alive();

	if (neighbours < min_parents or neighbours > max_parents)
		return false;

	return true;
}

void grid::update(const grid& next)
{
	for (int row = 1; row < rowmax; row++) {
		for (int col = 1; col < colmax; col++) {
			cells[row][col] = next.cells[row][col];
		}
	}
}

void calculate(grid& old_generation, grid& new_generation)
{
	// By default, all cells in the next gen are initially unpopulated
	// Calculate which cells survive to next gen
	// Carry forward unpopulated ones

	for (int row = 1; row < rowmax; row++) {
		for (int col = 1; col < colmax; col++) {
			if (old_generation.will_survive(row, col))
				new_generation.create(row, col);
			else if (old_generation.will_create(row, col)) {
				new_generation.create(row, col);
			}
		}
	}
}
