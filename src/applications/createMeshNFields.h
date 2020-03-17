    double xs,ys,xe,ye; int nx,ny;
    xs=0.3; ys=0.02;xe=2.0;ye=1.2;nx=100;ny=100;
    Mesh mesh_(xs,ys,xe,ye,nx,ny);
    mesh_.createMesh(mesh_);
    Mesh mesh2_(mesh_);
    
Fields::volVectorField U
(mesh_.Nx,vector<Fields::vectorField>(mesh_.Ny));

Fields::volVectorField V
(mesh_.Nx,vector<Fields::vectorField>(mesh_.Ny));

Fields::volVectorField error
(mesh_.Nx,vector<Fields::vectorField>(mesh_.Ny));

Fields::volVectorField errorold
(mesh_.Nx,vector<Fields::vectorField>(mesh_.Ny));

Fields::volVectorField test
(mesh_.Nx,vector<Fields::vectorField>(mesh_.Ny));


Fields::volVectorField Unew
(mesh_.Nx,vector<Fields::vectorField>(mesh_.Ny));

Fields::volVectorField Vnew
(mesh_.Nx,vector<Fields::vectorField>(mesh_.Ny));


Fields::volScalarField p
(mesh_.Nx,vector<Fields::scalarField>(mesh_.Ny));

Fields::volScalarField pnew
(mesh_.Nx,vector<Fields::scalarField>(mesh_.Ny));


optimize::getMeshParam(U,mesh_);
optimize::getMeshParam(V,mesh_);
optimize::getMeshParam(Unew,mesh_);
optimize::getMeshParam(Vnew,mesh_);
optimize::getMeshParam(p,mesh_);
optimize::getMeshParam(pnew,mesh_);

    int nt =200;
    int newinneriterations =5;
    double dt = 0.001;
    solutionControl sol_(nt,newinneriterations,dt);
    sol_.nu  = 0.01;
    sol_.rho = 1;
    

     
    string GLinear = "linear";
    string CDS = "CDS";

// assign boundary conditions
fvBoundary boundary_(mesh_);
  double inletvalue = 1.0;
    double zerovalue = 0.0;

        
boundary_.correctVelocityBoundaries(U,inletvalue);
boundary_.correctVelocityBoundaries(Unew,inletvalue);
boundary_.correctVelocityBoundaries(V,zerovalue);
boundary_.correctVelocityBoundaries(Vnew,zerovalue);
boundary_.correctPressureBoundaries(pnew);
boundary_.correctPressureBoundaries(p);
        
