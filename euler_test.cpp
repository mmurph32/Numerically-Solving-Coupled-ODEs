#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

double f(double& x, double& y);

int main()
{
	double x0, y0, xn, h, yn, slope;
	int i, n;

	std::cout << "Enter initial conditions" << std::endl;
	std::cout << "x0: ";
	std::cin >> x0;
	
	std::cout << "y0: ";
	std::cin >> y0;

	std::cout << "Enter calculation point xn: ";
	std::cin >> xn;

	std::cout << "Enter number of steps: ";
	std::cin >> n;
	
	h = (xn - x0) / n;

	std::cout << "\nx0\ty0\tslope\tyn\n";
	std::cout << "--------------------------------\n";

	for (i = 0; i < n; i++)
	{
	slope = f(x0, y0);
	yn = y0 + h * slope;
	std::cout << x0 << "\t" << y0 << "\t" << slope << "\t" << yn <<std::endl;
	y0 = yn;
	x0 = x0 + h;
	}

	std::cout << "\n" << "Value of y at x = " << xn << " is " << yn << "\n";

}

double f(double& x, double& y)
{	
	return 1 + (y / x);
}

