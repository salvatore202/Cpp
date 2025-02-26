/*
 * ClasseComplesso.h
 *
 *  Created on: 3 apr 2023
 *      Author: salva
 */

#ifndef NAMESPACE_H_
#define NAMESPACE_H_


//CLASSI  COMPLESSO-TERMINALE

namespace ComplexProject
{

	//TIPO SIZE_TYPE

	typedef double size_type;   //size_type = double



	//CLASSE COMPLESSO

	class Complesso
	{

	//INTERFACCIA

		public:


			size_type x=realstart, y=imaginarystart;


			//Costruttore

			Complesso(size_type reale, size_type immaginaria);
			Complesso();



			//Metodi

			void Stampa();
			Complesso Somma( const Complesso &altro_complesso);
			Complesso Differenza( const Complesso &altro_complesso);



	//IMPLEMENTAZIONE

		private:

			size_type realstart=0.0;
			size_type imaginarystart=0.0;

	};




	//CLASSE TERMINALE

	class terminale
	{

	public:

		// INSERIMENTO COMPLESSI

		void inserimento(Complesso &a, Complesso &b);


		//STAMPA FINALE

		void visualizzazione(Complesso &a, Complesso &b);

	};


}


#endif /* NAMESPACE_H_ */
