## Clase memoria dinamica
# Notes

1. Stack(Pila)
+ Memoria estatica
+ 1 Mb en Windows, hasta 8 Mb en Linux y mac

2. Heap (Monticulo)
+ Memoria Dinamica
+ Reserva memoria hasta llenar la ram
+ Mas accesible
+ Se reserva memoria a medida que se usa, al llenarse 

/* Cuando se trabaja con memoria dinamica, cuando un arreglo se llena.
Se crea uno nuevo con el doble de almacenamiento, se copia y se libera el viejo. 
Ej: */
´´´cpp
int main(){
    int *x = new int [5];

    int *y = new int [10];
    for (int i = 0; i < 5; i++)
    {
        x[i]=y[i];
    }

    return 0;
}
´´´´

3. Estado de excepción: Error que ocurre en tiempo de ejecucion, no se debe a a la sintaxis del codigo. 
+ try-catch para manejar excepciones

4. Memory Leak
+ Cuando se tiene un arreglo de arreglos se debe liberar la memoria de adentro hacia afuera para evitar memory leaks, ya que no podre acceder a la memoria.
+ Si tengo una funcio Ej: 
```cpp
void (){
    new (5);
    return; // Nunca libere memoria y no podre acceder a ella, cada vez que se ejecute reservara mas memoria.
}
````

5. Nullptr
+ Si no lo hago, el sistema puede tratar de usar esa info y se crashea.

Los punteros en algunos sistemas pesan 4 bits en los de sistemas de 32x y 8 bits en los de 64x

6. Call back
+ Una funcion que se envia como argumento o parametro a otra funcion


    