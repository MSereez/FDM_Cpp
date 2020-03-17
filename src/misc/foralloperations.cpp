#include "foralloperations.h"

template<class T>
foralloperations<T>::foralloperations()
{
}

template<class T>
foralloperations<T>::~foralloperations()
{
}

template<class T>
  void foralloperations<T>::print2dvector(vector<vector<T> >& vec)
  {
          for(unsigned int i=0; i<vec.size(); i++) 
          {
                 for(unsigned int j=0; j<vec[i].size(); j++) 
                 {
                     cout << vec[i] << ' ';
                 }
                 cout << endl;
          }
     
      
  }

