// VectorExample.cpp : Defines the entry point for the console application.
//

#include <iostream>

class Vector2D
{
private:
	double x;
	double y;
public:
	Vector2D(double x, double y) : x(x), y(y) {}

	Vector2D(const Vector2D& other) : x(other.x), y(other.y) {}

	double getX() const
	{
		return x;
	}

	double getY() const
	{
		return y;
	}
};

Vector2D& operator+(const Vector2D& a, const Vector2D& b)
{
	Vector2D res(a.getX() + b.getX(), a.getY() + b.getY());
	return res;
}

Vector2D& operator+(const Vector2D& a, const double b)
{
	Vector2D res(a.getX() + b, a.getY());
	return res;
}

Vector2D& operator+=(Vector2D& a, const double b)
{
	Vector2D res(a.getX() + b, a.getY());
	return a;
}

int main()
{
	Vector2D a(1.0, 2.0);
	Vector2D b(5.0, 6.5);
	Vector2D c(100, 7895);
	std::cout << (a + 9450).getX() << '\n';
	std::cout << (a + b).getX() << '\n';
    return 0;
}

