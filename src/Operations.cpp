/*
 * Operations.cpp
 *
 *  Created on: 29 jul. 2017
 *      Author: colosu
 */

#include <cmath>
#include "Operations.h"
using namespace std;

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

	int sq = 0;
	int* inputs = new int;
	map<string, int>* mapOtoI = new map<string, int>;

	SqueezinessAux(g->getAutomaton(), g->getAutomaton()->root_id, 0, length, inputs, mapOtoI, "");

	for (std::map<string, int>::iterator it = mapOtoI->begin(); it != mapOtoI->end(); it++) {
		sq += pow((double)it->second/(*inputs), 2) * log2((double)(*inputs));
	}

	return sq;
}

double Operations::ProbSqueeziness(Graph<void>* g, int length) {

	if (length <= 0) {
		return 0;
	}

	int sq = 0;
	int psq = 0;
	int* inputs = new int;
	map<string, int>* mapOtoI = new map<string, int>;

	SqueezinessAux(g->getAutomaton(), g->getAutomaton()->root_id, 0, length, inputs, mapOtoI, "");

	double max = 0;
	for (std::map<string, int>::iterator it = mapOtoI->begin(); it != mapOtoI->end(); it++) {
		sq += pow((double)it->second/(*inputs), 2) * log2((double)(*inputs));
		if (it->second > max) {
			max = it->second;
		}
	}
	psq = sq/log2(max);
	return psq;
}


void Operations::SqueezinessAux(gfsmAutomaton* fsm, int qid, int iter, int k, int* inputs, map<string,int>* mapOtoI, string output) {

	if (iter == k) {

		if (mapOtoI->find(output) != mapOtoI->end()) {
			mapOtoI->at(output)++;
		} else {
			mapOtoI->emplace(output, 1);
		}

	} else {

		gfsmArcIter* arcIter = new gfsmArcIter();
		gfsmArc* arc = new gfsmArc();

		gfsm_arciter_open(arcIter, fsm, qid);
		arc = gfsm_arc_clone(gfsm_arciter_arc(arcIter));

		*inputs = *inputs + 1;
		SqueezinessAux(fsm, gfsm_arc_target(arc), iter + 1, k, inputs, mapOtoI, output + to_string(gfsm_arc_upper(arc)));

		for (unsigned int i = 1; i < gfsm_automaton_out_degree(fsm, qid); i++) {

			gfsm_arciter_next(arcIter);
			arc = gfsm_arc_clone(gfsm_arciter_arc(arcIter));
			*inputs = *inputs + 1;
			SqueezinessAux(fsm, gfsm_arc_target(arc), iter + 1, k, inputs, mapOtoI, output + to_string(gfsm_arc_upper(arc)));
		}
	}
}

} /* namespace std */
