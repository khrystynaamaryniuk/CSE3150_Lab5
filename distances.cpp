#include "distances.h"
#include <cmath>

double cosine_similarity(const SingleVector& v1, const SingleVector& v2) {
    if (v1.magnitude() == 0.0 || v2.magnitude() == 0.0) {
        throw std::invalid_argument("Cannot compute cosine similarity for zero magnitude vector.");
    }
    double dot_product = 0.0;
    for (size_t i = 0; i < v1.values.size(); i++) {
        dot_product += v1.values[i] * v2.values[i];
    }
    double x= dot_product / (v1.magnitude() * v2.magnitude());
    return acos(x);
}

bool compare_pairs(const VectorPair& v1, const VectorPair& v2) {
    return v1.alpha < v2.alpha;
}