/*
 * Test.cpp
 *
 *  Created on: 20 mar 2024
 *      Author: salva
 */


#include <iostream>
#include "stack2.h"
#include "queue.h"


int main()
{

	typedef char value_type;

	queue<value_type> q;  //Coda
	stack<value_type> s;  //Stack
	value_type lettera;
	queue<value_type>::size_type differenze = 0; // Differenze tra Coda e Stack


	std::cout << "Scrivi una parola e ti diro' se e' palindroma  " << std::endl;


	//Ciclo di Inserimento
	while (std::cin.peek( ) != '\n')
	{
		std::cin >> lettera;
		if (isalpha(lettera))
		{
			q.push(toupper(lettera));
			s.push(toupper(lettera));
		}
	}


	//Verifica della stringa
	while ((!q.empty( )) && (!s.empty( ))) //Verifichiamo fin quando la coda e lo stack non sono vuoti
	{
		if (q.front( ) != s.top( ))
			++differenze;

		q.pop( );
		s.pop( );
	}


	if (differenze == 0)
		std::cout << " La stringa e' palindroma " << std::endl;

	else  //C'è almeno una differenza
		std::cout << " La stringa NON e' palindroma " << std::endl;


	return EXIT_SUCCESS;

}

