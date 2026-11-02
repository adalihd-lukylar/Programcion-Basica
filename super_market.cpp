#include <iostream>
#include <string>
#include <cmath>

using namespace std;    

int main () {

    int sexo, edad, tipo_cliente, dia_semana;
    string nombre;


    cout <<"Bienvenido a  Super Market!" << endl;
    cout <<"INGRESE SU NOMBRE: " << endl;
    cin >> nombre;

    cout << "Seleccione el sexo del cliente: " << endl;
    cout << "1. Masculino" << endl;
    cout << "2. Femenino" << endl;
    cout << "3. Otro" << endl;
    cin >> sexo;

    cout << "Ingrese la edad del cliente: " << endl;
    cin >> edad;
    if (edad < 15 || edad > 100) {
        cout << "Lo siento, no puede ingresar al supermercado." << endl;
        return 0;
    } 

    cout << " seleccione el tipo de cliente: " << endl;
    cout <<"1. Regular" << endl;
    cout <<"2. VIP" << endl;    
    cout <<"3. nuevo " << endl;
    cin >> tipo_cliente;

    cout << "seleccione dia de la semana: " << endl;
    cout <<"1. Lunes" << endl;      
    cout <<"2. Martes" << endl;
    cout <<"3. Miercoles" << endl; 
    cout <<"4. Jueves" << endl;
    cout <<"5. Viernes" << endl;
    cout <<"6. Sabado" << endl;
    cout <<"7. Domingo" << endl;
    cin >> dia_semana;

    

    return 0;
}