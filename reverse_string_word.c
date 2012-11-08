#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    char input[3000],sent[100][100];
    scanf("%[^\n]",input);
    //printf("%s",input);
    int i=0,j=0,k=0;
    while(input[i]!='\0'){
        j=0;
        while(input[i] != ' ' && input[i]!='\0'){
            sent[k][j++]=input[i++];
        }
      //  printf("%s",sent[k]);
        sent[k][j]='\0';
        k++;
        if(input[i]=='\0')
            break;
        i++;
    }
    //printf("\n");
    for(i=k-1;i>=0;i--)
        printf("%s ",sent[i]);
    printf("\n");


}
