#include "fileWriter.h"
#include <iostream>
#include <string>
fileWriter::fileWriter()
{
}

fileWriter::~fileWriter()
{
}


    void fileWriter::write(string& name, Mesh& meshes, Fields::volVectorField& Utempo, Fields::volVectorField& Vtempo, Fields::volScalarField& ptempo,int time)
  {
    string  myfileType = ".dat";
    int ttime = time;
          string timename ;
      ostringstream temp; 
      temp << ttime;
      timename = temp.str();
      string newnames_ = name;
    string newfilename= newnames_.append(timename);
    string name2 = newfilename.append(myfileType);
    char cstr[name2.size() + 2];
    strcpy(cstr, newfilename.c_str());
 //   cout << "file name " << cstr << endl;
 	FILE *outfile;
	outfile = fopen( cstr,"w+t"); 

        int NXtemp = meshes.Nx;
         int NYtemp = meshes.Ny;
	fprintf( outfile, "VARIABLES=\"X\",\"Y\",\"U\",\"V\",\"P\"\n");
	fprintf( outfile, "ZONE  F=POINT\n");
	fprintf( outfile, "I=%d, J=%d\n", NXtemp, NYtemp );

  for (  int j = 0 ; j <NYtemp ;j++ )
	{
    for (  int i = 0 ; i <NYtemp ; i++ )
    {
		double xpos, ypos, UU, VV, pp;
		xpos = meshes.vecX[i][j];
		ypos = meshes.vecY[i][j];
        UU = Utempo[i][j].value;
           VV = Vtempo[i][j].value;
              pp = ptempo[i][j].value;
              

		fprintf( outfile, "%5.8lf\t%5.8lf\t%5.8lf\t%5.8lf\t%5.8lf\n", xpos, ypos,UU,VV, pp );
    }
	}
    
    fclose(outfile);
  
  }
