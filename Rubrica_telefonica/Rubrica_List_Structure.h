/*
 * Linked_List_Structure.h
 *
 *  Created on: 26 mag 2023
 *      Author: salva
 */



//NOT COMPLETE



#ifndef RUBRICA_LIST_STRUCTURE_H_
#define RUBRICA_LIST_STRUCTURE_H_

#include <cstdlib>
#include <string>

namespace rubrica
{
	class contatto
	{
	public:


		//CONSTRUCTOR
		contatto(const std::string& init_number_data=std::string(),  const std::string& init_name_data = std::string(), const std::string& init_surname_data = std::string(), contatto*init_link=NULL)
		{
			number_field= init_number_data;
			name_field=init_name_data;
			surname_field= init_surname_data;
			link_field=init_link;
		}


		//MODIFICATION MEMBER FUNCTION
		contatto* link(){return link_field;}
		void set_number (const std::string& new_number) {number_field = new_number;}
		void set_name (const std::string& new_name) {name_field = new_name;}
		void set_surname (const std::string& new_surname) {surname_field = new_surname;}
		void set_link( contatto* new_link) {link_field = new_link; }


		//CONST MEMBER FUNCTION
		std::string Number() const {return number_field;}
		std::string Name()const {return name_field;};
		std::string Surname()const {return surname_field;};
		const contatto* link() const {return link_field;}


	private:
		std::string number_field;
		std::string name_field;
		std::string surname_field;
		contatto* link_field;
	};



	//LINKED LIST TOOLKIT-WITH TEMPLATE
	std::size_t list_length(const contatto* head_ptr);

	void list_head_insert(contatto*& head_ptr, const std::string& new_name, const std::string& new_surname, const std::string& new_number);

	void list_insert(contatto* previous_ptr, const std::string& new_name, const std::string& new_surname, const std::string& new_number);

	void list_tail_insert(contatto*& head_ptr, contatto*& tail_ptr,  const std::string& new_name,  const std::string& new_surname, const std::string& new_number);

	const contatto* list_search(contatto* head_ptr,  const std::string& number_target);

	void list_head_remove( contatto*& head_ptr);

	void list_clear(contatto*& head_ptr);

	void list_print_all(const contatto* head_ptr);

}
#endif /* RUBRICA_LIST_STRUCTURE_H_ */
