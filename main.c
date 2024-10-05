#include <stdio.h>
#define M 7

void menu();
void meter();
int sacar();
void recorre();
void mostrar();

int cola[M] = {0};
int ind = 0, end = 0;

int main(void)
{
    menu();
}

void menu()
{
    int opt;
    do
    {
        printf("1. Meter\n2. Sacar\n3. Mostrar\n0. Salir\n>> ");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                meter();
                break;
            case 2:
                printf("Elemento que sale: %d\n", sacar());
                break;
            case 3:
                mostrar();
                break;
            case 0:
                printf("...");
                break;
            default:
                printf("No se vale\n");
                break;
        }
    } while(opt != 0);
}

void recorre()
{
    int aux = 0;
    while (ind < end)
    {
        cola[aux] = cola[ind];
        aux ++;
        ind ++;
    }

    end = ind;
    ind = 0;
}

void meter()
{
    int elem;
    printf("Introduzca el numero que entra a la pila\n>> ");
    scanf("%d", &elem);

    if (ind == 0 && end == M)
        printf("Cola llena");
    else
    {
        if (end == M)
        {
            recorre();
            cola[end] = elem;
        }
        else
            cola[end] = elem;

        end ++;
    }
}

int sacar()
{
    int elem = -1;

    if (ind != end)
    {
        elem = cola[ind];
        cola[ind] = -1;
        ind ++;

        if (ind == end)
        {
            ind = 0;
            end = 0;
        }
    }
    else
    {
        printf("Cola vacía\n");
    }

    return elem;
}

void mostrar()
{
    for (int i = ind; i < end; i++)
    {
        printf("%d\n", cola[i]);
    }
    printf("\n");
}
