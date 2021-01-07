#include <vector>

#include "absl/random/random.h"
#include "absl/strings/numbers.h"
#include "fmt/core.h"

char *x; // Pointer auf einen char mit Namen x.

typedef std::vector<double> vector_t;
// using vector_t = std::vector<double>;

absl::BitGen bitgen;

vector_t RandomNVector(int n) {
  vector_t x(n);
  for (int i = 0; i < n; ++i) {
    x[i] = absl::Uniform(bitgen, i * 1.0 / n, (i + 1) * 1.0 / n);
  }
  return x;
}

void Shuffle(vector_t *x) {
  double *xx = x->data();
  for (size_t i = x->size() - 1; i > 0; --i) {
    size_t j = absl::Uniform<size_t>(bitgen, 0, i);
    std::swap(xx[i], xx[j]);
  }
}

int main(int argc, char *argv[]) {
  size_t number_of_points, number_of_dimensions;
  if (argc != 3) {
    fmt::print(
        "Usage: {} <n> <d>\n n - Number of points\n d - Number of dimensions\n",
        argv[0]);
    return 1;
  }

  if (!absl::SimpleAtoi(argv[1], &number_of_points)) {
    fmt::print("Du Du Du! Keine gültige Zahl als erstes Argument.\n");
    return 1;
  }
  if (!absl::SimpleAtoi(argv[2], &number_of_dimensions)) {
    fmt::print("Pöser Pube!\n");
    return 1;
  }

  std::vector<vector_t> X;
  for (size_t d = 0; d < number_of_dimensions; ++d) {
    auto x = RandomNVector(number_of_points);
    if (d > 0) {
      Shuffle(&x);
    }
    X.push_back(x);
  }

  for (size_t n = 0; n < number_of_points; ++n) {
    for (size_t d = 0; d < number_of_dimensions; ++d) {
      fmt::print("{} ", X[d][n]);
    }
    fmt::print("\n");
  }

  return 0;
}
