#ifndef SOLUTIONCONTROL_H
#define SOLUTIONCONTROL_H

class solutionControl
{
public:
    solutionControl();
    solutionControl(int&,int&, double&);
    virtual ~solutionControl();
    int nt,innerIt, timeStep;
    double dt, nu, rho;     
};

#endif // SOLUTIONCONTROL_H
