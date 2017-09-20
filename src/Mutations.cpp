/*
 * Mutations.cpp
 *
 *  Created on: 29 jul. 2017
 *      Author: colosu
 */

#include "Mutations.h"

namespace std {

Mutations::Mutations() {
	// TODO Auto-generated constructor stub

}

Mutations::~Mutations() {
	// TODO Auto-generated destructor stub
}

Graph<void>* Mutations::mutate(Graph<void>* g) {

	Graph<void>* m = new Graph<void>;
	gfsmArcIter* arcIter = new gfsmArcIter();
	gfsmAutomaton* mut = gfsm_automaton_clone(g->getAutomaton());
	gfsmArc* arc = new gfsmArc();

	int state = rand() % gfsm_automaton_n_states(mut);
	int ind = rand() % gfsm_automaton_out_degree(mut, state);

	gfsm_arciter_open(arcIter, mut, state);
	for (int i = 0; i < ind; i++) {
		gfsm_arciter_next(arcIter);
	}
	arc = gfsm_arc_clone(gfsm_arciter_arc(arcIter));
	if(arc == NULL) {
		return NULL;
	}

	gfsm_automaton_remove_arc_ptr(mut, gfsm_arciter_arc(arcIter));

	unsigned int obj = rand() % gfsm_automaton_n_states(mut);
	while (obj == gfsm_arc_source(arc) || obj == gfsm_arc_target(arc)) {
		obj = rand() % gfsm_automaton_n_states(mut);
	}

	int r = rand() % 2;
	if (r == 0) {
		gfsm_automaton_add_arc(mut, obj, gfsm_arc_target(arc), gfsm_arc_lower(arc), gfsm_arc_upper(arc), gfsm_arc_weight(arc));
	} else {
		gfsm_automaton_add_arc(mut, gfsm_arc_source(arc), obj, gfsm_arc_lower(arc), gfsm_arc_upper(arc), gfsm_arc_weight(arc));
	}

	m->setAutomaton(mut);

	return m;
}

} /* namespace std */
