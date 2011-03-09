#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "floatfann.h"

using namespace std;

int main()
{
    char * cstr, *valor;
    fann_type *calc_out;    

    struct fann *ann = fann_create_from_file("mlp2.net");//carregando rede
 
    ifstream infile;
    string line;
    string strEntrada("");
    string strSaida("");

    int QtdTestes=0,QtdEntradas=0,QtdSaidas=0;
    int testeAtual=0;

    infile.open ("runSeno.data", ifstream::in);
    

   //Obtendo Infos dos dados
   if(!infile.eof()){	
        getline (infile,line);

	cstr = new char [line.size()+1];
	strcpy (cstr, line.c_str());

	valor=strtok (cstr," ");
	QtdTestes = atoi(valor);

	valor=strtok (NULL," ");
	QtdEntradas = atoi(valor);

	valor=strtok (NULL," ");
	QtdSaidas = atoi(valor);

	cout << "Lendo arquivo: " << QtdTestes << " Testes, " << QtdEntradas << " Entradas " << QtdSaidas << " Saidas" << endl;
    }

    fann_type input[QtdEntradas];

   //Lendo Cada Teste
   while( (!infile.eof()) && (testeAtual<QtdTestes) ) {
	getline (infile,line);

	//Lendo Entradas do teste atual
        int i=0;
	strEntrada="";
	cstr = new char [line.size()+1];
	strcpy (cstr, line.c_str());
        valor = strtok (cstr," ");
  	while (valor != NULL)
  	{
	  strEntrada=strEntrada+" "+valor;
    	  input[i]=atof(valor);
    	  valor = strtok (NULL, " ");

	  i++;
  	}

	//AQUI
	//fann_scale_input(ann,input);
	calc_out = fann_run(ann, input); //Rodando o Teste

	//obtento resposta do teste
	char buff[30];
	strSaida="";

	//AQUI
	//fann_descale_output(ann,calc_out);

	for(int j=0; j<QtdSaidas;j++){
		sprintf(buff,"%.6f", calc_out[j]);
		strSaida=strSaida+" "+buff;
	}
	
	//Lendo resposta correta
	getline (infile,line);


	cout << "=======Teste " << (testeAtual+1) <<"======="<< endl;
	cout << "Entrada         -> "<< strEntrada << endl;
	cout << "Saida do teste  -> "<< strSaida << endl;
        cout << "Saida do Correta->  "<<line << endl;
	cout << "====================="<< endl;
	cout << endl;
	
	testeAtual++;
   }
   infile.close();

//===========================
  struct fann_train_data *data = fann_read_train_from_file("runSeno.data");

  //AQUI	
  //fann_scale_train_data(data,-1,1);
  fann_reset_MSE(ann);
  fann_test_data(ann, data);
  printf("Mean Square Error: %f\n", fann_get_MSE(ann));
  

  fann_destroy_train(data);

//===========================

    fann_destroy(ann);    
    return 0;
}//*/


