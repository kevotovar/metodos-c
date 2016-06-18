#include "header.h"
#include "prototipos.h"

void dif_divididas(double *m,double *r,int n, double d, double *yint, double *ea)
{
    double **fdd,xterm,yint2;
    int order,i,j;
    fdd=crear_matriz(n,n);
    for(i=0;i<n;i++)
        {
         fdd[i][0]=r[i];
        }
    for(j=1;j<n;j++)
    {
        for(i=0;i<n-j;i++)
        {
            fdd[i][j]=(fdd[i+1][j-1]-fdd[i][j-1])/(m[i+j]-m[i]);
        }
    }
    xterm=1;
    yint[0]=fdd[0][0];
    for(order=1;order<=n;order++)
    {
        xterm=xterm*(d-m[order-1]);
        yint2=yint[order-1]+(fdd[0][order]*xterm);
        ea[order-1]=yint2-yint[order-1];
        yint[order]=yint2;
    }
}

double lagrange(double *m, double *r, int n, double d)
{
    int i,j;
    double sum=0,prod;
    sum=0;
    for(i=0;i<=n-1;i++)
    {
        prod=r[i];
        for(j=0;j<=n-1;j++)
        {
            if(i!=j)
                prod=prod*((d-m[j])/(m[i]-m[j]));
        }
        sum=sum+prod;
    }
    return sum;
}
