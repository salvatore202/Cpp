/*
 * bag.h
 *
 *  Created on: 19 set 2023
 *      Author: salva
 */

#ifndef BAG_H_
#define BAG_H_

#include <cstdlib>
#include "node.h"

namespace BAG
{
	template <class item>
	class bag
	{

	public:

		//TYPEDEFS

		typedef item value_type;
		typedef std::size_t size_type;
		//
		static const size_type DEFAULT_CAPACITY	= 30;


		//CONSTRUCTORS and DESTUCTORS

		bag();
		bag(const bag<item>& source); //copy constructor
		~bag();  //destructor


		//MODIFICATION MEMBER FUNCTION

		//void reserve(size_type new_capacity);
		bool erase_one(const item& target);
		size_type erase(const item& target);
		void insert(const item& entry);
		void operator +=( const bag& addend);
		void operator =(const bag& source);  //overload


		//CONSTANT MEMBER FUNCTION

		size_type size() const {return many_nodes;}
		size_type count(const item& target) const;
		value_type grab() const;
		void show_items() const;


	private:

		linked_list::node<item>* head_ptr; //Puntatore alla testa della lista
		size_type many_nodes;  //Numero di nodi della lista

	};


	//NONMEMBER FUNCTION

	template <class item>
	BAG::bag<item> operator+(const BAG::bag<item>& b1, const BAG::bag<item>& b2);

}

#include "bag_implementation.template"

#endif /* BAG_H_ */
