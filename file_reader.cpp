#include "file_reader.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

vector<SingleVector> read_vectors_from_file(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Cannot open file " << filename << "\n";
        return {};
    }

    vector<SingleVector> vectors;
    string line;
    int id =0;
    while (getline(file, line)) {
        istringstream iss(line);
        vector<double> vals;
        double num;
        while (iss >> num) {
            vals.push_back(num);
        }
        
        if (!vals.empty()) {
            SingleVector vec(vals);
            vec.id = id++;  // Assign unique ID
            vectors.push_back(vec);
        };
    }

    file.close();
    return vectors;
}
