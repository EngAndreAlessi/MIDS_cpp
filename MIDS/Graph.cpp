#include "Graph.h"

Graph::Graph(const std::string path)
{
	// path is in the format "Dataset/Dataset_name/instance_name.file_type"
	// will find the last "/" and split the string path, getting instance_name.file_type
	// then, whill find the delimiter "." and split again, getting instance_name
	std::string auxiliar_string = "";
	std::size_t start = path.find_last_of("/")+1;
	std::size_t end = path.size();
	auxiliar_string = path.substr(start, end);
	start = 0;
	end = auxiliar_string.find(".");
	this->instance_name = auxiliar_string.substr(start, end);
	std::ifstream file;
	file.open(path);
	if (file.is_open())
	{
		if (path.find(".mis") != std::string::npos) // If file is of type .mis
		{
			// First line of the .mis file has number of edges and number of vertices
			file >> this->m >> this->n;
			// We will resize the adj_list to the number of vertices
			this->adj_list.resize(this->n);
			int w; // Variable to receive the vertices weight
			std::size_t i; // Counter
			for (i = 0; i < this->n; i += 1)
			{
				// The next line of the .mis file has the node weights as 1
				// As we don't work with node weights, we just
				// read them and do nothing
				file >> w;
				// We will add the own vertex to the list of each position
				this->adj_list[i].push_back(i + 1);
			}

			// The next m lines have the edges (u,v)
			std::size_t u, v;
			for (i = 0; i < this->m; i += 1)
			{
				// In the file, first vertex = 1
				// In the data structure, first vertex = 0
				file >> u >> v;
				this->adj_list[u - 1].push_back(v);
				this->adj_list[v - 1].push_back(u);
			}

		}
		else if (path.find(".clq") != std::string::npos) // If file is of type .clq
		{
			// First line of the .clq file has the format
			// p edge #vertices #edges
			char input_char;
			char input_edge[5];
			std::cin >> input_char >> input_edge >> this->n >> this->m;
			// We will resize the adj_list to the number of vertices
			this->adj_list.resize(this->n);
			// We will add the own vertex to the list of each position
			std::size_t i; // Counter
			for (i = 0; i < this->n; i += 1)
			{
				this->adj_list[i].push_back(i + 1);
			}
			// The next m lines have the format
			// e u v
			// where e is a char (will read to variable input_char)
			// (u,v) is an edge
			std::size_t u, v;
			for (i = 0; i < this->m; i += 1)
			{
				// In the file, first vertex = 1
				// In the data structure, first vertex = 0
				std::cin >> input_char >> u >> v;
				this->adj_list[u - 1].push_back(v);
				this->adj_list[v - 1].push_back(u);
			}
		}
		calculate_max_min_degree();
		file.close();
	}
	else
	{
		this->n = 0;
		this->m = 0;
		this->max_degree = 0;
		this->min_degree = 0;
		std::cout << "Error in opening path " << path << std::endl;
	}
	
}

void Graph::calculate_max_min_degree()
{
	// Minimum degree starts as the highest int possible
	this->min_degree = std::numeric_limits<int>::max();
	// Maximum degree starts as zero, as it can't be lower than this
	this->max_degree = 0;
	std::size_t i; // Counter
	std::size_t deg; // Current degree
	for (i = 0; i < this->n; i += 1)
	{
		deg = this->adj_list[i].size() - 1;
		if (deg > this->max_degree)
		{
			this->max_degree = deg;
		}
		if (deg < this->min_degree)
		{
			this->min_degree = deg;
		}
	}
}

void Graph::printGraphInfo()
{
	std::cout << "Instance name: " << this->instance_name << std::endl;
	std::cout << "Number of vertices: " << this->n << std::endl;
	std::cout << "Number of edges: " << this->m << std::endl;
	std::cout << "Maximum degree: " << this->max_degree << std::endl;
	std::cout << "Minimum degree: " << this->min_degree << std::endl;
	std::size_t i; // Node counter
	for (i = 0; i < this->n; i += 1)
	{
		// Print the lists
		for (std::size_t v : this->adj_list[i])
		{
			std::cout << v << "->";
		}
		std::cout << "NULL" << std::endl;
	}
}

std::size_t Graph::getMaxDegreeVertex()
{
	std::size_t i = 0; // Counter
	while (this->adj_list[i].size() - 1 != this->max_degree)
	{
		i += 1;
	}
	return this->adj_list[i].front();
}

void Graph::removeVertex(const int v)
{
	// First we will remove all edges of that vertex
	int i = 0; // Counter
	for (i = 0; i < this->n; i += 1)
	{
		if (this->adj_list[i].front() != v)
		{
			this->adj_list[i].remove(v);
			this->m -= 1;
		}
	}
	// Now we will remove the vertex itself
	// We will create an AdjList iterator and make it find the vertex
	Graph::AdjList::iterator Iter = this->adj_list.begin();
	i = 0; // Counter reset
	while (this->adj_list[i].front() != v)
	{
		i += 1;
		Iter += 1;
	}
	// Now removing the vertex
	this->adj_list.erase(Iter);
	// Reducing the number of nodes by one
	this->n -= 1;
	// Recalculates the max and min degrees
	calculate_max_min_degree();
}