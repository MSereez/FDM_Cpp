#include "fvBoundary.h"
#include "Fields.h"
#include "Mesh.h"

fvBoundary::fvBoundary() 
{
}

fvBoundary::fvBoundary(const Mesh& mesh_) : boundaries_(mesh_.Nx, vector<fvBoundary>(mesh_.Ny))
{
    forAllCells(boundaries_)
    {
          boundaries_[i][j].btype = "FLUID";
        if(mesh_.vecNodeType[i][j] == 2)
        {
             boundaries_[i][j].type = "BOUNDARY";
             
        if(   boundaries_[i][j].type == "BOUNDARY")
        {
             if(mesh_.vecNodeBoundaryType[i][j] == 2)
               {
                   boundaries_[i][j].btype = "INLET";
               }
               else if (mesh_.vecNodeBoundaryType[i][j] == 1)
               {
                                  boundaries_[i][j].btype = "WALL";
               }
        }
        
        }
        
       
    }
}

fvBoundary::~fvBoundary()
{
}

   Fields::volVectorField fvBoundary::correctVelocityBoundaries(Fields::volVectorField& vec, double val)
   {
       forAllCells(vec)
       {
           if(boundaries_[i][j].btype == "INLET")
           {
                vec[i][j].value =val;
           }
           if(boundaries_[i][j].btype == "WALL")
           {
               vec[i][j].value = 0.0;
           }
           
       }
       return vec;
       
   }
   Fields::volScalarField fvBoundary::correctPressureBoundaries(Fields::volScalarField& vec)
   {
       int size2 = (vec.size()-1);
          forAllCells(vec)
       {
             if(boundaries_[i][j].btype == "WALL")
           {
                if(i==0)
                {
                      vec[i][j].value =   vec[i+1][j].value;
                }
                     if(i==size2)
                {
                      vec[i][j].value =   vec[i-1][j].value;
                }
                
                                if(j==0)
                {
                      vec[i][j].value =   vec[i][j+1].value;
                }
                     if(j==size2)
                {
                      vec[i][j].value =   vec[i][j-1].value;
                }
           }  
                  if(boundaries_[i][j].btype == "INLET")
           {

                      vec[i][j].value =   vec[i][j-1].value;
                
           }
           
       }
       
            return vec;
   }
