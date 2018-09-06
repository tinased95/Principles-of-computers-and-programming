#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int select[100];
	int n,i,tmp=0;
	cout << "enter number of elements u wanna sort";
	cin >>n;
	for(int i=0;i<n;i++)
		cin >> select[i];
	for(i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(select[j]>select[i]){
				tmp=select[j];
				select[j]=select[i];
				select[i]=tmp;
			}
		}
	}
	for(i=0;i<n;i++)
		cout << select[i];
	
	getchar();
	getchar();
	return 0;
}



