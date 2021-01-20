
// benutzt wurde dann std::vector<int> v; aber wäre das notwendig gewesen?
// bzw ist alles der std library automatisch verfügbar und wenn ja warum musste
// man hier vector extra includen?
#include "lhc-generator.h"

//#include "fmt/core.h" //https://github.com/fmtlib/fmt (in and out streaming)
#include "absl/random/random.h" //https://abseil.io/docs/cpp/guides/random

#include <cmath>
#include <limits>
// typedef std::vector<double> vector_t; reicht im header
// using vector_t = std::vector<double>;

static absl::BitGen bitgen; // get random seed "bitgen" static-> wird nur in
                            // dieser datei genutzt

static Eigen::VectorXd RandomNVector(int n) {
  Eigen::VectorXd x(n);                // vector der länge n mit daten typ double
  for (int i = 0; i < n; ++i) { // schleife über vector länge
    x[i] = absl::Uniform(bitgen, i * 1.0 / n, (i + 1) * 1.0 / n); //
  }
  return x;
}

static void Shuffle(Eigen::VectorXd *x) {
  double *xx = x->data(); // äquvivalent zu (*x).data()
  for (size_t i = x->size() - 1; i > 0; --i) {
    size_t j = absl::Uniform<size_t>(bitgen, 0, i);
    std::swap(xx[i], xx[j]);
  }
}







Eigen::MatrixXd LhcDataGenerator(size_t number_of_points, size_t number_of_dimensions) {

  //std::vector<vector_t> X; // ein vektor aus vektoren -> matrix
  Eigen::MatrixXd X(number_of_points,number_of_dimensions);
  for (size_t d = 0; d < number_of_dimensions; ++d) {
    Eigen::VectorXd x = RandomNVector(number_of_points);
    if (d > 0) {
      Shuffle(&x);
    }
    X.col(d) = x; // https://www.cplusplus.com/reference/vector/vector/push_back/
  }

  return X;
}

//Übergebe constante reference kein speicher wird kopiert
//variable kann nicht verändert werden aber es ist ein in jedem fall gültiges objekt (Kein nullpointer)
double LhcMinDistance(const Eigen::MatrixXd &X){
    size_t rows = X.rows();
    size_t cols = X.cols();
    double best_min = std::numeric_limits<double>::max();
    for(size_t n = 0; n < (rows-1); n++){
      auto pt = X.row(n);
      double min;
      min = (X.block(n+1,0,rows-(n+1),cols).rowwise() - pt).rowwise().squaredNorm().minCoeff();
      if(min < best_min) {
        best_min = min;
      }
    }
  return std::sqrt(best_min);
}
