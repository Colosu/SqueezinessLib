/*
 * Node.cpp
 *
 *  Created on: 29 jul. 2017
 *      Author: colosu
 */

#include "Node.h"

namespace std {

template <class T>
Node<T>::Node() {
	data = NULL;
	isInit = false;
	state = gfsm_state_new();
}

template <class T>
Node<T>::Node(T dat, bool initial, bool final) {
	data = dat;
	isInit = initial;
	state = gfsm_state_new_full(final, NULL);
}

template <class T>
Node<T>::~Node() {
	gfsm_state_close(state);
	state = NULL;
	data.~T();
	data = NULL;
	isInit = false;
}

template <class T>
void Node<T>::initNode(T dat, bool initial, bool final) {
	data = dat;
	isInit = initial;
	gfsm_state_set_final(state, final);
}

template <class T>
void Node<T>::initNode(T dat, bool initial, bool final, gfsmArcList* arc) {
	data = dat;
	isInit = initial;
	gfsm_state_set_final(state, final);
	state->arcs = arc;
}

template <class T>
T Node<T>::getData() {
	return data;
}

template <class T>
gfsmState* Node<T>::getState() {
	return state;
}

template <class T>
list<Edge<T>> Node<T>::getEdges() {
	return edges;
}

template <class T>
void Node<T>::setEdges(list<Edge<T>> list) {
	edges = list;
}

template <class T>
bool Node<T>::isInitial() {
	return isInit;
}

template <class T>
bool Node<T>::isFinal() {
	return gfsm_state_is_final(state);
}

template <class T>
bool Node<T>::isValid() {
	return gfsm_state_is_ok(state);
}

} /* namespace std */
