#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <iostream>
using namespace std;
void sleep(long wait)
{
	clock_t start = clock();
	while (clock() - start < wait);
}
void print();
void deleting(int x, int y);
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
	int ms=0;
	int s=0;
	int m=0;
void printdigit(int digit,int x,int y);
void sec();
void mili();
void minute();
void time();
void setcolor(int color_code)
{
    HANDLE ConsoleSettings;
    ConsoleSettings=GetStdHandle(STD_OUTPUT_HANDLE);
    
    SetConsoleTextAttribute(ConsoleSettings,color_code);
}
//int ms,s,m;
int main()
{
	print();
	printdigit(0,20,12);
	printdigit(0,40,12);
	printdigit(0,60,12);
	while(1){
	char ch;
		ch=getch();
			if(ch=='B' || ch=='b'){
				srand(time(NULL));
				printdigit(0,20,12);
				printdigit(0,40,12);
				printdigit(0,60,12);
				while(!kbhit())
				{
					mili();
				}
}
			else
	
				ch=getch();
}
}
void print()
{
	gotoxy(3,1);
	cout<<"press b for begin";
	gotoxy(3,2);
	cout<<"press r for reset";
	gotoxy(3,3);
	cout<<"press s for stop";
}
void printdigit(int digit,int x,int y)
{
	if(x==20)
	setcolor(3);
		if(x==40)
	setcolor(4);
			if(x==60)
	setcolor(5);
	if(digit/10 == 1){
		gotoxy(x-3,y+1);
		cout<<"|"<<endl;
		gotoxy(x-3,y+2);
		cout<<"|"<<endl;
		gotoxy(x-3,y+3);
		cout<<"|"<<endl;
		gotoxy(x-3,y+4);
		cout<<"|"<<endl;
		digit=digit%10;
	}
	else
		if(digit/10 ==2){
			gotoxy(x-5,y);
			cout<<" _ _"<<endl;
			gotoxy(x-5,y+1);
			cout<<"    |"<<endl;
			gotoxy(x-5,y+2);
			cout<<" _ _"<<endl;
			gotoxy(x-5,y+3);
			cout<<"|   "<<endl;
			gotoxy(x-5,y+4);
			cout<<" _ _"<<endl;
			digit=digit%10;
		}
		else
			if(digit/10 ==3){
				gotoxy(x-5,y);
				cout<<" _ _"<<endl;
				gotoxy(x-5,y+1);
				cout<<"    |"<<endl;
				gotoxy(x-5,y+2);
				cout<<" _ _"<<endl;
				gotoxy(x-5,y+3);
				cout<<"    |"<<endl;
				gotoxy(x-5,y+4);
				cout<<" _ _"<<endl; 
				digit%=10;
			}
			else if(digit/10 ==4){
				gotoxy(x-5,y+1);
				cout<<"|   |"<<endl;
				gotoxy(x-5,y+2);
				cout<<"|_ _|"<<endl;
				gotoxy(x-5,y+3);
				cout<<"    |"<<endl;
				gotoxy(x-5,y+4);
				cout<<"    |"<<endl;
				digit%=10;
			}
			else if(digit/10 ==5){
				gotoxy(x-5,y);
				cout<<" _ _"<<endl;
				gotoxy(x-5,y+1);
				cout<<"|   "<<endl;
				gotoxy(x-5,y+2);
				cout<<" _ _"<<endl;
				gotoxy(x-5,y+3);
				cout<<"    |"<<endl;
				gotoxy(x-5,y+4);
				cout<<" _ _"<<endl;
				digit%=10;
			}
			 if(digit/10 ==6){
				gotoxy(x-5,y);
				cout<<" _ _"<<endl;
				gotoxy(x-5,y+1);
				cout<<"|   "<<endl;
				gotoxy(x-5,y+2);
				cout<<" _ _"<<endl;
				gotoxy(x-5,y+3);
				cout<<"|   |"<<endl;
				gotoxy(x-5,y+4);
				cout<<"|_ _"<<endl;
				digit%=10;
			}
			 if(digit/10 ==7){
				gotoxy(x-5,y);
				cout<<" _ _"<<endl;
				gotoxy(x-5,y+1);
				cout<<"    |"<<endl;
				gotoxy(x-5,y+2);
				cout<<"    |"<<endl;
				gotoxy(x-5,y+3);
				cout<<"    |"<<endl;
				gotoxy(x-5,y+4);
				cout<<"    |"<<endl;
				digit%=10;
			}
			 if(digit/10 ==8){
			    gotoxy(x-5,y);
				cout<<" _ _"<<endl;
				gotoxy(x-5,y+1);
				cout<<"|   |"<<endl;
				gotoxy(x-5,y+2);
				cout<<" _ _"<<endl;
				gotoxy(x-5,y+3);
				cout<<"|   |"<<endl;
				gotoxy(x-5,y+4);
				cout<<"|_ _"<<endl;
				digit%=10;
				}
			 if(digit/10 ==9){
				gotoxy(x-5,y);
				cout<<" _ _"<<endl;
				gotoxy(x-5,y+1);
				cout<<"|   |"<<endl;
				gotoxy(x-5,y+2);
				cout<<" _ _"<<endl;
				gotoxy(x-5,y+3);
				cout<<"    |"<<endl;
				gotoxy(x-5,y+4);
				cout<<" _ _"<<endl;
				digit%=10;
				}


			switch(digit)
			{
			case 0:		
				gotoxy(x,y);
				cout<<" _  _ "<<endl;
				gotoxy(x,y+1);
				cout<<"|    | "<<endl;
				gotoxy(x,y+2);
				cout<<"|    | "<<endl;
				gotoxy(x,y+3);
				cout<<"|    | "<<endl;
				gotoxy(x,y+4);
				cout<<" _  _ "<<endl;

				break;

			case 1:
				gotoxy(x,y+1);
				cout<<"|"<<endl;
				gotoxy(x,y+2);
				cout<<"|"<<endl;
				gotoxy(x,y+3);
				cout<<"|"<<endl;
				gotoxy(x,y+4);
				cout<<"|"<<endl;
				break;
			case 2:
				gotoxy(x,y);
				cout<<" _ _"<<endl;
				gotoxy(x,y+1);
				cout<<"    |"<<endl;
				gotoxy(x,y+2);
				cout<<" _ _"<<endl;
				gotoxy(x,y+3);
				cout<<"|   "<<endl;
				gotoxy(x,y+4);
				cout<<" _ _"<<endl;
				break;
			case 3:
				gotoxy(x,y);
				cout<<" _ _"<<endl;
				gotoxy(x,y+1);
				cout<<"    |"<<endl;
				gotoxy(x,y+2);
				cout<<" _ _"<<endl;
				gotoxy(x,y+3);
				cout<<"    |"<<endl;
				gotoxy(x,y+4);
				cout<<" _ _"<<endl; 
				break;
			case 4:
				gotoxy(x,y+1);
				cout<<"|   |"<<endl;
				gotoxy(x,y+2);
				cout<<"|_ _|"<<endl;
				gotoxy(x,y+3);
				cout<<"    |"<<endl;
				gotoxy(x,y+4);
				cout<<"    |"<<endl;
				break;
			case 5:
				gotoxy(x,y);
				cout<<" _ _"<<endl;
				gotoxy(x,y+1);
				cout<<"|   "<<endl;
				gotoxy(x,y+2);
				cout<<" _ _"<<endl;
				gotoxy(x,y+3);
				cout<<"    |"<<endl;
				gotoxy(x,y+4);
				cout<<" _ _"<<endl;
				break;
			case 6:
				gotoxy(x,y);
				cout<<" _ _"<<endl;
				gotoxy(x,y+1);
				cout<<"|   "<<endl;
				gotoxy(x,y+2);
				cout<<" _ _"<<endl;
				gotoxy(x,y+3);
				cout<<"|   |"<<endl;
				gotoxy(x,y+4);
				cout<<"|_ _"<<endl;
				break;
			case 7:
				gotoxy(x,y);
				cout<<" _ _"<<endl;
				gotoxy(x,y+1);
				cout<<"    |"<<endl;
				gotoxy(x,y+2);
				cout<<"    |"<<endl;
				gotoxy(x,y+3);
				cout<<"    |"<<endl;
				gotoxy(x,y+4);
				cout<<"    |"<<endl;
				break;

			case 8:
				gotoxy(x,y);
				cout<<" _ _"<<endl;
				gotoxy(x,y+1);
				cout<<"|   |"<<endl;
				gotoxy(x,y+2);
				cout<<" _ _"<<endl;
				gotoxy(x,y+3);
				cout<<"|   |"<<endl;
				gotoxy(x,y+4);
				cout<<"|_ _"<<endl;
				break;
			case 9:
				gotoxy(x,y);
				cout<<" _ _"<<endl;
				gotoxy(x,y+1);
				cout<<"|   |"<<endl;
				gotoxy(x,y+2);
				cout<<" _ _"<<endl;
				gotoxy(x,y+3);
				cout<<"    |"<<endl;
				gotoxy(x,y+4);
				cout<<" _ _"<<endl;
				break;
			}	
}
void mili()
{
	printdigit(m,20,12);
	while(!kbhit()){
		if(ms<100){
b:	    Sleep(1);
			printdigit(ms,60,12);
			ms++;
			Sleep(1);
			//system("cls");
			deleting(60,12);
		}

		else{
			deleting(40,12);
			ms=0;
			s++;
			printdigit(s,40,12);

			if(s==60){
		    	deleting(20,12);
				s=0;
				m++;
				printdigit(m,20,12);
			
			}
			goto b;

	}
	}
		if(kbhit()){
			char ch;
			ch=getch();
				if(ch=='S' || ch=='s'){
					deleting(20,12);
					deleting(40,12);
					deleting(60,12);
					printdigit(m,20,12);
					printdigit(s,40,12);
					printdigit(ms,60,12);
					gotoxy(5,24);
					system("pause");
					
					if(kbhit()){
						char c;
						c=getch();
                      if(c=='B' || c=='b'){
						mili();
					}
				}
				}
				else
					if(ch=='R' || ch=='r'){
					deleting(20,12);
						deleting(40,12);
						deleting(60,12);
					printdigit(0,20,12);
					printdigit(0,40,12);
					printdigit(0,60,12);
					ms=0,s=0,m=0;
					gotoxy(5,24);
						system("pause");
					if(kbhit()){
						 if(ch=='B' || ch=='b'){
						mili();
					}
					}

	

		}
		}
}
void deleting(int x, int y)
{
	x=x-5;
	y=y;
	for(int j=0;j<11;j++){
	for(int i=0;i<5;i++){
	gotoxy(x,y);
	cout<<(char)255;
	y++;
	}
	y=y-5;
	x++;
}
}