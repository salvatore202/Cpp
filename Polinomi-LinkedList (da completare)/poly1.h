/*
 * poly1.h
 *
 *  Created on: 9 ott 2023
 *      Author: salva
 */

#ifndef POLY1_H_
#define POLY1_H_

#include "termine.h"

namespace polinomi
{


	class poly
	{

	public:

		//CONSTRUCTOR AND DESTRUCTOR
		poly();
		poly(const poly& source);
		~poly();

		// MODIFICATION MEMBER FUNCTIONS
		void add_to_coef(double amount, unsigned int exponent);
		void assign_coef(double coefficient, unsigned int exponent);
		void clear( );

		// CONSTANT MEMBER FUNCTIONS
		double coefficient(unsigned int exponent) const;
		unsigned int degree( ) const { return current_degree;}
		poly derivative( ) const;
		double eval(double x) const;
		unsigned int next_term(unsigned int e) const;
		unsigned int previous_term(unsigned int e) const;

		// CONSTANT OPERATORS
		double operator( ) (double x) const { return eval(x); }

	private:

		unsigned int current_degree;
		linked_list::termine* head_ptr;
	};
}



#endif /* POLY1_H_ */
