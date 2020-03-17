#ifndef SCALARFIELDS_H
#define SCALARFIELDS_H

class scalarFields
{
public:
    scalarFields();
    
    scalarFields(const scalarFields& );
    virtual ~scalarFields();
    double value;
    double X,Y;
};

#endif // SCALARFIELDS_H
