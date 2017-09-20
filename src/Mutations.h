/*
 * Mutations.h
 *
 *  Created on: 29 jul. 2017
 *      Author: colosu
 */

#ifndef MUTATIONS_H_
#define MUTATIONS_H_

#include "Graph.h"
namespace std {

class Mutations {
public:
	Mutations();
	~Mutations();
	Graph<void>* mutate(Graph<void>* g);
};

} /* namespace std */

#endif /* MUTATIONS_H_ */
