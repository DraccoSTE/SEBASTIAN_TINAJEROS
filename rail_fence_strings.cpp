#include <iostream>
#include <string>
using namespace std;

class algoritmo{
    int clave;
public:
    int elem_number;
    int Nrail;
    
    algoritmo(){
        Nrail = getsetPrivate();
        elem_number = (Nrail * 2) - 2;
    }
    int getsetPrivate()
    {
        int temporary;
        cout << "Ingrese la clave: ";
        cin >> temporary;
        clave = temporary;
        return clave;
    }
    string encriptar(string cadena) {
        int length = cadena.length();
        string crypt;
        for (int j = 0; j < clave; ++j){
            for (int i = 0; j + (elem_number * i) - (2 * j)< length; ++i){
                    if ((j + (elem_number * i)) < length){
                        crypt=crypt+(cadena[(i*elem_number)+j]);
                    }
                    if ((j % (elem_number/ 2) != 0) && (i != 0)){
                        crypt=crypt+(cadena[(i*elem_number)+j-(j*2)]);
                    }
            }
        }
        return crypt;
    }
    string descifrar(string cadena) {
        int length = cadena.length();
        string decrypt;
        for (int j = 0; j < clave; ++j){
            for (int i = 0; j + (elem_number * i) - (2 * j)< length; ++i){
                    if ((j + (elem_number * i)) < length){
                        decrypt=decrypt+(cadena[(i*elem_number)+j]);
                    }
                    if ((j % (elem_number/ 2) != 0) && (i != 0)){
                        decrypt=decrypt+(cadena[(i*elem_number)+j-(j*2)]);
                    }
            }
        }
        return decrypt;
    }
};
int main() {
    string mensaje_crp;
    string mensaje_original;
    string mensaje = "hola como estan";
    algoritmo emisor;
    mensaje_crp = emisor.encriptar(mensaje);
    algoritmo receptor;
    mensaje_original=receptor.descifrar(mensaje_crp);
    cout << "mensaje encriptado: " << mensaje_crp << endl;
    cout << "mensaje descifrado: " << mensaje_original;
    return 0;
}
