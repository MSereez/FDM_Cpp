#ifndef MESH_H
#define MESH_H
#include "foralloperations.h"

class Mesh
{


public:
    // default constructor
    Mesh();
    // overloaded constructor 1
    Mesh(double, double, double, double, int, int);
    
    //copy constructor
    Mesh(const Mesh&);
    // virtual destructor
    virtual ~Mesh();
        typedef vector<int> single_IntField;
            typedef vector<double> single_DField;
    typedef vector<vector<double> > twoD_DoubleField;
    typedef vector<vector<int> > twoD_IntField;

   

    
     void calcX(twoD_DoubleField& );
     void calcY(twoD_DoubleField& );
     void assignNodeType(twoD_IntField&);
     void assignBoundaryType(twoD_IntField&,twoD_IntField&);
     void createMesh(Mesh&);
    
    Mesh::twoD_DoubleField vecX;
    Mesh::twoD_DoubleField vecY;
    Mesh::twoD_IntField vecNodeType;  // 1 for internal fluid zone, 2 for boundary;
    Mesh::twoD_IntField vecNodeBoundaryType; // 1 for wall, 2 for inlet, 3 for outlet.
     
    int Nx,Ny;
    double Dx,Dy;
private:
    double Xs,Ys,Xe,Ye,Xl,Yl;
    
};

#endif // MESH_H
