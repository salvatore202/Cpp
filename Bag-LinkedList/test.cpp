/*
 * test.cpp
 *
 *  Created on: 20 set 2023
 *      Author: salva
 */


#include <iostream>
#include "node.h"
#include "bag.h"

using namespace BAG;

int main()
{
	int x,y,z;
	std::string prima, seconda, terza;
	bag<int> integer_bag;
	bag<std::string> string_bag;
	char scelta, scelta_int;

	cout<<"\n\n x = ";
	cin>>x;

	cout<<"\n y = ";
	cin>>y;

	cout<<"\n z = ";
	cin>>z;

	cout<<"\n prima parola = ";
	cin>>prima;

	cout<<"\n seconda parola = ";
	cin>>seconda;

	cout<<"\n terza parola = ";
	cin>>terza;

	integer_bag.insert(x);
	integer_bag.insert(y);
	integer_bag.insert(z);

	string_bag.insert(prima);
	string_bag.insert(seconda);
	string_bag.insert(terza);

	cout<<"\n\n INSERT - SHOW_ITEMS ";
	cout<<"\n\n Nella bag di interi sono presenti "<<integer_bag.size()<<" elementi \n";
	integer_bag.show_items();

	cout<<"\n Nella bag di stringhe sono presenti "<<string_bag.size()<<" elementi \n";
	string_bag.show_items();

	cout<<"\n\n Ora verra' estratto un elemento a caso dalla bag di interi...  ...";
	cout<<integer_bag.grab();

	cout<<"\n\n Ora verra' estratto un elemento a caso dalla bag di stringhe... ...";
	cout<<string_bag.grab();


	cout<<"\n\n Nella bag e' presente un elemento duplicato ?  ( scrivere S per si oppure N per no) : ";
	cin>>scelta;

	if(scelta=='S')
	{
		cout<<"\n Indica l'elemento duplicato : ";
		cin>>scelta_int;

		if(scelta_int=='x')
			integer_bag.erase_one(x);

		else if(scelta_int=='y')
			integer_bag.erase_one(y);

		else if(scelta_int=='z')
			integer_bag.erase_one(z);

		else
			cout<<"\n Non e' presente nessuna copia di questo elemento";
	}


	cout<<"\n Le copie in eccesso dell' elemento selezionato sono state rimosse ";
	cout<<"\n\n Nella bag di interi sono presenti "<<integer_bag.size()<<" elementi \n";
	integer_bag.show_items();

}

