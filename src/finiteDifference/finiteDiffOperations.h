#include "foralloperations.h"
#include "fieldOperations.h"
#include "finiteMatrix.h"
#include "solutionControl.h"
namespace optimize
{
  Fields::volVectorField getMeshParam(Fields::volVectorField& vec, Mesh& mesh_)
 {
             forAllCells(vec)
        {
            vec[i][j].X =mesh_.vecX[i][j];
            vec[i][j].Y =mesh_.vecY[i][j];
        }
            return vec;
     
 }
 
     Fields::volScalarField getMeshParam( Fields::volScalarField& vec, const Mesh& mesh_)
    {

        forAllCells(vec)
        {
            vec[i][j].X =mesh_.vecX[i][j];
            vec[i][j].Y =mesh_.vecY[i][j];
        }
            return vec;
    }
      
    
}
namespace fd
{
     
 
    
  finiteMatrix::fdm Field(Fields::volVectorField& vec)
 {
   Fields::volVectorField temporary(vec.size(),vector<Fields::vectorField>(vec[0].size()));
    finiteMatrix::fdm result(vec.size(),vector<finiteMatrix>(vec[0].size()));
    Fields::volVectorField vectemp(vec.size(),vector<Fields::vectorField>(vec[0].size()));
     forAllInternal(vec)
        
        {
          vectemp[i][j].value= vec[i][j].value;
          result[i][j].value=   vectemp[i][j].value;
        }
        
    return result;
 } 
    
 finiteMatrix::fdm Field(Fields::volScalarField& vec)
 {
   Fields::volScalarField temporary(vec.size(),vector<Fields::scalarField>(vec[0].size()));
    finiteMatrix::fdm result(vec.size(),vector<finiteMatrix>(vec[0].size()));
    Fields::volScalarField vectemp(vec.size(),vector<Fields::scalarField>(vec[0].size()));
     forAllInternal(vec)
        
        {
          vectemp[i][j].value= vec[i][j].value;
          result[i][j].value=   vectemp[i][j].value;
        }
        
    return result;
 }   

 finiteMatrix::fdm pressurepoison(Fields::volScalarField& vec)
 {
         Fields::volScalarField vectempx(vec.size(),vector<Fields::scalarField>(vec[0].size()));
         Fields::volScalarField vectempy(vec.size(),vector<Fields::scalarField>(vec[0].size()));
       finiteMatrix::fdm result(vec.size(),vector<finiteMatrix>(vec[0].size()));
       double dxsq;
       double dysq;
     forAllInternal(vec)
        { 
        dxsq =  pow((vec[i][j].X - vec[i][j-1].X),2); 
        dysq =  pow((vec[i][j].Y - vec[i-1][j].Y),2); 
        vectempx[i][j].value=  vec[i+1][j].value+vec[i-1][j].value;
           vectempy[i][j].value= vec[i][j+1].value+vec[i][j-1].value;
            result[i][j].value =   (vectempx[i][j].value*dxsq + vectempy[i][j].value*dysq)/(2*(dysq+dxsq)) ;
           
        }
    return result; 
 }

 
 finiteMatrix::fdm laplacianY(Fields::volVectorField& vec)
 {
          Fields::volVectorField vectemp(vec.size(),vector<Fields::vectorField>(vec[0].size()));
       finiteMatrix::fdm result(vec.size(),vector<finiteMatrix>(vec[0].size()));
     forAllInternal(vec)
        {     
         vectemp[i][j].value= (vec[i][j+1].value-(2*vec[i][j].value)+vec[i][j-1].value)/(pow((vec[i][j].Y-vec[i-1][j].Y),2));
            result[i][j].value =   vectemp[i][j].value;
           
        }
    return result; 
 }
 
 finiteMatrix::fdm laplacianX(Fields::volVectorField& vec)
 {
finiteMatrix::fdm result(vec.size(),vector<finiteMatrix>(vec[0].size()));
      Fields::volVectorField vectemp(vec.size(),vector<Fields::vectorField>(vec[0].size()));
     forAllInternal(vec)
        
        {
          vectemp[i][j].value= (vec[i+1][j].value-2*vec[i][j].value+vec[i-1][j].value)/(pow((vec[i][j].X-vec[i][j-1].X),2));
          result[i][j].value=   vectemp[i][j].value;
        }
        
    return result;
 }

