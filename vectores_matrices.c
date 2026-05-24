#include <stdio.h>

int main() {
    int i, j;
    float notas[7][3];
    float suma;

    // Ingreso de notas con validación
    for(i = 0; i < 7; i++) {
        printf("\nEstudiante %d:\n", i + 1);
        for(j = 0; j < 3; j++) {
            do {
                printf("Ingrese nota de la asignatura %d: ", j + 1);
                scanf("%f", &notas[i][j]);
            } while(notas[i][j] < 0 || notas[i][j] > 10);
        }
    }

    // Promedio por estudiante
    printf("\n--- PROMEDIO POR ESTUDIANTE ---\n");
    for(i = 0; i < 7; i++) {
        suma = 0;
        for(j = 0; j < 3; j++) {
            suma += notas[i][j];
        }
        printf("Estudiante %d: %.2f\n", i + 1, suma / 3);
    }

    // Promedio por asignatura
    printf("\n--- PROMEDIO POR ASIGNATURA ---\n");
    for(j = 0; j < 3; j++) {
        suma = 0;
        for(i = 0; i < 7; i++) {
            suma += notas[i][j];
        }
        printf("Asignatura %d: %.2f\n", j + 1, suma / 7);
    }

    // Máximo y mínimo por estudiante
    printf("\n--- NOTA MAX Y MIN POR ESTUDIANTE ---\n");
    for(i = 0; i < 7; i++) {
        float max = notas[i][0];
        float min = notas[i][0];

        for(j = 1; j < 3; j++) {
            if(notas[i][j] > max) max = notas[i][j];
            if(notas[i][j] < min) min = notas[i][j];
        }

        printf("Estudiante %d -> Max: %.2f | Min: %.2f\n", i + 1, max, min);
    }

    // Máximo y mínimo por asignatura
    printf("\n--- NOTA MAX Y MIN POR ASIGNATURA ---\n");
    for(j = 0; j < 3; j++) {
        float max = notas[0][j];
        float min = notas[0][j];

        for(i = 1; i < 7; i++) {
            if(notas[i][j] > max) max = notas[i][j];
            if(notas[i][j] < min) min = notas[i][j];
        }

        printf("Asignatura %d -> Max: %.2f | Min: %.2f\n", j + 1, max, min);
    }

    // Aprobados y reprobados
    printf("\n--- APROBADOS Y REPROBADOS ---\n");
    for(j = 0; j < 3; j++) {
        int aprobados = 0, reprobados = 0;

        for(i = 0; i < 7; i++) {
            if(notas[i][j] >= 6)
                aprobados++;
            else
                reprobados++;
        }

        printf("Asignatura %d -> Aprobados: %d | Reprobados: %d\n",
               j + 1, aprobados, reprobados);
    }

    return 0;
}