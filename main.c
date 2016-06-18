#include "header.h"
#include "prototipos.h"

int main()
{
    int menu;
    printf("ESIME Zacatenco\n");
    printf("Alumno: Tovar Ochoa Kevin Ricardo\n");
    printf("Profesor: Martinez Roldan Enrique\n");
    printf("Materia: Analisis numerico\n");
    printf("Grupo: 3AM1\n\n");
    printf("1.-Raices\n2.-Matrices\n3.-Sistemas de ecuacion\n");
    printf("4.-Interpolacion\n");
    printf("5.-Minimos Cuadrados\n");
    printf("6.-Integracions\n");
    printf("7.- EDO\n");
    scanf("%d",&menu);
    system("cls");
    switch(menu)
    {
    case 1:
        raices();
        break;
    case 2:
        matrices();
        break;
    case 3:
        gauss();
        break;
    case 4:
        interpolacion();
        break;
    case 5:
        minimos();
        break;
    case 6:
        integracion();
        break;
    case 7:
        euler();
        break;
    default:
        system("cls");
        printf("Opcion Invalida");
    }
    return 0;
}