 finiteMatrix::fdm laplacian(Fields::volVectorField& vec)
 {
  finiteMatrix::fdm result(vec.size(),vector<finiteMatrix>(vec[0].size()));
          Fields::volVectorField vectemp(vec.size(),vector<Fields::vectorField>(vec[0].size()));
               Field(vectemp)=   laplacianX(vec) +  laplacianY(vec);
               result =  Field(vectemp);
                return result;

 }
 

finiteMatrix::fdm laplacianY(Fields::volScalarField& vec)
 {
   Fields::volScalarField vectemp(vec.size(),vector<Fields::scalarField>(vec[0].size()));
    finiteMatrix::fdm result(vec.size(),vector<finiteMatrix>(vec[0].size()));
     forAllInternal(vec)
        {
            vectemp[i][j].value= (vec[i][j+1].value-2*vec[i][j].value+vec[i][j-1].value)/(pow((vec[i][j].Y-vec[i-1][j].Y),2));
            result[i][j].value =   vectemp[i][j].value;
           
        }
    return result; 
 }
 finiteMatrix::fdm laplacianX(Fields::volScalarField& vec)
 {

     finiteMatrix::fdm result(vec.size(),vector<finiteMatrix>(vec[0].size()));
    Fields::volScalarField vectemp(vec.size(),vector<Fields::scalarField>(vec[0].size()));
     forAllInternal(vec)
        
        {
          vectemp[i][j].value= (vec[i+1][j].value-2*vec[i][j].value+vec[i-1][j].value)/(pow((vec[i][j].X-vec[i][j-1].X),2));
          result[i][j].value=   vectemp[i][j].value;
        }
        
    return result;
 }
 finiteMatrix::fdm laplacian(Fields::volScalarField& vec)
 {
       Fields::volScalarField vectemp(vec.size(),vector<Fields::scalarField>(vec[0].size()));
    finiteMatrix::fdm result(vec.size(),vector<finiteMatrix>(vec[0].size()));
               Field(vectemp) =   laplacianX(vec) +  laplacianY(vec);
               result = Field(vectemp);
                return result;

 }
 
 
finiteMatrix::fdm ddt(Fields::volVectorField& vec2, Fields::volVectorField vec, solutionControl& sol_)
{
finiteMatrix::fdm result(vec.size(),vector<finiteMatrix>(vec[0].size()));
       Fields::volVectorField vectemp(vec.size(),vector<Fields::vectorField>(vec[0].size()));

    double rdelta = 1/sol_.dt;
    forAllInternal(vec)
    {
        vectemp[i][j].value = rdelta*(vec2[i][j].value-vec[i][j].value);
               result[i][j].value =   vectemp[i][j].value;
    }
    return result;
}   


finiteMatrix::fdm gradY(Fields::volVectorField& vec,string& gradMethod)
{
    string gradMethod1 = "linear";
    string gradMethod2 = "CDS";   
finiteMatrix::fdm result(vec.size(),vector<finiteMatrix>(vec[0].size()));
   Fields::volVectorField vectemp(vec.size(),vector<Fields::vectorField>(vec[0].size()));
    if(gradMethod == gradMethod1) // i.e. CDS
    {
     forAllInternal(vec)
        {
          vectemp[i][j].value= (vec[i][j].value-vec[i][j-1].value)/(vec[i][j].Y-vec[i-1][j].Y);
                          result[i][j].value =   vectemp[i][j].value;

        }
        
        
    }

       if(gradMethod == gradMethod2) // i.e. CDS
    {
     forAllInternal(vec)
        {
          vectemp[i][j].value= (vec[i][j+1].value-vec[i][j-1].value)/(2*(vec[i][j].Y-vec[i-1][j].Y));
                result[i][j].value =   vectemp[i][j].value;
        }
    
    }

    return result;

}


finiteMatrix::fdm gradX(Fields::volVectorField& vec,string& gradMethod)
{
    string gradMethod1 = "linear";
    string gradMethod2 = "CDS";
finiteMatrix::fdm result(vec.size(),vector<finiteMatrix>(vec[0].size()));
   Fields::volVectorField vectemp(vec.size(),vector<Fields::vectorField>(vec[0].size()));
   if(gradMethod == gradMethod1)
  {
       
     forAllInternal(vec)
        {
          vectemp[i][j].value= (vec[i][j].value-vec[i-1][j].value)/(vec[i][j].X-vec[i][j-1].X);
                result[i][j].value =   vectemp[i][j].value;
        }
  }
    
    if(gradMethod == gradMethod2) // i.e. CDS
    {
     forAllInternal(vec)
        {
          vectemp[i][j].value= (vec[i+1][j].value-vec[i-1][j].value)/(2.0*(vec[i][j].X-vec[i][j-1].X));
               result[i][j].value =   vectemp[i][j].value;
         }
      
    }      
 
    return result;
}

 finiteMatrix::fdm gradX(Fields::volScalarField& vec,string& gradMethod)
{
    string gradMethod1 = "linear";
    string gradMethod2 = "CDS";
        Fields::volScalarField vectemp(vec.size(),vector<Fields::scalarField>(vec[0].size()));
   finiteMatrix::fdm result(vec.size(),vector<finiteMatrix>(vec[0].size()));
   if(gradMethod == gradMethod1)
  {

     forAllInternal(vec)
        {
          vectemp[i][j].value= (vec[i][j].value-vec[i-1][j].value)/(vec[i][j].X-vec[i][j-1].X);
          result[i][j].value =   vectemp[i][j].value;
        }
        
  }
    
    if(gradMethod == gradMethod2) // i.e. CDS
    {
     forAllInternal(vec)
        {
          vectemp[i][j].value= (vec[i+1][j].value-vec[i-1][j].value)/(2*(vec[i][j].X-vec[i][j-1].X));
           result[i][j].value=   vectemp[i][j].value;
         }  
    }    

    return result;
  
}

 finiteMatrix::fdm gradY(Fields::volScalarField& vec,string& gradMethod)
{
  finiteMatrix::fdm result(vec.size(),vector<finiteMatrix>(vec[0].size()));
     Fields::volScalarField vectemp(vec.size(),vector<Fields::scalarField>(vec[0].size()));
    string gradMethod1 = "linear";
    string gradMethod2 = "CDS";   
    if(gradMethod == gradMethod1) // i.e. CDS
    {
     forAllInternal(vec)
    {
        {
          vectemp[i][j].value= (vec[i][j].value-vec[i][j-1].value)/(vec[i][j].Y-vec[i-1][j].Y);
             result[i][j].value =   vectemp[i][j].value;
        }
        
        
    }
    }
    if(gradMethod == gradMethod2) // i.e. CDS
    {
        
     forAllInternal(vec)
        {
          vectemp[i][j].value= (vec[i][j+1].value-vec[i][j-1].value)/(2*(vec[i][j].Y-vec[i-1][j].Y));
               result[i][j].value =   vectemp[i][j].value;
        }
    }

     return result;
}

}
