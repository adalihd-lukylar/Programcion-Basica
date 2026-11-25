#include <iostream>

using namespace std;    

bool esPar(int numero) {
    return numero % 2 == 0;
}

int sumar(int a, int b) {
    return a + b;
}

int main() {
    int numero1, numero2;

    cout << "Ingrese el primer numero: ";
    cin >> numero1;5

    cout << "Ingrese el segundo numero : ";
    cin >> numero2;

    int resultadoSuma = sumar(numero1, numero2);
    cout << "La suma de " << numero1 << " y " << numero2 << " es: " << resultadoSuma << endl;

    if (esPar(resultadoSuma)) {
        cout << "El resultado de la suma es un número par." << endl;
    } else {
        cout << "El resultado de la suma es un número impar." << endl;
    }

    return 0;
}