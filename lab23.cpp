#define _USE_MATH_DEFINES ;
#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber
{
public:
	double real;
	double imag;
	ComplexNumber(double, double);
	ComplexNumber operator+(const ComplexNumber &);
	ComplexNumber operator-(const ComplexNumber &);
	ComplexNumber operator*(const ComplexNumber &);
	ComplexNumber operator/(const ComplexNumber &);
	bool operator==(const ComplexNumber &);
	double abs();
	double angle();
};

ComplexNumber::ComplexNumber(double x = 0, double y = 0)
{
	real = x;
	imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c)
{
	return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c)
{
	return ComplexNumber(real - c.real, imag - c.imag);
}

// Write your code here

ComplexNumber operator+(const double &a, const ComplexNumber &b)
{
	return ComplexNumber(b.real + a, b.imag);
}

ComplexNumber operator-(const double &a, const ComplexNumber &b)
{
	return ComplexNumber(b.real - a, -b.imag);
}

ostream &operator<<(ostream &os, const ComplexNumber &a)
{
	if (a.real != 0)
		os << a.real;
	if (a.imag > 0)
	{
		if(a.real != 0)os << "+";
		os << a.imag << "i";
	
	}else if (a.imag < 0)
		os << a.imag << "i";
	if (a.imag == 0 && a.real == 0)
		os << "0";
	return os;
}

double ComplexNumber::abs()
{
	return sqrt(imag * imag + real * real);
}

double ComplexNumber::angle()
{
	return atan2(imag, real) / M_PI * 180.0f;
}

bool ComplexNumber::operator==(const ComplexNumber &b)
{
	return (real == b.real) && (imag == b.imag);
}

bool operator==(const double &a, const ComplexNumber &b)
{
	return (a == b.real) && (0 == b.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c)
{
	return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + c.real * imag);
}

ComplexNumber operator*(const double &a, const ComplexNumber &b)
{
	return ComplexNumber(a, 0) * b;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c)
{
	ComplexNumber conj = *this * ComplexNumber(c.real, -c.imag);
	double div = (c.imag * c.imag + c.real * c.real);
	return ComplexNumber(conj.real / div, conj.imag / div);
}

ComplexNumber operator/(const double &a, const ComplexNumber &b)
{
	return ComplexNumber(a, 0) / b;
}

int main()
{
	ComplexNumber a(1.5, 2), b(3.2, -2.5), c(-1, 1.2);
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a + 2.5 << "\n";
	cout << 2.5 + a << "\n";
	cout << a - 1.5 << "\n";
	cout << 1.5 - a << "\n";
	cout << b + ComplexNumber(0, 2.5) << "\n";
	cout << c - c << "\n";
	cout << "-----------------------------------\n";

	ComplexNumber d = (a + b) / c;
	ComplexNumber e = b / (a - c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c * 2 << "\n";
	cout << 0.5 * c << "\n";
	cout << 1 / c << "\n";
	cout << "-----------------------------------\n";

	cout << ComplexNumber(1, 1).abs() << "\n";
	cout << ComplexNumber(-1, 1).abs() << "\n";
	cout << ComplexNumber(1.5, 2.4).abs() << "\n";
	cout << ComplexNumber(3, 4).abs() << "\n";
	cout << ComplexNumber(69, -9).abs() << "\n";
	cout << "-----------------------------------\n";

	cout << ComplexNumber(1, 1).angle() << "\n";
	cout << ComplexNumber(-1, 1).angle() << "\n";
	cout << ComplexNumber(-1, -1).angle() << "\n";
	cout << ComplexNumber(1, -1).angle() << "\n";
	cout << ComplexNumber(5, 2).angle() << "\n";
	cout << "-----------------------------------\n";

	cout << (ComplexNumber(1, 1) == ComplexNumber(1, 2)) << "\n";
	cout << (ComplexNumber(1, 1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}