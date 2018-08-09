#ifndef GAUSS_SEIDEL_H_INCLUDED
#define GAUSS_SEIDEL_H_INCLUDED
#include "matrix.h"

void seidel(){

    double tol = .001;
    int n;
    fstream fin;
    fin.open("q4data.txt");
    fin>>n;
            cout<<"############################    TEST    ############################\n";

    double **A = createMat(n);
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

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
        double inv = 1/A[i][i];
        double sum1 = 0.0;
        double sum2 = 0.0;
            for(int j=0;j<i;j++)
            {
                if(j!=i)
                {
                sum1+=A[i][j]*x[j];
                }
            }
            for(int j=i;j<n;j++)
            {
                if(j!=i)
                {
                sum2+=A[i][j]*xold[j];
                }
            }

        sum1*=(-1);

        x[i]=inv*((sum1-sum2)+b[i]);
        xold[i] = x[i];


        }
    }



    ofstream fout;
    fout.open("seidel_out.txt");
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

#endif // GAUSS_SEIDEL_H_INCLUDED
