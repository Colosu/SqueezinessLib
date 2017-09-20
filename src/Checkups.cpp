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

bool Checkups::has_FEP(Graph<void>* g1, Graph<void>* g2, int length, int &k) {

	gfsmAutomaton* orig = gfsm_automaton_clone(g1->getAutomaton());
	gfsmAutomaton* mut = gfsm_automaton_clone(g2->getAutomaton());
	k = 0;

	return FEPaux(orig, mut, orig->root_id, mut->root_id, "", "", 0, k, length);
}


bool Checkups::FEPaux(gfsmAutomaton* fsm1, gfsmAutomaton* fsm2, int qid1, int qid2, string output1, string output2, int iter, int &k, int length) {

	if (iter == length) {
		if (k != 0 && output1 == output2) {
			return true;
		} else {
			return false;
		}
	}

	gfsmArcIter* arcIter1 = new gfsmArcIter();
	gfsmArcIter* arcIter2 = new gfsmArcIter();
	gfsmArc* arc1 = new gfsmArc();
	gfsmArc* arc2 = new gfsmArc();
	bool result = false;

	gfsm_arciter_open(arcIter1, fsm1, qid1);
	gfsm_arciter_open(arcIter2, fsm2, qid2);
	arc1 = gfsm_arc_clone(gfsm_arciter_arc(arcIter1));
	arc2 = gfsm_arc_clone(gfsm_arciter_arc(arcIter2));

	if (qid1 != qid2) {

		if (output1 != output2) {
			return false;
		} else {
			k = iter;
		}
	}

	result = result || FEPaux(fsm1, fsm2, gfsm_arc_target(arc1), gfsm_arc_target(arc2), output1 + to_string(gfsm_arc_upper(arc1)), output2 + to_string(gfsm_arc_upper(arc2)), iter + 1, k, length);

	for (unsigned int i = 1; i < gfsm_automaton_out_degree(fsm1, qid1); i++) {
		gfsm_arciter_next(arcIter1);
		gfsm_arciter_next(arcIter2);
		arc1 = gfsm_arc_clone(gfsm_arciter_arc(arcIter1));
		arc2 = gfsm_arc_clone(gfsm_arciter_arc(arcIter2));
		result = result || FEPaux(fsm1, fsm2, gfsm_arc_target(arc1), gfsm_arc_target(arc2), output1 + to_string(gfsm_arc_upper(arc1)), output2 + to_string(gfsm_arc_upper(arc2)), iter + 1, k, length);
	}
	return result;
}

} /* namespace std */
