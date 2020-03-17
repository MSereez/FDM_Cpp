#include "finiteMatrix.h"

finiteMatrix::finiteMatrix() :value(0.0)
{
}

finiteMatrix::~finiteMatrix()
{
}

      
finiteMatrix::fdm operator+(const finiteMatrix::fdm& A, const finiteMatrix::fdm& B)
{
 finiteMatrix::fdm result(A);
forAllInternal(A)
{
   result[i][j].value =A[i][j].value + B[i][j].value;
}
 return result;
}
         
finiteMatrix::fdm operator&&(const finiteMatrix::fdm& A, const finiteMatrix::fdm& B)
{
finiteMatrix::fdm result(A);
forAllInternal(A)
 {
  result[i][j].value *= B[i][j].value;
}
return result;
}

finiteMatrix::fdm operator==(const finiteMatrix::fdm& A, const finiteMatrix::fdm& B)
{
finiteMatrix::fdm result(A);
 forAllInternal(A)
 {
  result[i][j].value = B[i][j].value;
 }
 return result;
}

finiteMatrix::fdm operator-(const finiteMatrix::fdm& A, const finiteMatrix::fdm& B)
{
finiteMatrix::fdm result(A);
 forAllInternal(A)
  {
    result[i][j].value -= B[i][j].value;
 } 
return result;
 }
 
finiteMatrix::fdm operator*(double& dblvalue, const finiteMatrix::fdm& A)
{
 finiteMatrix::fdm result(A);
    forAllInternal(A)
    {
    result[i][j].value *=  dblvalue ;
    } 
  return result;
}  
