/*
 * Edge.h
 *
 *  Created on: 29 jul. 2017
 *      Author: colosu
 */

#ifndef EDGE_H_
#define EDGE_H_

#include <gfsm.h>
// #include "Node.h"

template <class T> class Node;

namespace std {

template <class T> class Edge {

	//TODO: complete or simplify/delete this class.
public:
	Edge();
	Edge(Node<T>* src, Node<T>* dst, gfsmLabelVal lo, gfsmLabelVal hi, gfsmWeight wt);
	~Edge();
	void initEdge(Node<T>* src, Node<T>* dst, gfsmLabelVal lo, gfsmLabelVal hi, gfsmWeight wt);
	gfsmArc* getEdge();
	Node<T>* getSource();
	Node<T>* getDestination();

private:
	Node<T>* source;
	Node<T>* destination;
	gfsmArc* edge;
};

} /* namespace std */

#endif /* EDGE_H_ */
