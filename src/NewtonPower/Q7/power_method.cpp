#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

void test();

double  **readMatrix(char *path,int n){
    ifstream fin;
    fin.open(path);



    double **A = new double *[n];

    for(int i=0; i<n; i++)
    {
        A[i]=new double[n];

    }

    for(int i=0; i<n; i++)
    {
            for(int j=0; j<n; j++)
            {
            fin>>A[i][j];
            }
    }
    fin.close();
    return A;
}

void test(){
    cout<<"________________________________________________________________________\n"
        <<"##############################    TEST    ##############################\n"
        <<"________________________________________________________________________\n";
}

int main()
{
    char *fpath = "q7data.txt";
    int n = 3;

    double A[n][n];
    A[0][0]=0;
    A[0][1]=11.0;
	A[0][2]=-5;
    A[1][0]=-2;
    A[1][1]=17;
	A[1][2]=-7;
	A[2][0]=-4;
	A[2][1]=26;
	A[2][2]=-10;
	cout<<"A matrix\n";
	for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
			cout<<setprecision(6)<<A[i][j]<<" ";
			}
			cout<<endl;
	}


    double x[3], xnew[3];
    x[0]=1;
    x[1]=1;
	x[2]=1;
    xnew[0]=0.0;
    xnew[1]=0.0;
	xnew[2]=0.0;

    double rho=0.0;
    double rhoOld=100.0;
    int i=0;




 ///while(fabs(rhoOld-rho)>.001)
    for(int a=0;a<11;a++)
    {
        if(i>0){rhoOld=rho;}
        xnew[0]=(A[0][0]*x[0]) +(A[0][1]*x[1])+(A[0][2]*x[2]);
        xnew[1]=(A[1][0]*x[0]) +(A[1][1]*x[1])+(A[1][2]*x[2]);
        xnew[2]=(A[2][0]*x[0]) +(A[2][1]*x[1])+(A[2][2]*x[2]);

        if(fabs(xnew[2])>fabs(xnew[0])){rho=xnew[2];}
		else if(fabs(xnew[1])>fabs(xnew[0])){rho=xnew[1];}
        else
        {
			rho=xnew[0];
		}


        x[0]=xnew[0]/rho;
        x[1]=xnew[1]/rho;
        x[2]=xnew[2]/rho;


        cout<<setprecision(6)<<"Rho: "<<rho<<"   x["<<x[0]<<", "<<x[1]<<", "<<x[2]<<"]"<<endl;
    i++;
    }
    cout<<"Solution"<<endl;
    cout<<"after "<<i<<" iterations"<<endl;
	cout<<setprecision(6)<<"Rho: "<<rho<<"   x["<<x[0]<<", "<<x[1]<<", "<<x[2]<<"]"<<endl;

    return 0;
}
