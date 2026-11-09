/*Se realiza el profram donde se calcula en registro de las calificaciones de 5 estudiantes temiendeo como referencia en 1er ,2do ,3er parcial 
sera  tomara del 1er-25%, 2do-35% y 3er-40% de la calificacion final 
las notas deben ingresarsse en base a 100,aparte con el promedio final mostrar una ponderacion de acuerdo a la siguiente tabla
100-90 =sobresaliente
89-80 =notable
79-70 =bueno
69-60 =suficiente
59-0 =insuficiente
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main() {
    const int numEstudiantes = 5;   
    double calificaciones[numEstudiantes][3]; // 3 parciales por estudiante
    double promedioFinal[numEstudiantes];
    string ponderacion[numEstudiantes];

    for (int i = 0; i < numEstudiantes; ++i) {
        cout << "Ingrese las calificaciones del estudiante " << (i + 1) << ":\n";
        cout << "Primer parcial (25%): ";
        cin >> calificaciones[i][0];
        cout << "Segundo parcial (35%): ";
        cin >> calificaciones[i][1];
        cout << "Tercer parcial (40%): ";
        cin >> calificaciones[i][2];

        // Calcular el promedio final ponderado
        promedioFinal[i] = (calificaciones[i][0] * 0.25) + 
                           (calificaciones[i][1] * 0.35) + 
                           (calificaciones[i][2] * 0.40);

        // Determinar la ponderación según la tabla
        if (promedioFinal[i] >= 90) {
            ponderacion[i] = "Sobresaliente";
        } else if (promedioFinal[i] >= 80) {
            ponderacion[i] = "Notable";
        } else if (promedioFinal[i] >= 70) {
            ponderacion[i] = "Bueno";
        } else if (promedioFinal[i] >= 60) {
            ponderacion[i] = "Suficiente";
        } else {
            ponderacion[i] = "Insuficiente";
        }
    }

    // Mostrar resultados
    cout << fixed << setprecision(2);
    for (int i = 0; i < numEstudiantes; ++i) {
        cout << "\nEstudiante " << (i + 1) << ":\n";
        cout << "Promedio final: " << promedioFinal[i] << "\n";
        cout << "Ponderación: " << ponderacion[i] << "\n";
    }

    return 0;
}