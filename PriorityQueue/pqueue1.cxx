/*
 * pqueue1.cxx
 *
 *  Created on: 5 ott 2023
 *      Author: salva
 */

#include <assert.h>
#include <stdlib.h> // Provides NULL
#include "pqueue1.h" // Provides PriorityQueue and Node

PriorityQueue::PriorityQueue( )
{
	many_nodes = 0;
	head_ptr = NULL;
}
PriorityQueue::PriorityQueue(const PriorityQueue& source)
{
	Node *source_cursor; // To traverse the source list.
	Node *my_cursor; // To construct my own list.

	// Handle the special case of an empty list:
	many_nodes = 0;
	head_ptr = NULL;

	if (source.many_nodes == 0)
		return;
	// Insert the first node into this new list.

	insert(source.head_ptr->data, source.head_ptr->priority);
	many_nodes = 1;

	// Traverse the source list,
	// adding copies of each node that's encountered:
	my_cursor = head_ptr;
	source_cursor = source.head_ptr->link;

	while (source_cursor != NULL)
	{
		my_cursor->link = new Node;
		my_cursor = my_cursor->link;
		my_cursor->data = source_cursor->data;
		my_cursor->priority = source_cursor->priority;
		my_cursor->link = NULL;
		source_cursor = source_cursor->link;
	}

	many_nodes = source.many_nodes;
	}
PriorityQueue::~PriorityQueue( )
{
	Node *temp;
	while (head_ptr != NULL)
	{
		temp = head_ptr;
		head_ptr = head_ptr->link;
		delete temp;
	}
}

void PriorityQueue::operator =(const PriorityQueue& source)
{
	Node *source_cursor; // To traverse the source list.
	Node *my_cursor; // To construct my own list.
	// Handle self-assignment.
	if (this == &source)
	return;
	// Release the old memory:
	while (many_nodes > 0)
	get_front( );

// Handle the special case of an empty list:
	if (source.many_nodes == 0)
		return;

	// Insert the first node into this new list.
	insert(source.head_ptr->data, source.head_ptr->priority);
	many_nodes = 1;
	// Traverse the source list,
	// adding copies of each node that's encountered:
	my_cursor = head_ptr;
	source_cursor = source.head_ptr->link;
	while (source_cursor != NULL)
	{
	my_cursor->link = new Node;
	my_cursor = my_cursor->link;
	my_cursor->data = source_cursor->data;
	my_cursor->priority = source_cursor->priority;
	my_cursor->link = NULL;
	source_cursor = source_cursor->link;
	}
	many_nodes = source.many_nodes;
	}

	void PriorityQueue::insert(const Item& entry, unsigned int priority)
	{
		Node *insert_ptr; // Node for the new element
		Node *cursor; // Pointer that traverses the list
		// Create the new node
		insert_ptr = new Node;
		insert_ptr->data = entry;
		insert_ptr->priority = priority;
		if ((head_ptr == NULL) || (priority > head_ptr->priority))
		{ // Insert the new item at the front of the queue.
			insert_ptr->link = head_ptr;
			head_ptr = insert_ptr;
		}
		else
		{ // Add the new node further down the linked list.
			cursor = head_ptr;
			while ((cursor->link != NULL) && (cursor->link->priority >= priority))
			cursor = cursor->link;
			// New node goes right after the cursor node.
			insert_ptr->link = cursor->link;
			cursor->link = insert_ptr;
		}

		many_nodes++;

	}
	PriorityQueue::Item PriorityQueue::get_front( )
	{
		Item answer;
		Node *temp;
		assert(size( ) > 0);
		answer = head_ptr->data;
		temp = head_ptr;
		head_ptr = head_ptr->link;
		delete temp;
		many_nodes--;
		return answer;
	}

	Node* PriorityQueue::search( const Item& target)
		{
			Node* cursor;
			cursor=head_ptr;

			assert(!is_empty());

			while(cursor->link!=NULL)
			{
				if(cursor->data==target)
					return cursor;
				else
					cursor=cursor->link;
			}
			return NULL;
		}


	void PriorityQueue::remove_pop(const Item& removal)
	{

		assert(search(removal)!=NULL);

			do
			{
				get_front();
			}
			while(head_ptr->data!=removal);
			get_front();
	}


	/*void PriorityQueue::remove_one(const Item& removal)
	{
		Node* cursor;

		cursor=head_ptr;

		assert(!is_empty());

		while(cursor->link!=NULL)
		{
			if(head_ptr->data==removal)
			{
				head_ptr=head_ptr->link;
				delete cursor;
				--many_nodes;
			}
			else if(cursor->link->data==removal)
			{

				delete cursor;
			}
			else
				cursor=cursor->link;
		}
	}

*/


	Node* PriorityQueue::precursor( const Item& target)
	{
		Node* cursor;
		cursor=head_ptr;

		assert(!is_empty());

		if(head_ptr->data==target)
			return NULL;

		else
		{
			while(cursor->link!=NULL)
			{
				if(cursor->link->data==target)
					return cursor;
				else
					cursor=cursor->link;
			}
		}
		return NULL;
	}


	Node* PriorityQueue::list_locate(size_t position)
	{
		Node* cursor;
		cursor=head_ptr;

		assert(!is_empty());

		if(position>many_nodes)
			return NULL;

		for(size_t i=0; (i<position)&&(cursor->link!=NULL); ++i)
		{
			cursor=cursor->link;
		}

		return cursor;
	}


	void PriorityQueue::clear()
	{
		Node* cursor;
		cursor=head_ptr;

		assert(!is_empty());

		while (cursor!=NULL)
		{
			head_ptr=head_ptr->link;
			delete cursor;
			cursor=cursor->link;
		}
	}
