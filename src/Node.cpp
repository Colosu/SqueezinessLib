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
	qid = 0;
	data = NULL;
	isInit = false;
	state = gfsm_state_new();
	edges = new list<Edge<T>*>();
}

template <class T>
Node<T>::Node(T dat, bool initial, bool final) {
	qid = 0;
	data = dat;
	isInit = initial;
	state = gfsm_state_new_full(final, NULL);
	edges = new list<Edge<T>*>();
}

template <class T>
Node<T>::Node(int id, T dat, bool initial, bool final) {
	qid = id;
	data = dat;
	isInit = initial;
	state = gfsm_state_new_full(final, NULL);
	edges = new list<Edge<T>*>();
}

template <class T>
Node<T>::~Node() {
	//TODO: I end here?
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
void Node<T>::initNode(int id, T dat, bool initial, bool final) {
	qid = id;
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
void Node<T>::initNode(int id, T dat, bool initial, bool final, gfsmArcList* arc) {
	qid = id;
	data = dat;
	isInit = initial;
	gfsm_state_set_final(state, final);
	state->arcs = arc;
}

template <class T>
int Node<T>::getQid() {
	return qid;
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
list<Edge<T>*>* Node<T>::getEdges() {
	return edges;
}

template <class T>
void Node<T>::setQid(int id) {
	qid = id;
}

template <class T>
void Node<T>::setData(T dat) {
	data = dat;
}

template <class T>
void Node<T>::setState(gfsmState* stat) {
	state = stat;
}

template <class T>
void Node<T>::setEdges(list<Edge<T>*>* list) {
	if (edges != NULL)
		edges->~list<Edge<T>*>();
	edges = list;
}

template <class T>
void Node<T>::addEdge(Edge<T>* edge) {
	edges->push_back(edge);
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
