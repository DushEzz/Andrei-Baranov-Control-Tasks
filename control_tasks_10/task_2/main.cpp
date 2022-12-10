#include <iostream>
#include "Triangle.h"

using namespace std;

int main()
{
    Triangle* tr = new Triangle();

    tr->show_sides();

    cout << "Perimeter: " << tr->perimeter() << endl;
    cout << "Square: " << tr->square() << endl;
    
    delete tr;
    
    return 0;
}
