
/*
 * Figure_implementation.cxx
 *
 *  Created on: 16 mar 2024
 *      Author: salva
 */



#include "figure.h"

namespace figura
{

value_type cerchio::get_area() const
{
	value_type Area;
	Area= 3.1415*cerchio::radius*cerchio::radius;

	return Area;
}

value_type cono::get_volume() const
{
	value_type Volume;
	Volume=(1/3)*(3.1415)*cono::radius*cono::radius*cono::height;

	return Volume;
}

void punto::operator =(const cono& source)
{
	punto::x=source.get_x();
	punto::y=source.get_y();
}

//Costruttori

punto::punto(value_type x, value_type y)
{
	punto::setpoint(x, y);
}

punto::punto()
{
	punto::setpoint(0, 0);
}

cono::cono(value_type x,value_type y,value_type radius,value_type height)
{
	cono::set_centre(x, y);
	cono::set_radius(radius);
	cono::set_height(height);
}

cono::cono()
{
	cono::set_centre(0, 0);
	cono::set_radius(0);
	cono::set_height(0);
}


cerchio::cerchio(value_type x_c,value_type y_c,value_type radius_c)
{
	cerchio::set_centre(x_c, y_c);
	cerchio::set_radius(radius_c);
}

cerchio::cerchio()
{
	cerchio::set_centre(0, 0);
	cerchio::set_radius(0);
}


}
