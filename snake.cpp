#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;
void game();
void controls(char s[][22],int temp[][22],int eating);
void table(char s[][22],int score);
bool checkfood(char s[][22],int fx,int fy);
void food(char s[][22],int & fx,int & fy);
bool gameover(char s[][22],int temp[][22]);
void endgame(int score);
int length;
int speed=500;
char contr='n';
void setcolor(int color_code)
{
	HANDLE ConsoleSettings;
	ConsoleSettings=GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(ConsoleSettings,color_code);
}
int check[80][22];
int main()
{
	setcolor(3);
    srand(time(0));
            game();
            return 0;
}
void table(char s[][22],int score)
{
    int x=79;
    int y=22;
    int i,j;
    for(i=0;i<y;i++)
    {
        for(j=0;j<x;j++)
        {
            if(j<(x-1)) 
				cout<<s[j][i];
            if(j==(x-1))
				cout<<s[j][i]<<endl;
        }
    }
    cout<<"Your score: "<<score;
}

void game()
{
    char s[80][22];
    int temp[80][22];
    int i,j,fx,fy,x,y,score=0;
    int eating;
    for(i=0;i<22;i++)
    {
        for(j=0;j<80;j++)
        {
            if(i==1 || i==21){
				s[j][i]='-';cout<<s[j][i];
			}
			else s[j][i]=' ';
        }
    }
   food(s,fx,fy);
    for(y=1;y<21;y++)
    {
        for(x=1;x<80;x++)
        {
            temp[x][y]=0;
		}
    }
    s[42][10]='o';
    s[41][10]='*';
    s[40][10]='*';

    temp[40][10]=3;
    temp[41][10]=2;
    temp[42][10]=1;

    system("cls");
    table(s,score);
    length=3;
	while(true)
    {
		
        eating=0;
        Sleep(speed);
        if(kbhit())
        {
            contr=getch();
        }
            for(x=1;x<80;x++)
            {
                for(y=1;y<21;y++)
                {
                    if(s[x][y]=='*')
                    {
                        check[x][y]=1;
                    }
                    else check[x][y]=0;
                }
            }
            if(checkfood(s,fx,fy)==true)
            {
                eating=1;
                score=score+1;
                controls(s,temp,eating);
                food(s,fx,fy);
            }
            else
            {
                controls(s,temp,eating);
            }

            if(gameover(s,temp)==true)
				{
					endgame(score);
        return;
			}
            else
            {
            system("cls");
            table(s,score);
			}

    }
    }

