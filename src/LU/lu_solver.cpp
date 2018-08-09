#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "matrix.h"
using namespace std;

void getLU(double **A,double *b,int n){
    double **L = createMat(n);
    double **U = createMat(n);
    double *x = new double[n];
    double *y = new double[n];

    for(int i=0; i<n; i++)
    {
        L[i]=new double[n];
        U[i]=new double[n];

    }




    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i)
                L[j][i] = 0;
            else
            {
                L[j][i] = A[j][i];
                for (int k = 0; k < i; k++)
                    L[j][i] -= (L[j][k] * U[k][i]);

            }
        }
        for (int j = 0; j < n; j++)
        {
            if (j < i)
                U[i][j] = 0;
            else if (j == i)
                U[i][j] = 1;
            else
            {
                U[i][j] = (A[i][j] / L[i][i]);
                for (int k = 0; k < i; k++)
                    U[i][j] -= ((L[i][k] * U[k][j]) / L[i][i]);

            }
        }
    }
    double **C = createMat(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
        double sum=0;
              for(int k=0;k<n;k++)
            {
                sum+=L[i][k]*U[k][j];
            }
            C[i][j]=sum;
        }
    }

    double sum = 0.0;


    for(int i=0;i<n;i++)
    {                                        //forward subtitution method
        sum=0.0;
        for(int j=0;j<i;j++)
            sum+=L[i][j]*y[j];
        y[i]=(b[i]-sum)/L[i][i];
    }

    for(int i=n-1;i>0;i--)
    {
        sum=0.0;
        for(int j=n-1;j>i;j--) {
            sum+=U[i][j]*x[j];
        }
        x[i]=(y[i]-sum)/U[i][i];
    }




    ofstream fout;
    fout.open("lu_out.txt");
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


int main(){

    ifstream infile;
    infile.open("q2data.txt");
    int n;
    infile>>n;

    double sum;
    double **A   =  new double*[n];
    double *b   =   new double[n];


    for(int i=0; i<n; i++)
    {
        A[i]=new double[n];
    }






     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
        infile>>A[i][j];
        }
    }
     for(int i=0;i<n;i++)
    {
        infile>>b[i];
    }
    infile.close();

   // display(A,n);


	getLU(A,b,n);

return 0;
}
