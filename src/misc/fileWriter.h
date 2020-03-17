#ifndef FILEWRITER_H
#define FILEWRITER_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "Fields.h"
#include <cstring>
#include <sstream>
using namespace std;
using std::vector;
using std::string;



class fileWriter
{
public:
    fileWriter();
    
    virtual ~fileWriter();
    
    
    void write(string&, Mesh&, Fields::volVectorField&, Fields::volVectorField& , Fields::volScalarField&,int  );
    
};

#endif // FILEWRITER_H
