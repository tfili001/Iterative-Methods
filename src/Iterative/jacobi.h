#ifndef JACOBI_H_INCLUDED
#define JACOBI_H_INCLUDED
#include "matrix.h"
void jacobi()
{

    int n;
    fstream fin;
    fin.open("q3data.txt");
    fin>>n;
            cout<<"############################    TEST    ############################\n";

    double **A = createMat(n);

    double tol = .001;
    double *b = new double[n];

    double *x = new double[n];
    double *xold = new double[n];

    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
        fin>>A[i][j];
       }
    }


    for(int i=0;i<n;i++)
    {
        fin>>b[i];
    }
    fin.close();

      for(int j=0;j<n;j++)
        {
        xold[j]=0;
        x[j]=0;
        }


for(int k=0;k<5;k++)
{

	for(int i=0;i<n;i++)
	{
	    double sum = 0.0;
	    double diag = 1/A[i][i];
		for(int j=0;j<n;j++)
		{
 ///       cout<<"i="<<i<<" j="<<j<<endl;

            if(j!=i)
            {
            sum +=((-A[i][j])*(xold[j]));
            }
		}
	x[i]=1/A[i][i]*(sum+b[i]);
	}


    for(int i = 0; i < n; i++)
    {
        xold[i] = x[i];
    }
}
/**
	cout<<"____________________\nX Vector\n";
	for(int i=0;i<n;i++)
	{
		cout<<setprecision(4)<<x[i]<<endl;
	}
**/
double sum = 0.0;

    double *c = new double[n];



        for(int j=0;j<n;j++)
        {
        c[j]=0;
        }


	 for(int i=0;i<n;i++)
     {
        for(int j=0;j<n;j++)
        {

            c[i]+=(A[i][j]*x[j]);

        }
    }
  ///  errorNorm(b,A,x,n);
    ofstream fout;
    fout.open("jacobi_out.txt");
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

#endif // JACOBI_H_INCLUDED
