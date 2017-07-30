/*
 * Edge.cpp
 *
 *  Created on: 29 jul. 2017
 *      Author: colosu
 */

#include "Edge.h"

namespace std {

template <class T>
Edge<T>::Edge() {
	edge = gfsm_arc_new();
	source = NULL;
	destination = NULL;
}

template <class T>
Edge<T>::Edge(Node<T>* src, Node<T>* dst, gfsmLabelVal lo, gfsmLabelVal hi, gfsmWeight wt) {
	edge = gfsm_arc_new_full(src->getQid(), dst->getQid(), lo, hi, wt);
	source = src;
	destination = dst;
}

template <class T>
Edge<T>::~Edge() {
	//TODO: I really need to destroy nodes here?
	gfsm_arc_free(edge);
	edge = NULL;
	source.~Node();
	source = NULL;
	destination.~Node();
	destination = NULL;
}

template <class T>
void Edge<T>::initEdge(Node<T>* src, Node<T>* dst, gfsmLabelVal lo, gfsmLabelVal hi, gfsmWeight wt) {
	edge = gfsm_arc_init(edge, src->getQid(), dst->getQid(), lo, hi, wt);
	source = src;
	destination = dst;
}

template <class T>
gfsmArc* Edge<T>::getEdge() {
	return edge;
}

template <class T>
Node<T>* Edge<T>::getSource() {
	return source;
}

template <class T>
Node<T>* Edge<T>::getDestination() {
	return destination;
}

} /* namespace std */
