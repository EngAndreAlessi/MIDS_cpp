#pragma once
#include <list>

// Everything is public as this is only a scientific experiment
// So I declare Graph as a struct, not a class
struct Solver
{
	// We will define a type solution as a list of ints
	typedef std::list<int> solution;
	// Solver attributes
	solution best_solution;
	int best_objective_function;

	// Solver methods
	// Greedy
	// GRASP (reactive ?)
	int objective_function(const solution);
};

