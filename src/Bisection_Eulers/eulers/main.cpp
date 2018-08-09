#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
/// dy/dx = y
/// y(0)=1
/// y(x) = e^x
/*
 * dy/dx  =   y^2 - x^2   and y0 = -1 and
 * 	dx = .5 to find the solution at x = 1.5
 *
 */
double e = 2.71828182846;
double dx = 0.5;
///cout<<"what is the value of dx? "; cin>>dx;
double x = 0.0;
double y = -1.0;
double dydx;
double acty;
//acty=-1;
dydx=dx*y;
cout<<"X      Y    dy/dx       "<<endl;
cout<<setprecision(4)<<setw(7)<<left<<x<<setw(7)
	<<y<<setw(7)<<dydx<<setw(7)<<endl;


while(x<=1)
{
  //y = 1/3*(pow(y,3)-pow(x,2)*y);
  //y=x*pow(y,2)-(pow(x,3)/3);
  //y = y+(dx*dydx);

  dydx = pow(y,2)-pow(x,2);
  y=y+dx*dydx;
    x = x+dx;

  //acty = pow(e,x);
  cout<<setprecision(4)<<setw(7)<<left<<x<<setw(7)
	  <<y<<setw(7)<<dydx<<setw(14)<<endl;
}
return 0;
}
