#include<cmath>
#include <iostream>

using namespace std;

class Triangle
{
    public:
        class wrong_sides
        {
            public:
                double wa, wb, wc;

                wrong_sides(double ws_1, double ws_2, double ws_3)
                {
                    wa = ws_1;
                    wb = ws_2;
                    wc = ws_3;
                }
        };

        Triangle(double a, double b, double c)
        {
            if (a + b <= c) 
                throw wrong_sides(a, b, c);

            if (a + c <= b)
                throw wrong_sides(a, c, b);

            if (b + c <= a)
                throw wrong_sides(b, c, a);

            Triangle::set_a(a);
            Triangle::set_b(b);
            Triangle::set_c(c);
        }

        void set_a(double a)
        {
            Triangle::a = a;
        }

        double get_a()
        {
            return Triangle::a;
        }

        void set_b(double b)
        {
            Triangle::b = b;
        }

        double get_b()
        {
            return Triangle::b;
        }

        void set_c(double c)
        {
            Triangle::c = c;
        }

        double get_c()
        {
            return Triangle::c;
        }

        double square()
        {
            double p = (a + b + c) / 2;

            return sqrt(p * (p - a) * (p - b) * (p - c));
        }
    private:
        double a, b, c;
};

int main()
{
    double a, b, c;

    cout << "Input first side: "; cin >> a;
    cout << "Input second side: "; cin >> b;
    cout << "Input third side: "; cin >> c;

    try
    {
        Triangle tr_1 = Triangle(a, b, c);

        cout << "Result: " << tr_1.square();
    }
    catch (Triangle::wrong_sides& wr)
    {
        cout << "Error. Summary of sides a=" << wr.wa << " and b=" << wr.wb << " is equal or less than the value of the third side c=" << wr.wc;
    }
}