/*
 * Graph.h
 *
 *  Created on: 29 jul. 2017
 *      Author: colosu
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <gfsm.h>
#include "Node.h"
#include "Edge.h"

namespace std {

template <class T> class Graph {
public:
	Graph<T>();
	~Graph<T>();
	gfsmAutomaton* getAutomaton();
	Node<T>* getInit();
	void setAutomaton(gfsmAutomaton* autom);

private:
	gfsmAutomaton* automaton;
	Node<T>* init;

};

} /* namespace std */

#endif /* GRAPH_H_ */
