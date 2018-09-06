#include <iostream>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
using namespace std;
typedef struct list{
	char name[20];
	char family[20];
	char tel[20];
	char email[50];
	char group[20];
	struct list *next;
}*node;
list *head,*p,*record;
void setcolor(int color_code)
{
	HANDLE ConsoleSettings;
	ConsoleSettings=GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(ConsoleSettings,color_code);
}
void gotoxy(int x, int y)
{

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void cursor(int x,int y)
{
	setcolor(12);
	gotoxy(x,y);
	for(int i=0;i<3;i++){
		cout<<char(219);
		x++;
	}
	gotoxy(x-6,y);
		cout<<"<==";

	setcolor(7);
}
void delet(int x,int y)
{
	gotoxy(x-3,y);
	for(int i=0;i<6;i++){
		cout<<char(255);
		x++;
	}
}
void add()
{
	system ("cls");
	cout<<endl<<"ADDING A CONTACT"<<endl<<endl;
	record=(list *)malloc(sizeof(list));
	if(record==NULL)
	cout<<"out of memory";
	cout<<"name:";
	fgets(record->name,20,stdin);
	cout<<"family:";
	fgets(record->family,20,stdin);
	cout<<"tel:";
	fgets(record->tel,20,stdin);
	cout<<"email:";
	fgets(record->email,20,stdin);
	cout<<"which group?press 1 for family,2 for friends,or else for others"<<endl;
	fgets(record->group,20,stdin);
	record->next=head;
	head=record;
}
void display()
{
	cout<<endl<<"YOUR CONTACTS:"<<endl<<endl;
	list *temp;
	cout<<"family \t\t\t friends \t\t\t others"<<endl;
	temp=head;
	while(temp!=NULL)
	{
		cout<<"*******************************************************************************"<<endl;
		if(temp->group[0]=='1')
			cout<<"name:"<<(temp->name)<<"family:"<<(temp->family)<<"tel:"<<(temp->tel)<<"email:"<<(temp->email)<<endl;
		else if(temp->group[0]=='2')
			cout<<"\t\t\tname:"<<(temp->name)<<"\t\t\tfamily:"<<(temp->family)<<"\t\t\ttel:"<<(temp->tel)<<"\t\t\temail:"<<(temp->email)<<endl;
		else
		cout<<"\t\t\t\t\t\t\tname:"<<(temp->name)<<"\t\t\t\t\t\t\tfamily:"<<(temp->family)<<"\t\t\t\t\t\t\ttel:"<<(temp->tel)<<"\t\t\t\t\t\t\temail:"<<(temp->email)<<endl;

		temp=temp->next;
	}
	cout<<"*******************************************************************************"<<endl;
}
void Delete()
{
	list *pdel;
	list *pprev;
	char del_name[20];
	printf ("what is the name that you want to delete ?");
	fgets (del_name, 20, stdin);
	if (head == NULL) {
		printf ("No list to delete from\n");
		return;
	}
	if (strcmp(head->name, del_name) == 0) {
		pdel= head;
		head= head->next;
		cout<<"successfully deleted"<<endl;
		free(pdel);
		return; 
	}
	pprev= head;
	while (pprev->next != NULL) {
		if (strcmp(pprev->next->name,del_name) == 0) {
			pdel= pprev->next;
			pprev->next= pdel->next;
			free(pdel);
			cout<<"successfully deleted"<<endl;
			return;
		}
		pprev= pprev->next;
		cout<<"successfully deleted"<<endl;
	}
	printf ("name not found!\n");
}
void search()
{
	char search_name[20];
	cout<<"enter the name you want to search"<<endl;
	fgets(search_name,20,stdin);
	if(head==NULL)
	{
		cout<<"no list to search"<<endl;
		return ;
	}
	if(strcmp(head->name,search_name)==0){
		cout<<"name:"<<head->name<<endl;
		cout<<"family:"<<head->family<<endl;
		cout<<"tel:"<<head->tel<<endl;
		cout<<"email:"<<head->email<<endl;
		cout<<"group:"<<head->group<<endl;
	cout<<"*********************************************"<<endl;
	}
	list *psearch;
	psearch=head;
	while(psearch->next!=NULL && !kbhit()){
		if (strcmp(psearch->next->name, search_name) == 0)
		{
			cout<<"name:"<<search_name<<endl;
			cout<<"family:"<<head->family<<endl;
			cout<<"tel:"<<head->tel<<endl;
			cout<<"email:"<<head->email<<endl;
			cout<<"group:"<<head->group<<endl;
			cout<<"*********************************************"<<endl;
		}
		psearch= psearch->next;
	}
	if(kbhit())
	{
		char ch;
		ch=getch();
		if(ch='y')
			return;
	}
}
void modify()
{		
	char modify[20];
	if(head==NULL)
	{
		cout<<"no list to modify"<<endl;
		return ;
	}
	list *temp=head;
	cout<<"enter the name which you want to change"<<endl;
	fgets(modify,20,stdin);
		if(strcmp(head->name,modify)==0){
			cout<<"enter name"<<endl;
			fgets(head->name,20,stdin);
			cout<<"enter familyname"<<endl;
			fgets(head->family,20,stdin);
			cout<<"enter tel"<<endl;
			fgets(head->tel,20,stdin);
			cout<<"enter email"<<endl;
			fgets(head->email,20,stdin);
		}
	while(temp->next!=NULL && !kbhit()){
		if (strcmp(temp->next->name,modify) == 0)
		{	cout<<"enter name"<<endl;
			fgets(temp->next->name,20,stdin);
			cout<<"enter familyname"<<endl;
			fgets(temp->next->family,20,stdin);
			cout<<"enter tel"<<endl;
			fgets(temp->next->tel,20,stdin);
			cout<<"enter email"<<endl;
			fgets(temp->next->email,20,stdin);
	
		}
		temp= temp->next;
	}
		if(kbhit())
	{
		char ch;
		ch=getch();
		if(ch='y')
			return;
	}
	//printf ("name not found!\n");
	return;
}
void save()
{
	FILE *fp;
	fp=fopen("r.txt","r+");
	list *it = head;

	while (it != NULL) {
		fwrite (it->name, sizeof(it->name), 1, fp);
		fwrite (it->family, sizeof(it->family), 1, fp);
		fwrite (it->tel, sizeof(it->tel), 1, fp);
		fwrite (it->email, sizeof(it->email), 1, fp);
		it = it->next;
	}
	cout<<"successfully saved"<<endl;
}
void readfromfile()
{
	FILE *fp;
	fp=fopen("r.txt","r");
	list *it = head;
	while (it != NULL) {
		fread(it->name, sizeof(it->name), 1, fp);
		printf("name:%s",it->name);
		fread(it->family, sizeof(it->family), 1, fp);
		printf("family:%s",it->family);
		fread (it->tel, sizeof(it->tel), 1, fp);
		printf("tel:%s",it->tel);
		fread(it->email, sizeof(it->email), 1, fp);
		printf("email:%s",it->email);
		cout<<"*********************************************"<<endl;
		it = it->next;
	}
}
void print()
{
	setcolor(11);
	cout<<"                              MY PHONE BOOK"<<endl;
		cout<<"*******************************************************************************"<<endl;
		cout<<"1) add a contact"<<endl<<"2) delete a contact"<<endl<<"3) display the list"<<endl<<"4) search"<<endl<<"5) modify"<<endl<<"6) save the list to file"<<endl<<"7) see the list from the file"<<endl<<"8) exit"<<endl;
		cout<<endl<<"press 'y' to select"<<endl;
		setcolor(7);
}
void main(void)
{
	print();
	int y=2;
	cursor(35,y);
	while(1){
	while(kbhit())
	{
		char c;
		c=getch();
		switch(c)
		{
		case 80:
			if(y!=9){
			delet(35,y);
			y=y+1;
			cursor(35,y);
			break;
			}
			else if(y==9)
			break;
		case 72:
			if(y!=2){
			delet(35,y);
			y=y-1;
			cursor(35,y);
			break;
			}
			else if(y==2)
				break;
		case 'y':
			cout<<"Pressed";
			system("cls");
			if(y==2){
				add();
				system("cls");
				y=2;
				print();
				cursor(35,y);
				break;
			}
			
			if(y==3){
			Delete();
			system("cls");
				y=2;
				print();
				cursor(35,y);
				break;
			}
			if(y==4){
			display();
			if(getch()=='y'){
			system("cls");
				y=2;
				print();
				cursor(35,y);
				break;
			}
			}
			if(y==5){
			search();
			if(getch()=='y'){
			system("cls");
				y=2;
				print();
				cursor(35,y);
				break;
			}
			}
			if(y==6){
			modify();
			if(getch()=='y'){
			    system("cls");
				y=2;
				print();
				cursor(35,y);
				break;
			}
			}
			if(y==7){
			save();
			if(getch()=='y'){
			    system("cls");
				y=2;
				print();
				cursor(35,y);
				break;
			}
			}
			if(y==8){
			readfromfile();
			if(getch()=='y'){
			    system("cls");
				y=2;
				print();
				cursor(35,y);
				break;
			}
			}
			if(y>=9)
				exit(0);
			break;
		}
		
	}
	}
	getchar();

}
