/*
 * List_structure.h
 *
 *  Created on: 7 mag 2023
 *      Author: salva
 */

#ifndef LIST_STRUCTURE_H_
#define LIST_STRUCTURE_H_

#include<cstdlib>


namespace linked_list
{
	//NODE
	template <class item>
	class node
	{
	public:

		//TYPEDEF
		typedef item value_type;

		//CONSTRUCTOR
		node(const value_type& init_data=value_type(), node*init_link=NULL)
		{data_field= init_data; link_field=init_link;}


		//MODIFICATION MEMBER FUNCTION
		node* link(){return link_field;}
		void set_data (const value_type& new_data) {data_field = new_data;}
		void set_link( node* new_link) {link_field = new_link; }


		//CONST MEMBER FUNCTION
		value_type data() const {return data_field;}
		const node* link() const {return link_field;}


	private:
		value_type data_field;
		node* link_field;
	};



	//LINKED LIST TOOLKIT-WITH TEMPLATE
	template <class item>
	std::size_t list_length(const linked_list::node<item>* head_ptr);

	template <class item>
	void list_head_insert(linked_list::node<item>*& head_ptr, const item& entry);

	template <class item>
	void list_insert(linked_list::node<item>* previous_ptr, const item& entry);

	template <class item>
	void list_tail_insert(linked_list::node<item>*& head_ptr, linked_list::node<item>*& tail_ptr, const item& entry);

	template <class item>
	const linked_list::node<item>* list_search(linked_list::node<item>* head_ptr, const item& target);

	template  <class item>
	void list_head_remove( linked_list::node<item>*& head_ptr);

	template  <class item>
	void list_clear(linked_list::node<item>*& head_ptr);

	template  <class item>
	void list_print_all(const linked_list::node<item>* head_ptr);
}

#include "List_implementation.template"

#endif /* LIST_STRUCTURE_H_ */
