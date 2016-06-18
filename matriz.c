#include "header.h"
#include "prototipos.h"

double ** crear_matriz(int filas, int columnas)
{
    double **m;
    int j;

    m=(double **) malloc(filas * sizeof(double *));
    for(j=0;j<filas;j++)
        m[j]=(double *) malloc(columnas * sizeof(double));

    return m;
}
void destruye_matriz(double **m, int filas, int columnas)
{
    int i;
    for(i=0;i<columnas;i++)
        free(m[i]);

    free(m);
}
void lee_matriz(double **m, int filas, int columnas)
{
    int i,j;
    double dato;

    for (i=0;i<filas;i++)
    {
        for (j=0;j<columnas;j++)
        {
            printf("Dar el elemento [%d][%d]",i+1,j+1);
            scanf("%lf",&dato);
            m[i][j]=dato;
        }
    }
}
void imprime_matriz ( double **m, int filas, int columnas )
{
    int i,j;

    for ( i=0; i < filas; i++ ) {

        for ( j=0; j < columnas; j++ ) {
            printf("[ %11.6lf ] ",m[i][j]);
        }
        printf("\n");
    }
}
/**Menu**/
void matrices()
{
    int menu;
    printf("Elige una opcion del menu\n");
    printf("1.-Multiplicacion\n");
    scanf("%d",&menu);
    switch(menu)
    {
        case 1:
            matriz_mult();
        break;
    }
}
void matriz_mult()
{
    double **A, **B, **C;
    int n,m1,m2,l;
    printf("Dame las filas de la primera matriz: ");
    scanf("%d",&n);
    printf("Dame las columnas de la primera matriz: ");
    scanf("%d",&m1);
    printf("Dame las filas de la segunda matriz: ");
    scanf("%d",&m2);
    printf("Dame las columnas de la primera matriz: ");
    scanf("%d",&l);
    if (m1!=m2)
    {
        system("cls");
        printf("Error la columna de la primera matriz no es igual a la columna de la segunda matriz\n");
        matriz_mult();
    }
    else
    {
        system("cls");
        A=crear_matriz(n,m1);
        B=crear_matriz(m2,l);
        C=crear_matriz(n,l);
        printf("Primera matriz\n");
        lee_matriz(A,n,m1);
        printf("Segunda matriz\n");
        lee_matriz(B,m2,l);
        mat_mult(A,B,C,n,l,m1);
        printf("El resultado de la multiplicacion es\n");
        imprime_matriz(C,n,l);
        destruye_matriz(A,n,m1);
        destruye_matriz(B,m2,l);
        destruye_matriz(C,n,l);
        system("pause");
    }
}
void mat_mult(double **A, double **B,double **C, int n, int l, int m)
{
    int i,j,k;
    double sum;
    for(i=0;i<n;i++)
    {
        for(j=0;j<l;j++)
        {
            sum=0;
            for(k=0;k<m;k++)
                sum=sum + A[i][k] * B[k][j];
            C[i][j]=sum;
        }
    }
}
void imprime_matriz_aumentada ( double **a, double *b, int tam )
{
    int i,j;

    for ( i=0; i < tam; i++ )
    {

        for ( j=0; j < tam; j++ )
        {
            printf("[ %11.6lf ] ",a[i][j]);
        }
        printf(" = [ %11.6lf ]",b[i]);
        printf("\n");
    }
}
