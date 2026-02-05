#include <iostream>
#include <locale>
#include <iomanip>
using namespace std;

/* 
===============================================
    EJERCICIO PUNTEROS Y MEMORIA DINÁMICA
===============================================
*/

// 1. Función para crear arreglo dinámico de numeros enteros
int* crearArreglo(int tamanio) {

    if (tamanio <= 0) // Validando que el tamaño sea positivo
    {
        return nullptr; 
    } 
    
    int* arreglodinamico = new int[tamanio]; // Creando arreglo dinamico con new

    if (arreglodinamico == nullptr) // Verificando que new no retorne nullptr
    {
        cout << "Error, memoria no asignada." << endl;
    }
    return arreglodinamico;
}

// 2. Función para llenar el arreglo con valores ingresados por el usuario
void llenarArreglo(int* arreglo, int tamanio) {
    if (arreglo==nullptr) // Verificando que el arreglo no sea nullptr
    {
        return;
    }
    
    cout << "Ingrese " << tamanio << " numeros para el arreglo." << endl;
    for (int i = 0; i < tamanio; i++)
    {
        cout << "Elemento [" << i+1 << "]: ";
        cin >> arreglo[i];
    } // Llenando arreglo con valores ingresados por el usuario
}

// 3. Función para mostrar todos los números del arreglo
void mostrarArreglo(int* arreglo, int tamanio) {
    if (arreglo==nullptr) // Verificando que arreglo no sea nullptr o vacio
    {
        cout << "Arreglo vacio o no inicializado";
        return;
    }
    cout << "Arreglo: "; 
    for (int i = 0; i < tamanio; i++) // Mostrando elementos del arreglo
    {
        cout << "Elemento [" << i+1 << "]: " << arreglo[i] << " ";
    }
}

// 4. Función para encontrar el número mayor
int encontrarMayor(int* arreglo, int tamanio) {

    if (arreglo==nullptr || tamanio<=0)
    {
        return 0; 
    }
    
    int mayor = arreglo[0];

    for (int i = 1; i < tamanio; i++) 
    {
        if (mayor < arreglo[i])
        {
            mayor = arreglo[i];
        }
    } // Buscando el número mayor en el arreglo

    return mayor; // Retornando el número mayor
}

// 5. Función para calcular el promedio
float calcularPromedio(int* arreglo, int tamanio) {
    
    if (arreglo==nullptr || tamanio<=0)
    {
        return 0.0f; 
    }
    
    int suma = 0;
    float Promedio;
    
    for (int i = 0; i < tamanio; i++) // Sumando todos los elementos
    {
        suma += arreglo[i];
    }
    Promedio = suma/tamanio; // Sacando promedio

    return Promedio; // Retornando el promedio
}

// 6. Función para liberar la memoria del arreglo correctamente
void liberarArreglo(int*& arreglo) {
   
    if (arreglo != nullptr) // Verificando que arreglo no sea nullptr
    {
        delete[] arreglo; // Liberando memoria
        arreglo = nullptr; // Asignando nullptr para evitar un puntero colgante
    }
}

// 7. Función para mostrar el menú
void mostrarMenu() {
    cout << "\n=== GESTIÓN DE ARREGLOS DINÁMICOS ===" << endl;
    cout << "1. Crear y llenar arreglo" << endl;
    cout << "2. Mostrar arreglo" << endl;
    cout << "3. Encontrar número mayor" << endl;
    cout << "4. Calcular promedio" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    setlocale(LC_ALL, "spanish");
    
    // Variables principales
    int* arreglo = nullptr;
    int tamanio = 0;
    
    cout << "=== GESTIÓN DE ARREGLOS DINÁMICOS ===" << endl;
    
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1: {
                // Crear y llenar arreglo
                cout << "Ingrese el tamaño del arreglo: ";
                cin >> tamanio;
                
                arreglo = crearArreglo(tamanio);
                if (arreglo != nullptr) {
                    llenarArreglo(arreglo, tamanio);
                    cout << "Arreglo creado y llenado correctamente." << endl;
                } else {
                    cout << "Error al crear el arreglo." << endl;
                }
                break;
            }
            
            case 2: {
                // Mostrar arreglo
                if (arreglo != nullptr) {
                    mostrarArreglo(arreglo, tamanio);
                } else {
                    cout << "No hay arreglo creado. Use la opción 1 primero." << endl;
                }
                break;
            }
            
            case 3: {
                // Encontrar número mayor
                if (arreglo != nullptr && tamanio > 0) {
                    int mayor = encontrarMayor(arreglo, tamanio);
                    cout << "El número mayor es: " << mayor << endl;
                } else {
                    cout << "No hay arreglo creado o está vacío. Use la opción 1 primero." << endl;
                }
                break;
            }
            
            case 4: {
                // Calcular promedio
                if (arreglo != nullptr && tamanio > 0) {
                    float promedio = calcularPromedio(arreglo, tamanio);
                    cout << "El promedio es: " << fixed << setprecision(2) << promedio << endl;
                } else {
                    cout << "No hay arreglo creado o está vacío. Use la opción 1 primero." << endl;
                }
                break;
            }
            
            case 5: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            
            default: {
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
            }
        }
    } while (opcion != 5);
    
    // Liberar memoria antes de salir
    liberarArreglo(arreglo);
    
    cout << "Programa finalizado. Memoria liberada." << endl;
    return 0;
}