TEST(RandomNVector, IncreasingValuesInVector) {
  auto x = RandomNVector(100);
  for (size_t i = 0; i < x.size()-1; ++i) {
    ASSERT_LT(x[i], x[i+1]) << "Vector values do not increase continuously ";
}
