#include<stdio.h>
#include<stdlib.h>



void MaxSubMatrix(int , int );
int max(int,int,int);
int matrix[10][10]={{0,1,1,0,1},{1,1,0,1,0},{0,1,1,1,0},{1,1,1,1,0},{1,1,1,1,1},{0,0,0,0,0}};
int main(void){

    printf("%d\n",matrix[5][6]);
    MaxSubMatrix(5,6);
    return 0;
}

void MaxSubMatrix(int m, int n){
    printf("I am ok!, %d\n",matrix[0][0]);
    int i=0,j=0,x_i=0, x_j=0, s_i=0;
    int Mat[m][n];
    for(j=0;j<n;j++){
        Mat[0][j]=matrix[0][j];
    }
    for(i=0;i<m;i++){
        Mat[i][0]=matrix[i][0];
    }
    for(i=1;i<m;i++){
        for(j=1;j<n;j++){
            if(matrix[i][j] == 1){
                Mat[i][j] = max(Mat[i-1][j-1], Mat[i][j-1], Mat[i-1][j]) +1;
            }
            else{
                Mat[i][j] = 0;
            }
        }
    }
    s_i = Mat[0][0];
    x_i = 0;
    x_j = 0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(Mat[i][j]>s_i){
                s_i = Mat[i][j];
                x_i = i;
                x_j = j;
            }
        }
    }
    printf("s = %d, x_i = %d, x_j = %d\n",s_i,x_i,x_j);
    for(i=x_i;i>(x_i-s_i);i--){
        for(j=x_j;j>(x_j-s_i);j--){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}

int max(int n1, int n2, int n3){
    int m;
    m = (n1>n2?n2:n1);
    m = (m>=n3?n3:m);
    return m;
}
