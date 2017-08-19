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
	bool equal(Graph<void>* g1, Graph<void>* g2);
};

} /* namespace std */

#endif /* CHECKUPS_H_ */
