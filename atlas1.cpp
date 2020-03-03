#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
#include<string.h>
#include<graphics.h>
#include<process.h>
#include<time.h>
using namespace std;

struct node
{
	char name[50];
	node *next;

}*start, *temp , *arr[26];
int delete_country(char[]);
void splash_screen()
{

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CXSCREEN);

	initwindow(screenWidth, screenHeight, "",-3 , -3);

	rectangle(0, 0, screenWidth, screenHeight);
	floodfill(200,200,WHITE);

	setbkcolor(WHITE);
	setcolor(RED);
	settextstyle(BOLD_FONT,HORIZ_DIR,10);

	outtextxy(570,370,"ATLAS");
	int i, x=500;
	int j=0;
	char d[5];
	settextstyle(1,HORIZ_DIR,1);
    for(i=0;i<520;++i)
    {
        delay(5);
        line(x,550,x,555);
        sprintf(d,"%d%", j);
        outtextxy(x+2,545,d);
        x++;
        if(i<500)
        {
            if(i%10==5)
            j=j+2;
        }
        if(i==420 || i==120)
        {
            delay(1000);
        }
    }
    delay(2000);
    cleardevice();

}
int entry()
{
	system("cls");
    int i;
    char a[]="WELCOME TO THE ULTIMATE GAME OF ATLAS";
    char b[]="Press Enter key to continue";
    char d[100];
    settextstyle(3,HORIZ_DIR,3);
    for(i=0;a[i]!='\0';i++)
    {
        d[i]=a[i];
        d[i+1]='\0';
        outtextxy(500,250, d);
        delay(50);
    }
    for(i=0;b[i]!='\0';i++)
    {
        d[i]=b[i];
        d[i+1]='\0';
        outtextxy(500,350, d);
        delay(50);
    }

    settextstyle(3,HORIZ_DIR,1);

    int j,flag=0;char c;
    cout<<"\n";
    settextstyle(3, HORIZ_DIR, 3);

	c=(char)getch();
	cleardevice();

    return 0;
}
int creating_list()
{
	FILE* fp;int i=0;
	fp=fopen("wordlist.txt","r");
	char a[50];char b[50];strcpy(b,arr[0]->name);
	node*temp=start;
	do{
        fscanf(fp,"%s",a);
        node *newnode = new node();
		strcpy(newnode -> name,a);
		newnode -> next = NULL;
        if(b[0]==a[0])
        {
            temp->next=newnode;
            temp=newnode;
        }
        else
        {
            i++;
            temp=arr[i];
            temp->next=newnode;
            temp=newnode;
            strcpy(b,a);
        }
	}while(!feof(fp)&&i<26);
	fclose(fp);
	return 0;
}
int allocate_pointers()
{
	//arr[0]=start;
	node* temp2=start;int i;
	node* temp3=start;
	for(i=0;i<=25;i++)
	{
		node* newnode=new node();
		newnode->name[0]=(char)(i+65);
		newnode->next=NULL;
		arr[i]=newnode;
	}
	start=arr[0];
}
void display()
{
	node* temp1=start;
	for(int i=0;i<26;i++)
    {
        temp1=arr[i];
       while(temp1!=NULL)
        {
		puts(temp1->name);
		temp1=temp1->next;
        }
    }
}
node* search_country(char a)
{
    int ascii=(int)a;
    node*temp2=arr[ascii-97]->next;
    char country[50];
    srand(time(NULL));
    int n=rand();
    n=n%10;
    for(int i=0;i<n;i++)
    {
        temp2=temp2->next;
        if(temp2==NULL)
            temp2=arr[ascii-97]->next;
    }
    return temp2;
}
int valid_country(char country[50],char c)
{
    int i=0,j=0,z=0;
    char s=(char)((int)c-32);
    char d[1000];
    if(country[0]!=(char)((int)c-32))
        {j=0;
            for(i=0;i<2;i++)
            {
                outtextxy(700,330, "Error !!!!");
                sprintf(d,"Please enter a country starting from %c :-                ",s);
                outtextxy(200 ,380 ,d);
                while(z==0)
                {
                    country[j]=(char)getch();
                    if((int)country[j]=='\b')
                    {
                        if(j!=0)
                        {
                            country[j-1]='\0';
                            sprintf(d,"%s ",country);
                            outtextxy(750 ,380 ,d );
                            j--;
                        }
                    }
                    else if ((int)country[j]==13)
                    {
                        z=1;
                        country[j]='\0';
                    }
                    else
                    {
                        country[j+1]='\0';
                        outtextxy(750 , 380, country);
                        j++;
                    }

                }
                if(country[0]==(char)((int)c-32))
                    return 0;
            }
            if(i==2)
                {
                    outtextxy(490,480, "Constantly wrong countries entered!!!!!!!!!!!");
                    delay(1000);
                    return 1;
                }
        }
        else
        {
           return 0;
        }
}
char last_letter(char country[50])
{
    int i=0;
    while(country[i]!='\0')
        i++;
    return country[i-1];
}
int country_used(char country[50],char c)
{
    int flag=delete_country(country);
    char s=(char)((int)c-32);
    int i=0;
    char d[1000];
    if(flag==1)
        {
            outtextxy(200,280,"This country is used or does not exist!!");
            delay(500);
            sprintf(d,"Please enter a country starting from %c :-                            ",s);
            outtextxy(200,380,d);
            int z=0;
        while(z==0)
        {
            country[i]=(char)getch();
            if((int)country[i]=='\b')
            {
                if(i!=0)
                {
                    country[i-1]='\0';
                    sprintf(d,"%s ",country);
                    outtextxy(750 ,380 ,d );
                    i--;
                }
            }
            else if ((int)country[i]==13)
            {
               z=1;
               country[i]='\0';
            }
            else
            {
                country[i+1]='\0';
                outtextxy(750 , 380, country);
                i++;
            }

        }
            flag=delete_country(country);
            if(flag==1)
            {
                outtextxy(490,480, "Constantly wrong countries entered!!!!!!!!!!!");
            delay(1000);
            return 1;}
            else
                return 0;
        }
    else
        return 0;
}
int game_start()
{
	system("cls");
	int flag=0,i=0;
	char country[50];char c;
	node* temp2;
    strcpy(country,"Atlas");
    do
    {
        settextstyle(BOLD_FONT,HORIZ_DIR,3);
        outtextxy(570, 80, "!!!!!!!! Your turn !!!!!");

        c=last_letter(country);
        temp2=search_country(c);

        settextstyle(8,HORIZ_DIR,2);
        strcpy(country,temp2->name);


        char d[1000];
        setcolor(BLACK);
        sprintf(d,"computers answer :- %s",country);
        outtextxy(200,280,d);
        setcolor(RED);
        c=last_letter(country);
        flag=delete_country(temp2->name);
        char s=(char)((int)c-32);
        //cout<<"\n\n\n\n\t\t\t\t\tYour Turn:\n\n\t\t\t\tPlease enter a country starting from  "<<(char)((int)c-32)<<"\t";
        sprintf(d,"Please enter a country starting from %c :-",s);
        outtextxy(200,380,d);
        i=0;
        char y;
        int z=0;
        while(z==0)
        {
            country[i]=(char)getch();
            y=country[i];
            if((int)country[i]=='\b')
            {
                if(i!=0)
                {
                    country[i-1]='\0';
                    puts(country);
                    sprintf(d,"%s ",country);
                    outtextxy(750 ,380 ,d );
                    i--;
                }
            }
            else if ((int)country[i]==13)
            {
               z=1;
               country[i]='\0';
            }
            else
            {
                country[i+1]='\0';
                outtextxy(750 , 380, country);
                i++;
            }

        }
        //gets(country);
        if(strcmp(country,"0")==0)
            break;
        flag=valid_country(country,c);
        if(flag==0)
        {
            //cout<<"Hello\n";
            flag=country_used(country,c);
            if(flag==1)
                break;
        }
        else
            break;
        cleardevice();
    }while(strcmp(country,"0")!=0);
    exit(0);
	return 0;

}
int delete_country(char c[50])
{
	int ascii,i=0;
	char a=c[0];
	ascii=(int)a;
	node* ptr=arr[ascii-65]->next;
	node* prev=arr[ascii-65];
    while(ptr!=NULL&&strcmp(ptr->name,c)!=0)
    {
        prev=ptr;
        ptr=ptr->next;
    }
	if(ptr==NULL)
	{
		return 1;
	}
	else if(strcmp(ptr->name,c)==0)
	{
		prev->next=ptr->next;
		free(ptr);
		return 0;
	}
}
int main()
{
    splash_screen();
	allocate_pointers();
	creating_list();
	entry();
	game_start();

	return 0;
}
