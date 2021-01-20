// lese datei nur einmal pro kompilieren ein
#pragma once

//#include <vector> //https://en.cppreference.com/w/cpp/container/vector

#include <Eigen/Eigen>

// typedef std::vector<double> vector_t;

// welche funktionen aus lhc-generator.cc werden exported und somit für die
// gelinkten dateien verfügbar gemacht vector_t RandomNVector(int n); void
// Shuffle(vector_t *x);
Eigen::MatrixXd LhcDataGenerator(size_t number_of_points,
                                 size_t number_of_dimensions);
double LhcMinDistance(const Eigen::MatrixXd &X);
