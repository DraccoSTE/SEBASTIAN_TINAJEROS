#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class afin {
		int a;
		int b;
		int inva;
	public:
		string alfa="abcdefghijklmnopqrstuvwxyz";
		int alfalong=alfa.length();
    	afin(){
        	a=generador(a);
        	srand(time(NULL));
        		b=rand()%alfalong;
    	}
    	afin(int f,int g){
			a=f;
			b=g;
			int aux=EuclidesEx(f,alfalong);
			inva=inversa(aux,alfalong);
		}
    int geta(){
        return a;
    }
    
    int getb(){
        return b;
    }
    
    int modulo(int a,int b){
    int q=a/b;
    int res=a-(q*b);
    if (res<0){
        q--;
        res=a-(q*b);
    }
    return res;
	}
	
	int Euclides(int x,int y){
    int aux=x-((x/y*y));
    while (aux!= 0){
       x=y;
       y=aux;
       aux= x-((x/y)*y);
    }
    return y;
	}
	
	int EuclidesEx(int x, int y){
    int aux;
	int v1 = 1, v2 = 0;
    while(y>0){
        int z=x/y;
        int result=x-(z*y);
        x=y;
        y=result;
        aux=v1-(z*v2);
        v1=v2;
        v2=aux;
    }
    return v1;
	}
	
    int generador(int v){
    	int aux=0;
    	srand(time(NULL));
    		v=rand()%(alfalong);
    	while(aux!=1){
    		v=rand()%(alfalong);
    		aux=Euclides(v,alfalong);
		}
		return v;
	}
	
	int inversa(int x, int y){
		int aux;
		aux=modulo(x,y);
		return aux;
	}
	
    string encriptar(string cadena){
    	string crypt(cadena.length(),' ');
    	int nano;
    	for(int i=0;i<cadena.length();i++){
    		nano=alfa.find(cadena[i]);
			nano=nano*a;
			if(nano>0){
				nano=modulo(nano,alfalong);
				}
			nano=nano+b;
			if(nano>0){
				nano=modulo(nano,alfalong);
				}
			crypt[i]=alfa[nano];
		}
	return crypt;
	}
	
	string descifrar(string cadena){
    	string decrypt(cadena.length(),' ');
    	int nano;
    	for(int i=0;i<cadena.length();i++){
    		nano=alfa.find(cadena[i]);
			nano=nano-b;
			if(nano<0){
				nano=modulo(nano,alfalong);
			}
			nano=nano*inva;
			if(nano>0){
				nano=modulo(nano,alfalong);
			}
			decrypt[i]=alfa[nano];
		}
	return decrypt;
	}

};
int main(){
	afin emisor;
  	afin receptor(emisor.geta(),emisor.getb());
}
