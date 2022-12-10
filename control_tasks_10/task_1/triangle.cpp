#include "Triangle.h"

#include <string>
#include <iostream>

using namespace std;

Triangle::Triangle(Dot* dot1, Dot* dot2, Dot* dot3)
{
	Triangle::set_dot_1(dot1);
	Triangle::set_dot_2(dot2);
	Triangle::set_dot_3(dot3);
}

void Triangle::set_dot_1(Dot* d_1)
{
	dot_1 = d_1;
}

void Triangle::set_dot_2(Dot* d_2)
{
	dot_2 = d_2;
}

void Triangle::set_dot_3(Dot* d_3)
{
	dot_3 = d_3;
}

Dot Triangle::get_dot_1()
{
	return *dot_1;
}

Dot Triangle::get_dot_2()
{
	return *dot_2;
}

Dot Triangle::get_dot_3()
{
	return *dot_3;
}

void Triangle::show_sides()
{
	cout << "First side: " << dot_1->distance_to_dot(*dot_2) << endl;
	cout << "Second side: " << dot_2->distance_to_dot(*dot_3) << endl;
	cout << "Third side: " << dot_3->distance_to_dot(*dot_1) << endl;
}

double Triangle::perimeter()
{
	return dot_1->distance_to_dot(*dot_2) + dot_2->distance_to_dot(*dot_3) + dot_3->distance_to_dot(*dot_1);
}

double Triangle::square()
{
	double p = perimeter() / 2;

	double s_1 = dot_1->distance_to_dot(*dot_2);
	double s_2 = dot_2->distance_to_dot(*dot_3);
	double s_3 = dot_3->distance_to_dot(*dot_1);

	return sqrt(p * (p - s_1) * (p - s_2) * (p - s_3));
}