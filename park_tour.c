#include<stdio.h>
#include<stdlib.h>

typedef struct park_des{
    char val;
    int E,W,N,S;
    int x,y;
}park;

typedef struct visit_path{
    int x,y;
    int index;
    struct visit_path *next;
}path;

park my_park[100][100];

void set_possible_path(char val, int i, int j, int max){
    if(val == '.'){
        my_park[i][j].E = -1;
        my_park[i][j].N = -1;
        my_park[i][j].W = -1;
        my_park[i][j].S = -1;
        if(i+1 < max){
            my_park[i][j].S = 1;
        }
        if(j+1 < max){
            my_park[i][j].E = 1;
        }
        if(i-1 >=0){
            my_park[i][j].N = 1;
        }
        if(j-1 >=0){
            my_park[i][j].W = 1;
        }
        return;
    }
    else if(val == '*'){
        my_park[i][j].E = -1;
        my_park[i][j].N = -1;
        my_park[i][j].W = -1;
        my_park[i][j].S = -1;
        return;
    }
    else{
        printf("Undefiend Symbol %c \n",val);
        exit(1);
    }
    return;
}

path * max_route(path * temp1,path *temp2, path *temp3, path * temp4){
    //printf("Calling Max_route\n");
    path *max1=NULL,*max2=NULL;
    if(temp1 != NULL || temp2 != NULL){
        if(temp1 == NULL){
            max1 = temp2;
        }
        else if(temp2 == NULL){
            max1 = temp1;
        }
        else{
            if(temp1->index > temp2->index){
                max1 = temp1;
            }
            else{
                max1 = temp2;
            }
        }
    }
    if(temp3 != NULL || temp4 != NULL){
        if(temp3 == NULL){
            max2 = temp4;
        }
        else if(temp4 == NULL){
            max2 = temp3;
        }
        else{
            if(temp3->index > temp4->index){
                max2 = temp3;
            }
            else{
                max2 = temp4;
            }
        }
    }
    if(max1 != NULL || max2 != NULL){
        if(max1 == NULL){
            return max2;
        }
        else if(max2 == NULL){
            return max1;
        }
        else{
            if(max1->index > max2->index){
                return max1;
            }
            else{
                return max2;
            }
        }
    }
    //printf("ALL NULL in max_route\n");

}

path * park_tour(int i,int j,int st_i, int st_j,int flag){
    //printf("Inside park_tour(%d,%d)\n",i,j);
    path *temp1=NULL,*temp2=NULL,*temp3=NULL,*temp4=NULL,*final=NULL,*temp = NULL;
    int t1=0,t2=0;
    int len;
    if(flag != 0 && i == st_i && j == st_j){
        final = (path *)malloc(sizeof(path));
        final->next = NULL;
        final->index = 1;
        final->x = i;
        final->y = j;
        //printf("Returnign 1 from park_tour()");
        return final;
    }
    if(my_park[i+1][j].N == 1 && my_park[i][j].S == 1){
        //block the path
        //printf("PATH from (%d,%d) to (%d,%d)",i,j,i+1,j);
        my_park[i][j].S = 0;
        if(my_park[i][j].N == 0){
            t1 = my_park[i][j].E ;
            t2 = my_park[i][j].W ;
            my_park[i][j].W = 0;
            my_park[i][j].E = 0;
        }
        temp1 = park_tour(i+1,j,st_i,st_j,1);
        my_park[i][j].W = t2;
        my_park[i][j].W = t1;
        my_park[i][j].S = 1;
        //release the path
    }
    if(my_park[i-1][j].S == 1 && my_park[i][j].N == 1){
        //block the path
        //printf("PATH from (%d,%d) to (%d,%d)",i,j,i-1,j);
        my_park[i][j].N = 0;
       // my_park[i-1][j].E = 0;
        if(my_park[i][j].S == 0){
            t1 = my_park[i][j].E ;
            t2 = my_park[i][j].W ;
            my_park[i][j].E = 0;
            my_park[i][j].W = 0;
        }
        temp2 = park_tour(i-1,j,st_i,st_j,1);
        my_park[i][j].N = 1;
        my_park[i][j].W = t2;
        my_park[i][j].E = t1;
        //release the path
    }
    if(my_park[i][j+1].W == 1 && my_park[i][j].E == 1){
        //block the path
        //printf("PATH from (%d,%d) to (%d,%d)",i,j,i,j+1);
        my_park[i][j].E = 0;
        if(my_park[i][j].W == 0){
            t1 = my_park[i][j].N ;
            t2 = my_park[i][j].S ;
            my_park[i][j].N = 0;
            my_park[i][j].S = 0;
        }
        temp2 = park_tour(i,j+1,st_i,st_j,1);
        my_park[i][j].N =t1;
        my_park[i][j].S =t2;
        my_park[i][j].E = 1;
        //release the path
    }
    if(my_park[i][j-1].E == 1 && my_park[i][j].W == 1){
        //block the path
        my_park[i][j].W = 0;
        ////printf("PATH from (%d,%d) to (%d,%d)",i,j,i,j-1);
        if(my_park[i][j].E == 0){
            t1 = my_park[i][j].N ;
            t2 = my_park[i][j].S ;
            my_park[i][j].N = 0;
            my_park[i][j].S = 0;
        }
        temp2 = park_tour(i,j-1,st_i,st_j,1);
        my_park[i][j].W = 1;
        my_park[i][j].N = t1;
        my_park[i][j].S = t2;
        //release the path
    }
    //Maximum path length
    final = max_route(temp1,temp2,temp3,temp4);

    if(final != NULL){
        temp = (path *) malloc(sizeof(path));
        temp->x = i;
        temp->y = j;
        temp->index = final->index + 1;
        temp->next = final;
    }
    else{
        //printf("Returnign NULL from park_tour..(%d,%d)\n",i,j);
        return NULL;
    }
    //printf("Returnign 2 from park_tour()\n");
    return temp;
}

int main(void){
    //printf("Hello World\n");
    int n=0,i,j;
    int val;
    printf("Enter N : ");
    scanf("%d",&n);
    printf("Enter characters: ");
    getchar();
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%c",&val);
            //getchar();
            //val = getchar();
            set_possible_path(val, i, j, n);
            my_park[i][j].x = i;
            my_park[i][j].y = j;
            //printf("my_park[%d][%d]---E=%d, W=%d, N=%d, S=%d\n",i,j,my_park[i][j].E, my_park[i][j].W, my_park[i][j].N , my_park[i][j].S);
        }
    }
    path *my_path=NULL;
    //printf("Calling park_tour()\n");
    my_path = park_tour(0,0,0,0,0);
    if(my_path == NULL){
        printf("Error in park_tour()");
        exit(2);
    }
    printf("%d\n",my_path->index-1);
    //printf("Path is :");
    path *temp;
    temp = my_path;
    while(temp->next != NULL){
        printf("(%d,%d)\n",temp->x,temp->y);
        temp = temp->next;
    }
    return 0;
}
