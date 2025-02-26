
/*
 * figure.h
 *
 *  Created on: 16 mar 2024
 *      Author: salva
 */

#ifndef FIGURE_H_
#define FIGURE_H_

namespace figura
{

typedef double value_type;

	class cerchio
	{

	public:
		//Costruttore
		cerchio(value_type x_c,value_type y_c,value_type radius_c);
		cerchio();

		//Funzioni setter
		void set_centre(value_type x_c,value_type y_c){x=x_c; y=y_c;};
		void set_radius(value_type raggio){radius=raggio;};

		//Funzioni getter
		value_type get_x() const{return x;}
		value_type get_y() const{return y;}
		value_type get_radius() const{return radius;}
		value_type get_area() const;

	private:
		//Coordinate Centro
		value_type x,y;

		//Raggio
		value_type radius;
	};


	class cono
	{

	public:
		//Costruttore
		cono(value_type x,value_type y,value_type radius,value_type height);
		cono();

		//Funzioni setter
		void set_centre(value_type x_c, value_type y_c){x=x_c; y=y_c;}
		void set_radius(value_type raggio){radius=raggio;}
		void set_height(value_type altezza){height=altezza;}

		//Funzioni getter
		value_type get_x() const {return x;}
		value_type get_y() const {return y;}
		value_type get_radius() const {return radius;}
		value_type get_height() const {return height;}
		//value_type get_area() const;
		value_type get_volume() const;

	private:
		//Raggio e Altezza
		value_type radius, height;

		//Coordinate centro
		value_type x,y;
	};


	class punto
	{

	public:
		//Costruttore
		punto(value_type x, value_type y);
		punto();

		//Funzioni setter
		void setpoint(value_type xp,value_type yp){x=xp; y=yp;}

		//Funzioni getter
		value_type get_x() {return x;}
		value_type get_y() {return y;}

		//Operatore
		void operator=(const figura::cono& source);

	private:
		//Coordinate
		value_type x,y;
	};

}



#endif /* FIGURE_H_ */
