/*
 * Rubrica_Main.cpp
 *
 *  Created on: 1 giu 2023
 *      Author: salva
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Rubrica_List_Structure.h"

using namespace std;

int main()
{
	rubrica::contatto* head_ptr=NULL;  // Puntatore alla testa della lista
	rubrica::contatto* tail_ptr;  //Puntatore alla coda della lista

	std::string name_choice;  // Nome inserito
	std::string surname_choice;  // Cognome inserito
	std::string number_choice;  // Numero inserito


	char answer;// Variabile per la richiesta di ripetizione del do-while


	// INSERIMENTO
	do
	{
		// Richiesta dei dati

		cout<<"\n\n   Inserici un nuovo contatto  ";
		cout<<"\n\n Nome :  ";
		cin>>name_choice;
		cout<<"\n Cognome : ";
		cin>>surname_choice;
		cout<<"\n Numero : ";
		cin>>number_choice;

		// Inserimento dei dati

		rubrica::list_tail_insert(head_ptr, tail_ptr, name_choice, surname_choice, number_choice);


		// Richiesta di ripetizione

		cout<<"\n\n Premere + per inserire un nuovo contatto\n Premere S per terminare\n";
		cin>>answer;

	}
	while( answer != 'S'); // Condizione di ripetizione

	// STAMPA
	cout<<"\n\n  ECCO I TUOI CONTATTI\n\n";
	list_print_all(head_ptr);

	cout<<"\n\n"<<rubrica::list_length(head_ptr);
}
;


