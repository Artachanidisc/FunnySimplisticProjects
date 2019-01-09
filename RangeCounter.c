/* FileName:RangeCounter.c
 * ---------------
 * This program calculates
 * the range of numbers
 * that a user has inputted
 * (from 0 to 100000)
 */

#include "stdio.h"
#include "simpio.h"
#include "genlib.h"

#define SIZE 100

int readData(int sizeX,int Table[]);
void maxMin(int sizeX,int Table[],int *maxX,int *minX);

main()
{

    int i;
    int A[SIZE];
    int sum;
    int max;
    int min;

    for(i=0; i<SIZE; i++)
    {
        A[i]=0;
    }

    sum=readData(SIZE,A);
    maxMin(sum,A,&max,&min);
    printf("The range of values is %d-%d\n",min,max);




}

int readData(int sizeX,int Table[])
{
    int flag=0;
    int i;
    int sum=0;

    printf("Enter the elements of the array,one per line.\nUse -1 to signal the end of the list.\n");
    for(i=0; i<sizeX; i++)
    {
        do
        {
            printf("? ");
            Table[i]=GetInteger();
            if(Table[i]>1000000 || Table[i]<0 && Table[i]!=-1)
            {
                printf("Input number out of bounds.(valid inputs 0-1000000)\n");
                flag=1;
            }
            else flag=0;
        }
        while(flag==1 && Table[i]!=-1);
        if(Table[i]==-1 && (i==0 || i==1))
        {
            printf("Insufficient inputs,no results\n");
            exit(1);
        }
        else if (Table[i]==-1){
            break;
        }
        sum++;

}
return sum;

}
void maxMin(int sizeX,int Table[],int *maxX,int *minX)
{

    int i;
    *maxX=Table[0];
    *minX=Table[0];

    for(i=1; i<sizeX; i++)
    {
        if(Table[i]>*maxX)
        {
            *maxX=Table[i];
        }
        else if(Table[i]<*minX)
        {
            *minX=Table[i];
        }
    }
}

