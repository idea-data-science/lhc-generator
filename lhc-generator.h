//lese datei nur einmal pro kompilieren ein
#pragma once

#include <vector>  //https://en.cppreference.com/w/cpp/container/vector

typedef std::vector<double> vector_t;

vector_t RandomNVector(int n);
void Shuffle(vector_t *x);
