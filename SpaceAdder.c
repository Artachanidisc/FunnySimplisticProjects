/* FileName:SpaceAdder.c
 * A program that adds
 * a space after every
 * full stop and comma punctuation mark
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

void writeData(FILE* ifile,FILE* ofile);

main()
{

    FILE* infile;
    FILE* outfile;

    char infileText[30];
    char outfileText[30];

    while(TRUE){
        printf("Please enter the file you want to be fixed: ");
        gets(infileText);
        infile=fopen(infileText,"r");
        if(infile==NULL){
            printf("File %s not found\n",infileText);

        }
        else break;
    }
    printf("Please enter the name of the new file: ");
    gets(outfileText);
    outfile=fopen(outfileText,"w");

    writeData(infile,outfile);

    printf("The spaces have successfully been added to your file\nCheck file %s!\n",outfileText);
    fclose(infile);
    fclose(outfile);

}
void writeData(FILE* ifile,FILE* ofile)
{

    char ch;
    char characters[295];
    int i=0;
    int j=0;
    char tmp;
    char tmp1;



    while((ch=getc(ifile))!=EOF)
    {
        characters[i]=ch;
        i++;
    }
    for(i=0;i<sizeof(characters);i++)
    {
        if(characters[i]=='.' || characters[i]==',')
        {
            if(!isspace(characters[i+1])){
                tmp=characters[i+1];
                characters[i+1]=' ';
                for(j=i+1;j<sizeof(characters);j++){
                   tmp1=tmp;
                    tmp=characters[j+1];
                    characters[j+1]=tmp1;
                }
            }
        }
    }

    for(i=0; i<sizeof(characters); i++)
    {
        putc(characters[i],ofile);
    }

}
