#include "header.h"
#include "prototipos.h"
void eliminacion(double **a, double *x, int filas, double *b)
{
    int i,j,k,n;
    float factor;

    n=filas;

    for(k=0;k<=n-2;k++)
    {
        for(i = k+1;i <= n-1;i++)
        {
            factor = a[i][k]/a[k][k];
            for(j=k+1;j<=n-1;j++)
            {
                a[i][j] = a[i][j]-factor*a[k][j];
            }
            b[i] = b[i]-factor*b[k];
        }
    }
}
void init_gauss()
{
    double **A, *B, *X;
    int tam;

    printf("Metodo de Eliminacion de Gauss Simple");
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
    eliminacion(A,X,tam,B);
    sustitucion(A,X,tam,B);
    printf("\n\nLa solucion a el sistema es:\n");
    imprime_vector(X,tam);
    destruye_matriz(A,tam,tam);
    destruye_vector(B);
    destruye_vector(X);
}
void gauss_mod(double **a, double *b, int n, double *x, double tol)
{
    int i,j, er;
    double *s;
    s=crear_vector(n);
    er=0;
    for(i=0; i<n; i++)
    {
        s[i]=fabs(a[i][0]);
        for(j=1; j<n; j++)
        {
            if(fabs(a[i][j])>s[i])
            {
                s[i]=fabs(a[i][j]);
            }
        }
    }
    eliminate_mod(a,s,n,b,tol,&er);
    if(er!=-1)
        sustitucion(a,x,n,b);

}
void sustitucion(double **a, double *x, int filas, double *b)
{
    int i,j,n;
    float sum;

    n=filas;

    x[n-1]=b[n-1]/a[n-1][n-1];

    for(i=n-2; i>=0; i--)
    {
        sum=b[i];
        for(j=i+1; j<=n-1; j++)
        {
            sum = sum - a[i][j]*x[j];
        }
        x[i] = sum / a[i][i];
    }

}
void eliminate_mod(double **a, double *s, int n, double *b, double tol, int *er)
{
    int k,i,j;
    double factor;
    for(k=0; k<n-1; k++)
    {
        pivot(a,b,s,n,k);
        for(i=k+1; i<n; i++)
        {
            factor=a[i][k]/a[k][k];
            for(j=k+1; j<n; j++)
            {
                a[i][j]=a[i][j]-factor*a[k][j];
            }
            b[i]=b[i]-factor*b[k];
        }
    }
    if(fabs(a[k][k]/s[k])<tol)
        *er=-1;
}
void pivot(double **a, double *b, double *s, int n, int k)
{
    int p,ii,jj;
    double big,dummy;
    p=k;
    big=fabs(a[k][k]/s[k]);
    for(ii=k; ii<n; ii++)
    {
        dummy=fabs(a[ii][k]/s[ii]);
        if(dummy>big)
        {
            big=dummy;
            p=ii;
        }
    }
    if(p!=k)
    {
        for(jj=k; jj<n; jj++)
        {
            dummy=a[p][jj];
            a[p][jj]=a[k][jj];
            a[k][jj]=dummy;
        }
        dummy=b[p];
        b[p]=b[k];
        b[k]=dummy;
        dummy=s[p];
        s[p]=s[k];
        s[k]=dummy;
    }
}
void init_gauss_mod(void)
{
    double **A, *B, *X, tol;
    int tam;

    printf("Metodo de Eliminacion de Gauss Simple");
    printf("\n\nIndique el numero de  variables: ");
    scanf("%d", &tam);
    A=crear_matriz(tam,tam);
    B=crear_vector(tam);
    X=crear_vector(tam);
    printf("\nIntroduzca los coeficientes de la matriz A[][]\n");
    lee_matriz(A,tam,tam);
    printf("\nIntroduzca los terminos independientes B[]\n ");
    lee_vector(B,tam);
    printf("\nIntroduzca la tolerancia\n ");
    scanf("%lf",&tol);
    printf("\nMatriz aumentada original:\n");
    imprime_matriz_aumentada(A,B,tam);
    gauss_mod(A,B,tam,X,tol);
    printf("\n\nLa solucion a el sistema es:\n");
    imprime_vector(X,tam);
    destruye_matriz(A,tam,tam);
    destruye_vector(B);
    destruye_vector(X);
}
void init_gauss_seid()
{
    double **A, *B, *X, es;
    int imax, tam;
    printf("\n\t\tMetodo de Gauss Seidel");
    printf("\n\tIngresa las iteraciones maximas:\t");
    scanf("%d",&imax);
    printf("\n\tIngresa el error:\t");
    scanf("%lf",&es);
    printf("\n\tIngresa el numero de variables:\t");
    scanf("%d",&tam);
    A=crear_matriz(tam, tam);
    B=crear_vector(tam);
    X=crear_vector(tam);
    printf("\n\t\tDame los valores de la matriz:");
    lee_matriz(A, tam, tam);
    printf("\n\t\tDame los valores del vector:");
    lee_vector(X, tam);
    printf("\nMatriz aumentada original:\n");
    imprime_matriz_aumentada(A,B,tam);
    gauss_seidel(A,B,X,tam,imax,es);
    printf("Solucion al sistema\n");
    imprime_vector(X, tam);
    destruye_matriz(A,tam,tam);
    destruye_vector(X);
    destruye_vector(B);
}

void gauss_seidel(double **m,double *r,double *s,int n, int imax, double es)
{
    int i,j,iter,cent;
    double sum,dummy,ea,old,lambda=1;
    for(i=0;i<=n-1;i++)
    {
        dummy=m[i][i];
        for(j=0;j<=n-1;j++)
        {
            m[i][j]=m[i][j]/dummy;
        }
        r[i]=r[i]/dummy;
    }
    for(i=0;i<=n-1;i++)
    {
        sum=r[i];
        for(j=0;j<=n-1;j++)
        {
            if(i!=j)
            sum=sum-m[i][j]*s[j];
        }
        s[i]=sum;
    }
    iter=1;
    cent=1;
    do
    {
         for(i=0;i<=n-1;i++)
         {
             old=s[i];
             sum=r[i];
             for(j=0;j<=n-1;j++)
             {
                if(i!=j)
                sum=sum-m[i][j]*s[j];
             }
             s[i]=lambda*sum+(1-lambda)*old;
             if(cent==1 && s[0]!=0)
                ea=fabs((s[i]-old)/s[i])*100;
             if(ea>=es)
                cent=0;
         }
         iter+=1;
    }
    while(cent==0 && iter<=imax);
}
