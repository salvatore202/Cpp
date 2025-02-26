/*
 * pqueue_main.cpp
 *
 *  Created on: 6 ott 2023
 *      Author: salva
 */


#include "pqueue1.h"
#include <cctype>
#include <iostream>

using namespace std;

PriorityQueue coda1;
PriorityQueue coda2;

void print_menu()
{
	cout<<"\n\n TEST CODA CON PRIORITA  "<<endl<<endl;
	cout<<" a - Indice\n";
	cout<<" b - Clear\n";
	cout<<" c - Insert\n";
	cout<<" d - Get_front\n";
	cout<<" e - Remove\n";
	cout<<" f - Copy\n";
	cout<<" g - Size\n";
	cout<<" h - View_all\n";
	cout<<" i - Quit\n";
}

char scelta()
{
	char comando;

	cout<<" Inserisci una scelta : \n";
	cin>>comando;

	return comando;
}


void Indice()
{
	std::size_t posizione;

	cout<<"\n\n Scrivi la posizione dell'elemento che vuoi visualizzare : ";
	cin>>posizione;

	coda1.list_locate(posizione);

}

void Remove()
{
	int removal=0;

	cout<<"\n\n Scrivi il valore da eliminare dalla coda\n N.B. tutti gli elementi precedenti all'argomento specificato verranno rimossi\n Scelta : ";
	cin>>removal;

	coda1.remove_pop(removal);
}

void Copy ()
{
	PriorityQueue new_queue;
	cout<<"\n Nuova coda = Prima coda...";
	new_queue.insert(8, 8);
	coda1=new_queue;
}

void Size()
{
	int scelta;

	cout<<"\n\n Indicare di quale coda si vuole mostrare la dimensione\n 1 - coda1\n 2 - coda2";
	cin>>scelta;

	switch(scelta)
	{
	case 1: cout<<endl<<coda1.size();
	break;

	case 2: cout<<endl<<coda2.size();
	break;
	}
}


void View_all()
{
	Node* cursor;
	cursor=coda1.list_locate(0);

	while(cursor!=NULL)
	{
		cout<<cursor->data<<endl;
		cursor=cursor->link;
	}
	cout<<endl<<endl;

	cursor=coda2.list_locate(0);

		while(cursor!=NULL)
		{
			cout<<cursor->data<<endl;
			cursor=cursor->link;
		}
}

void Insert()
{
	unsigned int priority;
	int entry;
	int scelta;

	cout<<"\n\n Inserisci il valore da aggiungere alla coda : ";
	cin>>entry;

	cout<<"\n Specificare la priorita' : ";
	cin>>priority;

	cout<<"\n In che coda inserire ? :\n";
	cin>>scelta;

	switch(scelta)
	{
	case 1: coda1.insert(entry, priority);
	break;

	case 2: coda2.insert(entry,priority);
	break;
	}

}

bool is_wrong(const char& choice)
{
	if( (choice!='a')&&(choice!='b')&&(choice!='c')&&(choice!='d')&&(choice!='e')&&(choice!='f')&&(choice!='g')&&(choice!='h')&&(choice!='i'))
		return true;
	return false;
}

int main()
{

	char choise;

	    do
	    {
	        print_menu();
	        choise = scelta();

	        if(is_wrong(choise))
	        	cout<<"\n\n   HAI INSERITO UN COMANDO NON VALIDO  ";

	        switch(choise)
	        {
	        case 'a': Indice();
	            break;

	        case 'b':coda1.clear();
	            break;

	        case 'c': Insert();
	                break;

	        case 'd': coda1.get_front();
	                break;

	        case 'e': Remove();
	                break;
	        case 'f':Copy();
	            break;

	        case 'g': cout<<coda1.size()<<endl;
	                break;
	        case 'h': View_all();
	            break;
	        case 'i': cout<<"fine";
	                break;
	        }
	    }
	    while((choise!='i'));

}

