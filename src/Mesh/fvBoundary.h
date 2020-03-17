#ifndef FVBOUNDARY_H
#define FVBOUNDARY_H
#include "fieldOperations.h"

class fvBoundary
{
public:
  fvBoundary();
    fvBoundary(const Mesh&);
    virtual ~fvBoundary();
        vector<vector<fvBoundary> > boundaries_;
        string type;
        string btype;
   Fields::volVectorField correctVelocityBoundaries(Fields::volVectorField&, double);
   Fields::volScalarField correctPressureBoundaries(Fields::volScalarField&);
};

#endif // FVBOUNDARY_H
