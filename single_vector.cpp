#include "single_vector.h"
#include <cmath>

SingleVector::SingleVector(vector<double> vals) : values(move(vals)) {}

double SingleVector::magnitude() const {
    double sum = 0.0;
    for (double val : values) {
        sum += val * val;
    }
    return sqrt(sum);
}

ostream& operator<<(ostream& os, const SingleVector& vec) {
    os << "ID: "<< vec.id<< " (";
    for (size_t i = 0; i < vec.values.size(); ++i) {
        os << vec.values[i];
        if (i < vec.values.size() - 1) os << ", ";
    }
    os << ")";
    os << " with magnitute: "<<vec.magnitude();
    return os;
}
