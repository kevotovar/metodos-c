#include "prototipos.h"
#include "header.h"

void graficador(char *func, char *points, char *type,double rangen, double rangep)
{
    FILE *gnuplotPipe = popen(".\\gnuplot\\gnuplot.exe -persist","w");
    if (!gnuplotPipe)
    {
        printf("No se pudo encontrar gnuplot\n");
    }
    else
    {
        fprintf(gnuplotPipe, "set terminal windows\n");
        fprintf(gnuplotPipe, "set xlabel \"Valor de las x\"\n");
        fprintf(gnuplotPipe, "set ylabel \"f(x)\"\n");
        fprintf(gnuplotPipe, "set xtics 1\n");
        fprintf(gnuplotPipe, "set ytics 1\n");
        fprintf(gnuplotPipe, "set grid ytics lt 0 lw 1 lc rgb \"#bbbbbb\"\n");
        fprintf(gnuplotPipe, "set grid xtics lt 0 lw 1 lc rgb \"#bbbbbb\"\n");
        fprintf(gnuplotPipe, "set style line 1 lc rgb \'#0060ad\' lt 1 lw 2 pt 7 ps 1.5\n");
        fprintf(gnuplotPipe, "set samples 2000\n");
        fprintf(gnuplotPipe, "plot [%lf:%lf] %s, %s using 1:2 with %s ls 1\n",rangen,rangep,func,points,type);
        fflush(gnuplotPipe);
        fprintf(gnuplotPipe,"exit \n");
        pclose(gnuplotPipe);
    }
}
