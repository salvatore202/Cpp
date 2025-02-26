/*
 * queue_ca.h
 *
 *  Created on: 26 set 2023
 *      Author: salva
 */

#ifndef QUEUE_CA_H_
#define QUEUE_CA_H_

#include<cstdlib>

template <class item>
class queue_array
{

public:

	//TYPEDEF
	typedef std::size_t size_type;
	static const size_type CAPACITY=30;

	//CONSTRUCTOR
	queue_array();

	//MODIFICATION MEMEBER FUNCTION
	void pop();
	void push(const item& entry);

	//CONSTANT MEMBER FUNCTION
	size_type size() const {return count;}
	bool empty() const {return (count==0);}
	item front() const;

private:

	item data[CAPACITY];
	size_type first;
	size_type last;
	size_type count;

	//HELPER MEMBER FUNCTION
	size_type next_index(size_type i) const {return (i+1)% CAPACITY;}
};

#include "queue_ca_implementation.template"

#endif /* QUEUE_CA_H_ */
