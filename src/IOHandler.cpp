/*
 * IOHandler.cpp
 *
 *  Created on: 30 jul. 2017
 *      Author: colosu
 */

#include <stdio.h>
#include <iostream>
#include <gfsmAutomatonIO.h>
#include "Graph.h"
#include "IOHandler.h"

namespace std {

IOHandler::IOHandler() {
	// TODO Auto-generated constructor stub

}

IOHandler::~IOHandler() {
	// TODO Auto-generated destructor stub
}

Graph<void>* IOHandler::readGraph(string file) {

	Graph<void>* g = new Graph<void>;
	FILE* f;
	gfsmError** e = new gfsmError*();
	f = fopen(file.c_str(), "r");
	if (f == NULL) {
		cerr << "Unable to open the file." << endl;
		return NULL;
	}
	if (!gfsm_automaton_load_bin_file(g->getAutomaton(), f, e)) {
		cerr << "Unable to load the automaton." << endl;
		return NULL;
	}

	fclose(f);
	return g;

}

} /* namespace std */
