#ifndef FIELDS_H
#define FIELDS_H
#include "Mesh.h"
#include "scalarFields.h"
#include "vectorFields.h"
#include "foralloperations.h"

class Fields : public scalarFields, public vectorFields
{
public:
    Fields();
    virtual ~Fields();

    typedef vectorFields vectorField;
    typedef scalarFields scalarField;
    typedef vector<vector<vectorField> > volVectorField;
    typedef vector<vector<scalarField> > volScalarField;
    


private:
    
};

#endif // FIELDS_H
