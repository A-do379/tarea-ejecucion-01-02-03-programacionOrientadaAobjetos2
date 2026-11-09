#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    // Definición del array de 20 enteros impares con la distribución solicitada:
    // - Primeros 5: mayores que 20 y menores que 50 (ej. 21, 25, 29, 33, 37)
    // - Siguientes 10 (parte central): impares de relleno (ej. 51, 53, 55, 57, 59, 61, 63, 65, 67, 69)
    // - Últimos 5: menores que 20 (ej. 3, 7, 11, 15, 19)
    array<int, 20> numeros = {
        21, 25, 29, 33, 37,
        51, 53, 55, 57, 59, 61, 63, 65, 67, 69,
        3, 7, 11, 15, 19
    };

    // a) Imprimir todos los elementos
    cout << "--- a) Todos los elementos del arreglo ---" << endl;
    for (auto it = numeros.begin(); it != numeros.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;

    // b) Imprimir únicamente los elementos mayores que 20 y menores que 50
    cout << "--- b) Elementos mayores que 20 y menores que 50 ---" << endl;
    for (size_t i = 0; i < numeros.size(); ++i) {
        if (numeros.at(i) > 20 && numeros.at(i) < 50) {
            cout << numeros.at(i) << " ";
        }
    }
    cout << endl << endl;

    // c) Ordenar los elementos utilizando algoritmos STL e imprimir nuevamente
    sort(numeros.begin(), numeros.end());
    cout << "--- c) Elementos ordenados (Ascendente) ---" << endl;
    for (const auto& num : numeros) {
        cout << num << " ";
    }
    cout << endl << endl;

    // d) Imprimir los elementos ubicados en índices impares menores que 10
    cout << "--- d) Elementos en indices impares menores que 10 ---" << endl;
    for (size_t i = 1; i < 10; i += 2) {
        cout << "Indice " << i << ": " << numeros.at(i) << endl;
    }

    return 0;
}
