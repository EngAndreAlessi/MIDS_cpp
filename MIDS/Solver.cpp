#include "Solver.h"
#include <limits>

Solver::Solver()
{
    // Setting the best_objective_function attribute as the highest
    // size_t possible as we will try to minimize it
    this->best_objective_function = std::numeric_limits<std::size_t>::max();
}

//void Solver::Greedy(Graph * graph, const int method)
//{
//    if (method == 1) // Greedy function == vertex degree
//    {
//        Solver::solution current_solution;
//        int chosen_vertex = 
//    }
//    else
//    {
//        std::cout << "Method invalid" << std::endl;
//    }
//}

inline std::size_t Solver::objective_function(const Solver::solution s)
{
    return s.size();
}
