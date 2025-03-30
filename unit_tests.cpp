#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "single_vector.h"
#include "distances.h"
#include "file_reader.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

TEST_CASE("Testing SingleVector::magnitude") {
    // Test case 1: Magnitude of a vector with all zeros
    SingleVector v1({0, 0, 0});
    CHECK(v1.magnitude() == 0);

    // Test case 2: Magnitude of a vector with non-zero values
    SingleVector v2({3.0, 4.0});
    CHECK(v2.magnitude() == 5.0);  // sqrt(3^2 + 4^2) = 5

    // Test case 3: Magnitude of a vector with negative values
    SingleVector v3({-3.0, 4.0});
    CHECK(v3.magnitude() == 5.0);  // sqrt((-3)^2 + 4^2) = 5
}

TEST_CASE("Testing cosine_similarity") {
    // Test case 1: Valid vectors
    SingleVector v1({1.0, 0.0});
    SingleVector v2({0.0, 1.0});
    CHECK(cosine_similarity(v1, v2) == M_PI_2);  // 90 degrees (cos(90) = 0)


    // Test case 3: Vectors with zero magnitude (should throw exception)
    SingleVector v5({0.0, 0.0});
    SingleVector v6({1.0, 1.0});
    CHECK_THROWS_AS(cosine_similarity(v5, v6), std::invalid_argument);  // Expecting an exception due to zero vector

    // Test case 4: Vectors that are orthogonal (cosine similarity = 0)
    SingleVector v7({1.0, 0.0, 0.0});
    SingleVector v8({0.0, 1.0, 0.0});
    CHECK(cosine_similarity(v7, v8) == M_PI_2); 
 

}

TEST_CASE("Testing read_vectors_from_file") {
    // Creating a temporary file for testing
    std::ofstream out("test_vectors.txt");
    out << "1 2 3\n4 5 6\n7 8 9\n";
    out.close();

    // Test case 1: Read vectors from a file
    std::vector<SingleVector> vectors = read_vectors_from_file("test_vectors.txt");

    CHECK(vectors.size() == 3);  // Should read 3 vectors

    // Test case 2: Check the values of the first vector
    CHECK(vectors[0].values[0] == 1);
    CHECK(vectors[0].values[1] == 2);
    CHECK(vectors[0].values[2] == 3);

    // Test case 3: Check the values of the second vector
    CHECK(vectors[1].values[0] == 4);
    CHECK(vectors[1].values[1] == 5);
    CHECK(vectors[1].values[2] == 6);

    // Test case 4: Check the values of the third vector
    CHECK(vectors[2].values[0] == 7);
    CHECK(vectors[2].values[1] == 8);
    CHECK(vectors[2].values[2] == 9);

    // Clean up
    std::remove("test_vectors.txt");
}

TEST_CASE("Testing edge cases for cosine similarity") {
    // Zero vector and non-zero vector
    SingleVector zeroVec({0, 0, 0});
    SingleVector nonZeroVec({1, 2, 3});
    
    CHECK_THROWS_AS(cosine_similarity(zeroVec, nonZeroVec), std::invalid_argument);
}