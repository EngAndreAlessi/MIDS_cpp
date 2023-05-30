#include "Graph.h"

Graph::Graph(const std::string path)
{
	std::ifstream file;
	file.open(path);
	if (file.is_open())
	{
		// path is in the format "Dataset/Dataset_name/instance_name.file_type"
		// will find the last "/" and split the string path, getting instance_name.file_type
		// then, whill find the delimiter "." and split again, getting instance_name
		std::string auxiliar_string = "";
		std::size_t start = path.find_last_of("/") + 1;
		std::size_t end = path.size();
		auxiliar_string = path.substr(start, end);
		start = 0;
		end = auxiliar_string.find(".");
		this->instance_name = auxiliar_string.substr(start, end);
		std::size_t n, m; // Variables to store number of vertices and edges from file
		if (path.find(".mis") != std::string::npos) // If file is of type .mis
		{
			// First line of the .mis file has number of edges and number of vertices
			file >> m >> n;
			int w; // Variable to receive the vertices weight
			std::size_t i; // Counter
			for (i = 0; i < n; i += 1)
			{
				// The next line of the .mis file has the node weights as 1
				// As we don't work with node weights, we just
				// read them and do nothing
				file >> w;
			}

			// The next m lines have the edges (u,v)
			std::size_t u, v;
			for (i = 0; i < m; i += 1)
			{
				file >> u >> v;
				this->g[i].push_back(v);
			}

		}
		else if (path.find(".clq") != std::string::npos) // If file is of type .clq
		{
			// First line of the .clq file has the format
			// p edge #vertices #edges
			char input_char;
			char input_edge[5];
			std::cin >> input_char >> input_edge >> n >> m;
			// The next m lines have the format
			// e u v
			// where e is a char (will read to variable input_char)
			// (u,v) is an edge
			std::size_t i, u, v;
			for (i = 0; i < m; i += 1)
			{
				std::cin >> input_char >> u >> v;
				this->g[v].push_back(v);
			}
		}
		file.close();
	}
	else
	{
		std::cout << "Error in opening path " << path << std::endl;
	}
	
}

void Graph::printGraphInfo()
{
	std::cout << "Instance name: " << this->instance_name << std::endl;
	Graph::graph::iterator Iter;
	for (Iter = this->g.begin(); Iter != this->g.end(); Iter++)
	{
		std::cout << Iter->first << "->";
		for (int i : Iter->second)
		{
			std::cout << i << "->";
		}
		std::cout << "NULL" << std::endl;
	}
}

void Graph::removeVertex(const int v)
{
	this->g.erase(v);
	Graph::graph::iterator Iter;
	for (Iter = this->g.begin(); Iter != this->g.end(); Iter++)
	{
		Iter->second.remove(v);
	}
}

inline Graph::neighborhood Graph::ClosedNeighborhood(const int v)
{
	return this->g.at(v);
}
