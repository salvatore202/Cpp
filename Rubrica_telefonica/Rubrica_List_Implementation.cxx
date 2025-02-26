/*
 * Rubrica_List_Implementation.cxx
 *
 *  Created on: 2 giu 2023
 *      Author: salva
 */

#include "Rubrica_List_Structure.h"
#include <iostream>

void rubrica::list_head_remove(rubrica::contatto*& head_ptr)
{

	rubrica::contatto* remove_ptr;

	remove_ptr = head_ptr;
	head_ptr = head_ptr->link();  //head_ptr punta all'elemento successivo della lista
	delete remove_ptr;
}
// PRECONDITION: "head_ptr" deve essere un nodo
// POSTCONDITION: un nodo della lista viene rimosso




void rubrica::list_head_insert(rubrica::contatto*& head_ptr, const std::string& new_name, const std::string& new_surname, const std::string& new_number)
{
	head_ptr = new rubrica::contatto;
	head_ptr->set_name(new_name);
	head_ptr->set_surname(new_surname);
	head_ptr->set_number(new_number);
}
// PRECONDITION: head_ptr è il puntatore alla testa della lista e entry è un valore double
// POSTCONDITION:: viene inserito un nuovo nodo in testa




const rubrica::contatto* rubrica::list_search(rubrica::contatto*head_ptr, const std::string& number_target)
{

	const rubrica::contatto* cursor;

	for( cursor = head_ptr; cursor!=NULL; cursor=cursor->link())
		if (number_target == cursor->Number())
			return cursor;
	return NULL;
}
//	PRECONDITION: head_ptr è il puntatore alla testa della lista e target è l'elemento che si desidera cercare
//	POSTCONDITION: ritorna un puntatore "cursor" al primo nodo che contiene l'elemento cercato




std::size_t rubrica::list_length(const rubrica::contatto* head_ptr)
{

	const rubrica::contatto* cursor;
	std::size_t answer=0;

	for(cursor=head_ptr; cursor!=NULL; cursor=cursor->link())
		++answer;

	return answer;
}
// PRECONDITION: head_ptr è il puntatore alla testa della lista
// POSTCONDITION: ritorna il numero di nodi della lista




void rubrica::list_clear(rubrica::contatto*& head_ptr)
{

	while(head_ptr!=NULL)
		rubrica::list_head_remove(head_ptr);

}
// PRECONDITION: head_ptr è il puntatore alla testa della lista
// POSTCONDITION: la lista viene svuotata




void rubrica::list_print_all(const rubrica::contatto* head_ptr)
{
	const rubrica::contatto* cursor;
	for(cursor=head_ptr; cursor!=NULL; cursor=cursor->link())
	{
		std::cout<<cursor->Name()<<std::endl;
		std::cout<<cursor->Surname()<<std::endl;
		std::cout<<cursor->Number()<<std::endl;
		std::cout<<"\n\n";
	}
}
// PRECONDITION: head_ptr è il puntatore alla testa della lista
// POSTCINDITION: lla lista viene stampata




void rubrica::list_insert(rubrica::contatto* previous_ptr, const std::string& new_name, const std::string& new_surname, const std::string& new_number)
{
	rubrica::contatto* insert_ptr;

	insert_ptr = new rubrica::contatto;
	insert_ptr->set_name(new_name);
	insert_ptr->set_surname(new_surname);
	insert_ptr->set_number(new_number);
	insert_ptr->set_link(previous_ptr->link());

	previous_ptr->set_link(insert_ptr);
}
//POSTCONDITION: inserisce un nodo NON in testa





void rubrica::list_tail_insert(rubrica::contatto*& head_ptr, rubrica::contatto*& tail_ptr,  const std::string& new_name, const std::string& new_surname, const std::string& new_number)
{
	if(rubrica::list_length(head_ptr)==0)
	{
		rubrica::list_head_insert(head_ptr, new_name, new_surname, new_number);
		tail_ptr=head_ptr;
	}
	else
	{
		rubrica::list_insert(tail_ptr, new_name, new_surname, new_number);
		tail_ptr=tail_ptr->link();
	}
}
//PRECONDITION: head_ptr deve puntare alla testa e tail_ptr deve puntare alla coda della lista
//POSTCONDITION: inserisce in coda un nodo alla lista






