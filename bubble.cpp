#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int bubble[100];
	int n,i,tmp=0;
	cout << "enter number of elements u wanna sort";
	cin >>n;
	for(int i=0;i<n;i++)
		cin >> bubble[i];
	for(i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(bubble[j]>bubble[j+1]){
				tmp=bubble[j];
				bubble[j]=bubble[j+1];
				bubble[j+1]=tmp;
			}
		}
	}
	for(i=0;i<n;i++)
		cout << bubble[i];
	
	getchar();
	getchar();
	return 0;
}



