#include <iostream>
//#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include "floatfann.h"

using namespace std;

int main()
{
	
    srand(time(NULL));
    int contador=0;
    int decimal=0;

    for(int i=0;i<357; i+= ((rand() % 3) +1)){	//Passo do i Randomico
		decimal = rand() % 99;		
		int inteiro=i;	
		float numero=inteiro + ((float)decimal/100);
		float numEscalaEntrada=(((float)numero*2)/360)-1;
		float numEscalaSaida=(numero*(2*M_PI))/360;		
		printf("%f\n%f\n",numEscalaEntrada,sin(numEscalaSaida));			
		contador++;
    }//*/

    /*for(int i=0;i<6; i++){
	for(int j=0;j<20;j++){
		decimal = rand() % 99;
		int inteiro=i+rand() % 3;	
		float numero=inteiro + ((float)decimal/100);
		float sigmoid=1/(1 + ( pow((float)M_E,numero) ));
		cout << numero/100 << "\n" << sigmoid << "\n";	
		contador++;
	}
    }//*/

	cout << "\nTOTAL:" << contador << "\n";	
    return 0;
}
