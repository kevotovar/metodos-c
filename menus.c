#include "header.h"
#include "prototipos.h"
/**Menus Raices**/
void raices()
{
    int menu;
    printf("Elegir el tipo de solucion\n");
    printf("1.- Raices Cerradas\n2.- Raices Abiertas\n");
    scanf("%d",&menu);
    switch(menu)
    {
    case 1:
        raices_c();
        break;
    case 2:
        raices_a();
        break;
    default:
        system("cls");
        printf("Opcion incorrecta\n");
        raices();
        break;
    }
}
/**Menus Gauss**/
void gauss()
{
    int menu;
    printf("Elegir el metodo a realizar\n");
    printf("1.- Gauss Simple\n2.- Gauss Modificado\n3.- Gauss Seidel\n");
    printf("4.- LU\n");
    scanf("%d",&menu);
    switch (menu)
    {
    case 1:
        init_gauss();
        break;
    case 2:
        init_gauss_mod();
        break;
    case 3:
        init_gauss_seid();
        break;
    case 4:
        init_lu();
        break;
    default:
        system("cls");
        printf("Opcion incorrecta\n");
        gauss();
        break;
    }

}

void interpolacion()
{
    int tam,opc;
    double *x,*y, punto, *yi, *eab, pfinal;
    printf("Escribe el numero de puntos\n");
    scanf("%d",&tam);
    x=crear_vector(tam);
    y=crear_vector(tam);
    printf("Dame los valores del vector X\n");
    lee_vector(x,tam);
    printf("Dame los valores del vector Y\n");
    lee_vector(y,tam);
    printf("En que valor de X deseas calcular Y\n");
    scanf("%lf",&punto);
    printf("Elige el metodo a utilizar\n");
    printf("1.- Diferencias divididas de newton\n");
    printf("2.- Lagrange\n");
    scanf("%d",&opc);
    switch (opc)
    {
    case 1:
        system("cls");
        printf("Diferencias Divididas");
        yi=crear_vector(tam);
        eab=crear_vector(tam);
        dif_divididas(x,y,tam,punto,yi,eab);
        imprime_vector(yi,tam);
        printf("\n");
        imprime_vector(eab, --tam);
        destruye_vector(yi);
        destruye_vector(eab);
        destruye_vector(x);
        destruye_vector(y);
        system("pause");
        break;
    case 2:
        system("cls");
        printf("Lagrange");
        pfinal=lagrange(x,y,tam,punto);
        printf("El valor de f(%.2lf) es = %.4lf",punto,pfinal);
        destruye_vector(x);
        destruye_vector(y);
        system("pause");
    default:
        system("cls");
        printf("Opcion invalida\n");
        system("pause");
        break;
    }

}

/**Minimos**/

void minimos ()
{
    int op;
    printf("MINIMOS CUADRADOS\n");
    printf("1.- Regresion Lineal\n");
    printf("2.- Regresion Polinomial\n");
    printf("Elige una opcion: ");
    scanf("%d", &op);
    switch (op)
    {
        case 1: system ("cls");
        init_lineal();
        break;
        case 2: system ("cls");
        init_polinomial();
        break;
        default:
        printf("Opcion Incorrecta\n");
        system ("pause");
        system ("cls");
        break;
    }
}

/**Integracion **/

void integracion()
{
    void minimos ()
{
    int op;
    printf("INTEGRACION\n");
    printf("1.- Trapecio\n");
    printf("2.- 1/3 Simpson\n");
    printf("3.- Simpson Combinado\n");
    printf("Elige una opcion: ");
    scanf("%d", &op);
    switch (op)
    {
        case 1: system ("cls");
        trapecio_multiple();
        break;
        case 2: system ("cls");
        simpson_13();
        break;
        case 3: system("cls");
        simpson_combinado();
        break;
        default:
        printf("Opcion Incorrecta\n");
        system ("pause");
        system ("cls");
        break;
    }
}
}
