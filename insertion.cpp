#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int insert[100];
	int n,i,j,tmp=0;
	cout << "enter number of elements u wanna sort";
	cin >>n;
	for(int i=0;i<n;i++)
		cin >> insert[i];
	for(i=1;i<n;i++){
		tmp=insert[i];
		j=i-1;
		while(tmp<insert[j]&&j>=0){
			insert[j+1]=insert[j];
			j=j-1;
		}
		insert[j+1]=tmp;
	}
	for(i=0;i<n;i++)
		cout << insert[i];
	getchar();
	getchar();
	return 0;
}



