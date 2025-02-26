/*
 * termine.cxx
 *
 *  Created on: 9 ott 2023
 *      Author: salva
 */




#include "termine.h"
#include <iostream>
#include <cassert>
#include <cmath>



void linked_list::list_head_remove(linked_list::termine*& head_ptr)
{

	linked_list::termine* remove_ptr;

	remove_ptr = head_ptr;
	head_ptr = head_ptr->link();  //head_ptr punta all'elemento successivo della lista
	delete remove_ptr;
}
//PRECONDITION: "head_ptr" deve essere un nodo
//POSTCONDITION: un nodo della lista viene rimosso




void linked_list::list_head_insert(linked_list::termine*& head_ptr, const linked_list::termine::item& coefficient, const unsigned int exponent)
{
	head_ptr= new linked_list::termine(coefficient,exponent, head_ptr);
}
//PRECONDITION: head_ptr è il puntatore alla testa della lista e entry è un valore "item"
//POSTCONDITION:: viene inserito un nuovo nodo in testa




linked_list::termine* linked_list::list_search(linked_list::termine* head_ptr, const linked_list::termine::item& target_coef, const unsigned int target_exp)
{

	linked_list::termine* cursor;

	for( cursor = head_ptr; cursor!=NULL; cursor=cursor->link())
		if ( target_coef == cursor->coefficient() && target_exp==cursor->exponent())
			return cursor;
	return NULL;
}
//PRECONDITION: head_ptr è il puntatore alla testa della lista e target è l'elemento che si desidera cercare
//POSTCONDITION: ritorna un puntatore "cursor" al primo nodo che contiene l'elemento cercato



std::size_t linked_list::list_length(const linked_list::termine* head_ptr)
{

	const linked_list::termine* cursor;
	std::size_t answer=0;

	for(cursor=head_ptr; cursor!=NULL; cursor=cursor->link())
		++answer;

	return answer;
}
//PRECONDITION: head_ptr è il puntatore alla testa della lista
//POSTCONDITION: ritorna il numero di nodi della lista



void linked_list::list_clear(linked_list::termine*& head_ptr)
{

	while(head_ptr!=NULL)
		linked_list::list_head_remove(head_ptr);

}
//PRECONDITION: head_ptr è il puntatore alla testa della lista
//POSTCONDITION: la lista viene svuotata



void linked_list::list_print_all(const linked_list::termine* head_ptr)
{
	const linked_list::termine* cursor;
	for(cursor=head_ptr; cursor!=NULL; cursor=cursor->link())
	{
		if(cursor->coefficient()<0 && cursor==head_ptr)
			std::cout<<"-";
		else if(cursor->coefficient()<0 && cursor!=head_ptr)
			std::cout<<" - ";
		else if(cursor->coefficient()>0 && cursor!=head_ptr)
			std::cout<<" + ";

		std::cout<<" "<<fabs(cursor->coefficient())<<"x^"<<fabs(cursor->exponent())<<std::endl;
	}

}
//PRECONDITION: head_ptr è il puntatore alla testa della lista
//POSTCINDITION: lla lista viene stampata




void linked_list::list_insert(linked_list::termine* previous_ptr, const termine::item& coefficient, const unsigned int exponent)
{
	linked_list::termine* insert_ptr;

	insert_ptr = new linked_list::termine;
	insert_ptr->set_coefficient(coefficient);
	insert_ptr->set_exponent(exponent);
	insert_ptr->set_link(previous_ptr->link());

	previous_ptr->set_link(insert_ptr);
}
//POSTCONDITION: inserisce un nodo NON in testa



void linked_list::list_tail_insert(linked_list::termine*& head_ptr, linked_list::termine*& tail_ptr, const linked_list::termine::item& coefficient, const unsigned int& exponent)
{
	if(linked_list::list_length(head_ptr)==0)
	{
		linked_list::list_head_insert(head_ptr, coefficient, exponent);
		tail_ptr=head_ptr;
	}
	else
	{
		linked_list::list_insert(tail_ptr, coefficient, exponent);
		tail_ptr=tail_ptr->link();
	}
}
//PRECONDITION: head_ptr deve puntare alla testa e tail_ptr deve puntare alla coda della lista
//POSTCONDITION: inserisce in coda un nodo alla lista



void linked_list::list_copy(const linked_list::termine*source_ptr, linked_list::termine*& head_ptr, linked_list::termine*& tail_ptr)
{
	head_ptr=NULL;
	tail_ptr=NULL;

	if(source_ptr==NULL)
		return;

	linked_list::list_head_insert(head_ptr, source_ptr->coefficient(), source_ptr->exponent());
	tail_ptr=head_ptr;

	source_ptr=source_ptr->link();

	while(source_ptr != NULL)
	{
		linked_list::list_insert(tail_ptr, source_ptr->coefficient(), source_ptr->exponent());
		tail_ptr=tail_ptr->link();
		source_ptr=source_ptr->link();
	}
}



linked_list::termine* linked_list::list_locate(linked_list::termine* head_ptr, std::size_t position)
{
	linked_list::termine* cursor;
	std::size_t i;

	assert(0<position);

	cursor=head_ptr;
	for(i=1; (i<position) && (cursor!=NULL); ++i)
		cursor=cursor->link();

	return cursor;
}
//PRECONDITION: head_ptr è il puntatore alla testa della lista e position è >0
//POSTCONDITION: ritorna un puntatore ad un nodo nella posizione ( position ) della lista





