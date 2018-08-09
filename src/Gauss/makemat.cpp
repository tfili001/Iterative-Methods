#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

int seed = time(0);
default_random_engine engine(seed);

void display(double **A,int n){
	cout<<"Display____________________\n";

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
        cout<<setw(8)<<setprecision(4)<<A[i][j]<<" ";
        }
     cout<<endl;
    }
}

double *createSol(int n){
      uniform_real_distribution<double> dist (-100,100);

	double *sol = new double[n];
cout<<"given Solution vector\n";
	for(int i=0;i<n;i++)
	{
		double a=dist(engine);
		sol[i]=a;
		cout<<sol[i]<<endl;
    }
return sol;
}

double **createMat(int n){

    double sum=0;
    double **A;
      uniform_real_distribution<double> dist (-100,100);

    A = new double *[n];
///Have each of the new pointers point at a vector of size t
    for(int i=0; i<n; i++)
    {
        A[i]=new double[n];
    }

///Fill in the matrix
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
		A[i][j]=dist(engine);
        }
    }
    cout<<"Random Matrix \n";
	display(A,n);


///Set entries absolute
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
        if(A[i][j]<0)
           A[i][j]=abs(A[i][j]);
        }
    }

///Set diagonals to zero
/*
    for(int i=0; i<n; i++)
    {
        A[i][i]=0;
    }
*/
///Diagonally dominant
	for(int i=0; i<n; i++)
	{
        for(int j=0; j<n; j++)
        {
		sum+=A[i][j];
        }
	A[i][i]=sum*10;
	sum=0;
    }

	display(A,n);

return A;
}

double *getB(double **A,double *sol,int n){
	double *B = new double[n];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			B[i]+=(A[i][j])*(sol[j]);
		}
	}
	cout<<"____________________\nB Vector\n";
	for(int i=0;i<n;i++)
	{
		cout<<fixed<<B[i]<<endl;
	}

return B;
}



int main()
{
    int n;
    default_random_engine engine(seed);
    uniform_int_distribution<int> dist(0,100);
    cout<<"What size?"<<endl;
    cin>>n;

    double **A  = createMat(n);
	double *sol = createSol(n);
	double *b   = getB(A,sol,n);
    ofstream outfile;
    outfile.open("input.txt");
    outfile<<n<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
        outfile<<A[i][j]<<" ";
        }
        outfile<<endl;
    }
    for(int i=0;i<n;i++){
        outfile<<b[i]<<endl;
    }
return 0;
}

