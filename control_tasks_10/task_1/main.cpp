#include <iostream>
#include "triangle.h"

using namespace std;

int main()
{
    Dot* dot_1 = new Dot(0, 0);
    Dot* dot_2 = new Dot(1, 4);
    Dot* dot_3 = new Dot(0, 3);

    Triangle* tr = new Triangle(dot_1, dot_2, dot_3);

    tr->show_sides();

    cout << "Perimeter: " << tr->perimeter() << endl;
    cout << "Square: " << tr->square() << endl;

    delete tr;

    return 0;
}