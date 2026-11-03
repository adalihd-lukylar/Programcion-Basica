#include <iostream>
#include <string>
#include <cmath>

using namespace std;    

int main () {

    int sexo, edad, tipo_cliente, cantidad, tipo_producto, agregar_producto;
    string nombre,dia_semana, Tipo_producto;

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
    do {    
    cout <<" seleccione el tipo de producto que desea comprar: " << endl;
    cout <<"1. verduras" << endl;
    cout <<"2. carnes" << endl;
    cout <<"3. licores " << endl;
    cin >> tipo_producto;
    switch (tipo_producto) {
        case 1:
            do {
            cout << "Usted ha seleccionado verduras." << endl;
            cout << " ingrese tipo de producto que desea comprar: " << endl;    
            cout <<"1. tomate      " << endl;
            cout <<"2. repollo     " << endl;
            cout <<"3. papas       " << endl;
            cin >> tipo_producto;
            
                switch (tipo_producto) {
                case 1:
                    cout << "Usted ha seleccionado tomate." << endl;
                    cout << "Precio: L 10.00" << endl;
                    cout << "Ingrese la cantidad que desea comprar: " << endl;
                    cin >> cantidad;
                    cout << "Total a pagar: L " << cantidad * 10.00 << endl;
                    break;
                case 2:
                    cout << "Usted ha seleccionado repollo." << endl;
                    cout << "Precio: L 15.00" << endl;
                    cout << "Ingrese la cantidad que desea comprar: " << endl;
                    cin >> cantidad;
                    cout << "Total a pagar: L " << cantidad * 15.00 << endl;
                    break;
                case 3:
                    cout << "Usted ha seleccionado papas." << endl;
                    cout << "Precio: L 12.00" << endl;
                    cout << "Ingrese la cantidad que desea comprar: " << endl;
                    cin >> cantidad;
                    cout << "Total a pagar: L " << cantidad * 12.00 << endl;
                    break;
                default:
                    cout << "Opción inválida." << endl;
                    break;
                }
                cout <<" desea agregar otro producto menu verduras? "<< endl;
                cout <<"1. si "<< endl;
                cout <<"2. no "<< endl;
                cin >> agregar_producto;
    
            }while (agregar_producto == 1);        

            break;


        case 2:
            do {
            cout << "Usted ha seleccionado carnes." << endl;
            cout << " ingrese tipo de producto que desea comprar: " << endl;    
            cout <<"1. carne molida         " << endl;
            cout <<"2. carne de cerdo  " << endl;
            cout <<"3. cerdo       " << endl;
            cin >> tipo_producto;
            switch (tipo_producto) {    
                case 1:
                cout << "Usted ha seleccionado carne molida." << endl;
                cout << "Precio: L 20.00" << endl;
                cout << "Ingrese la cantidad que desea comprar: " << endl;
                cin >> cantidad;
                cout << "Total a pagar: L " << cantidad * 20.00 << endl;
                break;
                case 2:
                cout << "Usted ha seleccionado carne de cerdo." << endl;
                cout << "Precio: L 18.00" << endl;
                cout << "Ingrese la cantidad que desea comprar: " << endl;
                cin >> cantidad;
                cout << "Total a pagar: L " << cantidad * 18.00 << endl;
                break;
                case 3:
                    cout << "Usted ha seleccionado  carne de cerdo." << endl;
                    cout << "Precio: L 22.00" << endl;
                    cout << "Ingrese la cantidad que desea comprar: " << endl;
                    cin >> cantidad;
                    cout << "Total a pagar: L " << cantidad * 22.00 << endl;
                    break;
                default:
                    cout << "Opción inválida." << endl;
                    break;
                }
                cout <<" desea agregar otro producto menu carnes? "<< endl;
                cout <<"1. si "<< endl;
                cout <<"2. no "<< endl;
                cin >> agregar_producto;
            
            }while (agregar_producto == 1);
            
            break;


        case 3:
                do {
                cout << "Usted ha seleccionado licores." << endl;
                cout << "verifique la edad del cliente: " << endl;
                cin >> edad;
                    if (edad <= 18) {
                        cout << "Lo siento, no puede comprar licores." << endl;
                        return 0;
                    } else {
                        cout << "Ingrese el tipo de licor que desea comprar: " << endl;    
                        cout <<"1. cerveza nacional       " << endl;
                        cout <<"2. cerveza importada   " << endl;
                        cout <<"3. vino  " << endl;
                        cout <<"4. vodka  " << endl; 
                        cin >> tipo_producto;
                        switch (tipo_producto) {
                            case 1:
                                cout << "Usted ha seleccionado cerveza nacional." << endl;
                                cout << "Precio: L 50.00" << endl;
                                cout << "Ingrese la cantidad que desea comprar: " << endl;
                                cin >> cantidad;
                                cout << "Total a pagar: L " << cantidad * 50.00 << endl;
                                break;
                            case 2:
                                cout << "Usted ha seleccionado cerveza importada." << endl;
                                cout << "Precio: L 80.00" << endl;
                                cout << "Ingrese la cantidad que desea comprar: " << endl;
                                cin >> cantidad;
                                cout << "Total a pagar: L " << cantidad * 80.00 << endl;
                                break;
                            case 3:
                                cout << "Usted ha seleccionado vino." << endl;
                                cout << "Precio: L 200.00" << endl;
                                cout << "Ingrese la cantidad que desea comprar: " << endl;
                                cin >> cantidad;
                                cout << "Total a pagar: L " << cantidad * 200.00 << endl;       
                                break;
                            case 4:
                                cout << "Usted ha seleccionado vodka." << endl;
                                cout << "Precio: L 100.00" << endl;
                                cout << "Ingrese la cantidad que desea comprar: " << endl;
                                cin >> cantidad;
                                cout << "Total a pagar: L " << cantidad * 100.00 << endl;
                                break;  
                            default:
                                cout << "Opción inválida." << endl;
                                break;
                        } 
                        cout <<" desea agregar otro producto menu licores? "<< endl;
                        cout <<"1. si "<< endl;
                        cout <<"2. no "<< endl;
                        cin >> agregar_producto; 
                    }

                }while (agregar_producto == 1);

            break;
        default:
            cout << "Opción inválida." << endl;
            break;
   }    cout <<" desea agregar otro producto menu principal? "<< endl;
        cout <<"1. si "<< endl;
        cout <<"2. no "<< endl;
        cin >> agregar_producto; 
    }while (agregar_producto == 1);




    return 0;
}