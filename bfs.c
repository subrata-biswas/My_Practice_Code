/*
*Here user give input for n nodes of a graph. Self loop is discarded. The input is stored in 2D Matrix
*/

#include<stdio.h>

int main(void){
    printf("Hello World\n");
    int graph[10][10],n,i=0,j=0,start=0;
    printf("Enter number of Nodes: ");
    scanf("%d",&n);
    //graph = (int *)malloc(sizeof(int)*n);
    //*graph = (int *)malloc(sizeof(int)*n);
    printf("Please enter the connectivity :\n ");
    for(i=0;i<n;i++){
        printf("%d is Connected with : ", i);
        for(j=0;j<n;j++){
            if(j==i){
                graph[i][j]=0;
                continue;
            }
            printf("%d->",j);
            scanf("%d",&graph[i][j]);
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
    /*BFS ALGO*/
    int stack[10][10]={0},top = -1,st;
    printf("Enter the starting node (0-%d)\n",n-1)
    scanf("%d\n",start);
    st = start;
    printf("The BFS is : \n");
    //Explore all the nodes coonected via start and psuh it in stack
    j=0;
    while(1){
        for(i=0;i<n;i++){
            if(graph[st][i] == 0)
                continue;
            if(graph[i][i] == 0)
                stack[j][++top] = i;
        }
        j++;
        graph[st][st]=-1;

    }


    return 0;
}
