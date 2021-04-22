#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class cesar {
		int clave;
	public:
		string Alfamin="abcdefghijklmnopqrstuvwxyz";
		string Alfamay="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    	cesar(){
        	int claveT = getsetPrivate();
    	}
    int getsetPrivate()
    {
    	int temporary;
    	cout<<"Ingrese la clave: ";
        cin >> temporary;
        clave=temporary;
        return clave;
    }
    int modulo(int a,int b)
	{
    int q=a/b;
    int res=a-(q*b);

    if (res<0){
        q--;
        res=a-(q*b);
    }
    return res;
	}
    string encriptar(string cadena){
    	string crypt(cadena.length(),' ');
    	int indice;
    	for(int i=0;i<cadena.length();i++){
			for(int j=0;j<Alfamin.length();j++){
				if(cadena[i]==Alfamin[j]){
					indice=modulo(j+clave,Alfamin.length());
					crypt[i]=Alfamin[indice];
				}
			}
			for(int j=0;j<Alfamay.length();j++){
				if(cadena[i]==Alfamay[j]){
					indice=modulo(j+clave,Alfamay.length());
					crypt[i]=Alfamay[indice];
				}
			}
		}
	return crypt;
	}
	string descifrar(string cadena){
    	string decrypt(cadena.length(),' ');
    	int indice;
    	for(int i=0;i<cadena.length();i++){
			for(int j=0;j<Alfamin.length();j++){
				if(cadena[i]==Alfamin[j]){
					indice=modulo(j-clave,Alfamin.length());
					decrypt[i]=Alfamin[indice];
				}
			}
			for(int j=0;j<Alfamay.length();j++){
				if(cadena[i]==Alfamay[j]){
					indice=modulo(j-clave,Alfamay.length());
					decrypt[i]=Alfamay[indice];
				}
			}
		}
	return decrypt;
	}
};
main(){
	string mensaje="noseusarhtml";
	cesar emisor;
	string mensaje_crp=emisor.encriptar(mensaje);
	cout<<mensaje_crp<<endl;
	cesar receptor;
	string descifrar="wrgrxqfudfneroxgr";
	string mensaje_dcrp=receptor.descifrar(descifrar);
	cout<<mensaje_dcrp<<endl;
}
