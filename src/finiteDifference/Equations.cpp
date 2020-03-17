#include "Equations.h"

Equations::Equations()
{
}
Equations::Equations(const finiteMatrix::fdm& A) : temp(A)
{
    
}
Equations::~Equations()
{
}

Fields::volVectorField Equations::solve(Equations& Eqn, Fields::volVectorField& vecnew,solutionControl& sol_)
{
 if (Eqn.EqnTypes == Equations::Momentum)
 {
   //   cout << "solving for momentum type equation " << endl;
   forAllInternal(vecnew)
    {
      vecnew[i][j].value =    vecnew[i][j].value +(sol_.dt*Eqn.temp[i][j].value);
    }
}

else
{
 //   cout << " missing equation type " << endl;
}

return vecnew;
 }
 
 
 
 Fields::volScalarField Equations::solve(Equations& Eqn, Fields::volScalarField& vecnew, solutionControl& sol_) 
{
   if (Eqn.EqnTypes == Equations::Continuity)
 {
   //   cout << "solving for momentum type equation " << endl;
   forAllInternal(vecnew)
    {
      vecnew[i][j].value = Eqn.temp[i][j].value;
    }
}

   if (Eqn.EqnTypes == Equations::ScalarTransport)
 {
   //   cout << "solving for momentum type equation " << endl;
   forAllInternal(vecnew)
    {
       vecnew[i][j].value =    vecnew[i][j].value +(sol_.dt*Eqn.temp[i][j].value);
    }
}

else
{
  //  cout << " missing equation type " << endl;
}  
    return vecnew;
}

     finiteMatrix::fdm Equations:: clear()
    {
    finiteMatrix::fdm A(temp);
    forAllCells(A)
    {
        A[i][j].value = 0;
        temp[i][j].value =  A[i][j].value;
    }
        return temp;
    }
