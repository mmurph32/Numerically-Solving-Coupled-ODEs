#include <iostream>
#include <vector>

double f(const double& t, const double& x, const double& y);
double g(const double& t, const double& x, const double& y);

void Runge_Kutta_coupled(std::vector<double>& x, std::vector<double>&  y, std::vector<double>& t, const double& h, const int& n);

void printVector(std::vector<double>& v);

int main()
{

	int n;
	std::cout << "Please enter the number of iterations: ";
	std::cin >> n;

	std::vector<double> t(n);
	std::vector<double> x(n);
	std::vector<double> y(n);
	double h = 0.02;

	//initial conditions
	t[0] = 0;
	x[0] = 6;
	y[0] = 4;
	
	Runge_Kutta_coupled(x, y, t, h, n);

	std::cout << "t = ";
	printVector(t);
	std::cout << "x = ";
	printVector(x);
	std::cout << "y = ";
	printVector(y);


}

double f(const double& t, const double& x, const double& y){

	return x + 2 * y;

}
double g(const double& t, const double& x, const double& y){

	return 3 * x + 2 * y;

}

void Runge_Kutta_coupled(std::vector<double>& x, std::vector<double>&  y, std::vector<double>& t, const double& h, const int& n){

double F1, F2, F3, F4, G1, G2, G3, G4 = 0;
for (int i = 0; i < n-1; i++){

	F1 = f(t[i], x[i], y[i]);
	G1 = g(t[i], x[i], y[i]);
	F2 = f(t[i] + (h / 2.) , x[i] + F1 * (h / 2.), y[i] + G1 * (h / 2.));
	G2 = g(t[i] + (h / 2.) , x[i] + F1 * (h / 2.), y[i] + G1 * (h / 2.));
	F3 = f(t[i] + (h / 2.) , x[i] + F2 * (h / 2.), y[i] + G2 * (h / 2.));
	G3 = g(t[i] + (h / 2.) , x[i] + F2 * (h / 2.), y[i] + G2 * (h / 2.));
	F4 = f(t[i] + h, x[i] + F3 * h, y[i] + G3 * h);
	G4 = g(t[i] + h, x[i] + F3 * h, y[i] + G3 * h);

	x[i+1] = x[i] + (h / 6.) * (F1 + 2 * F2 + 2 * F3 + F4);
	y[i+1] = y[i] + (h / 6.) * (G1 + 2 * G2 + 2 * G3 + G4);
	t[i+1] = t[i] + h;
}
}

void printVector(std::vector<double>& v){

	std::cout << "[ " ;
	for(double element : v){
		std::cout << element << ", ";
	}
	std::cout << "]" << std::endl;
	
}






