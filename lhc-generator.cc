
// benutzt wurde dann std::vector<int> v; aber wäre das notwendig gewesen?
// bzw ist alles der std library automatisch verfügbar und wenn ja warum musste
// man hier vector extra includen?
#include "lhc-generator.h"

#include "absl/random/random.h" //https://abseil.io/docs/cpp/guides/random

// typedef std::vector<double> vector_t; reicht im header
// using vector_t = std::vector<double>;

static absl::BitGen bitgen; // get random seed "bitgen" static-> wird nur in
                            // dieser datei genutzt

vector_t RandomNVector(int n) {
  vector_t x(n);                // vector der länge n mit daten typ double
  for (int i = 0; i < n; ++i) { // schleife über vector länge
    x[i] = absl::Uniform(bitgen, i * 1.0 / n, (i + 1) * 1.0 / n); //
  }
  return x;
}

void Shuffle(vector_t *x) {
  double *xx = x->data(); // ist eigenschaft der std::vector klasser
  for (size_t i = x->size() - 1; i > 0; --i) {
    size_t j = absl::Uniform<size_t>(bitgen, 0, i);
    std::swap(xx[i], xx[j]);
  }
}
