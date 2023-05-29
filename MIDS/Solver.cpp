#include "Solver.h"

inline int Solver::objective_function(const solution s)
{
    return (int)s.size();
}
