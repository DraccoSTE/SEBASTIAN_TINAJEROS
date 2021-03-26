#include <iostream>
#include <string>
using namespace std;

class algoritmo{
		int clave;
	public:
		int filas;
    	int columnas;
    	char** array;
    	algoritmo(){
        	int claveT = getsetPrivate();
        	columnas = claveT%10;
        	filas = (claveT-columnas)/10;
        	array = new char* [filas];
        	for (int i = 0; i < filas; i++){
            	array[i] = new char[columnas];
            	for (int j = 0; j < columnas; j++){
                	array[i][j] = ' ';
            	}
        	}
    	}
    int getsetPrivate()
    {
    	int temporary;
    	cout<<"Ingrese la clave: ";
        cin >> temporary;
        clave=temporary;
        return clave;
    }
    string encriptar(string cadena){
        int comprobar = 0;
        for (int i = 0; i < cadena.length(); ++i)
        {
            for (int j = 0; j < columnas; ++j)
            {
                if (comprobar < cadena.length())
                {
                	
                    array[i][j] = cadena[(i * columnas) + j];
                    comprobar++;
                }
            }
        }
        string crypt="                  ";
        int counter=0;
        for (int i = 0; i < (columnas); i++){
        	for (int j = 0; j< (filas); j++){
            	 	crypt[counter]=array[j][i];
            	 	counter++;
        	}
        }
        return crypt;
	}
    string desencriptar(string cadena){
    	int comprobar = 0;
        for (int i = 0; i < filas; ++i)
        {
            for (int j = 0; j < columnas; ++j)
            {
                if (comprobar < cadena.length())
                {
                    array[i][j] = cadena[(j * filas) + i];
                    cout << cadena[(j * filas) + i] << '\t';
                    comprobar++;
                }
            }
            cout << endl;
        }
        string decrypt="                  ";
        int counter=0;
        for (int i = 0; i < (filas); i++){
        	for (int j = 0; j< (columnas); j++){
            	 	decrypt[counter]=array[i][j];
            	 	counter++;
        	}
        }
        return decrypt;
	}
};
int main(){
	string mensaje_crp;
	string mensaje_original;
	string mensaje = "hola como estan";
    algoritmo emisor;
	mensaje_crp = emisor.encriptar(mensaje);
	algoritmo receptor;
	mensaje_original=receptor.desencriptar(mensaje_crp);
    cout << "mensaje encriptado: " << mensaje_crp<<endl;
    cout << "mensaje descifrado: " << mensaje_original;
    return 0;
}