void controls(char s[][22],int temp[][22],int eating) 
{
    int i,x,y;
    for(i=length;i>0;i--)
    {
        if(i==length)
        {
            for(x=1;x<80;x++)
            {
                for(y=1;y<21;y++)
                {
                    if(temp[x][y]==i && s[x][y]=='*')
                    {
                        if(eating==0)
                        {
                            s[x][y]=' '; temp[x][y]=0;
                           break;
                        }
                        else if(eating==1)
                        {                  
                            s[x][y]='*'; temp[x][y]=length+1;
                            length++;
							break;
                        }
                    }
                }
            }
        }
        else if(i>1 && i<length) 
        {                    
			for(x=1;x<=80;x++)
            {
                for(y=1;y<21;y++)
                {
                    if(temp[x][y]==i && s[x][y]=='*')
                    {
                        temp[x][y]=i+1;
                      break;
                    }
                }
            }
        }
        else if(i==1)
        {
            for(x=1;x<=80;x++)
            {
                for(y=1;y<=21;y++)
                {
					
			     if(temp[x][y]==i && s[x][y]=='o')
                    {
                        movecheck:
                        if(contr!='w' && contr!='s' && contr!='a' && contr!='d')
                        {   
							s[x][y]='*'; temp[x][y]=i+1;
							if(x==80)
							{ 
								x=length;
								i=1;
							temp[x][y]=i;s[x][y]='o';
								for(x=length-1;x>0;x--){
									temp[x][y]=i+1; s[x][y]='*';
										i++;
							}
							}
							if(x==1)
							{ 
								x=80-length;
								i=1;
							temp[x][y]=i;s[x][y]='o';
								for(x=80-length+1;x<80;x++){
									temp[x][y]=i+1; s[x][y]='*';
										i++;
								}
							}
		                  if(temp[x-1][y]==i+2)
                        {
                            s[x+1][y]='o'; temp[x+1][y]=1;
                            return; 
                        }
                        else if(temp[x+1][y]==i+2)
                        {
                            s[x-1][y]='o'; temp[x-1][y]=1;
                            return;
                        }
                        else if(temp[x][y+1]==i+2)
                        {
                            s[x][y-1]='o'; temp[x][y-1]=1;
                            return;
                        }
                        else if(temp[x][y-1]==i+2)
                        {
                            s[x][y+1]='o'; temp[x][y+1]=1;
                            return;
                        }
                        }
                        else if(contr=='w')
                        {
                            if(temp[x][y-1]==0)
                            {              
                            s[x][y]='*'; temp[x][y]=i+1;
                            s[x][y-1]='o'; temp[x][y-1]=1;
                            return;
                            }
                            else 
                            {  
                                contr='n';
                                goto movecheck;
                            }
                        }
                        else if(contr=='s')
                        {
                            if(temp[x][y+1]==0)
                            {
                            s[x][y]='*'; temp[x][y]=i+1;
                            s[x][y+1]='o'; temp[x][y+1]=1;
                            return;
                            }
                            else
                            {
                                contr='n';
                                goto movecheck;
                            }
                        }
                        else if(contr=='a')
                        {
                            if(temp[x-1][y]==0)
                            {
                            s[x][y]='*'; temp[x][y]=i+1;
                            s[x-1][y]='o'; temp[x-1][y]=1;
                            return;
                            }
                            else
                            {
                                contr='n';
                                goto movecheck;
                            }
                        }
                        else if(contr=='d')
                        {
                            if(temp[x+1][y]==0)
                            {
                            s[x][y]='*'; temp[x][y]=i+1;
                            s[x+1][y]='o'; temp[x+1][y]=1;
                            return;
                            }
                            else
                            {
                                contr='n';
                                goto movecheck;
                            }
                        }
                    }
                }
            }
        }

    }

}
bool checkfood(char s[][22],int fx,int fy) 
{
    int x,y,c=0;
    for(x=1;x<80;x++)
    {
        for(y=1;y<21;y++)
        {
            if(s[x][y]=='o' && x==fx && y==fy)
            {
                c=1;
            }
        }
    }
    if(c==1) 
	{
		if(speed-10>0)
		speed=speed-10;
		else
		speed;
		return true;
	}
	else 
		return false;
}
void food(char s[][22],int & fx,int & fy)
{
        int i,j;
        fx=(rand()%78)+1;
        fy=(rand()%18)+2;
        for(j=1;j<80;j++)
        {
            for(i=1;i<20;i++)
            {
                if(s[j][i]!='*' && s[j][i]!='o') 
				{
                    s[fx][fy]='+';
                    return;
                }
                else
                {
                    fx=(rand()%78)+1;
                    fy=(rand()%18)+2;
                    i=1;
                    j=1;
                }
            }
        }
}
bool gameover(char s[][22],int temp[][22])
{
    int x,y,c=0;

    for(x=0;x<80;x++)
    {
        for(y=0;y<22;y++)
        {
			
            if((y==1 || y==21) && s[x][y]=='o')
               c=1;
            if(check[x][y]==1 && s[x][y]=='o')
            {
                c=1;
            }
        }
    }
    if(c==1) 
		return true;
    if(c==0) 
		return false;
}
void endgame(int score)
{
	system("cls");
	setcolor(12);
    cout<<""<<endl<<endl;
    cout<<" ------------------------------------------------------------------------- "<<endl;
    cout<<"|    *****      *     *       * ******       ****  *       ****** ****    |"<<endl;
    cout<<"|   *          * *    * *   * * *           *    *  *     * *     *   *   |"<<endl;
    cout<<"|   *  ****   *   *   *  * *  * *****       *    *   *   *  ****  ****    |"<<endl;
    cout<<"|   *  *  *  *******  *   *   * *           *    *    * *   *     * *     |"<<endl;
    cout<<"|    *****  *       * *       * ******       ****      *    ***** *   *   |"<<endl;
    cout<<" ------------------------------------------------------------------------- "<<endl;
    cout<<""<<endl<<endl;
    cout<<"                        Y O U R   S C O R E : "<<score<<endl<<endl;
    cout<<""<<endl<<endl;
	Sleep(500000);
}
