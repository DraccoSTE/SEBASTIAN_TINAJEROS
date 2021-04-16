#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//18.7
class rot13 {
		int clave;
	public:
		string Alfamin="abcdefghijklmnñopqrstuvwxyz";
		string Alfamay="ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    	algoritmo(){
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
    	//string crypt[cadena.length()];
    	string crypt;
    	int indice;
    	for(int i=0;i<cadena.length();i++){
    		if(cadena[i]=' '){
    			//crypt[i]=cadena[i];
    			crypt=crypt+cadena[i];
    			cout<<crypt;
			}
			else{
				for(int j=0;j<Alfamin.length();j++){
					indice=modulo(j+13,27);
					cout<<indice;
					if(indice>Alfamin.length()){
						//crypt[i]=Alfamin[indice];
						crypt=crypt+Alfamin[indice];
					}
					if(indice>Alfamay.length()){
						//crypt[i]=Alfamay[indice];
						crypt=crypt+Alfamay[indice];
						cout<<crypt;
					}
				}
			}
		}
		return crypt;
	}
};
main(){
	string mensaje="hola mundo";
	rot13 emisor;
	string mensaje_crp=emisor.encriptar(mensaje);
	//18.11
	string name;
	string apellido;
	cout<<"Introduzca su primer nombre: ";
	cin>>name;
	cout<<endl<<"Introduzca se primer apellido: ";
	cin>>apellido;
	string concat;
	concat=name+' '+apellido;
	cout<<concat;
	//18.12
	string word="vaquero";
	string crypt;
	for(int i=0;i<word.length();i++){
		crypt=crypt+'X';
	}
	bool run=true;
	char letra;
	int count;
	int acertado=0;
	while(run=true){
		cout<<endl<<"Adivine la palabra: "<<crypt;
		cout<<endl<<"  O  "<<endl;
	    cout<<" /|\ "<<endl;
		cout<<"  |  "<<endl;
		cout<<" / \ "<<endl;
		cin>>letra;
		for(int i=0;i<word.length();i++){
			if(letra==word[i]){
				crypt[i]=word[i];
				acertado=1;
			}
			
		}
	}
	//18.19
	string palabra="vaquero";
	int longitud=palabra.length();
	int mitad=longitud/2;
	string pt1;
	string pt2;
	if(longitud%2==0){
		for(int i=0;i<mitad;i++){
			pt1=pt1+palabra[i];
		}
		for(int j=0;j<5;j++){
			pt1=pt1+'*';
		}
		for(int k=mitad;k<longitud;k++){
			pt2=pt2+palabra[k];
		}
		pt1=pt1+pt2;
	}
	else{
		for(int i=0;i<mitad+1;i++){
			pt1=pt1+palabra[i];
		}
		for(int j=0;j<5;j++){
			pt1=pt1+'*';
		}
		for(int k=mitad+1;k<longitud;k++){
			pt2=pt2+palabra[k];
		}
		pt1=pt1+pt2;
	}
	cout<<pt1;
	//18.21
	char frase[]="Esto es.una frase";
	for(int i=0;i<strlen(frase);i++){
		if(frase[i]=='.'){
			frase[i]=' ';
		}
	}
	cout<<endl<<frase<<endl;
	char *tokenptr;
	tokenptr=strtok(frase," ");
	while(tokenptr!=NULL){
		cout<<tokenptr<<endl;
		tokenptr=strtok(NULL," ");
	}
	//18.22
	string chain="vaquero";
	string inverso;
	string::const_iterator iterador1=chain.end()-1;
	while(iterador1!=chain.begin()-1){
		inverso=inverso+*iterador1;
		iterador1--;
	}
	cout<<inverso<<endl;
	//18.27
	string array[]={"dkhf","zob"};
	int tamanio=2;
	for(int i=0;i<tamanio-1;i++){
		for(int j=tamanio-1;j>0;j++){
			array[i].compare(array[j]);
			if(array[i]<array[j]){
				array[i].swap(array[j]);
			}
		}
	}
}
