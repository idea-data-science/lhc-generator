char *x; // Pointer auf einen char mit Namen x.

typedef std::vector<double> vector_t;
// using vector_t = std::vector<double>;

absl::BitGen bitgen; //get random seed "bitgen"

vector_t RandomNVector(int n) {
  vector_t x(n);
  for (int i = 0; i < n; ++i) {
    x[i] = absl::Uniform(bitgen, i * 1.0 / n, (i + 1) * 1.0 / n);
  }
  return x;
}

void Shuffle(vector_t *x) {
  double *xx = x->data(); //ist das standard mäßig bei einem vektor so?
  for (size_t i = x->size() - 1; i > 0; --i) {
    size_t j = absl::Uniform<size_t>(bitgen, 0, i);
    std::swap(xx[i], xx[j]);
  }
}
