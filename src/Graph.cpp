/*
 * Graph.cpp
 *
 *  Created on: 29 jul. 2017
 *      Author: colosu
 */

#include "Graph.h"

namespace std {

template <class T>
Graph<T>::Graph() {
	automaton = gfsm_automaton_new();
	init = NULL;
	qidNodeMap = new map<int,Node<T>>();
	qidEdgeMap = new map<int,Edge<T>>();
}

template <class T>
Graph<T>::Graph(gfsmAutomaton* autom) {
	automaton = NULL;
	qidNodeMap = new map<int,Node<T>>();
	qidEdgeMap = new map<int,Edge<T>>();
	setAutomaton(autom);
	int qid = gfsm_automaton_get_root(automaton);
	init = qidNodeMap->find(qid);
}

template <class T>
Graph<T>::~Graph() {
	gfsm_automaton_free(automaton);
	automaton = NULL;
	init.~Nodo();
	init = NULL;
	qidNodeMap->~map();
	qidEdgeMap->~map();
}

template <class T>
gfsmAutomaton* Graph<T>::getAutomaton() {
	return automaton;
}

template <class T>
Node<T>* Graph<T>::getInit() {
	return init;
}

template <class T>
map<int,Node<T>>* Graph<T>::getQidNodeMap() {
	return qidNodeMap;
}

template <class T>
map<int,Edge<T>>* Graph<T>::getQidEdgeMap() {
	return qidEdgeMap;
}

template <class T>
void Graph<T>::setAutomaton(gfsmAutomaton* autom) {
	if (automaton != NULL) {
		gfsm_automaton_free(automaton);
	}
	automaton = autom;

	/*
	for(int i = 0; i < gfsm_automaton_n_states(automaton); i++) {
		//TODO: complete the function.
	}
	*/
}

template <class T>
void Graph<T>::addNode(bool initial, bool final) {
	int qid = 0;
	qid = gfsm_automaton_add_state(automaton);
	gfsm_automaton_set_final_state(automaton, qid, final);
	Node<T> node = new Node<T>(qid, initial, final);
	qidNodeMap->insert(qid, node);

}

template <class T>
void Graph<T>::addEdge(gfsmArc* arc, Node<T> source, Node<T> destination, gfsmLabelVal lo, gfsmLabelVal hi, gfsmWeight wt) {
	int qid = 0;
	qid = gfsm_automaton_add_arc(automaton, source.getQid(), destination.getQid(), lo, hi, wt);
	Edge<T> edge = new Edge<T>(source, destination, lo, hi, wt);
	source.getEdges().insert(edge);
	qidEdgeMap->insert(qid, edge);
}

} /* namespace std */
