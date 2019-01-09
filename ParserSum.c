/* FileName:ParserSum.c
 * ----------------
 * This program calculates
 * the summary of numbers
 * that are contained in
 * an alphanumeric.
 */

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <stdlib.h>
#include <string.h>

#define LEN 50

int digits(char x[],int nums[]);

main()
{

    char an[LEN];
    int nums[LEN];
    int index;
    int i=0;
    int sum=0;


    printf("Enter an alphanumeric: ");
    gets(an);
    index=digits(an,nums);

    for(i=0; i<index-1; i++)
    {
        sum+=nums[i];
        printf("%d + ",nums[i]);
    }
    sum+=nums[index-1];
    printf("%d ",nums[index-1]);
    printf("= %d\n",sum);



    system("pause");
}

int digits(char x[],int nums[])
{

    int i;
    int j=0;
    int size=strlen(x);


    for(i=0; i<size; i++)
    {
        if(isdigit(x[i]))
        {
            nums[j]= x[i] - '0';
            j++;
        }

    }
    return j;
}

