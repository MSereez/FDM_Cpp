#include "fieldOperations.h"

fieldOperations::fieldOperations()
{
}

fieldOperations::~fieldOperations()
{
}


/*
Fields::volVectorField operator+(const Fields::volVectorField& A,const Fields::volVectorField& B)
 {
     Fields::volVectorField result(A);
         forAllInternal(A)
         {
                    result[i][j].value += B[i][j].value;
             }
         
     return result;
 }

 Fields::volVectorField operator+(const Fields::volVectorField& A,const Fields::volScalarField& B)
 {
     Fields::volVectorField result(A);
         forAllInternal(A)
         {
                    result[i][j].value += B[i][j].value;
             }
       
     return result;
 }
 
   Fields::volScalarField operator+(const Fields::volScalarField& A,const Fields::volVectorField& B)
 {
     Fields::volScalarField result(A);
         forAllInternal(A)
         {
                    result[i][j].value += B[i][j].value;
             }
       
     return result;
 }
 Fields::volScalarField operator+(const Fields::volScalarField& A,const Fields::volScalarField& B)
 {
     Fields::volScalarField result(A);
         forAllInternal(A)
         {
                    result[i][j].value += B[i][j].value;
             }
       
     return result;
 }*/
 
/*
// cross product
 Fields::volVectorField operator&&(const Fields::volVectorField& A,const Fields::volVectorField& B)
    {
          Fields::volVectorField result(A);
         forAllInternal(A)
         {
                  result[i][j].value *= B[i][j].value;
             }
       
        return result;
    }

 Fields::volVectorField operator&&(const Fields::volVectorField& A,const Fields::volScalarField& B)
    {
          Fields::volVectorField result(A);
         forAllInternal(A)
         {
                  result[i][j].value *= B[i][j].value;
             }
       
        return result;
    }
      Fields::volVectorField operator==(const Fields::volVectorField& A, const Fields::volVectorField& B)
      {
          Fields::volVectorField result(A);
         forAllInternal(A)
         {
                  result[i][j].value = B[i][j].value;
             }
       
        return result;
    }
          Fields::volVectorField operator==(const Fields::volVectorField& A, const Fields::volScalarField& B)
      {
          Fields::volVectorField result(A);
         forAllInternal(A)
         {
                  result[i][j].value = B[i][j].value;
             }
       
        return result;
    }


 Fields::volVectorField operator-(const Fields::volVectorField& A,const Fields::volVectorField& B)
 {
     Fields::volVectorField result(A);
         forAllInternal(A)
         {
                    result[i][j].value -= B[i][j].value;
             }
         
     return result;
 }
  Fields::volScalarField operator-(const Fields::volScalarField& A,const Fields::volVectorField& B)
 {
     Fields::volScalarField result(A);
         forAllInternal(A)
         {
                    result[i][j].value -= B[i][j].value;
             }
         
     return result;
 }
 
   Fields::volVectorField operator-(const Fields::volVectorField& A,const Fields::volScalarField& B)
 {
     Fields::volVectorField result(A);
         forAllInternal(A)
         {
                    result[i][j].value -= B[i][j].value;
             }
         
     return result;
 }
     Fields::volVectorField operator*(double& dblvalue, const Fields::volVectorField& A)
    {
         Fields::volVectorField result(A);
         forAllInternal(A)
         {
                   result[i][j].value *=  dblvalue ;
             }
       
       return result;
    }   


 Fields::volScalarField operator*(double& dblvalue, const Fields::volScalarField& A)
    {
         Fields::volScalarField result(A);
         forAllInternal(A)
         {
                   result[i][j].value *=  dblvalue ;
             }
       
       return result;
    }   */
