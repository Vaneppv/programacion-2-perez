/*
 * EJERCICIO CLASE 2 - PUNTEROS Y STRUCTS
 * ======================================
 */

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

struct Materia {
    int codigo;
    char nombre[40];
    int creditos;
};

struct Estudiante {
    int id;
    char nombre[40];
    float promedio;
    int codigoMateriaPrincipal;
};

struct Escuela {
    Estudiante* estudiantes;
    int cantidadEstudiantes;
    Materia* materias;
    int cantidadMaterias;
};

// Crea la escuela con arreglos dinamicos
void crearEscuela(Escuela& escuela, int cantEst, int cantMat) {
    if (cantEst <= 0 || cantMat <= 0)
    {
        return;
    }
    if (escuela.estudiantes!=nullptr)
    {
        delete[] escuela.estudiantes;
        escuela.estudiantes = nullptr;
    }
     if (escuela.materias != nullptr)
    {
        delete[] escuela.materias;
        escuela.materias = nullptr;        
    }
    escuela.cantidadEstudiantes = cantEst;
    escuela.cantidadMaterias = cantMat;
    escuela.estudiantes = new Estudiante[cantEst];
    escuela.materias = new Materia[cantMat];
}

// Llena la lista de estudiantes
void llenarEstudiantes(Escuela& escuela) {
    if (escuela.estudiantes==nullptr || escuela.materias == nullptr)
    {
        return;
    }
    
    for (int i = 0; i < escuela.cantidadEstudiantes; i++)
    {
        cout << "Ingrese Nombre del Estudiante [" << (i+1) << "]: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(escuela.estudiantes[i].nombre, 40);
        cout << "Ingrese ID del Estudiante [" << (i+1) << "]: ";
        cin >> escuela.estudiantes[i].id; 
        cout << "Ingrese promedio del Estudiante [" << (i+1) << "]: ";
        cin >> escuela.estudiantes[i].promedio;
        

        int *codMat = new int();
        bool existe = false;

        do
        {
            cout << "Ingrese codigo de la materia principal del Estudiante [" << (i+1) << "]: ";
            cin >> *codMat;
            for (int j = 0; j < escuela.cantidadMaterias; j++)
            {
                if (*codMat == escuela.materias[j].codigo)
                {
                    existe = true;
                    break;
                }               
            }
            
            if (existe!=true)
            {
                cout << "Error: El codigo ingresado no existe, intente de nuevo.";
            }
            
        } while (existe!=true);
        escuela.estudiantes[i].codigoMateriaPrincipal = *codMat;
        
        delete codMat;
        codMat = nullptr;
    }
}

// Llena la lista de materias
void llenarMaterias(Escuela& escuela) {
    if (escuela.materias == nullptr )
    {
        return;
    }
    
    for (int i = 0; i < escuela.cantidadMaterias; i++)
    {
        cout << "Ingrese nombre de la Materia [" << (i+1) << "]: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(escuela.materias[i].nombre, 40);
        cout << "Ingrese codigo de la Materia [" << (i+1) << "]: ";
        cin >> escuela.materias[i].codigo;
        cout << "Ingrese creditos de la Materia [" << (i+1) << "]: ";
        cin >> escuela.materias[i].creditos;
    }
}

// Muestra la escuela completa
void mostrarEscuela(const Escuela& escuela) {
    
    if (escuela.estudiantes==nullptr || escuela.materias == nullptr)
    {
        return;
    }

    cout << "\n===== Lista de Materias =====" << endl;
    cout << left << setw(10) << "Cod" << setw(20) << "Nombre" << "Creditos" << endl;

    for (int i = 0; i < escuela.cantidadMaterias; i++)
    {
        cout << setw(10) << escuela.materias[i].codigo
        << setw(20) << escuela.materias[i].nombre
        << escuela.materias[i].creditos << endl;
    }

    cout << endl;
    cout << "\n===== Estudiantes =====" << endl;
    cout << left << setw(10) << "ID" << setw(20) << "Nombre" << "Prom" << "Cod Materia" << endl;

    for (int i = 0; i < escuela.cantidadEstudiantes; i++)
    {
        cout << setw(10) << escuela.estudiantes[i].id
        << setw(20) << escuela.estudiantes[i].nombre
        << setw(10) << escuela.estudiantes[i].promedio
        << escuela.estudiantes[i].codigoMateriaPrincipal << endl;
    }    
}

// Retorna el indice del estudiante con mejor promedio
int buscarMejorPromedio(const Escuela& escuela) {
    if (escuela.estudiantes == nullptr || escuela.cantidadEstudiantes <= 0)
    {
        return -1;
    }

    int indiceMax = 0;
    for (int i = 1; i < escuela.cantidadEstudiantes; i++)
    {
        if (escuela.estudiantes[indiceMax].promedio < escuela.estudiantes[i].promedio)
        {
            indiceMax= i;
        }
    }
    return indiceMax;
}

