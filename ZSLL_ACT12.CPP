// LUISA LIZETH ZEREGA SOTO 
// MAT:356491
// FECHA: 9-11-2023
// DESCRIP: Archivos Texto.
// ZSL_ACT12.CPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REGISTROS 1500

typedef struct {
    int status;
    int matricula;
    char ApPat[30];
    char ApMat[30];
    char Nombre[30];
    int Edad;
    char sexo;
} Registro;

int leer_archivo(Registro vect[], int i) {
    int x;
    FILE *fa;
    Registro reg;
    fa = fopen("datos.txt", "r");
    if (fa) {
        do {
            fscanf(fa, "%d%d%s%s%s%c%d", &x, &reg.matricula, reg.ApPat, reg.ApMat, reg.Nombre, &reg.sexo, &reg.Edad);
            vect[i] = reg;
            i++;
        } while (!feof(fa));
        fclose(fa);
    } else {
        printf("No existe");
    }
    return i;
}

void cargarArchivo(Registro registros[], int* numRegistros) {
    *numRegistros = leer_archivo(registros, *numRegistros);
}

void agregar(Registro registros[], int* numRegistros) {
    int matricula;
    printf("Ingrese la matricula del alumno a buscar: ");
    scanf("%d", &matricula);
    
    for (int i = 0; i < *numRegistros; i++) {
        if (registros[i].matricula == matricula && registros[i].status == 1) {
            printf("Registro encontrado:\n");
            printf("Matricula: %d\n", registros[i].matricula);
            printf("Apellido Paterno: %s\n", registros[i].ApPat);
            printf("Apellido Materno: %s\n", registros[i].ApMat);
            printf("Nombre: %s\n", registros[i].Nombre);
            printf("Edad: %d\n", registros[i].Edad);
            printf("Sexo: %c\n", registros[i].sexo);
            return;
        }
    }
    
    printf("No se encontró ningún registro con esa matricula.\n");
}

int buscar(Registro registros[], int numRegistros, int matricula) {
    printf("Ingrese la matricula del alumno a buscar: ");
    scanf("%d", &matricula);
    
    for (int i = 0; i < numRegistros; i++) {
        if (registros[i].matricula == matricula && registros[i].status == 1) {
            printf("Registro encontrado:\n");
            printf("Matricula: %d\n", registros[i].matricula);
            printf("Apellido Paterno: %s\n", registros[i].ApPat);
            printf("Apellido Materno: %s\n", registros[i].ApMat);
            printf("Nombre: %s\n", registros[i].Nombre);
            printf("Edad: %d\n", registros[i].Edad);
            printf("Sexo: %c\n", registros[i].sexo);
            return i;
        }
    }
    
    printf("No se encontró ningún registro con esa matricula.\n");    
    return -1; 
}

void ordenar(Registro registros[], int numRegistros) {
    Registro temp;
    
    for (int i = 0; i < numRegistros - 1; i++) {
        for (int j = 0; j < numRegistros - i - 1; j++) {
            if (registros[j].matricula > registros[j + 1].matricula) {
                temp = registros[j];
                registros[j] = registros[j + 1];
                registros[j + 1] = temp;
            }
        }
    }
    
    printf("Registros ordenados correctamente.\n");   
}

void mostrarTodo(Registro registros[], int numRegistros) {
    for (int i = 0; i < numRegistros; i++) {
        printf("Registro %d:\n", i + 1);
        printf("Matricula: %d\n", registros[i].matricula);
        printf("Apellido Paterno: %s\n", registros[i].ApPat);
        printf("Apellido Materno: %s\n", registros[i].ApMat);
        printf("Nombre: %s\n", registros[i].Nombre);
        printf("Edad: %d\n", registros[i].Edad);
        printf("Sexo: %c\n", registros[i].sexo);
        printf("\n");
    }
}

void generarArchivo(Registro registros[], int numRegistros) {
    FILE *fa;
    fa = fopen("datos_generados.txt", "w");
    if (fa) {
        for (int i = 0; i < numRegistros; i++) {
            fprintf(fa, "%d %d %s %s %s %c %d\n", i + 1, registros[i].matricula, registros[i].ApPat, registros[i].ApMat, registros[i].Nombre, registros[i].sexo, registros[i].Edad);
        }
        fclose(fa);
        printf("Archivo generado correctamente.\n");
    } else {
        printf("No se pudo generar el archivo.\n");
    }
}

int main() {
    Registro registros[MAX_REGISTROS];
    int numRegistros = 0;
    int opcion;

    do {
        printf("MENU\n");
        printf("1.- Cargar Archivo\n");
        printf("2.- Agregar\n");
        printf("3.- Buscar\n");
        printf("4.- Ordenar\n");
        printf("5.- Mostrar Todo\n");
        printf("6.- Generar Archivo\n");
        printf("0.- Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                cargarArchivo(registros, &numRegistros);
                break;
            case 2:
                agregar(registros, &numRegistros);
                break;
            case 3:
                int matricula;
                printf("Ingrese la matrícula a buscar: ");
                scanf("%d", &matricula);
                int indice = buscar(registros, numRegistros, matricula);
                if (indice != -1) {
                    printf("Registro encontrado en el índice %d\n", indice);
                } else {
                    printf("Registro no encontrado\n");
                }
                break;
            case 4:
                ordenar(registros, numRegistros);
                break;
            case 5:
                mostrarTodo(registros, numRegistros);
                break;
            case 6:
                generarArchivo(registros, numRegistros);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida\n");
                break;
        }

        printf("\n");
    } while (opcion != 0);

    return 0;
}