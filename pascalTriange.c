#include<stdio.h>
#include<stdlib.h>

void printPascalTriangle(int n){
    if(n == 0){
        printf("1\n");
        return;
    }
    if(n == 1){
        printf("1\t1\n");
        return;
    }
    int a[2][n],j;
    a[0][0]=1;
    a[0][1]=1;
    a[0][2]=1;
    a[1][0]=1;
    a[1][1]=1;
    a[1][2]=1;
    int flag=2;
    int i=0;
    printf("1\n");
    printf("1\t1\n");
    for(i=2;i<=n;i++){
        printf("1\t");
        for(j=1;j<i;j++){
            a[(flag+1)%2][j]=a[flag%2][j-1] + a[flag%2][j];
            printf("%d\t",a[(flag+1)%2][j]);
        }
        a[(flag+1)%2][j] = 1;
        flag++;
        printf("1\n");
    }
}

int main(){
    int n=0;
    printf("Enter N : ");
    scanf("%d",&n);
    printPascalTriangle(n);
    return 0;
}
