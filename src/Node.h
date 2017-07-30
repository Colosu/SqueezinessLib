/*
 * Node.h
 *
 *  Created on: 29 jul. 2017
 *      Author: colosu
 */

#ifndef NODE_H_
#define NODE_H_

#include <gfsm.h>
#include <list>
#include "Edge.h"

namespace std {

template <class T> class Node {
public:
	Node();
	Node(T dat, bool initial, bool final);
	Node(int id, T dat, bool initial, bool final);
	~Node();
	void initNode(T dat, bool initial, bool final);
	void initNode(int id, T dat, bool initial, bool final);
	void initNode(T dat, bool initial, bool final, gfsmArcList* arc);
	void initNode(int id, T dat, bool initial, bool final, gfsmArcList* arc);
	int getQid();
	T getData();
	gfsmState* getState();
	list<Edge<T>*>* getEdges();
	void setQid(int id);
	void setData(T dat);
	void setState(gfsmState* stat);
	void setEdges(list<Edge<T>*>* list);
	void addEdge(Edge<T>* edge);
	bool isInitial();
	bool isFinal();
	bool isValid();

private:
	int qid;
	T data;
	bool isInit;
	gfsmState* state;
	list<Edge<T>*>* edges;
};

} /* namespace std */

#endif /* NODE_H_ */
