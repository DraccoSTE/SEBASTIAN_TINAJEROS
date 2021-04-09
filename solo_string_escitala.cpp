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
        	columnas = claveT % 10;
        	filas = (claveT-columnas)/10;
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
        string crypt;
        int extra_spaces=(columnas*filas)-cadena.size();
        cadena.insert(cadena.size(),extra_spaces,' ');
		for (int j = 0; j < cadena.length(); ++j)
        {
            for (int i = 0; i < filas; ++i)
            {
                if (comprobar < cadena.length())
                {
                	
                    crypt=crypt+(cadena[(i * columnas) + j]);
                    comprobar++;
                    
                }
            }
        }
        return crypt;
	}
	string descifrar(string cadena){
        int comprobar = 0;
        string decrypt;
		for (int j = 0; j < cadena.length(); ++j)
        {
            for (int i = 0;  i< columnas; ++i)
            {
                if (comprobar < cadena.length())
                {
                	
                    decrypt= decrypt+(cadena[(i * filas) + j]);
                    comprobar++;
                    cout<<decrypt<<endl;
                }
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
	mensaje_original=receptor.descifrar(mensaje_crp);
    cout << "mensaje encriptado: " << mensaje_crp<<endl;
    cout << "mensaje descifrado: " << mensaje_original;
    return 0;
}
