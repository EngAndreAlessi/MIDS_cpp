#pragma once
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <tuple>
#include <algorithm>

// Everything is public as this is only a scientific experiment
// So I declare Graph as a struct, not a class
struct Graph 
{
	// We declare the neighborhood type as a list of ints
	typedef std::list<std::size_t> neighborhood;
	// We declare the graph type as a map of integers (vertice id) to its neighborhood
	typedef std::map<std::size_t, neighborhood> graph;

	// Graph attributes
	
	// Graph itself
	graph g;
	// Instance name
	std::string instance_name;

	// Graph functions
	
	// Constructor method, will read a .mis or .clq file and build the graph
	Graph(const std::string);
	// Prints the graph information
	void printGraphInfo();
	// Remove a vertex from the graph
	void removeVertex(const std::size_t);
	// Gets closed neighborhood of a vertex
	Graph::neighborhood ClosedNeighborhood(const std::size_t);

};



