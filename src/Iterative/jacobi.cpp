#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>
#include "matrix.h"
#include "jacobi.h"
#include "gauss_seidel.h"
#include "sor.h"
using namespace std;



int main()
{

    int choice;


         cout<<"Choose a method\n"
             <<"0 Exit\n"
             <<"1 Jacobi\n"
             <<"2 Gauss Seidel\n"
             <<"3 Sor Method\n";
          cin>>choice;
          if(choice==0)
          {    cout<<"Exited\n";
              return 0;
          }

      switch(choice)
      {
          case 1:

              cout<<"JACOBI      \n________________________________\n";
                jacobi();
                        break;

          case 2:

              cout<<"GAUSS SEIDEL\n________________________________\n";
                seidel();
                        break;

          case 3:

              cout<<"SOR Method  \n________________________________\n";
                sor();
                        break;
      }
return 0;
}
