#pragma once
#include "Graph.h"
#include <map>

// Everything is public as this is only a scientific experiment
// So I declare Graph as a struct, not a class
struct Solver
{
	// We will define a type solution as a list of ints
	typedef std::list<int> solution;
	// Solver attributes
	solution best_solution;
	std::size_t best_objective_function;
	
	// Solver functions
	
	// Solver Constructor
	Solver();
	// Finds a MIDS solution using a greedy approach
	// Second argument is an integer corresponding to the greedy function
	// 1 - Vertex degree
	void Greedy(Graph *, const int);
	// GRASP (reactive ?)
	std::size_t objective_function(const Solver::solution);
};

