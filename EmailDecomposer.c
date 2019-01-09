/* FileName:EmailDecomposer.c
 * ----------------
 * This program isolates
 * the name and the server of an
 * email address(input).
 */

#include <Stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <string.h>

#define LEN 80

void removeSpaces(char table[],char table2[]);
int getName(char name[],char email[]);
void getServer(char email[],char server[],int x);

main(){

    char temp[LEN];
    char email[LEN];
    char name[LEN];
    char server[LEN];
    int i;
    int index=0;

    printf("Please enter an email address: ");
    gets(temp);
    printf("Initial address : %s\n",temp);
    removeSpaces(temp,email);
    printf("Email is: %s\n",email);

    index=getName(name,email);
    printf("Name: %s\n",name);
    index++;
    getServer(email,server,index);
    printf("Server: %s\n\n",server);


    system("PAUSE");
}
void removeSpaces(char table[],char table2[]){

    int i;
    int j=0;
    int size;

    size=strlen(table);
    for(i=0;i<=size;i++){
        if(table[i] != ' '){
            table2[j]=table[i];
            j++;
        }
    }
}

int getName(char name[],char email[]){

    int i=0;
    int j=0;

    for(i=0;email[i]!='@';i++){
        name[j]=email[i];
        j++;
    }
    name[j]='\0';

    return j;
}
void getServer(char email[],char server[],int x){

    int i;
    int j=0;
    int size;

    size=strlen(email);

    for(i=x;i<size;i++){
        server[j]=email[i];
        j++;
    }
    server[j]='\0';

}


