#include <iostream>
#include <vector>
#include <cmath>
#include "distances.h"
#include "single_vector.h"
#include "file_reader.h"
#include <algorithm>

using namespace std;

int main() {
    vector<SingleVector> vectors = read_vectors_from_file("vectors.txt");
    for (auto t: vectors){
        cout<<t<<endl;
    }
    // Create vector pairs
    vector<VectorPair> pairs;
    for (size_t i = 0; i < vectors.size(); ++i) {
        for (size_t j = i + 1; j < vectors.size(); ++j) {
            double cos_dist = cosine_similarity(vectors[i], vectors[j]);
            pairs.push_back(VectorPair(vectors[i], vectors[j], cos_dist)); // Correct initialization
        }
    }
   


    // Sort pairs by cosine similarity (alpha)
    sort(pairs.begin(), pairs.end(), compare_pairs);

    // Print the sorted pairs with IDs and cosine distances
    for (const auto& pair : pairs) {
        cout << "(" << pair.v1.id << ", " << pair.v2.id << ") cos dist = " 
            << pair.alpha << endl;  // Use the cosine distance (pair.alpha) correctly
    }


    return 0;
}
