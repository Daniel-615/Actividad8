#include <iostream>
using namespace std;
const char *nombre_archivo= "archivo.dat";
void Crear();
void leer();
void actualizar();
void borrar();
struct Estudiante{
    int codigo;
    char nombres[50];
    char apellidos[50];
    int telefono;
};
int main(){
        //Crear();
        //leer();
        //actualizar();
        //borrar();

}
void borrar(){
    const char *nombre_archivo_temp = "archivo_temp.dat";
	FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
	FILE* archivo = fopen(nombre_archivo,"rb");
	Estudiante estudiante;
	int id=0,id_n=0;
	cout<<"Ingrese el ID a eliminar:";
	cin>>id;
	while(fread(&estudiante,sizeof(Estudiante),1,archivo)){
		if (id_n !=id ){
			fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
		}
		id_n++;
	}
	fclose(archivo);
	fclose(archivo_temp);

	archivo_temp = fopen(nombre_archivo_temp,"rb");
	archivo = fopen(nombre_archivo,"wb");
	while(fread(&estudiante,sizeof(Estudiante),1,archivo_temp)){
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);

	}
		fclose(archivo);
	fclose(archivo_temp);
	leer();

};
void actualizar(){
    FILE* archivo = fopen(nombre_archivo,"r+b");
	Estudiante estudiante;
	int id=0;
	cout<<"Ingrese el ID que desea Modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
		cout<<"Ingrese Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();

		cout<<"Ingrese Nombres:";
		cin.getline(estudiante.nombres,50);

		cout<<"Ingrese Apellidos:";
		cin.getline(estudiante.apellidos,50);

		cout<<"Ingrese Telefono:";
		cin>>estudiante.telefono;

		fwrite(&estudiante,sizeof(Estudiante),1,archivo);


	fclose(archivo);
	leer();

};
void Crear(){
    FILE*archivo=fopen(nombre_archivo,"a+b");
    Estudiante estudiante;
    char res;
    do{
        fflush(stdin);
        cout<<"Ingrese Codigo: ";
        cin>>estudiante.codigo;
        cin.ignore();
        cout<<"Ingrese Nombres: ";
        cin.getline(estudiante.nombres,50);

        cout<<"Ingrese Apellidos: ";
        cin.getline(estudiante.apellidos,50);

        cout<<"Ingrese Telefono: ";
        cin>>estudiante.telefono;

        fwrite(&estudiante,sizeof(Estudiante),1,archivo);
        cout<<"Desea ingresar otro estudiante (S/N)";
        cin>>res;
        system("cls");
    }while(res=='s' || res=='S');
    leer();
    fclose(archivo);
};
void leer(){
    system("cls");
     FILE*archivo=fopen(nombre_archivo,"rb");
     if(!archivo){
           FILE*archivo=fopen(nombre_archivo,"w+b");
     }
     Estudiante estudiante;
     int id=0;
     fread(&estudiante,sizeof(Estudiante),1,archivo);
     cout<<"=========================================="<<endl;
     cout<<"ID"<<"|"<<"CODIGO"<<"|"<<"NOMBRES"<<"|"<<"APELLIDOS"<<"|"<<"TELEFONO"<<endl;
     do{
        cout<<"ID"<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;
        fread(&estudiante,sizeof(Estudiante),1,archivo);
        id+=1;
     }while(feof(archivo)==0);
     fclose(archivo);
};