// Calcula el promedio general de la escuela
float calcularPromedioGeneral(const Escuela& escuela) {
    if (escuela.estudiantes == nullptr || escuela.cantidadEstudiantes <= 0)
    {
        return 0.0f;
    }
    
    float PromedioG = 0;

    for (int i = 0; i < escuela.cantidadEstudiantes; i++)
    {
        PromedioG += escuela.estudiantes[i].promedio;
    }
    PromedioG /= escuela.cantidadEstudiantes;
    return PromedioG;
}

// Busca un estudiante por id y retorna su indice
int buscarEstudiantePorId(const Escuela& escuela, int id) {
    if (escuela.estudiantes == nullptr || escuela.cantidadEstudiantes <= 0)
    {
        return -1;
    }
    
    int *tempID = new int (id);
    int IndiceEncontrado = -1;
    for (int i = 0; i < escuela.cantidadEstudiantes; i++)
    {
        if (*tempID == escuela.estudiantes[i].id)
        {
            IndiceEncontrado = i;
            break;
        }
    }
    delete tempID;
    tempID = nullptr;

    return IndiceEncontrado; 
}

// Libera la memoria de la escuela
void liberarEscuela(Escuela& escuela) {
    delete[] escuela.estudiantes;
    delete[] escuela.materias;
    escuela.estudiantes = nullptr;
    escuela.materias = nullptr;
    escuela.cantidadEstudiantes = 0;
    escuela.cantidadMaterias = 0;
}

// Muestra el menu principal
void mostrarMenu() {
    cout << "\n=== GESTION DE ESTUDIANTES ===" << endl;
    cout << "1. Crear y llenar escuela" << endl;
    cout << "2. Mostrar escuela" << endl;
    cout << "3. Estudiante con mejor promedio" << endl;
    cout << "4. Promedio general" << endl;
    cout << "5. Buscar por id" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    Escuela escuela;
    escuela.estudiantes = nullptr;
    escuela.materias = nullptr;
    escuela.cantidadEstudiantes = 0;
    escuela.cantidadMaterias = 0;

    cout << "=== GESTION DE ESTUDIANTES ===" << endl;

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int cantEst = 0;
                int cantMat = 0;
                cout << "Ingrese la cantidad de estudiantes: ";
                cin >> cantEst;
                cout << "Ingrese la cantidad de materias: ";
                cin >> cantMat;

                liberarEscuela(escuela);
                crearEscuela(escuela, cantEst, cantMat);

                if (escuela.estudiantes != nullptr && escuela.materias != nullptr) {
                    llenarMaterias(escuela);
                    llenarEstudiantes(escuela);
                    cout << "Escuela creada y llenada correctamente." << endl;
                } else {
                    cout << "Error al crear la escuela." << endl;
                }
                break;
            }

            case 2: {
                if (escuela.estudiantes != nullptr && escuela.materias != nullptr) {
                    mostrarEscuela(escuela);
                } else {
                    cout << "No hay escuela creada. Use la opcion 1 primero." << endl;
                }
                break;
            }

            case 3: {
                if (escuela.estudiantes != nullptr && escuela.cantidadEstudiantes > 0) {
                    int indice = buscarMejorPromedio(escuela);
                    if (indice >= 0) {
                        cout << "Mejor promedio: " << escuela.estudiantes[indice].nombre
                             << " (" << fixed << setprecision(2)
                             << escuela.estudiantes[indice].promedio << ")" << endl;
                    } else {
                        cout << "No hay estudiantes en la lista." << endl;
                    }
                } else {
                    cout << "No hay escuela creada o esta vacia." << endl;
                }
                break;
            }

            case 4: {
                if (escuela.estudiantes != nullptr && escuela.cantidadEstudiantes > 0) {
                    float promedio = calcularPromedioGeneral(escuela);
                    cout << "Promedio general: " << fixed << setprecision(2)
                         << promedio << endl;
                } else {
                    cout << "No hay escuela creada o esta vacia." << endl;
                }
                break;
            }

            case 5: {
                if (escuela.estudiantes != nullptr && escuela.cantidadEstudiantes > 0) {
                    int idBuscado;
                    cout << "Ingrese el id a buscar: ";
                    cin >> idBuscado;
                    int indice = buscarEstudiantePorId(escuela, idBuscado);
                    if (indice >= 0) {
                        cout << "Encontrado: " << escuela.estudiantes[indice].nombre
                             << " (" << fixed << setprecision(2)
                             << escuela.estudiantes[indice].promedio << ")" << endl;
                    } else {
                        cout << "No se encontro un estudiante con ese id." << endl;
                    }
                } else {
                    cout << "No hay escuela creada o esta vacia." << endl;
                }
                break;
            }

            case 6: {
                cout << "Saliendo del programa..." << endl;
                break;
            }

            default: {
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
            }
        }
    } while (opcion != 6);

    liberarEscuela(escuela);
    cout << "Programa finalizado. Memoria liberada." << endl;
    return 0;
}
