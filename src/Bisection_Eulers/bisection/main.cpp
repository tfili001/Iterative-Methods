#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
/***
 *
   	 3x/2  - 6 − sin(2x)/2 = 0 has a
     unique real root (supposedly between
     0 and 5) use bisection to compute to
     3 decimal places of accuracy.
 *
 ***/
//The value of root is : 0.00976562
/***
double f(double x){

	return (3*x/2)- 6-sin(2*x)/2;
}

int main()
{
	double x = 0;
	double y = 5;
    double z = x;
    while ((y-x) >= 0.01)
    {
        z = (x+y)/2;

        if (f(z) == 0.0)
            break;

        else if (f(z)*f(x) < 0)
            y = z;
        else
            y = z;
    }
    cout << "The value of root is : " << z;


	return 0;
}
***/
double fx(double x);

int main()
{
    double x0, x1, xnew, soln, tol;
    int itcount=0;
    cout<<"Enter Tolerance ex: 0.001\n;
    cin>>tol;

    x0=0;
    x1= 5;
    tol=.0001;
    xnew=x1;
    soln=fx(xnew);
    itcount= 0;

    cout<<"checking end points for opposite sign"<<endl;
    cout<<fx(x0)<<" and "<<fx(x1)<<endl;

    while( fabs(soln)>tol )
    {
        xnew  = (x0+x1)/2.0;
        soln = fx(xnew);
        if((soln>0)&&(x1>0))
            {
            x1=xnew;
            }
        else {x0=xnew;}
        itcount++;
        cout<<x0<<" "<<xnew<<" "<<x1<<endl;
    }
    cout<<"Solution = "<<xnew<<" has fx= "<<soln<<" in "<<itcount<<" iterations"<<endl;
    return 0;

}

double fx(double x){

	return (3*x/2)- 6-sin(2*x)/2;
}
