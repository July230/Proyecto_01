//Este es el código para la situación problema
/*Diseña un sistema de inventario para registrar la información de las pymes que hay en tu 
comunidad y la información de sus trabajadores. La pyme deberá contener la siguiente 
información: nombre de la empresa, razón social, dirección, nombre del director, número 
de trabajadores y cantidad de pesos que genera al año. La información de los trabajadores 
deberá contener lo siguiente: nombre, edad, puesto, sueldo, nombre de la empresa en la que 
trabaja, dirección del lugar donde trabaja, razón social de la empresa donde trabaja. El 
sistema deberá tener un menú principal interactivo con 5 opciones*/

#include<iostream>
#include<cstdlib>
#include<time.h>
#include<cmath>
#include<string>

using namespace std;

class Pyme{ //Declarar la clase Pyme
    private:
        string pyme, razon, direccion, director; //variables privadas 
        double trabajadores, ingresos;
    public:
        //Pyme(string, string, string, string, double, double); //Constructor de la Pyme
        //Declarar los métodos de la clase dentro de la misma clase, de esta forma se ahorra espacio
        //Lectura
        string get_pyme(){
            return pyme;
        } 
        string get_razon(){
            return razon;
        } 
        string get_direccion(){
            return direccion;
        } 
        string get_director(){
            return director;
        } 
        double get_trabajadores(){
            return trabajadores;
        } 
        double get_ingresos(){
            return ingresos;
        }
        //Escritura
        void set_pyme(string pyme_){
            pyme = pyme_;
        } 
        void set_razon(string razon_){
            razon = razon_;
        }
        void set_direccion(string direccion_){
            direccion = direccion_;
        }
        void set_director(string director_){
            director = director_;
        }
        void set_trabajadores(double trabajadores_){
            trabajadores = trabajadores_;
        }
        void set_ingresos(double ingresos_){
            ingresos = ingresos_;
        }
        
        //Constructor por default de la pyme
        Pyme() : pyme(""), razon(""), direccion(""), director(""), trabajadores(0), ingresos(0) {}
        Pyme(string pyme_, string razon_, string direccion_, string director_, double trabajadores_, double ingresos_): pyme(pyme_), razon(razon_), direccion(direccion_), director(director_), trabajadores(trabajadores_), ingresos(ingresos_){}
};

//Ya no es necesario inicializar las variables de esta manera debido a que se han definido en el constructor por defecto
/*
Pyme::Pyme(string P, string R, string D, string Di, double T, double I){
    P = pyme;
    R = razon;
    D = direccion;
    Di = director;
    T = trabajadores;
    I = ingresos;
};
*/

//Declarar la clase trabajadores, hereda la clase Pyme
class Empleados: public Pyme{ 
    private:
        string nombre, puesto, nom_pyme_e, razon_e, direccion_e; //Datos de los trabajadores
        double edad, sueldo;
        Pyme pyme;
    public:
        //Empleados(string, string, string, string, string, double, double); //Constructor de la clase
        //Declarar métodos de los trabajadores dentro de la misma clase
        //Lectura
        string get_nombre(){
            return nombre;
        } 
        string get_puesto(){
            return puesto;
        } 
        string get_nom_pyme_e(){
            return nom_pyme_e;
        } 
        string get_razon_e(){
            return razon_e;
        } 
        string get_direccion_e(){
            return direccion_e;
        } 
        double get_edad(){
            return edad;
        } 
        double get_sueldo(){
            return sueldo;
        }
        //Escritura
        void set_nombre(string nombre_){
            nombre = nombre_;
        }
        void set_puesto(string puesto_){
            puesto = puesto_;
        }
        void set_nom_pyme_e(string nom_pyme_e_){
            nom_pyme_e = nom_pyme_e_;
        } 
        void set_razon_e(string razon_e_){
            razon_e = razon_e_;
        } 
        void set_direccion_e(string direccion_e_){
            direccion_e = direccion_e_;
        } 
        void set_edad(double edad_){
            edad = edad_;
        } 
        void set_sueldo(double sueldo_){
            sueldo = sueldo_;
        }
        
        Empleados() : nombre(""), puesto(""), nom_pyme_e(""), razon_e(""), direccion_e(""), edad(0), sueldo(0), Pyme() {};
        Empleados(string nombre_, string puesto_, string nom_pyme_e_, string razon_e_, string direccion_e_, double edad_, double sueldo_): nombre(nombre_), puesto(puesto_), nom_pyme_e(nom_pyme_e_), razon_e(razon_e_), direccion_e(direccion_e_), edad(edad_), sueldo(sueldo_) {}
};

//Variables inicializadas en el constructor por defecto
/*
Empleados::Empleados(string N, string p, string Pt, string Rt, string Dt, double Ed, double S){
    N = nombre;
    p = puesto;
    Pt = nom_pyme_e;
    Rt = razon_e;
    Dt = direccion_e;
    Ed = edad;
    S = sueldo;
};
*/




