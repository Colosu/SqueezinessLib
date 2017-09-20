/*
 * Checkups.h
 *
 *  Created on: 29 jul. 2017
 *      Author: colosu
 */

#ifndef CHECKUPS_H_
#define CHECKUPS_H_

#include <gfsm.h>
#include "Graph.h"

namespace std {

class Checkups {
public:
	Checkups();
	~Checkups();
	bool are_equivalent(Graph<void>* g1, Graph<void>* g2);
	bool is_valid(Graph<void>* g);
	bool has_FEP(Graph<void>* g1, Graph<void>* g2, int length, int &k);

private:
	bool FEPaux(gfsmAutomaton* fsm1, gfsmAutomaton* fsm2, int qid1, int qid2, string output1, string output2, int iter, int &k, int length);
};

} /* namespace std */

#endif /* CHECKUPS_H_ */
