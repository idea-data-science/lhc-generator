//TEST() arguments go from general to specific. The first argument is the name of the test suite, and the second argument is the test's name within the test suite.

#include <vector>
#include <gtest/gtest.h>

#include "absl/random/random.h"
#include "absl/strings/numbers.h"
#include "fmt/core.h"
#include "lhc-generator.cc"
#include "tests.cc"


}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  std::cout << RUN_ALL_TESTS();
  fmt::print("\n");
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
