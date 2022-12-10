#pragma once

class Dot
{
	private:
		double x;
		double y;
	public:
		Dot();
		Dot(double x, double y);

		double distance_to_dot(Dot point);
};
