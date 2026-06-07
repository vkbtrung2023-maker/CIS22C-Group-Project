//************************
//Author: Jordan Alejandro
//************************

#include <iostream>
#include <vector>
#include "Weighted_graph.h"

//Function Implementations

Weighted_graph::Weighted_graph(int numVertcies) {
	this->numVertices = numVertcies;
	this->numEdges = 0;
	edges.resize(numVertcies);
}

int Weighted_graph::degree(int n) const {
	if (n < 0 || n >= numVertices) {
		throw std::invalid_argument("Invalid vertex index");
	}
	return edges.at(n).size();
}

int Weighted_graph::edge_count() const {
	return numEdges;
}


// FIX ME...
double Weighted_graph::adjacent(int m, int n) const {
	if (m < 0 || m >= numVertices || n < 0 || n >= numVertices) {
		throw std::invalid_argument("Invalid vertex index");
	}

	if (m == n) { return 0.0; }

	double distance = INF;
	const vector<Edge>& edgesFromM = edges.at(m);
	for (int i = 0; i < edgesFromM.size(); i++) {
		if (edgesFromM.at(i).vertex1 == n || edgesFromM.at(i).vertex2 == n) {
			return edgesFromM.at(i).edgeWeight;
		}
	}
}

void Weighted_graph::insert(int m, int n, double weight) {
	Edge edgeMtoN(m, n, weight);
	Edge edgeNtoM(n, m, weight);
	edges.at(m).push_back(edgeMtoN);
	edges.at(n).push_back(edgeNtoM);
	numEdges++;
}



// IMPLEMENT THE Dijkstra's algorithm  HERE
double Weighted_graph::distance(int m, int n) {
	//IMPLEMENT HERE
	return 0.0;
}

std::ostream& operator<<(std::ostream& out, Weighted_graph const& graph) {
	for (int i = 0; i < graph.numVertices; i++) {
		out << i << ": ";
		for (const Edge& e : graph.edges.at(i)) {
			out << "(" << e.vertex2 << ", w=" << e.edgeWeight << ") ";
		}
		out << "\n";
	}
	return out;
}