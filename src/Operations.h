/*
 * Operations.h
 *
 *  Created on: 29 jul. 2017
 *      Author: colosu
 */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_

#include <gfsm.h>
#include "Graph.h"

namespace std {

class Operations {
public:
	Operations();
	~Operations();
	void minimization(Graph<void>* g);
	gfsmAutomaton* product(Graph<void>* g1, Graph<void>* g2);
	double Squeeziness(Graph<void>* g, int length);
	double ProbSqueeziness(Graph<void>* g, int length);
};

} /* namespace std */

#endif /* OPERATIONS_H_ */
