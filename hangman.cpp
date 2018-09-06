#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string>
#include<Windows.h>
#include <time.h>
using namespace std;
void alpha();
void gotoxy(int x, int y)
{

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void setcolor(int color_code)
{
	HANDLE ConsoleSettings;
	ConsoleSettings=GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(ConsoleSettings,color_code);
}
void printspace(int count);
int getwordcount(string str);
void play();
void ground();
void rode();
void head();
void body();
void lhand();
void rhand();
void lleg();
void rleg();
void drawhangman(int x);
string word;
string random()
{
	string random;
	char str[1000], pick[1000];
	FILE *fp;
	int readCount = 0;
	srand(time(NULL));
	fp = fopen("t.txt", "r");
	if (fp)
	{
		if (fgets(pick,1000, fp) != NULL)
		{
			readCount = 1;
			while (fgets (str,1000, fp) != NULL)
			{
				if ((rand() % ++readCount) == 0)
				{
					strcpy(pick, str);
				}
			}
		}
	}
	fclose(fp);
	random = pick;
	return random;
}
int main() 
{
	alpha();
	gotoxy(1,1);
	play();
	getch();
	return 0;
}
void printspace(int count)
{
	setcolor(2);
	int x=20,y=15;
	for(int i=0;i<count;i++){
		gotoxy(x,y);
		cout<<"_";
		x++;
	}
}
void alpha()
{
	gotoxy(5,20);
	for(int a=65;a<91;a++){
		setcolor(3);
		cout<<(char)a;
		cout<<"         ";
	}
	gotoxy(1,18);
	cout<<"incorrect characters:";
}
int getwordcount(string str)
{
	int count=0;
	for(int m=0; str[m] != 0; m++){
		if(str[m] != ' '){
			count ++;
		}
	}
	return count;
}
void play()
{
	string word = random();
	int n=word.size()-1;
	int q=25;
	//cout<<n;
	//cout << word << endl;
	printspace(	word.size()-1);
	int mistakes=1;
	gotoxy(5,5);
	cout<<"number of mistakes:"<<"0";
	char ch,search,*p;
	while(mistakes<=8)
	{
		if(kbhit()){
			ch=getch();
			for(int i=0;i<word.size()-1;i++)
			{
				if(ch==word[i]){
					gotoxy(20+i,15);
					setcolor(2);
					cout<<word[i];
					n--;
				}
					//cout<<n;
					if(n==0){
						gotoxy(5,6);
						setcolor(5);
						cout<<"congrajulations"<<endl;
						gotoxy(5,7);
						cout<<"press any key to exit";
						if(kbhit()){
							exit(0);
						//break;
						
						
					}
				}
			}
			if(word.find_first_of(ch)==string::npos){
				gotoxy(q,18);
				cout<<ch;
				q+=2;
				drawhangman(mistakes);
				gotoxy(5,5);
				cout<<"number of mistakes:"<<mistakes++;
			}
		}
	}
	if(mistakes=9){
		setcolor(5);
		gotoxy(6,6);
		cout<<"the word was:"<<word<<endl;
		gotoxy(6,7);
		cout<<"you lost\t";
		cout<<"press any key to exit";
	}
}
void ground(){
	int x=65;
	gotoxy(65,18);
	for(int i=0;i<10;i++){
		cout<<"*";
		x++;
	}
}
void rope(){
	int x=65,y=18;
	gotoxy(x+5,y);
	for(int j=0;j<10;j++){
		cout<<"*";
		y--;
		gotoxy(70,y);
	}
	gotoxy(70,8);
	x=70;
	for(int j=0;j<10;j++){
		cout<<"*";
		x--;
		gotoxy(x,8);
	}

}
void head()
{
	gotoxy(60,9);
	cout<<" * ";
	gotoxy(60,10);
	cout<<"***"<<endl;
	gotoxy(60,11);
	cout<<" * "<<endl;
}
void body()
{
	int y=12;
	gotoxy(61,12);
	for(int i=0;i<5;i++){
		cout<<"*";
		gotoxy(61,y);
		y++;
	}
}
void rhand()
{
	int x=60,y=14;
	gotoxy(60,14);
	for(int i=0;i<4;i++){
		cout<<"*";
		gotoxy(x,y);
		x--;
		y--;
	}
}
void lhand()
{
	int x=62,y=14;
	gotoxy(62,14);
	for(int i=0;i<4;i++){
		cout<<"*";
		gotoxy(x,y);
		x++;
		y--;
	}
}
void rleg()
{
	int x=60,y=15;
	gotoxy(60,15);
	for(int i=0;i<4;i++){
		cout<<"*";
		gotoxy(x,y);
		x--;
		y++;
	}
}
void lleg()
{
	int x=62,y=15;
	gotoxy(62,15);
	for(int i=0;i<4;i++){
		cout<<"*";
		gotoxy(x,y);
		x++;
		y++;
	}
}
void drawhangman(int x)
{
	setcolor(12);
	switch(x)
	{
	case 1:
		ground();
		break;
	case 2:
		rope();
		break;
	case 3:
		head();
		break;
	case 4:
		body();
		break;
	case 5:
		lhand();
		break;
	case 6:
		rhand();
		break;
	case 7:
		lleg();
		break;
	case 8:
		rleg();
		break;
	}
}