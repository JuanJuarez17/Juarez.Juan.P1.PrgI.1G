#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_STR 50

typedef struct{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
    int isEmpty;
}Notebook;

float aplicarDescuento(float precio);

int contarCaracteres(char vec[], char contar);

int ordenarNoteboook(Notebook vec[], int tam);

void mostrarNotebook(Notebook vec);

int listarNotebook(Notebook vec[], int tam);

int main()
{
    // PRIMER FUNCION

    float precio;
    printf("Ingrese el precio de su producto: ");
    scanf("%f", &precio);
    printf("El precio final de su producto con un descuento del 5 es: $%.2f", aplicarDescuento(precio));


    /*
    // SEGUNDA FUNCION

    char ingreso[TAM_STR];

    printf("Ingrese una cadena de caracteres: ");
    gets(ingreso);
    printf("La cantidad de caracteres es: %d\n", contarCaracteres(ingreso, '2'));
    */

    /*
    // TERCER FUNCION
    Notebook lista[8] = {
        {100, "Intel", "Asus", 15369, 0},
        {110, "Ryzen", "Pavilion", 9865, 0},
        {120, "Inten", "HP", 13568, 0},
        {130, "Intel", "Lenovo", 11250, 0},
        {140, "AMD", "Samsung", 9876, 0},
        {150, "Intel", "Lenovo", 7895, 0},
        {160, "AMD", "Pavilion", 9876, 0},
        {170, "AMD", "Lenovo", 10265, 0},
    };
    listarNotebook(lista, 8);

    system("pause");

    ordenarNoteboook(lista, 8);

    listarNotebook(lista, 8);
    */


    return 0;
}

float aplicarDescuento(float precio){
    return precio - (precio * 0.05);
}

int contarCaracteres(char vec[], char contar){
    int longitud;
    int cont = 0;

    longitud = strlen(vec);

    for(int i = 0; i < longitud; i++){
        if(vec[i] == contar){
            cont++;
        }
    }
    return cont;
}

void mostrarNotebook(Notebook vec){
    printf(" %4d   %10s     %10s     %10.2f\n",
           vec.id,
           vec.procesador,
           vec.marca,
           vec.precio);
}

int listarNotebook(Notebook vec[], int tam){
    int todoOk = 0;
    int flag = 1;
    if(vec != NULL && tam > 0){
        //system("cls");
        printf("********* Lista de notebook *********\n");
        printf("ID   PROCESADOR   MARCA   PRECIO\n");
        printf("--------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++){
            if(vec[i].isEmpty == 0){ //(!vec[i].isEmpty = vec[i].isEmpty == 0) Pregunto si el campo isEmpty de la estructura no esta vacio
                mostrarNotebook(vec[i]);
                flag = 0;
            }
        }
        if(flag){
            printf("*** No hay notebooks en el sistema ***\n\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int ordenarNoteboook(Notebook vec[], int tam){
    int todoOk = 0;
    Notebook aux;
    if(vec != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            for(int j = i + 1; j < tam; j++){
                if (strcmp(vec[i].marca, vec[j].marca) > 0){
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
