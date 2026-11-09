//funciones sin valor de retorno
// es una funcion que no devuelve ningun valor, solo realiza una accion
#include <iostream>
using namespace std;

void saludar() {
    cout << "Hola, bienvenido a la clase de C++!" << endl;
}   
// recibe dos numeros y los suma, no devuelve ningun valor
void sumar(int a, int b) {
    int resultado = a + b;
    cout << "La suma de " << a << " y " << b << " es: " << resultado << endl;
}   

// recibe un numero y lo multiplica por 2, no devuelve ningun valor
void multiplicarPorDos(int numero) {    
    int resultado = numero * 2;
    cout << "El resultado de multiplicar " << numero << " por 2 es: " << resultado << endl;
}

//es la funcion principal del programa, donde se llaman a las funciones definidas anteriormente
int main() {
    saludar(); // Llamada a la función saludar
    sumar(5, 3); // Llamada a la función sumar con los números 5 y 3
    multiplicarPorDos(4); // Llamada a la función multiplicarPorDos con el número 4

    return 0;
}

/// funciones con valor de retorno
// es una funcion que devuelve un valor, puede ser de cualquier tipo de dato

int sumarConRetorno(int a, int b) {
    return a + b;
}

int multiplicarPorDosConRetorno(int numero) {
    return numero * 2;
}

//bool si el valor es par o impar, devuelve true si es par y false si es impar
bool esPar(int numero) {
    return numero % 2 == 0;
}
string obtenerNombreCompleto(string nombre, string apellido) {
    return nombre + " " + apellido;
}

