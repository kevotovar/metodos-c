#include "header.h"
#include "prototipos.h"

double * crear_vector (int tam)
{
    double *v;
    v = (double *) malloc(tam * sizeof(double));
    return v;
}
void lee_vector ( double *v, int tam )
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("\nDar el elemento [%d] = ",i+1);
        scanf("%lf",&v[i]);
    }

}
void destruye_vector ( double *v )
{
    free(v);
}
void imprime_vector ( double *v, int tam )
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf("x[%d] = [ %11.6lf ] \n",i+1,v[i]);
    }
}
