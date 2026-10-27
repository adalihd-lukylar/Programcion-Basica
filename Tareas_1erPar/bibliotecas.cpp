#include <iostream> //binlioteca estandar de entrada y salida
#include <string> //biblioteca de manejo de cadenas
#include <cmath> //biblioteca de funciones matematicas
#include <iomanip> //biblioteca de manipulacion de entrada y salida

using namespace std; //espacio de nombres estandar
 
int main() {
    int edad;
    string nombre;

    cout<< "ingrese su nombre: ";
    getline(cin, nombre);  //solicita al usuario que ingrese su nombre tomando en cu
    //enta los espacios
    cout<< "ingrese su edad: ";
    cin>> edad;  //solicita al usuario que ingrese su edad  
    cout<< "su nombre es: " << nombre << " y su edad es: " << edad << endl;
    //muestra el nombre y la edad ingresados por el usuario

    //ejemplo de la libreria math para redondear un numero
    double numero = 3.7;
    cout << "el numero original es: " << numero  << endl;//muestra el numero el numero original y el numero redondeado
    cout << "NUmero redondeado es: " << round(numero) << endl; //muestra el numero redondeado   

    //ejmplo de la libreria iomanip para mostrar un numero con dos decimales
    double numero2 = 3.14159;
    cout << "el numero original es: " << numero2 << endl; //muestra el numero original y el numero con dos decimales
    cout << "el numero con dos decimales es: " << fixed << setprecision(2) << numero2 << endl; //muestra el numero con dos decimales

    return 0; //indica que el programa finalizo correctamente
}