//Función main, aquí está el menú
int main(){
    
    bool haypyme = false; //Las variables bool pueden tener true o false
    bool hayemp = false;
    string operacion; //Para el menu
    int magnitud_lista = 5; //Determinar la magnitudo del arreglo
    int i = 0; //contador de la lista
    string pyme, razon, direccion, director, nombre, puesto, nom_pyme_e, razon_e, direccion_e, salto, buscarp; //Volver a definir las variables
    double trabajadores, ingresos, edad, sueldo;
    
    Pyme lista[magnitud_lista]; //Ya hay constructor por defecto, por lo que sólo se declaran las listas
    Empleados listat[magnitud_lista];
    
    
    
    //Título
    cout << "Base de datos de la PYME\n" << endl;
    
    do{ //Menu de acciones
        cout << "1 = Agregar PYME \n" << "2 = Agregar Trabajador \n" << "3 = Consulta PYME \n" << "4 = Consulta Trabajador \n" << "5 = Salir \n" << endl;
        cin >> operacion;
        
        //Condiciones para cada accion
        if (operacion == "1"){
            getline(cin, salto);
            cout << "Agrega Pyme: " << endl;
            getline(cin, pyme);
            cout << "Agrega razón social de la Pyme: " << endl;
            getline(cin, razon);
            cout << "Agrega dirección de la Pyme: " << endl;
            getline(cin, direccion);
            cout << "Agrega director de la Pyme: " << endl;
            getline(cin, director);
            cout << "Agrega trabajadores de la Pyme: " << endl;
            cin >> trabajadores;
            cout << "Agrega ingresos anuales de la Pyme: " << endl;
            cin >> ingresos;
            
            lista[i] = Pyme(pyme, razon, direccion, director, trabajadores, ingresos);
        }else if(operacion == "2"){
            getline(cin, salto);
            cout << "Agrega Trabajador: " << endl;
            getline(cin, nombre);
            cout << "Agrega el puesto del trabajador: " << endl;
            getline(cin, puesto);
            cout << "Agregar pyme donde trabaja: " << endl;
            getline(cin, nom_pyme_e);
            cout << "Agregar razón social de la pyme donde trabajan: " << endl;
            getline(cin, razon_e);
            cout << "Agregar dirección de la pyme donde trabaja: " << endl;
            getline(cin, direccion_e);
            cout << "Agregar edad del trabajador: " << endl;
            cin >> edad;
            cout << "Agregar sueldo del trabajador: " << endl;
            cin >> sueldo;
            
            listat[i] = Empleados(nombre, puesto, nom_pyme_e, razon_e, direccion_e, edad, sueldo);
        }else if(operacion == "3"){
            cout << "Bucar Pyme " << endl;
            getline(cin, salto); //Evitar error que causa que el código se salte una línea de entrada de datos
            cout << "Nombre de la Pyme buscada: " << endl;
            getline(cin, pyme);
        
            
            for(int i=0; magnitud_lista;i++){
                if (pyme == lista[i].get_pyme()){
                    haypyme = true;
                    cout << "Nombre: " << lista[i].get_pyme() << endl;
                    cout << "Razón social: " << lista[i].get_razon() << endl;
                    cout << "Dirección: " << lista[i].get_direccion() << endl;
                    cout << "Director: " << lista[i].get_director() << endl;
                    cout << "Trabajadores en la Pyme: " << lista[i].get_trabajadores() << endl;
                    cout << "Ingresos anuales: " << lista[i].get_ingresos() << endl;
                }
                if(!haypyme == true){ //Si no hay pyme, imprime el mensaje
                    cout<< "Esta pyme no se encuentra registrada" <<endl;
                    break;
                }
                haypyme = false;
            }
        }else if(operacion == "4"){
            cout << "Bucar Trabajador " << endl;
            getline(cin, salto); //Evitar error que causa que el código se salte una línea de entrada de datos
            cout << "Nombre del trabajador buscado: " << endl;
            getline(cin, nombre);
        
            
            for(int i=0; magnitud_lista;i++){
                if (nombre == listat[i].get_nombre()){
                    hayemp = true;
                        cout << "Datos del trabajador" << endl;
                        cout << "Nombre del trabajador: " << listat[i].get_nombre() <<  endl;
                        cout << "Puesto del trabajador: " << listat[i].get_puesto() <<  endl;
                        cout << "Pyme donde trabaja: " << listat[i].get_nom_pyme_e() <<  endl;
                        cout << "Razón social de la Pyme donde trabaja: " << listat[i].get_razon_e() <<  endl;
                        cout << "Dirección de la Pyme donde trabaja: " << listat[i].get_direccion_e() <<  endl;
                        cout << "Edad del trabajador: " << listat[i].get_edad() <<  endl;
                        cout << "Sueldo del trabajador: " << listat[i].get_sueldo() <<  endl;
                }
                else if(!hayemp == true){ //Si no hay pyme, imprime el mensaje
                    cout<< "Esta trabajador no se encuentra registrado" <<endl;
                    break;
                }
                hayemp = false;
            }
        }else if(operacion == "5"){
            break;
        }
    }while ((operacion!="5")); //Condicion del while

    return 0;
}