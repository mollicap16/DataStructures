#include <iostream>
#include <gtest/gtest.h>
#include <graph.h>
#include <functional>

TEST(GraphTest, UnweightedGraphTest){
  std::cout << "Unweighted Graph Shortest Path Test" << std::endl;
  // Create Graph then Test shortest path algorithm
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
