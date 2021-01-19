// lese datei nur einmal pro kompilieren ein
#pragma once

#include <vector> //https://en.cppreference.com/w/cpp/container/vector
#include <eigen/eigen.h>
typedef std::vector<double> vector_t;


//welche funktionen aus lhc-generator.cc werden exported und somit für die gelinkten
//dateien verfügbar gemacht
//vector_t RandomNVector(int n);
//void Shuffle(vector_t *x);
int LhcDataPrinter(char *argv[], int argc);
