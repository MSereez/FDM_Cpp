#ifndef EQUATIONS_H
#define EQUATIONS_H
#include "solutionControl.h"
#include "Fields.h"
#include "finiteMatrix.h"

class Equations
{
public:
    Equations();
    Equations(const finiteMatrix::fdm&);
    virtual ~Equations();

    enum type{Momentum,Continuity, ScalarTransport};
    Equations::type EqnTypes;
    
     finiteMatrix::fdm temp;
     
     virtual  Fields::volVectorField solve(Equations&, Fields::volVectorField&, solutionControl&);
     virtual  Fields::volScalarField solve(Equations&, Fields::volScalarField&, solutionControl&);
      finiteMatrix::fdm clear();
};

#endif // EQUATIONS_H
