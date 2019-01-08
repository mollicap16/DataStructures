#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <string>
#include <queue>
#include <functional>
#include <list>

/***************************************************************************************************************************************************************
 * DESCRIPTION: Graphs are non-linear data structures, that are composed of two fundamental structures vertices (or nodes) and edges (or connections). Nodes
 *              are just elements that hold data and edges are just the connections between the nodes.
 *
 * IMPLEMENTATION: The graph will be represented by adjanceny lists. Multiple shortest-path algorithms will be implemented. This graph is modeled after the
 *                 examples used through out chapter 15 of Data Structures and Problem Solving Using C++, 2nd ed - Mark Weiss
 *
 **************************************************************************************************************************************************************/

struct Vertex;   // Forward declaration or I could put the vertex class before the edge class

struct Edge {
  Vertex* dest_;      // Destination Vertex
  double cost_;       // Cost of the Edge

  Edge(Vertex* dest = 0, double cost = 0.0)
    : dest_(dest), cost_(cost){}
};

struct Vertex {
  std::string  name_;           // Vertex name
  std::vector<Edge> adj_list_;  // Adjacency vertices and edge cost
  double distance_;             // shortest distance from the starting vertex
  Vertex *prev_;                // previous vertex on shortest path
  int32_t scratch_;             // extra variable used in different shortest-path algorithm

  Vertex( const std::string &name) : name_(name)
    {Reset();}

  void Reset()
    {distance_ = std::numeric_limits<double>::max(); prev_ = nullptr; scratch_ = 0;}
};

// This path structure is the structure we use for the priority queue in Dijkstra's algorithm
struct Path {
  Vertex* dest_;  // node w
  double cost_;   // D(w)

  Path(Vertex* dest = 0, double cost = 0.0)
    : dest_(dest), cost_(cost) {}

  // Overload operators for priority queue
  bool operator > (const Path& rhs) const {
    return cost_ > rhs.cost_;
  }
  bool operator < (const Path& rhs) const {
    return cost_ < rhs.cost_;
  }
};

class Graph {
public:
  Graph();
  ~Graph();

  void AddEdge (const std::string& source_name, const std::string& dest_name, double cost);
  void PrintPath(const std::string& dest_name) const;
  void Unweighted(const std::string& start_name); // Unweighted shortest-path algorithm (BFS)
  void Dijkstra(const std::string& start_name);   // Dijkstra's shortest-path algorithm
  // This function returns true if there isn't a negative cost cycle and the start node is in the graph
  bool Negative(const std::string& start_name);   // Negatvie weighted shortest-path algorithm
  void Acyclic(const std::string& start_name);                                 // Acyclic shortest-path algorithm
  Vertex* GetVertex(const std::string& vertex_name);

private:
  void PrintPath(const Vertex& dest) const;
  void ClearAll();

  typedef std::map<std::string, Vertex*, std::less<std::string> > vmap;

  // Copy Semantics are disabled
  Graph(const Graph&){}
  const Graph& operator=(const Graph& ){return *this;}

  vmap VertexMap;
};

#endif //GRAPH
