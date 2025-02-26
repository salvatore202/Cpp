/*
 * ComplessoMF.cpp
 *
 *  Created on: 3 apr 2023
 *      Author: salva
 */


#include <iostream>
#include "Namespace.h"

using namespace ComplexProject;



//COSTRUTTORI

Complesso::Complesso(size_type reale, size_type immaginaria)
{

};

Complesso::Complesso()  //Vuoto
{

};



//STAMPA NUMERO

void Complesso::Stampa()
{
	std::cout<<"( "<<x<<" , "<<y<<" )";
}


//SOMMA

Complesso Complesso::Somma( const Complesso &altro_complesso)
{
	Complesso somma = Complesso( 0.0, 0.0 );

	somma.x = x + altro_complesso.x;
	somma.y= y + altro_complesso.y;

	return somma;
}


//DIFFERENZA

Complesso Complesso::Differenza ( const Complesso &altro_complesso)
{

	Complesso differenza = Complesso( 0.0 , 0.0 );

	differenza.x = x - altro_complesso.x;
	differenza.y = y - altro_complesso.y;

	return differenza;
}


//INSERIMENTO

void terminale::inserimento(Complesso &a, Complesso &b)
{


	//Scelte reali e immaginarie per a e per b

	size_type scelta_reale[2], scelta_immaginaria[2];


		//CIN scelte reali e immaginarie

		for(int i=0;i<2;i++)
		{
			std::cout<<"\n\n\n   Scrivi la parte reale del complesso "<<i+1<<":  ";
			std::cin>>scelta_reale[i];
			std::cout<<"\n\n   Scrivi la parte immaginaria del complesso "<<i+1<<" : ";
			std::cin>>scelta_immaginaria[i];
		}


		//ASSEGNAZIONE

		for(int i=0;i<2;i++)
		{


			if(i==0)   // INSERISCI IN A
			{
				a.x=scelta_reale[i];
				a.y=scelta_immaginaria[i];
			}



			else	   //INSERISCI IN B
			{
				b.x=scelta_reale[i];
				b.y=scelta_immaginaria[i];
			}


		}

}


//STAMPA FINALE

void terminale::visualizzazione( Complesso &a, Complesso &b)
{

		using namespace std;


		//STAMPA A E B

		cout<<"\n\n   a = ";
		a.Stampa();
		cout<<"   ,   b = ";
		b.Stampa();


		// STAMPA SOMMA

		cout<<"\n\n   Somma :  ";
		a.Stampa();
		cout<<" + ";
		b.Stampa();
		cout<<" = ";
		a.Somma(b).Stampa();


		//STAMPA DIFFERENZA

		cout<<"\n\n   Differenza: ";
		a.Stampa();
		cout<<" - ";
		b.Stampa();
		cout<<" = ";
		a.Differenza(b).Stampa();


}




