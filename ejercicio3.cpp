#include <iostream>
#include <array>
#include <string>
#include <fstream>

using namespace std;

// Estructura que representa a un estudiante
struct Estudiante {
    string nombre;
    int anioNacimiento;
    double gpa;
};

int main() {
    const int TOTAL_ESTUDIANTES = 10;
    const int ANIO_ACTUAL = 2026;
    array<Estudiante, TOTAL_ESTUDIANTES> estudiantes;

    // Inicialización con los dos primeros estudiantes
    estudiantes[0] = {"Juan", 2000, 3.4};
    estudiantes[1] = {"Maria", 2005, 2.8};

    // a) Registrar el tercer y cuarto estudiante mediante datos ingresados por teclado
    cout << "--- Registro del tercer estudiante ---" << endl;
    cout << "Nombre: ";
    cin >> estudiantes[2].nombre;
    cout << "Anio de nacimiento: ";
    cin >> estudiantes[2].anioNacimiento;
    cout << "Promedio GPA: ";
    cin >> estudiantes[2].gpa;

    cout << "\n--- Registro del cuarto estudiante ---" << endl;
    cout << "Nombre: ";
    cin >> estudiantes[3].nombre;
    cout << "Anio de nacimiento: ";
    cin >> estudiantes[3].anioNacimiento;
    cout << "Promedio GPA: ";
    cin >> estudiantes[3].gpa;

    // b) Registrar el quinto y sexto estudiante utilizando arrays básicos
    // Arrays proporcionados: nombres = [Gaby, Patty, Diana], nacimientos = [2002, 2004, 2006], gpas = [3.8, 3.0, 2.9]
    // Explicación: Se emplean índices directos (posición 0 y 1 de los arrays básicos) para seleccionar 
    // a Gaby y Patty respectivamente, asignando sus propiedades correspondientes al contenedor std::array.
    string nombresArr[3] = {"Gaby", "Patty", "Diana"};
    int nacimientosArr[3] = {2002, 2004, 2006};
    double gpasArr[3] = {3.8, 3.0, 2.9};

    estudiantes[4] = {nombresArr[0], nacimientosArr[0], gpasArr[0]}; // Gaby
    estudiantes[5] = {nombresArr[1], nacimientosArr[1], gpasArr[1]}; // Patty

    // c) Registrar los cuatro estudiantes restantes leyendo desde el archivo externo datos.txt
    ifstream archivo("datos.txt");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo datos.txt" << endl;
        return 1;
    }

    // Índices del 6 al 9 para los 4 estudiantes restantes
    for (int i = 6; i < TOTAL_ESTUDIANTES; ++i) {
        archivo >> estudiantes[i].nombre >> estudiantes[i].anioNacimiento >> estudiantes[i].gpa;
    }
    archivo.close();

    // d) Mostrar los 10 estudiantes registrados, edad actual y si califica para beca (GPA >= 3.5)
    cout << "\n========================================" << endl;
    cout << "   LISTADO GENERAL DE ESTUDIANTES       " << endl;
    cout << "========================================" << endl;
    for (int i = 0; i < TOTAL_ESTUDIANTES; ++i) {
        int edad = ANIO_ACTUAL - estudiantes[i].anioNacimiento;
        string beca = (estudiantes[i].gpa >= 3.5) ? "SI califica" : "NO califica";

        cout << "Estudiante " << (i + 1) << ":" << endl;
        cout << "  - Nombre: " << estudiantes[i].nombre << endl;
        cout << "  - Anio de nacimiento: " << estudiantes[i].anioNacimiento << endl;
        cout << "  - Edad actual (" << ANIO_ACTUAL << "): " << edad << " años" << endl;
        cout << "  - GPA: " << estudiantes[i].gpa << endl;
        cout << "  - Beca: " << beca << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}
