#ifndef FILE_READER_H
#define FILE_READER_H

#include "single_vector.h"
#include <vector>
#include <string>
using namespace std;
vector<SingleVector> read_vectors_from_file(const string& filename);

#endif // FILE_READER_H
