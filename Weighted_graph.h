/*****************************************

 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *
 * The following is a list of those students
 * I had worked together in preparing this project:
 *    -
 *****************************************/

#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#ifndef nullptr
#define nullptr 0
#endif

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// include whatever classes you want

// Describes path and cost between two nodes
class Edge {
public:
	int vertex1;
	int vertex2;
	double edgeWeight;
	static constexpr double INF = std::numeric_limits<double>::infinity();
	Edge(int m = -1, int n = -1, double edgeWeight = -1) {
		this->vertex1 = m;
		this->vertex2 = n;
		this->edgeWeight = (edgeWeight > -1 && edgeWeight < INF) ? edgeWeight : INF;
	}
};


class Weighted_graph {
	private:
		// your implementation here
		//  you can add both private member variables and private member functions
		vector<vector<Edge>> edges;
		int numVertices;
		int numEdges;
		static constexpr double INF = std::numeric_limits<double>::infinity();


	public:
		//Maybe int in constructor not needed if we are using vectors?
		Weighted_graph( int numVertcies = 50 );
		~Weighted_graph() = default;

		int degree( int ) const;
		int edge_count() const;
		double adjacent( int, int ) const;
		double distance( int, int );

		void insert( int, int, double );

	// Friends

	friend std::ostream &operator<<( std::ostream &, Weighted_graph const & );
};


// Your implementation here

// You can modify this function however you want:  it will not be tested



// Is an error showing up in CIS22B.h or elsewhere?
// Did you forget a closing '}' ?

#endif
