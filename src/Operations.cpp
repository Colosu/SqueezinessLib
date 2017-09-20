/*
 * Operations.cpp
 *
 *  Created on: 29 jul. 2017
 *      Author: colosu
 */

#include "Operations.h"

namespace std {

Operations::Operations() {

}

Operations::~Operations() {

}

void Operations::minimization(Graph<void>* g) {
	g->setAutomaton(gfsm_automaton_minimize(g->getAutomaton()));
}

gfsmAutomaton* Operations::product(Graph<void>* g1, Graph<void>* g2) {
	gfsmAutomaton* a1 = gfsm_automaton_clone(g1->getAutomaton());
	gfsmAutomaton* a2 = gfsm_automaton_clone(g2->getAutomaton());
	gfsmAutomaton* prod = gfsm_automaton_product2(a1, a2);
	gfsm_automaton_free(a1);
	gfsm_automaton_free(a2);
	return prod;
}

double Operations::Squeeziness(Graph<void>* g, int length) {

	if (length <= 0) {
		return 0;
	}

	//TODO: calculate Squeeziness.
	return 0;
}

double Operations::ProbSqueeziness(Graph<void>* g, int length) {

	if (length <= 0) {
		return 0;
	}

	//TODO: calculate Probability Squeeziness.
	return 0;
}


} /* namespace std */
