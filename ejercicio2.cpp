#include <iostream>
#include <array>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    // Inicialización del objeto std::array con 10 países de Sudamérica
    array<string, 12> paises = {
        "Argentina", "Bolivia", "Brasil", "Ecuador", 
        "Guyana", "Paraguay", "Peru", "Surinam", 
        "Uruguay", "Venezuela"
    };

    // a) Insertar los 2 países restantes (Colombia y Chile) utilizando at() y operador []
    paises.at(10) = "Chile";
    paises[11] = "Colombia";

    // b) Imprimir solamente los países cuyos nombres comiencen con las letras C o P
    cout << "--- b) Paises que comienzan con C o P ---" << endl;
    for (const auto& pais : paises) {
        if (!pais.empty() && (pais.front() == 'C' || pais.front() == 'P')) {
            cout << pais << endl;
        }
    }
    cout << endl;

    // c) Imprimir el primer y último elemento
    cout << "--- c) Primer y ultimo elemento ---" << endl;
    cout << "Primer pais: " << paises.front() << endl;
    cout << "Ultimo pais: " << paises.back() << endl << endl;

    // d) Ordenar alfabéticamente todos los países e imprimir el resultado
    sort(paises.begin(), paises.end());
    cout << "--- d) Paises ordenados alfabeticamente ---" << endl;
    for (const auto& pais : paises) {
        cout << pais << endl;
    }

    return 0;
}
