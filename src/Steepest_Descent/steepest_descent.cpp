#include <iostream>
#include <cmath>
using namespace std;
///steepest descent solution to y^2/2 + xy + yx^2 -3y

double HprimeX(double x, double y);
double HprimeY(double x, double y);
double Hsolver(double x, double y, double a, double b);
int main()
{
    double x, y, xnew, ynew, a, b, h, hnew, diff;
    int its=1;
    cout<<"initial values for x and y?"<<endl;
   /// cin>>x>>y;
    x = -3; y = 3;
    ///diff is the distance between (x,y) and (xnew, ynew)
   diff=10;
   while(diff>.001)
    {
    cout<<"iteration number: "<<its<<endl;
    ///compute the gradient
    a=HprimeX(x,y);
    b=HprimeY(x,y);
    ///computing new h by setting current G' = 0
    h = Hsolver(x, y,a, b);
    cout<<"h = "<<h<<endl;

    xnew = x + (h*a);
    ynew = y + (h*b);
    ///this is the two norm of the change in x,y (diff)
    diff=sqrt(pow((xnew-x),2.0)+(pow((ynew-y),2.0)));

    ///updating x,y
    x = xnew;
    y = ynew;

    cout<<"("<<x<<", "<<y<<")"<<endl;
    its++;
    }
    return 0;
}

///function to evaluate the derivative with respect to x
double HprimeX(double x, double y)
    {
        double ans=0.0;
        ans = (50*x)-2;
        return ans;
    }

///function to evaluate the derivative with respect to y
double HprimeY(double x, double y)
{
    double ans=0.0;
    ans = (40*y)-1;
    return ans;
}

double Hsolver(double x, double y, double a, double b)
{
    ///if G has h^3 then G' h^2 use quadratic formula
    ///setting G' = 0.0 ans solving for h
    double ans=0.0;
    ans = ans -  ((y*b)+(x*b)+(y*a)+(2*a*x)-(3*b));
    ans = ans/((pow(b,2.0))+(2*a*b)+(2*pow(a,2.0)));
    return ans;
    /// G has higher order terms or trig or logs..use NEWTONS METHOD
    /// you would need to generate a G(x,y,a,b) function and
    /// you would need a Gprime(x,y,a,b) function to solve for h
    /// hnew = h*(G(x,y,a,b)/G'(x,y,a,b)) iteration till hnew ~ h
}
