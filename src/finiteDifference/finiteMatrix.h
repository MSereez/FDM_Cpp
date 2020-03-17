#ifndef FINITEMATRIX_H
#define FINITEMATRIX_H
#include "foralloperations.h"

class finiteMatrix
{
public:
    finiteMatrix();
    virtual ~finiteMatrix();
    
       typedef vector<vector<finiteMatrix> > fdm;
       
       friend finiteMatrix::fdm operator+(const finiteMatrix::fdm&, const finiteMatrix::fdm&);
       friend finiteMatrix::fdm operator&&(const finiteMatrix::fdm&, const finiteMatrix::fdm&);
       friend finiteMatrix::fdm operator==(const finiteMatrix::fdm&, const finiteMatrix::fdm&);
       friend finiteMatrix::fdm operator-(const finiteMatrix::fdm&, const finiteMatrix::fdm&);
       friend finiteMatrix::fdm operator*(double&, const finiteMatrix::fdm& );
       
       double value;

};

#endif // FINITEMATRIX_H
