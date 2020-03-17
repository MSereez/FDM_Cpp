#include "solutionControl.h"

solutionControl::solutionControl() : timeStep(0),dt(0.001), nu(0.01),rho(1)
{
    
}
solutionControl::solutionControl(int& newnt, int& newinneIt,double& newdt) : nt(newnt), innerIt(newinneIt),timeStep(0),dt(newdt), nu(0.1),rho(1)
{
    
}

solutionControl::~solutionControl()
{
}

