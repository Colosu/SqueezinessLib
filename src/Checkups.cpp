/*
 * Checkups.cpp
 *
 *  Created on: 29 jul. 2017
 *      Author: colosu
 */

#include "Checkups.h"
#include "Operations.h"

namespace std {

Checkups::Checkups() {
	// TODO Auto-generated constructor stub

}

Checkups::~Checkups() {
	// TODO Auto-generated destructor stub
}

bool Checkups::are_equivalent(Graph<void>* g1, Graph<void>* g2) {
	Operations* op = new Operations();
	op->minimization(g1);
	op->minimization(g2);
	gfsmAutomaton* prod = op->product(g1, g2);
	if (gfsm_automaton_n_states(gfsm_automaton_minimize(prod)) == gfsm_automaton_n_states(g1->getAutomaton())) {
		gfsm_automaton_free(prod);
		op->~Operations();
		return true;
	}
	gfsm_automaton_free(prod);
	op->~Operations();
	return false;
}

bool Checkups::is_valid(Graph<void>* g) {

	gfsmAutomaton* aux = gfsm_automaton_clone(g->getAutomaton());
	if (gfsm_automaton_is_transducer(aux)) {
		if (gfsm_automaton_determinize_full(aux, NULL) == g->getAutomaton()) {
			if (gfsm_automaton_connect(aux) == g->getAutomaton()) {
				if (gfsm_automaton_compact(aux) == g->getAutomaton()) {
					gfsm_automaton_free(aux);
					return true;
				}
			}
		}
	}
	gfsm_automaton_free(aux);
	return false;
}

bool Checkups::has_FEP(Graph<void>* g, int length, int &k) {

	//TODO: Check if g has FEP.

	k = 1;
	return true;
}

} /* namespace std */
