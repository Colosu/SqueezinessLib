/*
 * IOHandler.h
 *
 *  Created on: 30 jul. 2017
 *      Author: colosu
 */

#ifndef IOHANDLER_H_
#define IOHANDLER_H_

#include "Graph.h"

namespace std {

class IOHandler {
public:
	IOHandler();
	~IOHandler();
	Graph<void>* readGraph(string file);

private:

};

} /* namespace std */

#endif /* IOHANDLER_H_ */
