/*
 * Edge.h
 *
 *  Created on: 29 jul. 2017
 *      Author: colosu
 */

#ifndef EDGE_H_
#define EDGE_H_

#include <gfsm.h>
#include "Node.h"

namespace std {

template <class T> class Edge {
public:
	Edge();
	Edge(gfsmStateId src, gfsmStateId dst, gfsmLabelVal lo, gfsmLabelVal hi, gfsmWeight wt);
	~Edge();
	void initEdge(gfsmStateId src, gfsmStateId dst, gfsmLabelVal lo, gfsmLabelVal hi, gfsmWeight wt);
	gfsmArc* getEdge();
	Node<T>* getSource();
	Node<T>* getDestination();

private:
	Node<T> source;
	Node<T> destination;
	gfsmArc* edge;
};

} /* namespace std */

#endif /* EDGE_H_ */
