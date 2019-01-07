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

  Edge(Vertex* dest, double cost)
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

class Graph {
public:
  Graph();
  ~Graph();

  void AddEdge (const std::string& source_name, std::string& dest_name, double cost);
  void PrintPath(const std::string& dest_name) const;
  void Unweighted(); // Unweighted shortest-path algorithm (BFS)
  void Dijkstra();   // Dijkstra's shortest-path algorithm
  void Negative();   // Negatvie weighted shortest-path algorithm
  void Acyclic();    // Acyclic shortest-path algorithm

private:
  Vertex* GetVertex(const std::string& vertex_name);
  void PrintPath(const Vertex& dest) const;
  void ClearAll();

  typedef std::map<std::string, Vertex*, std::less<std::string> > vmap;

  // Copy Semantics are disabled
  Graph(const Graph&){}
  const Graph& operator=(const Graph& ){return *this;}

  vmap VertexMap;
};

#endif //GRAPH
