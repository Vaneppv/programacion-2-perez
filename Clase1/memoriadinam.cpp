#include <iostream>
using namespace std; 

/* Cuando se trabaja con memoria dinamica, cuando un arreglo se llena.
Se crea uno nuevo con el doble de almacenamiento, se copia y se libera el viejo. 
Ej: */
int main(){
    int *x = new int [5];

    int *y = new int [10];
    for (int i = 0; i < 5; i++)
    {
        x[i]=y[i];
    }

    return 0;
}
