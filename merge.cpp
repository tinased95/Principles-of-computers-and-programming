#include <stdio.h>

int array[128];
void merge(int i, int j, int k);
void sort(int i, int j);

int main(int argc, const char * argv[]){
    int n = 0,i = 0;
    
    do{
        printf("How many numbers(1-128)?\n");
        scanf("%d",&n);
    }while(n<=0 || n>128);
    
    for (i=0 ; i<n; i++)
        scanf("%d" , &array[i]);
    
    sort(0, n);
    
    printf("The sorted array is:\n");
    for(i=0; i<n;i++)
        printf("%d\n" , array[i]);
    getchar();
	getchar();
    return 0;
}


void merge (int i , int j , int k){
    int n = i, m = j;
    int sarr[128];
    int ps = i;
    
    //Start merging
    while(n < j && m < k){
        if (array[n] < array[m]) {
            sarr[ps]=array[n];
            n++;
        }else{
            sarr[ps]=array[m];
            m++;
        }
        ps++;
    }
    
    //Copy what's left
    while(m < k){
        sarr[ps]=array[m];
        ps++;
        m++;
    }
    while(n < j){
        sarr[ps]=array[n];
        ps++;
        n++;
    }
    
    //Overwrite the old content
    for( ; i < k ; i++)
        array[i] = sarr[i];
}

void sort (int i , int j){
    if( j-i < 2 )
        return;
    sort(i, i+(j-i)/2);
    sort(i+(j-i)/2,j);
    merge(i, i+(j-i)/2, j);
}