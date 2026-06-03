//************************
//Author: Jordan Alejandro
//************************

#include <iostream>
#include <vector>
#include "Weighted_graph.h"

//Function Implementations

struct VertexNode {
	int value;
};

Weighted_graph::Weighted_graph(int vertices) {
	this->distanceVect = new vector<int>;
	this->verticiesVect = new vector<int>;
}

Weighted_graph::~Weighted_graph() {
	delete this->distanceVect;
	delete this->verticiesVect;
}

int Weighted_graph::degree(int vertex) const {

}

int Weighted_graph::edge_count() const {

}

double Weighted_graph::adjacent(int vert1, int vert2) const {

}

double Weighted_graph::distance(int vert1, int vert2) {

}

void Weighted_graph::insert(int vert1, int vert2, double weight) {

}
