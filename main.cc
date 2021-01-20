// TEST() arguments go from general to specific. The first argument is the name
// of the test suite, and the second argument is the test's name within the test
// suite.

// https://en.cppreference.com/w/cpp/container/vector
// benutzt wurde dann std::vector<int> v; aber wäre das notwendig gewesen?
// bzw ist alles der std library automatisch verfügbar und wenn ja warum musste
// man hier vector extra includen?

//#include <gtest/gtest.h>
////https://github.com/google/googletest/blob/master/googletest/docs/primer.md

#include "absl/strings/numbers.h" //https://abseil.io/docs/cpp/guides/format
#include "fmt/core.h" //https://github.com/fmtlib/fmt (in and out streaming)

#include "lhc-generator.h"

int main(int argc, char *argv[]) {

  size_t number_of_points, number_of_dimensions;

  if (argc != 3) { // wenn nicht genau 3 argumente gegeben werden dann:
    fmt::print(
        "Usage: {} <n> <d>\n n - Number of points\n d - Number of dimensions\n",
        argv[0]);
    return 1;
  }

  // Converts the given string (optionally followed or preceded by ASCII
  // whitespace) into an integer value, returning `true` if successful. The
  // string must reflect a base-10 integer whose value falls within the range of
  // the integer type (optionally preceded by a `+` or `-`). If any errors are
  // encountered, this function returns `false`, leaving `out` in an unspecified
  // state.
  // template <typename int_type>
  // ABSL_MUST_USE_RESULT bool SimpleAtoi(absl::string_view str, int_type* out);
  if (!absl::SimpleAtoi(argv[1],
                        &number_of_points)) { // Zweites Argument der Funktion
                                              // ist der Speicherort
    fmt::print("Du Du Du! Keine gültige Zahl als erstes Argument.\n");
    return 1;
  }
  if (!absl::SimpleAtoi(argv[2], &number_of_dimensions)) {
    fmt::print("Pöser Pube!\n");
    return 1;
  }

  Eigen::MatrixXd X = LhcDataGenerator(number_of_points, number_of_dimensions);

  for (size_t n = 0; n < number_of_points; ++n) {
    for (size_t d = 0; d < number_of_dimensions; ++d) {
      fmt::print("{} ", X(n, d));
    }
    fmt::print("\n");
  }
  fmt::print("Minimal Distance: {} \n", LhcMinDistance(X));
  return 0;
}
