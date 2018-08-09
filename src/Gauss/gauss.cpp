#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

void display(double **A,int n){
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n+1; j++)
        {
        cout<<setw(8)<<fixed<<A[i][j]<<" ";
        }
     cout<<endl;
    }
}
double *getAx(double **A,double *sol,int n){
	double *B = new double[n];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			B[i]+=(A[i][j])*(sol[j]);
		}
	}
	cout<<"Ax____________________\n";
	for(int i=0;i<n;i++)
	{
		cout<<setprecision(4)<<B[i]<<endl;
	}

return B;
}


double* gauss(double **T,double *b, int n) {

 double **A = new double *[n];
 double *arr = new double[n];

    for(int i=0; i<n+1; i++)
    {
        A[i]=new double[n+1];
    }

       for(int i=0;i<n;i++)
       {
            for(int j=0;j<n+1;j++)
            {
                if(j==n)
                {
                A[i][j]=b[i];
                }
                else
                {
                A[i][j]=T[i][j];
                }
            }
       }
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                double sum = -A[j][i]/A[i][i];

                for (int k=i; k<n+1; k++)
                {
                    if (i==j) {

                        A[j][k] = 0;
                    }
                    else
                    {
                        A[j][k] += sum*A[i][k];
                    }
                }
            }
        }
    cout<<"Gauss Halfway\n";


    for (int i=n-1; i>=0; i--)
    {
        arr[i] = A[i][n]/A[i][i];

        for (int k=i-1;k>=0; k--)
        {
            A[k][n] -= A[k][i] * arr[i];
        }
    }

    cout<<"Done\n";


    return arr;
}

int main(){

    ifstream infile;
    infile.open("q1data.txt");
    int n;
    double sum;
    infile>>n;
    double **A  = new double*[n];
    double  *x  = new double[n+1];
    double  *Ax = new double[n];
    double  *b  = new double[n];

    for(int i=0; i<n; i++)
    {
        A[i]=new double[n];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            infile>>A[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        infile>>b[i];
    }
    cout<<"File read\n";

    x = gauss(A,b,n);

    ofstream fout;
    fout.open("gauss_out.txt");
    double m = sqrt(n);
    int k;
    for(int i=0;i<m;i++)
    {
         for(int j=0;j<m;j++)
        {
            k = j* m + i;
            fout<<x[k]<<" ";
        }
    fout<<endl;
    }
    fout.close();


}
