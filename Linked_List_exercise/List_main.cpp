/*
 * List_main.cpp
 *
 *  Created on: 8 mag 2023
 *      Author: salva
 */

#include <iostream>
#include "List_structure.h"

using namespace linked_list;
using namespace std;

int main()
{
	 std::string entry_string;//Valore da inserire in ogni nodo
	 int entry_int;


	linked_list::node<std::string>*head_ptr=NULL;  //Puntatore alla TESTA della lista
	linked_list::node<std::string>* tail_ptr;		 //Puntatore alla CODA della lista

	linked_list::node<int>*head_ptr_int=NULL;  //Puntatore alla TESTA della lista
	linked_list::node<int>* tail_ptr_int;		 //Puntatore alla CODA della lista


	char answer;	//variabile di inserimento per il do-while


	//INSERIMENTO
	do
	{

		//Inserimento dato
		cout<<"digita una parola  "<<endl;
		cin>>entry_string;


		linked_list::list_tail_insert(head_ptr, tail_ptr, entry_string);	//Aggiunge un nuovo nodo alla lista

		//Richiesta di ripetizione del ciclo
		cout<<"Vuoi continuare ? ( s per si ,  n per no) "<<endl;
		cin>>answer;


	}while(answer!='n'); //Condizione di ripetizione


	cout<<"\n\n";


	do
	{

		//Inserimento dato
		cout<<"digita una intero "<<endl;
		cin>>entry_int;


		linked_list::list_tail_insert(head_ptr_int, tail_ptr_int, entry_int);	//Aggiunge un nuovo nodo alla lista

		//Richiesta di ripetizione del ciclo
		cout<<"Vuoi continuare ? ( s per si ,  n per no) "<<endl;
		cin>>answer;


	}while(answer!='n'); //Condizione di ripetizione


	//STAMPA STRING
	linked_list::list_print_all(head_ptr);

	cout<<"\n";

	//STAMPA INT
	linked_list::list_print_all(head_ptr_int);

}


