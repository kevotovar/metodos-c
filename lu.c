#include "header.h"
#include "prototipos.h"

void init_lu()
{
    int tam;
    double **A, *B, *X;
    printf("\n\nIndique el numero de  variables: ");
    scanf("%d", &tam);
    A=crear_matriz(tam,tam);
    B=crear_vector(tam);
    X=crear_vector(tam);
    printf("\nIntroduzca los coeficientes de la matriz A[][]\n");
    lee_matriz(A,tam,tam);
    printf("\nIntroduzca los terminos independientes B[]\n ");
    lee_vector(B,tam);
    printf("\nMatriz aumentada original:\n");
    imprime_matriz_aumentada(A,B,tam);
    lu_decomp(A,B,tam,X);
    printf("\n\nLa solucion a el sistema es:\n");
    imprime_vector(X,tam);
    destruye_matriz(A,tam,tam);
    destruye_vector(B);
    destruye_vector(X);
}

void lu_decomp(double **a,double *b,int n, double *x)
{
    double *O, *S;
    O=crear_vector(n);
    S=crear_vector(n);
    lu_decompose(a,n,O,S);
    lu_sustitucion(a,O,n,b,x);
    destruye_vector(S);
    destruye_vector(O);
}
void lu_decompose(double **a,int n, double *O, double *S)
{
    int i, j, k;
    double factor;
    for (i=0; i<n; i++)
    {
        O[i]=i;
        S[i]=fabs(a[i][0]);
        for (j=1; j<n ; j++)
        {
            if(fabs(a[i][j])>S[i])
                S[i]=fabs(a[i][j]);
        }
    }
    for (k=0; k<n-1; k++)
    {
        lu_pivot(a,O,S,n,k);
        for (i=k+1; i<n ; i++ )
        {
            factor=a[i][k]/a[k][k];
            a[i][k]=factor;
            for (j=k+1; j<n ; j++ ){
                a[i][j]=a[i][j]-factor*a[k][j];
            }
        }
    }
}
void lu_sustitucion(double **a, double *o, int n, double *b, double *x)
{
    int i,j;
    double sum;

    for (i=1; i<n; i++)
    {
        sum=b[i];
        for (j=0; j<i-1 ; j++)
        {
            sum=sum-a[i][j]*b[j];
        }
        b[i]=sum;
    }

    x[n-1]=b[n-1]/a[n-1][n-1];

    for(i=n-2; i>=0; i--)
    {
        sum=0;
        for(j=i+1; j<n; j++)
        {
            sum = sum + a[i][j]*x[j];
        }
        x[i] = (b[i]-sum)/a[i][i];
    }

}
void lu_pivot(double **a, double *o, double *s, int n, int k)
{
    int p=k,ii;
    double big=fabs(a[k][k])/s[k],dummy;
    for (ii=k+1; ii<n ; ii++ )
    {
        dummy=fabs(a[ii][k]/s[ii]);
        if (dummy>big)
        {
            big=dummy;
            p=ii;
        }
    }
    dummy=o[p];
    o[p]=o[k];
    o[k]=dummy;
}
