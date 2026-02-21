## Clase Ficheros

Tipos de documentos: CSV, CCV, TXT, JSON.
CSV se separa por ,
Archivo Binario: no legible en lenguaje comun, no puede ser compartido entre diferentes arquitecturas de procesadores. 

ios::ap viene de append = si ya existe, agrega al final
ios::ate = se agre al final del archivo
ios::trunc

fstream:
+ofstream = escritura
Crea un archivo con el nombre especificado
Sobreescribe si ya existe

+iftream = lectura

getline recibe dos parametros: la fuente(source) y el target, de donde lo obtendre y donde lo guardare.


# Separa caracteres (espacios por espacio)

´´´cpp

int main() {
    // Crear un objeto de tipo ifstream para leer el archivo
    ifstream archivo("ejemplo.txt"); 

    // Verificar si el archivo se pudo abrir
    if (archivo.is_open()) {
        char c;
        cout << "Contenido del archivo:\n";
        while (archivo.get(c)) { // Leer linea por linea
            cout << "[" << c << "]" << endl;
        }
        archivo.close(); // Cerrar el archivo
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }

    return 0;
}
´´´

´´´cpp

int main() {
    // Crear un objeto de tipo ifstream para leer el archivo
    ifstream archivo("ejemplo.txt"); 

    // Verificar si el archivo se pudo abrir
    if (archivo.is_open()) {
        char palabra;
        cout << "Contenido del archivo:\n";
        while (archivo >> palabra) { // Leer linea por linea
            cout << "[" << palabra << "]" << endl;
        }
        archivo.close(); // Cerrar el archivo
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }

    return 0;
}
´´´

Hacer funcion solicitar substring, solicitar entero, solicitar entero. 
dentro de la funcion solicitar la informacion, leerla, si es esp o otro comando, salir, si no pues leerla. 

Principio DRY
"Don´t Repeat yourself"
