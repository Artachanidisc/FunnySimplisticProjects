/* FileName:WordShuffler.c
 * Anagramism function
 */

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <String.h>

#define LEN 20

void anagramism(char x[]);

main()
{

    char num[LEN];


    printf("Word to shuffle: ");
    gets(num);

    printf("Initial word: %s, ",num);

    anagramism(&num);
    printf("New word: %s\n",num);


}

void anagramism(char x[])
{

    srand(time(NULL));
    char temp;
    int num1;
    int num2;

    for(int i=0; i<3; i++)
    {
        num1=rand() % strlen(x);
        num2=rand() % strlen(x);
        while(num1==num2)
        {
            num1=rand() % strlen(x);
            num2=rand() % strlen(x);
        }
        temp=x[num1];
        x[num1]=x[num2];
        x[num2]=temp;
    }

}

