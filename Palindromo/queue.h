/*
 * queue.h
 *
 *  Created on: 20 mar 2024
 *      Author: salva
 */




#ifndef QUEUE_H_
#define QUEUE_H_

#include "node2.h"

template <class item>
class queue
{

public:

	//TYPEDEF
	typedef std::size_t size_type;

	//CONSTRUCTOR
	queue();
	queue( const queue<item>& source);
	~queue();

	//MODIFICATION MEMEBER FUNCTION
	void pop();
	void push(const item& entry);
	void operator =( const queue<item>& source);

	//CONSTANT MEMBER FUNCTION
	size_type size() const {return count;}
	bool empty() const {return (count==0);}
	item front() const;

private:

	linked_list::node<item>* front_ptr;
	linked_list::node<item>* rear_ptr;
	size_type count;
};

#include "queue_implementation.template"


#endif /* QUEUE_H_ */
