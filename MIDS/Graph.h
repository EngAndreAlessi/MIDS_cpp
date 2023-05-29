#pragma once
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <limits>

// Everything is public as this is only a scientific experiment
// So I declare Graph as a struct, not a class
struct Graph 
{
	// We define the adjacency list type as a vector of lists of int
	typedef std::vector<std::list<int>> AdjList;

	// Graph attributes
	
	// Adjacency list
	AdjList adj_list;
	// Number of vertices
	int n;
	// Number of edges
	int m;
	// Instance name
	std::string instance_name;
	// Maximum vertex degree
	int max_degree;
	// Minimum vertex degree
	int min_degree;

	// Graph methods
	
	// Constructor method, will read a .mis or .clq file and build the graph
	Graph(const std::string);
	// Calculates the maximum and minimum vertex degree of the graph
	void calculate_max_min_degree();
	// Prints the graph information
	void printGraphInfo();
	// Remove a vertex from the graph
	void removeVertex(const int);

};
