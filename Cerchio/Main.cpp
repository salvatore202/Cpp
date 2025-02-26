
#include <iostream>
#include <stdlib.h>
#include "figure.h"


namespace figura
{
	int main()
	{
		//Oggetti delle classi del file 'figure.h'
		punto P;
		cono CN;
		cerchio C;

		//Variabili di inserimento
		value_type ascissa;
		value_type ordinata;
		value_type raggio;
		value_type altezza;

		std::cout<<"\n\n Inserire le coordinate del punto\n x = ";
		std::cin>>ascissa;
		std::cout<<"\n y = ";
		std::cin>>ordinata;

		P.setpoint(ascissa,ordinata);

		std::cout<<"\n\n Inserire le coordinate del centro del cerchio\n x = ";
		std::cin>>ascissa;
		std::cout<<"\n y = ";
		std::cin>>ordinata;
		std::cout<<"\n Inserire il raggio  r = ";
		std::cin>>raggio;

		C.set_centre(ascissa,ordinata);
		C.set_radius(raggio);

		std::cout<<"\n\n Inserire le coordinate del cono\n x = ";
		std::cin>>ascissa;
		std::cout<<"\n y = ";
		std::cin>>ordinata;
		std::cout<<"\n Inserire il raggio di base r = ";
		std::cin>>raggio;
		std::cout<<"\n Inserire altezza h = ";
		std::cin>>altezza;

		CN.set_centre(ascissa,ordinata);
		CN.set_radius(raggio);
		CN.set_height(altezza);

		std::cout<<"\n\n\n      STAMPA DEI VALORI INSERITI E CALCOLATI \n\n";
		std::cout<<" Coordinate Punto:  x = "<<P.get_x()<<"  y = "<<P.get_y()<<std::endl;
		std::cout<<"\n Coordinate centro del Cerchio:  x = "<<C.get_x()<<"  y = "<<C.get_y()<<std::endl;
		std::cout<<" Raggio del Cerchio: r = "<<C.get_radius()<<std::endl;
		std::cout<<" Area del Cerchio: r = "<<C.get_area()<<std::endl;
		std::cout<<"\n Coordinate centro del Cono:  x = "<<CN.get_x()<<"  y = "<<CN.get_y()<<std::endl;
		std::cout<<" Raggio di base del Cono: r = "<<CN.get_radius()<<std::endl;
		std::cout<<" Altezza del Cono: h = "<<CN.get_height()<<std::endl;
		std::cout<<" Volume del Cono: V = "<<CN.get_volume()<<std::endl;


	
		system("PAUSE");
	}
}



