/*
 * Graph.cpp
 *
 *  Created on: 29 jul. 2017
 *      Author: colosu
 */

#include "Graph.h"

namespace std {

template <class T>
Graph<T>::Graph<T>() {
	automaton = NULL;
	root = NULL;
}

template <class T>
Graph<T>::~Graph<T>() {
	gfsm_automaton_free(automaton);
	automaton = NULL;
	root.~Nodo<T>();
	root = NULL;
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
void Graph<T>::setAutomaton(gfsmAutomaton* autom) {
	if (automaton != NULL) {
		gfsm_automaton_free(automaton);
	}
	automaton = autom;
	for(int i = 0; i < gfsm_automaton_n_states(automaton); i++) {

	}

}

} /* namespace std */
