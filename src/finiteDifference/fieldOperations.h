#ifndef FIELDOPERATIONS_H
#define FIELDOPERATIONS_H
#include "Fields.h"

class fieldOperations : public Fields
{
public:
    fieldOperations();
    virtual ~fieldOperations();


    // friend Fields::volVectorField operator==(const Fields::volVectorField&, const Fields::volVectorField&);
  
};

#endif // FIELDOPERATIONS_H

/*
    friend Fields::volVectorField operator+(const Fields::volVectorField&, const Fields::volVectorField&);
    friend Fields::volVectorField operator+(const Fields::volVectorField&, const Fields::volScalarField&);
    friend Fields::volScalarField operator+(const Fields::volScalarField&, const Fields::volVectorField&);
    friend Fields::volScalarField operator+(const Fields::volScalarField&, const Fields::volScalarField&);
    friend Fields::volVectorField operator&&(const Fields::volVectorField&, const Fields::volVectorField&);
    friend Fields::volVectorField operator&&(const Fields::volVectorField&, const Fields::volScalarField&);
    friend Fields::volVectorField operator==(const Fields::volVectorField&, const Fields::volVectorField&);
    friend Fields::volVectorField operator==(const Fields::volVectorField&, const Fields::volScalarField&);
    friend Fields::volVectorField operator-(Fields::volVectorField&, Fields::volVectorField&);
    friend Fields::volVectorField operator-(Fields::volScalarField&, Fields::volVectorField&);
    friend  Fields::volVectorField operator*(double&, const Fields::volVectorField& );
    friend  Fields::volScalarField operator*(double&, const Fields::volScalarField& );*/
