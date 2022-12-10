#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

class Point
{
	private:
		int x, y;
	public:
		Point() : x(0), y(0) { }
		Point(int xc, int yc)
		{
			x = xc;
			y = yc;
		}

		double distance()
		{
			return sqrt(x * x + y * y);
		}

		bool operator< (Point&);

		friend std::ostream& operator<< (std::ostream& out, const Point& point);
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
	out << "(" << point.x << ", " << point.y << ")";
	
	return out;
}

bool Point::operator< (Point& p_2)
{
	double d_1 = this->distance();
	double d_2 = p_2.distance();

	if (d_1 < d_2) return true;
	return false;
}

int main()
{
	std::vector<Point> v;

	v.push_back(Point(1, 2));
	v.push_back(Point(10, 12));
	v.push_back(Point(21, 7));
	v.push_back(Point(4, 8));

	std::sort(v.begin(), v.end());

	for (auto& point : v)
		std::cout << point << "\n";

	return 0;
}
