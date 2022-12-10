#pragma once

#include "dot.h"

class Triangle
{
	public:
		Triangle(Dot*, Dot*, Dot*);

		void set_dot_1(Dot*);
		Dot get_dot_1();

		void set_dot_2(Dot*);
		Dot get_dot_2();

		void set_dot_3(Dot*);
		Dot get_dot_3();

		void show_sides();

		double perimeter();
		double square();

	private:
		Dot* dot_1;
		Dot* dot_2;
		Dot* dot_3;
};
