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

  graph.AddEdge("V4", "V7", 1.0);
  graph.Unweighted("V2");

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

  vertex = graph.GetVertex("V7");
  ASSERT_EQ(vertex->distance_, 4);
}

TEST(GraphTest, PositveWeightedGraphTest){
  // This test will test Dijkstra's algorithm for a positive-weighted graph
  Graph graph;
  graph.AddEdge("V2", "V0", 4.0);
  graph.AddEdge("V0", "V1", 2.0);
  graph.AddEdge("V1", "V4", 10.0);
  graph.AddEdge("V4", "V6", 6.0);
  graph.AddEdge("V0", "V3", 1.0);
  graph.AddEdge("V1", "V3", 3.0);
  graph.AddEdge("V3", "V2", 2.0);
  graph.AddEdge("V3", "V4", 2.0);
  graph.AddEdge("V3", "V5", 8.0);
  graph.AddEdge("V3", "V6", 4.0);
  graph.AddEdge("V6", "V5", 1.0);
  graph.AddEdge("V2", "V5", 5.0);

  graph.Dijkstra("V0");

  Vertex* vertex;
  vertex = graph.GetVertex("V0");
  ASSERT_EQ(vertex->distance_, 0);

  vertex = graph.GetVertex("V1");
  ASSERT_EQ(vertex->distance_, 2);

  vertex = graph.GetVertex("V2");
  ASSERT_EQ(vertex->distance_, 3);

  vertex = graph.GetVertex("V3");
  ASSERT_EQ(vertex->distance_, 1);

  vertex = graph.GetVertex("V4");
  ASSERT_EQ(vertex->distance_, 3);

  vertex = graph.GetVertex("V5");
  ASSERT_EQ(vertex->distance_, 6);

  vertex = graph.GetVertex("V6");
  ASSERT_EQ(vertex->distance_, 5);
}

TEST(GraphTest, NegativeWeightedGraphTest){
  // This test will test Bellman-Ford algorithm for a negative-weighted graph
  Graph neg_cycle_graph;

  // This is a negative cycle graph
  neg_cycle_graph.AddEdge("V2", "V0", 4.0);
  neg_cycle_graph.AddEdge("V0", "V1", 2.0);
  neg_cycle_graph.AddEdge("V4", "V6", 6.0);
  neg_cycle_graph.AddEdge("V0", "V3", 1.0);
  neg_cycle_graph.AddEdge("V1", "V3", 3.0);
  neg_cycle_graph.AddEdge("V3", "V2", 2.0);
  neg_cycle_graph.AddEdge("V3", "V4", 2.0);
  neg_cycle_graph.AddEdge("V3", "V5", 8.0);
  neg_cycle_graph.AddEdge("V3", "V6", 4.0);
  neg_cycle_graph.AddEdge("V4", "V1", -10.0);
  neg_cycle_graph.AddEdge("V6", "V5", 1.0);
  neg_cycle_graph.AddEdge("V2", "V5", 5.0);

  ASSERT_EQ(neg_cycle_graph.Negative("V10"), false);
  ASSERT_EQ(neg_cycle_graph.Negative("V0"), false);

  Graph non_negative_graph;

  // This is a negative weighted graph without a negative cycle.
  non_negative_graph.AddEdge("V2", "V0", 4.0);
  non_negative_graph.AddEdge("V0", "V1", 2.0);
  non_negative_graph.AddEdge("V1", "V4", -10.0);
  non_negative_graph.AddEdge("V4", "V6", 6.0);
  non_negative_graph.AddEdge("V0", "V3", 1.0);
  non_negative_graph.AddEdge("V1", "V3", 3.0);
  non_negative_graph.AddEdge("V3", "V2", 2.0);
  non_negative_graph.AddEdge("V3", "V4", 2.0);
  non_negative_graph.AddEdge("V3", "V5", 8.0);
  non_negative_graph.AddEdge("V3", "V6", 4.0);
  non_negative_graph.AddEdge("V6", "V5", 1.0);
  non_negative_graph.AddEdge("V2", "V5", 5.0);

  ASSERT_EQ(non_negative_graph.Negative("V0"), true);

  Vertex* vertex;
  vertex = non_negative_graph.GetVertex("V0");
  ASSERT_EQ(vertex->distance_, 0);

  vertex = non_negative_graph.GetVertex("V1");
  ASSERT_EQ(vertex->distance_, 2);

  vertex = non_negative_graph.GetVertex("V2");
  ASSERT_EQ(vertex->distance_, 3);

  vertex = non_negative_graph.GetVertex("V3");
  ASSERT_EQ(vertex->distance_, 1);

  vertex = non_negative_graph.GetVertex("V4");
  ASSERT_EQ(vertex->distance_, -8);

  vertex = non_negative_graph.GetVertex("V5");
  ASSERT_EQ(vertex->distance_, -1);

  vertex = non_negative_graph.GetVertex("V6");
  ASSERT_EQ(vertex->distance_, -2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
