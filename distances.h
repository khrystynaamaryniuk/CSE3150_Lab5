#ifndef DISTANCES_H
#define DISTANCES_H

#include "single_vector.h"

struct VectorPair {
    SingleVector v1, v2;
    double alpha;

    VectorPair(SingleVector _v1, SingleVector _v2, double a) : v1(_v1), v2(_v2), alpha(a) {}
};

double cosine_similarity(const SingleVector& v1, const SingleVector& v2);
bool compare_pairs(const VectorPair& v1, const VectorPair& v2);

#endif // DISTANCES_H

