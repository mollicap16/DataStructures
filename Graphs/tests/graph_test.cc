#include <iostream>
#include <gtest/gtest.h>
#include <graph.h>
#include <functional>

TEST(GraphTest, UnweightedGraphTest){
  // Create Graph then Test shortest path algorithm
  Graph graph;
  graph.AddEdge("V2", "V0", 1.0);
  graph.AddEdge("V0", "V1", 1.0);
  graph.AddEdge("V1", "V4", 1.0);
  graph.AddEdge("V4", "V6", 1.0);
  graph.AddEdge("V0", "V3", 1.0);
  graph.AddEdge("V1", "V3", 1.0);
  graph.AddEdge("V3", "V2", 1.0);
  graph.AddEdge("V3", "V4", 1.0);
  graph.AddEdge("V3", "V5", 1.0);
  graph.AddEdge("V3", "V6", 1.0);
  graph.AddEdge("V6", "V5", 1.0);
  graph.AddEdge("V2", "V5", 1.0);

  graph.Unweighted("V2");
  Vertex* vertex;
  vertex = graph.GetVertex("V2");
  ASSERT_EQ(vertex->distance_, 0);

  vertex = graph.GetVertex("V0");
  ASSERT_EQ(vertex->distance_, 1);

  vertex = graph.GetVertex("V5");
  ASSERT_EQ(vertex->distance_, 1);

  vertex = graph.GetVertex("V1");
  ASSERT_EQ(vertex->distance_, 2);

  vertex = graph.GetVertex("V3");
  ASSERT_EQ(vertex->distance_, 2);

  vertex = graph.GetVertex("V4");
  ASSERT_EQ(vertex->distance_, 3);

  vertex = graph.GetVertex("V6");
  ASSERT_EQ(vertex->distance_, 3);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
