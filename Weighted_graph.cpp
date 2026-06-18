//************************
//Authors: Jordan Alejandro, Ishaan Verma, Trung Vo, Iryna Biziukova
//************************

#include <iostream>
#include <vector>
#include "Weighted_graph.h"

//Function Implementations

Weighted_graph::Weighted_graph(int numVertcies) {
	// Stores how many vertices this graph has
	this->numVertices = numVertcies;

	// No edges exist yet when the graph is first created
	this->numEdges = 0;

	// Resize the adjacency list so there's one empty edge-list per vertex
	// Each index in edges represents one vertex and holds all its connected edges
	edges.resize(numVertcies);
}

int Weighted_graph::degree(int n) const {
	// Makes sure n is actually a valid vertex in this graph
	if (n < 0 || n >= numVertices) {
		throw std::invalid_argument("Invalid vertex index");
	}

	// The degree of a vertex is just how many edges it has, which is the size of its adjacency list
	return edges.at(n).size();
}

int Weighted_graph::edge_count() const {
	// numEdges is kept up to date by insert(), so just return it directly
	return numEdges;
}

double Weighted_graph::adjacent(int m, int n) const {
	// Makes sure both vertices actually exist in the graph
	if (m < 0 || m >= numVertices || n < 0 || n >= numVertices) {
		throw std::invalid_argument("Invalid vertex index");
	}

	// A vertex is always considered to be adjacent to itself with a distance of 0
	if (m == n) { 
		return 0.0; 
	}

	// Grabs the list of all edges going out from vertex m
	const vector<Edge>& edgesFromM = edges.at(m);

	// Seaches through every edge from m to see if any of them connect to n
	for (int i = 0; i < edgesFromM.size(); i++) {
		if (edgesFromM.at(i).vertex1 == n || edgesFromM.at(i).vertex2 == n) {
			return edgesFromM.at(i).edgeWeight;
		}
	}

	// If everything is looped and nothing is found, m and n are not directly connected
	return INF;
}

void Weighted_graph::insert(int m, int n, double weight) {
	// Build the edge in both directions since this is an undirected graph
	// m -> n and n -> m should both exist with the same weight
	Edge edgeMtoN(m, n, weight);
	Edge edgeNtoM(n, m, weight);

	// Add each direction to the respective vertex's adjacency list
	edges.at(m).push_back(edgeMtoN);
	edges.at(n).push_back(edgeNtoM);

	// One new edge was added to the graph, so increment the count
	numEdges++;
}

double Weighted_graph::distance(int m, int n) {
	// Checks for valid vertex indices
	if (m < 0 || m >= numVertices || n < 0 || n >= numVertices) {
		throw std::invalid_argument("Invalid vertex index");
	}

	// If the vertices are the same, the distance would of course be 0
	if (m == n) {
		return 0.0;
	}

	// dist holds the shortest known distance from m to each vertex
	vector<double> dist(numVertices, INF);
	dist.at(m) = 0.0;

	// Just keeps track of which vertices have already been visited
	vector<bool> visited(numVertices, false);
	for (int i = 0; i < numVertices; i++) {

		// Picks the unisited vertex with the smallest known distance from m
		int current = -1;
		for (int j = 0; j < numVertices; j++) {
			if (visited.at(j) == false && (current == -1 || dist.at(j) < dist.at(current))) {
				current = j;
			}
		}

		// In the case that the smallest distance left is INF, then all remaining vertices are deemed to be unreachable
		if (dist.at(current) == INF) {
			break;
		}
		
		// Vertex is finalized
		visited.at(current) = true;

		// For each unvisited neighbor, if the path through current is shorter than the previously known distance, update the distance (neighbor score)
		const vector<Edge>& edgesFromCurrent = edges.at(current);
		for (int i = 0;i < edgesFromCurrent.size(); i++) {
			int neighbor = edgesFromCurrent.at(i).vertex2;
			double weight = edgesFromCurrent.at(i).edgeWeight;

			if (visited.at(neighbor) == false && dist.at(current) + weight < dist.at(neighbor)) {
				dist.at(neighbor) = dist.at(current) + weight;
			}
		}
	}

	return dist.at(n);
}

std::ostream& operator<<(std::ostream& out, Weighted_graph const& graph) {
	// Loops through every vertex in the graph and print the vertex number as a label
	// Alongside their neighbors and the weight of the edge connecting them
	for (int i = 0; i < graph.numVertices; i++) {
		out << i << ": ";
		for (const Edge& e : graph.edges.at(i)) {
			out << "(" << e.vertex2 << ", w=" << e.edgeWeight << ") ";
		}
		out << "\n";
	}
	return out;
}
