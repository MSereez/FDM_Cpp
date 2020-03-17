#include <stdio.h>
#include "foralloperations.h"
#include "Mesh.h"
#include "finiteDiffOperations.h"
#include "fvBoundary.h"
#include "Equations.h"
#include "fileWriter.h"

int main(int argc, char **argv)
{
	printf("CFD OOP \n");
    #include "createMeshNFields.h"
  cout << "mesh dx " <<  (mesh_.vecX[1][1]- mesh_.vecX[1][0]) << endl;
   
double two = 2.0; double invrho = 1/sol_.rho; 
for( int it=0; it<sol_.nt; it++)
{
       Unew=U;
       Vnew=V;
       
double xsp = mesh_.Dx; double ysp = mesh_.Dy; double dspacing  = mesh_.Dx*mesh_.Dx;
     double delta = (dspacing * dspacing)/ (two*( (dspacing + dspacing) ));
    double rdelta = 1/sol_.dt; 
    double rhodelta = delta*sol_.rho;
    double redeltaspacing = rdelta/2*xsp;
    
    for(int inner = 0; inner < sol_.innerIt; inner++)
    {
    pnew =p;
    Equations pEqn
    (
  fd::Field(p) == fd::pressurepoison(pnew)
       - (rhodelta*(rdelta*( fd::gradX(U,CDS)+ fd::gradY(V,CDS))
       - ( fd::gradX(U,CDS) &&  fd::gradX(U,CDS))
       -(two* ( fd::gradY(U,CDS)&&  fd::gradX(V,CDS)))
        -( fd::gradY(V,CDS)&&  fd::gradY(V,CDS))))
   );

    pEqn.EqnTypes = Equations::Continuity;
    pEqn.solve(pEqn,p,sol_);
    boundary_.correctPressureBoundaries(p);
    pEqn.clear();
    }

    

     Equations UEqn
    ( 
        fd::ddt(U,Unew,sol_) == 
           ( fd::Field(Unew) &&  fd::gradX(Unew,GLinear)) - ( fd::Field(Vnew) && fd::gradY(Unew,GLinear))
        - (invrho* fd::gradX(p,CDS)) + sol_.nu *(  fd::laplacianX(Unew)+ fd::laplacianY(Unew))
    );


    UEqn.EqnTypes = Equations::Momentum;
    UEqn.solve(UEqn,U,sol_);
    boundary_.correctVelocityBoundaries(U,inletvalue);
    UEqn.clear();


   Equations VEqn
   ( 
        fd::ddt(V,Vnew,sol_) == 
     (fd::Field(Unew) && fd::gradX(Vnew,GLinear)) -(fd::Field(Vnew) && fd::gradY(Vnew,GLinear))
        - (invrho*fd::gradY(p,CDS)) + (sol_.nu * (fd::laplacianX(Vnew)+ fd::laplacianY(Vnew))) 
    );

    VEqn.EqnTypes = Equations::Momentum;
    VEqn.solve(VEqn,V,sol_);
    boundary_.correctVelocityBoundaries(V,zerovalue);
    VEqn.clear();
    
    double currenterror;
    currenterror = 0.0;
    forAllInternal(U)
    {
         errorold[i][j].value = (( (Unew[i][j].value - Unew[i-1][j].value)/mesh_.Dx)+ ((Vnew[i][j].value - Vnew[i][j-1].value)/mesh_.Dy));
          error[i][j].value = (( (U[i][j].value - U[i-1][j].value)/mesh_.Dx) + ((V[i][j].value - V[i][j-1].value)/mesh_.Dy));
             currenterror = currenterror + (fabs( error[i][j].value))-(fabs( errorold[i][j].value));
    }
         cout << " Iteration No: " << it << endl;
     cout << " current error is " << currenterror << endl;
     fileWriter fileWriter_;
     int timestep = it; string filename = "UVP" ;
     if( timestep%20 ==1)
     {
             fileWriter_.write(filename,mesh_,U,V,p,timestep); 
     }
    
}
    
    
	return 0;
}
