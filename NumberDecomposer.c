/* FileName:NumberDecomposer.c
 * ----------------
 * Function decompose
 */

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

void decompose(int x,int *n,double *mo,int *max);

main()
{

    int num;
    int digits;
    double avg;
    int maximum;

    do
    {
        printf("Please insert a non-negative integer number:");
        num=GetInteger();
        if(num<0)
        {
            printf("Invalid input.\n");
        }
    }
    while( num<0);
    decompose(num,&digits,&avg,&maximum);
    printf("Digits: %d,Average: %g,Max: %d",digits,avg,maximum);
    printf("\n\n");

    system("PAUSE");

}

void decompose(int x,int *n,double *mo,int *max)
{

    double sum=0;
    int y=x%10;
    *n=0;
    *max=y;
    *mo=0;


    while(x!=0)
    {
        *n=*n+1;
        sum+=(x%10);
        x/=10;
        y=(x%10);
        if(y>*max)
        {
            *max=y;
        }
    }
    if(*n!=0)
    {
        *mo= sum/ *n;
    }


}

