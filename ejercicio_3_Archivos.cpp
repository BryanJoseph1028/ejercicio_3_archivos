#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
 
 
 const char *nombre_archivo = "regristro_2_lineas.txt";
 void ingresar_nombre();
 
int main(){
	ingresar_nombre();
	return 0;	
}

void abrir_archivo(){
	ifstream archivo;
	string contenido;
	archivo.open(nombre_archivo,ios::in);

	
	if (archivo.fail()) {
	cout<<"No se pudo abrir el archivo"<<endl;
	exit(1);
	}else{
	cout<<endl;
		do{
			getline(archivo,contenido);
			cout<<contenido<<endl;
		} while(archivo.eof()==false);
	}
}
void ingresar_nombre(){
	ofstream archivo;
	char continuar;
	archivo.open(nombre_archivo,ios::out);

	if (archivo.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}
	else{
		string nombre;
		string apellidos;
		string profesion;
		string sueldos;
		string sueldoBoni;
		string suma;

		do{
		fflush(stdin);
		cout<<"Ingrese el Nombre del empleado:";
		getline(cin,nombre);
		archivo<<nombre;
		cout<<"Ingrese los apellidos del empleado:";
		getline(cin,apellidos);
		archivo<<apellidos;
		cout<<"Ingrese la profesion del empleado:";
		getline(cin,profesion);
		archivo<<profesion;
		cout<<"Ingrese el sueldo del empleado:";
		getline(cin,sueldos);
		archivo<<sueldos;
		cout<<"Ingrese el sueldo Bonificacion del empleado:";
		getline(cin,sueldoBoni);
		archivo<<sueldoBoni;
		
		cout<<"Desea Agregar otro Nombre, apellido sueldo y profesion s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	}
	archivo.close();
	abrir_archivo();
}
