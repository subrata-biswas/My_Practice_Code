#include<stdio.h>
#include<stdlib.h>
int main(void){
    int a[]={3,4,1,4,1,3,2,4,1,6,7,8,9};
    int count = 0;
    int flag = 1,i=0,temp=0;
    while(flag){
        flag = 0;
        for(i=1;i<13;i++){
            if(a[i]<a[i-1]){
                flag = 1;
                count++;
                temp = a[i-1];
                a[i-1] = a[i];
                a[i]=temp;
            }
        }
    }
    for(i=0;i<13;i++)
        printf("%d ",a[i]);
    printf("count = %d\n",count);
    return 0;
}
