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
}

template <class T>
Edge<T>::Edge(gfsmStateId src, gfsmStateId dst, gfsmLabelVal lo, gfsmLabelVal hi, gfsmWeight wt) {
	edge = gfsm_arc_new_full(src, dst, lo, hi, wt);
}

template <class T>
Edge<T>::~Edge() {
	gfsm_arc_free(edge);
	edge = NULL;
	source.~Node<T>();
	source = NULL;
	destination.~Node<T>();
	destination = NULL;
}

template <class T>
void Edge<T>::initEdge(gfsmStateId src, gfsmStateId dst, gfsmLabelVal lo, gfsmLabelVal hi, gfsmWeight wt) {
	edge = gfsm_arc_init(edge, src, dst, lo, hi, wt);
}

template <class T>
gfsmArc* Edge<T>::getEdge() {
	return edge;
}

template <class T>
Node<T>* Edge<T>::getSource() {
	return edge;
}

template <class T>
Node<T>* Edge<T>::getDestination() {
	return edge;
}

} /* namespace std */
