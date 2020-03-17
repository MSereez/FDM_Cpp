#ifndef FORALLOPERATIONS_H
#define FORALLOPERATIONS_H
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

template<class T>
class foralloperations
{
public:
    foralloperations<T>();
    virtual ~foralloperations<T>();
    vector<vector<T> > tempvector;
    
    void print2dvector(vector<vector<T> >&);
};
#define forAllCells(tempvector) \
    for(unsigned int i=0; i<tempvector.size(); i++) \
        for(unsigned int j=0; j<tempvector[i].size(); j++)  
#define forAllInternal(tempvector) \
    for(unsigned int i=1; i<tempvector.size()-1; i++) \
        for(unsigned int j=1; j<tempvector[i].size()-1; j++) 
#define forAllOppInternal(tempvector) \
    for(unsigned int j=1; j<tempvector.size()-1; j++) \
        for(unsigned int i=1; i<tempvector[i].size()-1; i++) 

         
 
        
#endif // FORALLOPERATIONS_H
