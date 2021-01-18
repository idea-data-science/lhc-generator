// TEST() arguments go from general to specific. The first argument is the name
// of the test suite, and the second argument is the test's name within the test
// suite.

// https://en.cppreference.com/w/cpp/container/vector
// benutzt wurde dann std::vector<int> v; aber wäre das notwendig gewesen?
// bzw ist alles der std library automatisch verfügbar und wenn ja warum musste
// man hier vector extra includen?

//#include <gtest/gtest.h> //https://github.com/google/googletest/blob/master/googletest/docs/primer.md

//#include "absl/strings/numbers.h" //https://abseil.io/docs/cpp/guides/format
//#include "fmt/core.h" //https://github.com/fmtlib/fmt (in and out streaming)

#include "lhc-generator.h"

int main(int argc, char *argv[]) {

  LhcDataPrinter(argv, argc);

  return 0;
}
