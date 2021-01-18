
// benutzt wurde dann std::vector<int> v; aber wäre das notwendig gewesen?
// bzw ist alles der std library automatisch verfügbar und wenn ja warum musste
// man hier vector extra includen?
#include "lhc-generator.h"

#include "fmt/core.h" //https://github.com/fmtlib/fmt (in and out streaming)
#include "absl/random/random.h" //https://abseil.io/docs/cpp/guides/random

// typedef std::vector<double> vector_t; reicht im header
// using vector_t = std::vector<double>;

static absl::BitGen bitgen; // get random seed "bitgen" static-> wird nur in
                            // dieser datei genutzt

static vector_t RandomNVector(int n) {
  vector_t x(n);                // vector der länge n mit daten typ double
  for (int i = 0; i < n; ++i) { // schleife über vector länge
    x[i] = absl::Uniform(bitgen, i * 1.0 / n, (i + 1) * 1.0 / n); //
  }
  return x;
}

static void Shuffle(vector_t *x) {
  double *xx = x->data(); // ist eigenschaft der std::vector klasser
  for (size_t i = x->size() - 1; i > 0; --i) {
    size_t j = absl::Uniform<size_t>(bitgen, 0, i);
    std::swap(xx[i], xx[j]);
  }
}

int LhcDataPrinter( char *argv[], int argc) {
  /* code */


  size_t number_of_points, number_of_dimensions; // definiert zwei variablen des typs "size_t"
                            // https://en.cppreference.com/w/c/types/size_t


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

  std::vector<vector_t> X; // ein vektor aus vektoren -> matrix
  for (size_t d = 0; d < number_of_dimensions; ++d) {
    auto x = RandomNVector(number_of_points);
    if (d > 0) {
      Shuffle(&x);
    }
    X.push_back(
        x); // https://www.cplusplus.com/reference/vector/vector/push_back/
  }

  for (size_t n = 0; n < number_of_points; ++n) {
    for (size_t d = 0; d < number_of_dimensions; ++d) {
      fmt::print("{} ", X[d][n]);
    }
    fmt::print("\n");
  }
  return 0;
}
