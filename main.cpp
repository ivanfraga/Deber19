#include <iostream>
#include <fstream>

void guardarDatos ();
void leerDatos ();
using namespace std;


int main()
{
  int opcion ;
  do{
   cout<<"\n*********************************************\n";
   cout<<"Opcion 1: Registrar datos\n";
   cout<<"Opcion 2: Leer datos\n";
   cout<<"Opcion 3: Salir\n";
   cout<<"Seleccione una opcion : ";
   cin>>opcion;
   cin.ignore();

   cout<<"\n*********************************************\n";
   switch (opcion ){

   case 1 :
   {
     guardarDatos ();
     break;
   }
   case 2 :
   {
   
    leerDatos ();  
    break ; 
   }
   case 3: 
   {
     cout<<"Salio del programa \n";
     break;
   }
   default:{
        cout<<"Opcion no valida intentelo de nuevo "<<endl;
    }
   }
  }while (opcion!=3);
 return 0;
   
}

void guardarDatos(){

  string nombre;
  string apellido;
   
  int edad;
  char d;
  ofstream Drago; // se creo un objeto en ofstream, aqui lo definimos como archivo, para luego abrirlo e ingresar datos
   
  Drago.open("datos.txt",ios::app);//la terminacion ".c_str()" determina como constante a este nombre del archivo
  do
    {
    cout<<"\t Nombre : ";
    getline(cin,nombre,'\n');

    cout<<"\t Apellido : ";
    getline(cin,apellido,'\n');

    cout<<"\t Edad : ";
    cin>>edad;

    Drago << nombre << " " << apellido << " " << edad << "\n"; // Se deben registrar los datos en el archivo creado

    cout<<"Desea ingresar mas datos s/n : ";
    cin>>d;

    cin.ignore();//Se utiliza cin.ignore() para ignorar en este caso la actividad que produce el enter
  }while(d=='s');

   Drago.close(); //Todo archivo abierto se debe cerrar

  
}



void leerDatos (){
  string nombre;
  string apellido;
  string nombrearchivo;
  int edad;
  char r;
     
  ifstream archivolectura("datos.txt"); //se utiliza el ifstream para leer el archivo
  string texto;
  while(!archivolectura.fail())
  {
      
    archivolectura>>nombre>>apellido>>edad;

    if(!archivolectura.eof())
    {
      getline(archivolectura,texto);
      cout<<"Nombre : "<<nombre<<"\n";
      cout<<"Apellido : "<<apellido<<"\n";
      cout<<"Edad : "<<edad<<"\n";

    }

  }
  archivolectura.close(); 
}