#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    char *cstr, *cont,*valor;

 
    ifstream infile;
    string line;
    string strEntrada("");
    string strSaida("");

    infile.open ("sunsposts2.data", ifstream::in);
    


   //Lendo Cada Teste
   while( !infile.eof()) {
	getline (infile,line);

	if(line.size()>0){
		//Lendo Entradas do teste atual
		float contf=0;
		strEntrada="";
		cstr = new char [line.size()+1];
		strcpy (cstr, line.c_str());
		//cont = strtok (cstr," ");
	    	//valor = strtok (NULL, " ");
		cont = cstr;
		getline (infile,line);
		cstr = new char [line.size()+1];
		strcpy (cstr, line.c_str());
	    	valor = cstr;

		contf=atoi(cont);

		contf=((contf*2.0)/280.0)-1.0;

		cout << contf << " " << valor << "\n";	
	}	
   }
   infile.close();

    return 0;
}//*/


