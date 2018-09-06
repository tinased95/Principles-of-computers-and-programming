#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;
char present_screen[80][25]={' '};
char previous_screen[80][25]={' '};
short rings[3][12]={0};
long int move_=0;
void gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	_COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(hConsole, pos);
}
void print(char c, short x, short y)
{
	gotoxy(x,y);
	cout << c;
}
void setcolor(int color_code)
{
	HANDLE ConsoleSettings;
	ConsoleSettings=GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(ConsoleSettings,color_code);
}
void refresh()
{
	short x, y; 
	for(y=0 ; y<25 ; y++)
	{
		for(x=0 ; x<80 ; x++)
		{
			if(present_screen[x][y] != previous_screen[x][y])
			{
				print(present_screen[x][y],x,y); 
				previous_screen[x][y]=present_screen[x][y];         
			}        
		}        
	}     
}
void drawbars()
{
	setcolor(8);
	char z=219;
	int xx=12;
	int yy=10;
	for(int y=0 ; y<3 ; y++)
	{
		for(int x=0 ; x<13 ; x++)
		{
			gotoxy(xx,yy);
			cout<<z<<endl;	
			yy+=1;
		}
		xx+=27;
		yy=10;
	}
}
void screen_init()
{
	short x, y; 
	for(y=0 ; y<24 ; y++)
	{
		for(x=0 ; x<80 ; x++)
		{
			present_screen[x][y]=' ';
			previous_screen[x][y]=' ';
		}        
	}     
}
void drawrings(short x, short y, short n)
{
	int i;  
	setcolor(n);
	for(i=x-n ; i<=x+n ; i++)
	{
		present_screen[i][y]=(char)219;
		previous_screen[i][y]=(char)219;
		print((char)219, i, y);
	}
}
void hanoi_draw_rings(short n)
{
	short i=0;
	for(i=0 ; i<n ; i++)
	{
		drawrings(12, 22-i,n-i);        
	}        
}
void remove_rings(short x, short y, short n)
{
	int i;

	for(i=x-n ; i<=x+n ; i++)
	{
		present_screen[i][y]=' ';
	}
}
void hanoi_init(short n)
{
	short j,i;

	for(i=0 ; i<12 ; i++)
		for(j=0 ; j<3 ; j++)
			rings[j][i]=0;
	j=1;
	for(i=11 ; i>=11-n+1 ; i--)
	{
		rings[0][i]=j;
		j++;       
	}     
}
short calculate_top(short column)
{
	short j=0, i=11;
	for(i=11 ; rings[column][i]>0 ; i--)
	{
		j++;       
	}       
	return i;
}
short calculate_height(short column) //?????? ???? ?? ????
{
	short j=0, i=11;
	for(i=11 ; rings[column][i]>0 ; i--)
	{
		j++;       
	}        
	return j;
}
void ring_animate(short s[2], short e[2], short n)
{
	short i, j, direct=1;
	if(s[0] > e[0])
		direct=-1;      
	while(s[1]>8)
	{
		remove_rings(s[0],s[1],n);
		s[1]--;
		drawrings(s[0],s[1],n);
		drawbars();    
		refresh();
		Sleep(30);
	} //up 
	while(s[0]!=e[0])
	{
		remove_rings(s[0],s[1],n);
		s[0]+=direct;
		drawrings(s[0],s[1],n);
		drawbars();   
		refresh();
		Sleep(30);
	}  //left and right
	while(s[1]<e[1])
	{
		remove_rings(s[0],s[1],n);
		s[1]++;
		drawrings(s[0],s[1],n);
		drawbars();
		refresh();
		Sleep(30);
	}//down
}
void hanoi(short n, short from, short to, short temp)
{
	short start[2], end[2];  
	if(n>1)
    hanoi(n-1, from, temp, to);  
	move_++;
	gotoxy(0, 24);
	cout << "counting moves:"<< move_;
	switch(temp)
	{
	case 0:
		end[0]=12;
		break;
	case 1:
		end[0]=39;
		break;
	case 2:
		end[0]=66;
		break;         
	}
	end[1]=22-calculate_height(temp);  
	switch(from)
	{
	case 0:
		start[0]=12;
		break;
	case 1:
		start[0]=39;
		break;
	case 2:
		start[0]=66;
		break;         
	}
	start[1]=23-calculate_height(from);  
	rings[from][calculate_top(from)+1]=0;
	rings[temp][calculate_top(temp)]=n;
	ring_animate(start, end, n);  
	if(n>1)
		hanoi(n-1, to, from, temp);
	return;
}
void program(short n)
{
	hanoi_init(n);
	move_=0;
	screen_init();
	drawbars();
	hanoi_draw_rings(n);
	refresh();
	getchar();
	hanoi(n,0,1,2);
	getchar();
}
int main()
{
	short n=0;
	char z=219;
	while(n<1 || n>12)
	{
		cout << "Enter the height of the tower from 1 to 12 : ";
		cin  >> n;
	} 
	gotoxy(0,23);
	setcolor(8);
	for(int i=0 ; i<=79 ; i++)
	{
		cout<<z;
	}
	program(n);
	getchar();
	getchar();
	return 0;  
}
