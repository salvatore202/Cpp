/*
 * poly1.cxx
 *
 *  Created on: 9 ott 2023
 *      Author: salva
 */

#include "poly1.h"
#include "termine.h"


namespace polinomi
{
	poly::poly()
	{
		head_ptr=NULL;
		current_degree=0;

	}

	poly::poly(const poly& source)
	{
		head_ptr=source.head_ptr;
		current_degree=source.degree();
	}

	void poly::assign_coef(double coefficient, unsigned int exponent)
	{
		if(head_ptr==NULL)
			list_head_insert(head_ptr, coefficient, exponent);
	}


	void poly::add_to_coef(double amount, unsigned int exponent)
	{

	}
}

