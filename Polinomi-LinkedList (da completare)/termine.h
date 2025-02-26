/*
 * termine.h
 *
 *  Created on: 9 ott 2023
 *      Author: salva
 */

#ifndef TERMINE_H_
#define TERMINE_H_

#include <cstdlib>

namespace linked_list
{
	//NODE
	//template <class item>
	class termine
	{
	public:

		//TYPEDEF
		typedef double item;

		//CONSTRUCTOR
		termine(const item& init_coefficient=item(), const unsigned int& init_exponent =int(), termine*init_link=NULL)
		{coefficient_field= init_coefficient; exponent_field=init_exponent; link_field=init_link;}


		//MODIFICATION MEMBER FUNCTION
		termine* link(){return link_field;}
		void set_coefficient (const item& new_coefficient) {coefficient_field = new_coefficient;}
		void set_exponent( const unsigned int& new_exponent) {exponent_field = new_exponent;}
		void set_link( termine* new_link) {link_field = new_link; }


		//CONST MEMBER FUNCTION
		const item& coefficient() const {return coefficient_field;}
		const unsigned int& exponent()const {return exponent_field;}
		const termine* link() const {return link_field;}


	private:
		item coefficient_field;
		unsigned int exponent_field;
		termine* link_field;
	};



	//LINKED LIST TOOLKIT-WITH TEMPLATE
	std::size_t list_length(const termine* head_ptr);

	void list_head_insert(termine*& head_ptr, const termine::item& coefficient, const unsigned int exponent);

	void list_insert(termine* previous_ptr, const termine::item& coefficient, const unsigned int exponent);

	void list_tail_insert(termine*& head_ptr, termine*& tail_ptr, const termine::item& coefficient, const unsigned int& exponent);

	termine* list_search(termine* head_ptr, const termine::item& target_coef, const unsigned int target_exp);

	void list_head_remove(termine*& head_ptr);

	void list_clear(termine*& head_ptr);

	void list_copy(const termine* source_ptr, termine*& head_ptr, termine*& tail_ptr);

	void list_print_all(const termine* head_ptr);

	termine* list_locate(termine* head_ptr, std::size_t position);
}



#endif /* TERMINE_H_ */
