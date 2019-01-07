#include <graph.h>
#include <functional>

Graph::Graph(){}

Graph::~Graph(){
  // Clean up Vertex Objects
  for (vmap::iterator itr = VertexMap.begin(); itr!=VertexMap.end(); ++itr){
    delete (*itr).second;
  }
}

// Reset all the Vertices in the VertexMap
void Graph::ClearAll(){
  for (vmap::iterator itr = VertexMap.begin(); itr != VertexMap.end(); ++itr){
    (*itr).second->Reset();
  }
}

Vertex* Graph::GetVertex(const std::string &vertex_name){
  vmap::iterator itr = VertexMap.find(vertex_name);

  // If the vertex name is not in the map add it to the map
  if (itr == VertexMap.end()){
    Vertex* new_vertex = new Vertex(vertex_name);
    VertexMap[vertex_name] = new_vertex;
    return new_vertex;
  }

  return (*itr).second;
}

void Graph::AddEdge(const std::string &source_name, std::string &dest_name, double cost){
  Vertex* v = GetVertex(source_name);
  Vertex* w = GetVertex(dest_name);
  v->adj_list_.push_back(Edge(w, cost));
}

// Recursive function to print the shortest path from starting vertex to destination vertex.
// This is called after running the shortest path algorithm.
void Graph::PrintPath(const Vertex &dest) const{
  // Base Case
  if (dest.prev_ != nullptr){
    PrintPath(*dest.prev_);
    std::cout << " to ";
  }
  std::cout << dest.name_;
}

// Print shortest path along with total cost after a shortest-path algorithm has run
void Graph::PrintPath(const std::string &dest_name) const{
  vmap::const_iterator itr = VertexMap.find(dest_name);

  if (itr == VertexMap.end()){
    std::cout << "Destination vertex not found!!" << std::endl;
    return;
  }

  const Vertex & w = *(*itr).second;

  // Check if the destination vertex is unreachable
  if (w.distance_ == std::numeric_limits<double>::max()){
    std::cout << dest_name << " is unreachable" << std::endl;
  }
  else{
    std::cout << "(Cost is: " << w.distance_ << ") ";
    PrintPath(w);
  }
  std::cout << std::endl;
}


