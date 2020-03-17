#include "Mesh.h"

Mesh::Mesh():Nx(22),Ny(22),Xs(0.0),Ys(1.0),Xe(0.0),Ye(1.0),Xl(Xe-Xs),Yl(Xl-Yl),vecX(Nx,vector<double>(Ny,0.0)),
vecY(Nx,vector<double>(Ny,0.0)),vecNodeType(Nx,vector<int>(Ny,0)),vecNodeBoundaryType(Nx,vector<int>(Ny,0))
{
    Dx = Xl/(Nx-1);
    Dy = Yl/(Ny-1);
}

Mesh::Mesh(double newXs, double newYs, double newXe, double newYe, int newNX, int newNY):
Nx(newNX),Ny(newNY),Xs(newXs),Ys(newYs),Xe(newXe),Ye(newYe),Xl(Xe-Xs),Yl(Xl-Yl),vecX(newNX,Mesh::single_DField(newNY,0.0)),
vecY(newNX,Mesh::single_DField(newNY,0)),vecNodeType(newNX,Mesh::single_IntField(newNY,0)),vecNodeBoundaryType(newNX,Mesh::single_IntField(newNY,0))
{
    Dx = Xl/(Nx-1);
    Dy = Yl/(Ny-1);
    
}

Mesh::Mesh(const Mesh& mesh_) :
Nx(mesh_.Nx),Ny(mesh_.Ny),Xs(mesh_.Xs),Ys(mesh_.Ys),Xe(mesh_.Xe),Ye(mesh_.Ye),Xl(Xe-Xs),Yl(Xl-Yl),vecX(mesh_.Nx,Mesh::single_DField(mesh_.Ny,0.0)),
vecY(mesh_.Nx,Mesh::single_DField(mesh_.Ny,0)),vecNodeType(mesh_.Nx,Mesh::single_IntField(mesh_.Ny,0)),vecNodeBoundaryType(mesh_.Nx,Mesh::single_IntField(mesh_.Ny,0))
{
      Dx = Xl/(Nx-1);
    Dy = Yl/(Ny-1);
}
Mesh::~Mesh()
{
}

void Mesh::calcX(twoD_DoubleField& vec )
{

    for(unsigned int i=0; i<vec.size(); i++)
    {
        for(unsigned int j=1; j<vec[i].size(); j++)
        {
                vec[i][0] = Xs;
              vec[i][j] = vec[i][j-1] + Dx;
        }
    }     
}
        
void Mesh::calcY(twoD_DoubleField& vec)
{

    for(unsigned int i=1; i<vec.size(); i++)
    {
        for(unsigned int j=0; j<vec[i].size(); j++)
        {
             vec[0][j] = Ys;
              vec[i][j] = vec[i-1][j] + Dy;
        }
    }         
}

void  Mesh::assignNodeType(twoD_IntField& vec)
{
    forAllCells(vec)
             {
                 vec[i][j] = 1;
              
                if( j==0)
                 {
                     vec[i][j] = 2;
                 }

                   if(( i==vec.size()-1))
                 {
                     vec[i][j] = 2;
                 }
                if(( j==vec.size()-1))
                 {
                     vec[i][j] = 2;
                 }
                 if( i==0)
                 {
                     vec[i][j] =2;
                 }
                 
             }     
}
         

     
void  Mesh::assignBoundaryType(twoD_IntField& veci,twoD_IntField& vecb)
{
    forAllCells(veci)
    {
         if( veci[i][j] == 2)
          {
              if( j==0)
                 {
                     vecb[i][j] = 1;
                 }

                 if(( i==vecb.size()-1))
                 {
                     vecb[i][j] = 1;
                 }

                 if( i==0)
                 {
                     vecb[i][j] =1;
                 }   
                                  if( j==(vecb.size()-1))
                 {
                     vecb[i][j] = 2;
                 }
           }
        
    }
          
         
}
     
void  Mesh::createMesh(Mesh& mesh_)
{
    mesh_.calcX(vecX);
    mesh_.calcY(vecY);
    mesh_.assignNodeType(vecNodeType);
    mesh_.assignBoundaryType(vecNodeType,vecNodeBoundaryType);
    cout << " successfully created mesh X, Y and boundary types " << endl;
         
}
