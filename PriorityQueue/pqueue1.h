/*
 * pqueue1.h
 *
 *  Created on: 5 ott 2023
 *      Author: salva
 */

#ifndef PQUEUE1_H_
#define PQUEUE1_H_

#include <stdlib.h> // Provides size_t

struct Node; // This will be completely defined below.

class PriorityQueue
{
public:
	typedef int Item;
	PriorityQueue( );
	PriorityQueue(const PriorityQueue& source);
	~PriorityQueue( );
	void operator =(const PriorityQueue& source);
	size_t size( ) const { return many_nodes; }
	void insert(const Item& entry, unsigned int priority);
	void remove_pop(const Item& removal);
	//void remove_one( const Item& removal);
	Node* precursor( const Item& target);
	Node* search( const Item& target);
	Node* list_locate(size_t position);
	void clear();
	Item get_front( );
	bool is_empty( ) const { return many_nodes == 0; }

private:
	// Note: head_ptr is the head pointer for a linked list that
	// contains the items along with their priorities. These nodes are
	// kept in order from highest priority (at the head of the list)
	// to lowest priority (at the tail of the list). The private member
	// variable, many_nodes, indicates how many nodes are on the list.
	// The data type Node is completely defined below.
	Node* head_ptr;
	size_t many_nodes;
};


struct Node
{ // Node for a linked list
	PriorityQueue::Item data;
	unsigned int priority;
	Node *link;
};


#endif /* PQUEUE1_H_ */
