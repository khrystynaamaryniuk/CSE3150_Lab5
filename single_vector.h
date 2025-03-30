#ifndef SINGLE_VECTOR_H
#define SINGLE_VECTOR_H

#include <vector>
#include <iostream>

using namespace std;

class SingleVector {
public:
    vector<double> values;
    int id;
    SingleVector(vector<double> vals);
    double magnitude() const;
    friend ostream& operator<<(ostream& os, const SingleVector& vec);
};

#endif // SINGLE_VECTOR_H
