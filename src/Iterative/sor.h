#ifndef SOR_H_INCLUDED
#define SOR_H_INCLUDED
#include "matrix.h"
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;



void sor()
{

	double  rel = 1.15;
    int n;
    fstream fin;
    fin.open("q6data.txt");
    fin>>n;

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


	for(int i =0;i<n;i++)
	{
		xold[i]=0;
		x[i]=0;
	}
	cout<<"Size       = "<<n<<endl
		<<"Relaxation = "<<rel<<endl;



    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
			double sum1=0.0;
			double sum2=0.0;

			for(int j=0;j<i;j++)
			{
            ///xold[j]=x[j];

			///if(i!=j)
		//	xold[j]=x[j];

				sum1+=(A[i][j]*x[j]);


			}
			for(int j=i;j<n;j++)
			{

			xold[j]=x[j];

			if(i!=j)
                {
				sum2+=(A[i][j]*xold[j]);
                }

			}

		 x[i]=(rel/A[i][i])*(b[i]-sum1-sum2)+(1-rel)*xold[i];
			/*for(int a=0;a<n;a++)
			{
				xold[a]=x[a];
			}
			 */
		}

    }
	/***End of SOR***/

   ofstream fout;
    fout.open("testout.txt");
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

/*** Cleanup ***/
  removeMat(A,n);
  delete b;
  delete x;
  delete xold;
}







#endif // SOR_H_INCLUDED
