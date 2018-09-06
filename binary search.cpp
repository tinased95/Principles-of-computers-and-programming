#include<stdio.h>

#define SIZE 5


int main(){
    
    int a[100],i,n,m,c=0,f,e,mid;
    
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    
    printf("Enter the elements in ascending order: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    printf("Enter the number to be search: ");
    scanf("%d",&m);
    
    f=0,e=n-1;
    while(f<=e){
        mid=(f+e)/2;
        if(m==a[mid]){
            c=1;
            break;
        }
        else if(m<a[mid]){
            e=mid-1;
        }
        else
            f=mid+1;
    }
    if(c==0)
        printf("The number is not found.");
    else
        printf("The number is found.");
    
    return 0;
}