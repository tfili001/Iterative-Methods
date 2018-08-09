#ifndef MAT_H_INCLUDED
#define MAT_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <fstream>

#include <cmath>
using namespace std;
void display(double **A,int m,int n){
    cout<<"_____________________\n";
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
        cout<<setw(8)<<setprecision(4)<<A[i][j]<<" ";
        }
     cout<<endl;
    }
}
void display(double **A,int n){
    for(int i=0;i<n;i++){
    cout<<"_________";
    }
cout<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
        cout<<setw(8)<<setprecision(4)<<A[i][j]<<" ";
        }
     cout<<endl;
    }
}
void printVec(double *x,int n){
    for(int i=0; i<n; i++)
            {
            cout<<setw(8)<<setprecision(4)<<x[i]<<endl;
            }
}

double *createVec(int n)
{
    double *x = new double[n];
    for(int i=0;i<n;i++)
    {
        x[i]=0;
    }

    return x;
}
int seed = time(0);
default_random_engine engine(seed);

double *createRandVec(int n)
{
    uniform_real_distribution<double> dist (-100,100);

    double *x = new double[n];
    for(int i=0;i<n;i++)
    {
        x[i]=dist(engine);
    }

    return x;
}

double **createMat(int n)
{
    double **A = new double *[n];
    for(int i=0; i<n; i++)
    {
        A[i]=new double[n];
    }




return A;
}



double **randomizeMat(double **A,int n)
{
    uniform_real_distribution<double> dist (-100,100);
    double sum=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
		A[i][j]=dist(engine);
        }
    }

///Set entries absolute
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
        if(A[i][j]<0)
           A[i][j];
        }
    }
	for(int i=0; i<n; i++)
	{
        for(int j=0; j<n; j++)
        {
		sum+=A[i][j];
        }
	A[i][i]=sum*10;
	sum=0;
    }
return A;
}

double *matbyVec(double **A,double *sol,int n){
	double *B = new double[n];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			B[i]+=(A[i][j])*(sol[j]);
		}
	}


return B;
}
void removeMat(double **A,int n)
{
	for(int i=0;i<n;i++)
	{
		delete [] A[i];
	}
	delete [] A;
}

void errorNorm(double *b,double **A,double *x,int n)
{
	double *Ax=matbyVec(A,x,n);
	double row;

	cout<<"Compare vector B to Ax\n";
    for(int i=0;i<n;i++)
    {
		row += pow(b[i]-Ax[i],2);
		cout<<fixed<<std::right<<setw(10)<<b[i]<<" "<<Ax[i]<<endl;
    }
    cout<<"________________________________________\n";
    double norm = sqrt(row);
    cout<<fixed<<"Norm   = "<<" "<<norm<<endl;
    cout<<fixed<<"Norm/2 = "<<" "<<norm/2<<endl;


delete Ax;
}

#endif // MAT_H_INCLUDED
