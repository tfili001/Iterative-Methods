#include <iostream>
#include <cmath>
using namespace std;

double f(double x);
double ff(double x);
int main()
{
    double xold, xnew;
    xold = 0.5;
    double tol = .00001;
    bool cont = true;
    int it=0;
    while(cont)
    {
       xnew = xold - (f(xold)/ff(xold));
       cout<<"New x = "<<xnew<<endl;
       if(abs(xnew-xold)<tol){cont = false;}
       xold = xnew;
       it++;
    }
    cout<<"final solution: "<<xnew<<" in "<<it<<" iterations"<<endl;
}

double f(double x)
{
    x = pow(x,2)-sin(x);
    return x;
}
double ff(double x)
{
    x = 2*x-cos(x);
    return x;
}
