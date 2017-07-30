/*
 * Graph.h
 *
 *  Created on: 29 jul. 2017
 *      Author: colosu
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <gfsm.h>
#include <map>
#include "Node.h"
#include "Edge.h"

namespace std {

template <class T> class Graph {
public:
	Graph();
	Graph(gfsmAutomaton* autom);
	~Graph();
	gfsmAutomaton* getAutomaton();
	Node<T>* getInit();
	map<int,Node<T>>* getQidNodeMap();
	void setAutomaton(gfsmAutomaton* autom);
	void addNode(bool initial, bool final);
	void addEdge(gfsmArc* arc, Node<T> source, Node<T> destination, gfsmLabelVal lo, gfsmLabelVal hi, gfsmWeight wt);

private:
	gfsmAutomaton* automaton;
	Node<T>* init;
	map<int,Node<T>>* qidNodeMap;

};

} /* namespace std */

#endif /* GRAPH_H_ */
