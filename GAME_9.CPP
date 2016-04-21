#include<iostream.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<fstream.h>
void screen();
void bckgrnd(int x);
void move();
int level_1();
int hurdle_1();
int level_2();
int hurdle_2();
int level_3();
int hurdle_3();
int level_4();
int hurdle_4();
int lost();
int game();
int level(int x,int y,int z);
int one(int x,int y);
int two(int x,int y);
int three(int x,int y);
int four(int x,int y);
int compltd(int x,int y,int z);
void layout();
void entername();
void congo();
void thnx();
int l,p,v=0,flag=10,rec;
float octave[7] = { 130.81, 146.83, 164.81, 174.61, 196, 220, 246.94 } ;
int b=0,a=0,c,j,d,n,q,f,k,count=50,col=60,row=20,x,y,i,lvl=1;
char ch,w;
void database();
class Player{
	public:
		int score;
		char name[20];
		void show()
		{
			cprintf("%s  -  ",name);
			cprintf("%d",score);
		}
};
Player obj ,obj1[5] ,obj2;
fstream fin;


	//MAIN


void main()
{
	textcolor(WHITE);
	layout();
	clrscr();
	textbackground(0);
	clrscr();
	textbackground(2);
	textcolor(4);
	entername();
	textbackground(6);
	textcolor(15);
	clrscr();
	screen();
	gotoxy(75,6);
	printf("%d",level);
	gotoxy(75,4);
	printf("%d",b);
	randomize();
	n=random(9)+1;
	x=random(62)+2;
	y=random(19)+2;
	gotoxy(x,y);
	printf("%d",n);
	do
	{
		sound ( octave[random(7)] * 4 ) ;
		if(b>=10)
		{
			nosound();
			if(lvl==1)
			{
				level(6,12,2);
				delay(100);
				one(13,5);
				delay(100);
				compltd(10,1,6);
				delay(100);
				textbackground(4);
				clrscr();
				screen();
				gotoxy(75,4);
				printf("%d",b);
				row=20;
				col=60;
				level_2();
				lvl++;
				getch();
			}
		}
		if(b>=25)
		{
			nosound();
			if(lvl==2)
			{
				level(3,13,2);
				delay(100);
				two(11,5);
				delay(100);
				compltd(9,6,3);
				delay(100);
				textbackground(3);
				clrscr();
				screen();
				gotoxy(75,4);
				printf("%d",b);
				row=20;
				col=60;
				level_3();
				lvl++;
				getch();
			}
		}
		if(b>=40)
		{
			nosound();
			if(lvl==3)
			{
				level(5,4,1);
				delay(100);
				three(12,6);
				delay(100);
				compltd(1,4,5);
				delay(100);
				textbackground(5);
				clrscr();
				screen();
				gotoxy(75,4);
				printf("%d",b);
				row=20;
				col=50;
				level_4();
				lvl++;
				getch();
			}
		}
		if(b>=60)
		{
			nosound();
			if(lvl==4)
			{
				level(2,11,5);
				delay(100);
				four(9,3);
				delay(100);
				compltd(10,1,2);
				delay(100);
				lvl++;
				getch();
			}
		}
		if(lvl>4)
		{
			congo();
			delay(2000);
			thnx();
			delay(3000);
			database();
			break;
		}
		gotoxy(75,6);
		printf("%d",lvl);
		if(lvl==1)
		{
			screen();
			level_1();
			gotoxy(75,4);
			printf("%d",b);
			gotoxy(75,6);
			printf("%d",lvl);
			if(hurdle_1()==1)
				ch='o';
		}
		if(lvl==2)
		{
			if(hurdle_2()==1)
				ch='o';
		}
		if(lvl==3)
		{
			if(hurdle_3()==1)
			ch='o';
		}
		if(lvl==4)
		{
			if(hurdle_4()==1)
				ch='o';
		}
		move();
		gotoxy(x,y);
		printf("%d",n);
		if(count==1)
		{
			gotoxy(x,y);
			printf(" ");
			n=random(9)+1;
			x=random(62)+2;
			y=random(19)+2;
			count=50;
		}
		if(x==col&&y==row)
		{
			sound(450);
			delay(100);
			nosound();
			gotoxy(76,4);
			printf(" ");
			b=b+n;
			gotoxy(75,4);
			printf("%d",b);
			n=random(9)+1;
			x=random(62)+2;
			y=random(19)+2;
			count=50;
		}
		delay(100);
	}while(ch!='o');
	nosound();
}
int level_1()
{
	for(i=8;i<18;i++)
	{
		gotoxy(21,i);
		printf("%c",2);
	}
	for(i=8;i<18;i++)
	{
		gotoxy(42,i);
		printf("%c",2);
	}
	return 0;
}
int hurdle_1()
{
	if((col==21)&&(row>=8&&row<=17))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((col==42)&&(row>=8&&row<=17))
	{
	q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((x==21)&&(y>=8&&y<=17))
	{
		x++;
	}
	if((x==42)&&(y>=8&&y<=17))
	{
		x++;
	}
	return 0;
}
int level_2()
{
	for(i=24;i<=40;i++)
	{
		gotoxy(i,9);
		printf("%c",36);
		i++;
	}
	for(i=24;i<=40;i++)
	{
		gotoxy(i,17);
		printf("%c",36);
		i++;
	}
	for(i=11;i<=15;i++)
	{
		gotoxy(22,i);
		printf("%c",36);
	}
	for(i=11;i<=15;i++)
	{
		gotoxy(42,i);
		printf("%c",36);
	}
	return 0;
}
int hurdle_2()
{
	if((row==9)&&(col>=24&&col<=40))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((row==17)&&(col>=24&&col<=40))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((col==42)&&(row>=11&&row<=15))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((col==22)&&(row>=11&&row<=15))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((x==22)&&(y>=11&&y<=15))
	{
		x++;
	}
	if((x==42)&&(y>=11&&y<=15))
	{
		x--;
	}
	if((y==9)&&(x>=24&&x<=40))
	{
		y++;
	}
	if((y==17)&&(x>=24&&x<=40))
	{
		y--;
	}
	return 0;
}
int level_3()
{
	for(i=18;i<=49;i++)
	{
		gotoxy(i,6);
		printf("%c",21);
		i++;
	}
	for(i=18;i<=49;i++)
	{
		gotoxy(i,18);
		printf("%c",21);
		i++;
	}
	for(i=9;i<=15;i++)
	{
		gotoxy(19,i);
		printf("%c",21);
	}
	for(i=9;i<=15;i++)
	{
		gotoxy(47,i);
		printf("%c",21);
	}
	for(i=21;i<=27;i++)
	{
		gotoxy(i,12);
		printf("%c",21);
		i++;
	}
	for(i=45;i>=39;i--)
	{
		gotoxy(i,12);
		printf("%c",21);
		i--;
	}
	return 0;
}
int hurdle_3()
{
	if((row==6)&&(col>=18&&col<=49))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((row==18)&&(col>=18&&col<=49))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((col==19)&&(row>=9&&row<=15))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((col==47)&&(row>=9&&row<=15))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((row==12)&&(col>=39&&col<=45))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((row==12)&&(col>=21&&col<=27))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((y==6)&&(x>=18&&x<=49))
	{
		y++;
	}
	if((y==18)&&(x>=18&&x<=49))
	{
		y++;
	}
	if((x==19)&&(y>=9&&y<=15))
	{
		x--;
	}
	if((x==47)&&(y>=9&&y<=15))
	{
		x++;
	}
	if((y==12)&&(x>=39&&x<=45))
	{
		y--;
	}
	if((y==12)&&(x>=21&&x<=27))
	{
		y++;
	}
	return 0;
}
int level_4()
{
	for(i=2;i<=14;i++)
	{
		gotoxy(i,2);
		printf("%c",1);
		i++;
	}
	for(i=2;i<=14;i++)
	{
		gotoxy(i,21);
		printf("%c",1);
		i++;
	}
	for(i=52;i<=64;i++)
	{
		gotoxy(i,2);
		printf("%c",1);
		i++;
	}
	for(i=52;i<=64;i++)
	{
		gotoxy(i,21);
		printf("%c",1);
		i++;
	}
	for(i=3;i<=8;i++)
	{
		gotoxy(64,i);
		printf("%c",1);
	}
	for(i=15;i<=21;i++)
	{
		gotoxy(2,i);
		printf("%c",1);
	}
	for(i=15;i<=21;i++)
	{
		gotoxy(64,i);
		printf("%c",1);
	}
	for(i=3;i<=8;i++)
	{
		gotoxy(2,i);
		printf("%c",1);
	}
	for(i=18;i<=48;i++)
	{
		gotoxy(i,6);
		printf("%c",15);
		i++;
	}
	for(i=18;i<=48;i++)
	{
		gotoxy(i,16);
		printf("%c",15);
		i++;
	}
	for(i=9;i<=13;i++)
	{
		gotoxy(19,i);
		printf("%c",15);
	}
	for(i=9;i<=13;i++)
	{
		gotoxy(48,i);
		printf("%c",15);
	}
	for(i=21;i<=27;i++)
	{
		gotoxy(i,11);
		printf("%c",15);
		i++;
	}
	for(i=46;i>=40;i--)
	{
		gotoxy(i,11);
		printf("%c",15);
		i--;
	}
	return 0;
}
int hurdle_4()
{
	if((row==2)&&(col>=2&&col<=14))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((row==21)&&(col>=2&&col<=14))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((row==21)&&(col>=52&&col<=64))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((row==2)&&(col>=52&&row<=64))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((col==2)&&(row>=3&&row<=8))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((col==64)&&(row>=3&&row<=8))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((col==2)&&(row>=15&&row<=21))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((col==64)&&(row>=15&&row<=21))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((row==6)&&(col>=18&&col<=48))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((row==16)&&(col>=18&&col<=48))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((col==19)&&(row>=9&&row<=13))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((col==48)&&(row>=9&&row<=13))
	{	q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((row==11)&&(col>=40&&col<=46))
	{
		q=lost();
		if(q==1)
		{
			lvl;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((row==11)&&(col>=21&&col<=28))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}/*
	if((row==9)&&(col>=30&&col<=37))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}
	if((row==15)&&(col>=30&&col<=37))
	{
		q=lost();
		if(q==1)
		{
			lvl=1;
			b=0;
			col=60;
			row=20;
			return 0;
		}
		if(q==0)
		{
			return 1;
		}
	}*/
	if((y==2)&&(x>=2&&x<=14))
	{
		y++;
	}
	if((y==21)&&(x>=2&&x<=14))
	{
		y--;
	}
	if((y==21)&&(x>=52&&x<=64))
	{
		y--;
	}
	if((y==2)&&(x>=52&&x<=64))
	{
		y++;
	}
	if((x==2)&&(y>=3&&y<=8))
	{
		x++;
	}
	if((x==64)&&(y>=3&&y<=8))
	{
		x--;
	}
	if((x==2)&&(y>=15&&y<=21))
	{
		x++;
	}
	if((x==64)&&(y>=15&&y<=21))
	{
		x--;
	}
	if((y==6)&&(x>=18&&x<=49))
	{
		y--;
	}
	if((y==16)&&(x>=18&&x<=49))
	{
		y++;
	}
	if((x==19)&&(y>=9&&y<=13))
	{
		x--;
	}
	if((x==48)&&(y>=9&&y<=13))
	{
		x++;
	}
	if((y==11)&&(x>=40&&x<=46))
	{
		y--;
	}
	if((y==11)&&(x>=21&&x<=28))
	{
		y++;
	}/*
	if((y==9)&&(x>=30&&x<=37))
	{
		y++;
	}
	if((y==15)&&(x>=30&&x<=37))
	{
		y--;
	}*/
	return 0;
}
int level(int x,int y,int z)
{
    textbackground(x);
    clrscr();


       //for L

    textcolor(y+BLINK);
    textbackground(z);
    for(i=4;i<=8;i++)
    {
		gotoxy(13,i);
		cprintf("Û");
		gotoxy(14,i);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=15;i<=18;i++)
	{
		gotoxy(i,8);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}


		// for E


	for(i=4;i<=8;i++)
	{
		gotoxy(21,i);
		cprintf("Û");
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=22;i<=26;i++)
	{
		gotoxy(i,4);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=22;i<=25;i++)
	{
		gotoxy(i,6);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=22;i<=26;i++)
	{
		gotoxy(i,8);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}


		//for V


    for(i=4;i<=6;i++)
    {
	gotoxy(29,i);
	cprintf("Û");
	cprintf("Û");
	//sound(octave[random(7)]*4);
		//delay(30);
    }
	gotoxy(30,7);
	cprintf("Û");
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	for(i=31;i<=33;i++)
	{
	    gotoxy(i,8);
	    cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	gotoxy(33,7);
	cprintf("Û");
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	for(i=6;i>=4;i--)
    {
	gotoxy(34,i);
	cprintf("Û");
	cprintf("Û");
	//sound(octave[random(7)]*4);
		//delay(30);
    }

    //for E


	for(i=4;i<=8;i++)
	{
		k=random(200);
		gotoxy(38,i);
		cprintf("Û");
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=38;i<=43;i++)
	{
		gotoxy(i,4);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=38;i<=42;i++)
	{
		gotoxy(i,6);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=38;i<=43;i++)
	{
		gotoxy(i,8);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}


		//for L


	for(i=4;i<=8;i++)
	{
		gotoxy(46,i);
		cprintf("Û");
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=48;i<=51;i++)
	{
		gotoxy(i,8);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	nosound();
	return 0;
}
int one(int x,int y)
{


		//for 1


    textcolor(x+BLINK);
    textbackground(y);
    gotoxy(62,5);
    cprintf("Û");
	//sound(octave[random(7)]*4);
    //delay(30);
    gotoxy(63,4);
    cprintf("Û");
	//sound(octave[random(7)]*4);
    //delay(30);
    for(i=3;i<=8;i++)
    {
	gotoxy(64,i);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
    }
    gotoxy(61,8);
    cprintf("Û");
	//sound(octave[random(7)]*4);
    //delay(30);
    cprintf("Û");
	//sound(octave[random(7)]*4);
    //delay(30);
    cprintf("Û");
	//sound(octave[random(7)]*4);
    //delay(30);
    cprintf("Û");
	//sound(octave[random(7)]*4);
    //delay(30);
    cprintf("Û");
//sound(octave[random(7)]*4);
    //delay(30);
    cprintf("Û");
	//sound(octave[random(7)]*4);
    //delay(30);
    cprintf("Û");
	//sound(octave[random(7)]*4);
    //delay(30);
    nosound();
    return 0;
}
int two(int x,int y)
{


		//for 2


	textcolor(x+BLINK);
	textbackground(y);
	    for(i=61;i<=65;i++)
    {
        gotoxy(i,4);
	cprintf("Û");
		//sound(octave[random(7)]*4);
        //delay(30);
    }
    for(i=4;i<=5;i++)
    {
    gotoxy(65,i);
    cprintf("Û");
	//sound(octave[random(7)]*4);
    //delay(30);
    }
    for(i=65;i>=61;i--)
    {
	gotoxy(i,6);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
    }
    gotoxy(61,7);
    cprintf("Û");
	//sound(octave[random(7)]*4);
    //delay(30);
    for(i=61;i<=65;i++)
    {
	gotoxy(i,8);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
    }
    return 0;
}
int three(int x,int y)
{


		//for 3


	textcolor(x+BLINK);
	textbackground(y);
		gotoxy(61,5);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(61,4);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(65,5);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(65,6);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(64,6);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(65,6);
	//sound(octave[random(7)]*4);
	cprintf("Û");
	//delay(30);
	gotoxy(65,7);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(65,8);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(64,8);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(63,8);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(62,8);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(61,8);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(61,7);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	return 0;
}
int four(int x,int y)
{


		//for 4


	textcolor(x+BLINK);
	textbackground(y);
	gotoxy(66,7);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(65,7);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(64,7);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(63,7);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(62,7);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(61,7);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(62,6);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(63,5);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(64,4);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(65,4);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(65,5);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(65,6);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(65,7);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(65,8);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	return 0;
}
int compltd(int x,int y,int z)
{


		//for C



	textcolor(x+BLINK);
	textbackground(y);
	for(i=11;i>=6;i--)
	{
		gotoxy(i,11);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=11;i<=15;i++)
	{
		gotoxy(6,i);
		cprintf("Û");
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}

	for(i=6;i<=11;i++)
	{
		gotoxy(i,15);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}


		//for O


	for(i=13;i<=18;i++)
	{
		gotoxy(i,11);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=11;i<=15;i++)
	{
		gotoxy(18,i);
		//sound(octave[random(7)]*4);
		cprintf("Û");
		//delay(30);
	}
	for(i=18;i>=13;i--)
	{
		gotoxy(i,15);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=15;i>=11;i--)
	{
		gotoxy(13,i);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}


		//for M


	for(i=15;i>=11;i--)
	{
		gotoxy(20,i);
		cprintf("Û");
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	gotoxy(22,11);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(23,11);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(23,12);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(24,12);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	for(i=24;i<=26;i++)
	{
		gotoxy(i,13);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	gotoxy(26,12);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	gotoxy(27,12);
	cprintf("Û");
	//sound(octave[random(7)]*4);
	//delay(30);
	for(i=27;i<=30;i++)
	{
		gotoxy(i,11);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=11;i<=15;i++)
	{
		k=random(160);
		gotoxy(29,i);
		cprintf("Û");
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}


	       //	for P


	for(i=15;i>=11;i--)
	{
		gotoxy(32,i);
		cprintf("Û");
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=32;i<=37;i++)
	{
		gotoxy(i,11);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=36;i<38;i++)
	{
		gotoxy(i,12);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(10);
	}
	for(i=37;i>=32;i--)
	{
		gotoxy(i,13);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}


	       //for L


	for(i=11;i<=15;i++)
	{
		k=random(170);
		gotoxy(39,i);
		cprintf("Û");
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=39;i<=44;i++)
	{
		gotoxy(i,15);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}


	       //for E


	for(i=11;i<=15;i++)
	{
		gotoxy(46,i);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=46;i<=51;i++)
	{
		gotoxy(i,11);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=46;i<=50;i++)
	{
		gotoxy(i,13);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=46;i<=51;i++)
	{
		gotoxy(i,15);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}


		//for T


	for(i=53;i<=60;i++)
	{
		gotoxy(i,11);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=11;i<=15;i++)
	{
		gotoxy(56,i);
		cprintf("Û");
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}


		//for E


	for(i=11;i<=15;i++)
	{
		gotoxy(62,i);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=62;i<=67;i++)
	{
		gotoxy(i,11);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=62;i<=66;i++)
	{
		gotoxy(i,13);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=62;i<=67;i++)
	{
		gotoxy(i,15);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}


		//for D


	for(i=15;i>=11;i--)
	{
		gotoxy(69,i);
		cprintf("Û");
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=70;i<=74;i++)
	{
		gotoxy(i,11);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=12;i<15;i++)
	{
		gotoxy(74,i);
		cprintf("Û");
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=74;i>=70;i--)
	{
		gotoxy(i,15);
		cprintf("Û");
		//sound(octave[random(7)]*4);
		//delay(30);
	}
	for(i=27;i<=60;i++)
	{
		gotoxy(i,24);
		textbackground(z);
		cprintf(" ");
	}
	while(1)
    {
    sound(octave[random(7)]*4);
	delay(100);
    textcolor(14+128);
	gotoxy(27,24);
	cprintf("PRESS ANY KEY TO CONTINUE");
	if(kbhit())
    {
       nosound();
       break;
    }
    }
	getch();
	textcolor(15);
	delay(100);
	return 0;
}
int lost()
{
	clrscr();
	textbackground(5);
	clrscr();


	//for G

	
	textcolor(1+BLINK);
	textbackground(4);
	for(i=12;i>=6;i--)
	{
		gotoxy(i,4);
		cprintf("Û");
		//delay(20);
	}
	for(i=4;i<=9;i++)
    {
	gotoxy(6,i);
	cprintf("Û");
        cprintf("Û");
        //delay(20);
    }
	for(i=6;i<=12;i++)
	{
		gotoxy(i,9);
		cprintf("Û");
		//delay(20);
	}
	for(i=12;i>=9;i--)
    {
        gotoxy(i,7);
	cprintf("Û");
        //delay(20);
    }
	gotoxy(11,8);
	cprintf("Û");
    cprintf("Û");
	//delay(20);


	//for A


	for(i=9;i>=4;i--)
    {
        gotoxy(15,i);
        cprintf("Û");
        cprintf("Û");
      //  delay(20);
    }
    for(i=16;i<=20;i++)
    {
        gotoxy(i,4);
        cprintf("Û");
        //delay(20);
    }
    for(i=4;i<=9;i++)
    {
        gotoxy(20,i);
        cprintf("Û");
        cprintf("Û");
        //delay(20);
    }
    for(i=16;i<=20;i++)
    {
        gotoxy(i,7);
        cprintf("Û");
    //    delay(20);
    }


		//for M


	//sound(117+random(529));
	for(i=9;i>=4;i--)
	{
		gotoxy(24,i);
		cprintf("Û");
		//delay(20);
		cprintf("Û");
		//delay(20);
	}
	//sound(116+random(587));
	for(i=25;i<=27;i++)
	{
		gotoxy(i,4);
		cprintf("Û");
		//delay(20);
	}
	//sound(125+random(573));
	for(i=27;i<=28;i++)
	{
		gotoxy(i,5);
		cprintf("Û");
		//delay(20);
	}
	for(i=28;i<=30;i++)
	{
		gotoxy(i,6);
		cprintf("Û");
		//delay(20);
	}
	for(i=30;i<=31;i++)
	{
		//sound(126+random(640));
		gotoxy(i,5);
		cprintf("Û");
		//delay(20);
	}
	for(i=31;i<=34;i++)
	{
		gotoxy(i,4);
		cprintf("Û");
		//delay(20);
	}
	for(i=4;i<=9;i++)
	{
		k=random(128);
		//sound(k+random(520));
		gotoxy(33,i);
		cprintf("Û");
		//delay(20);
		cprintf("Û");
		//delay(20);
	}


		//for E


	for(i=4;i<=9;i++)
	{
		k=random(125);
		//sound(k+random(600));
		gotoxy(37,i);
		cprintf("Û");
	cprintf("Û");
		//delay(20);
	}
	for(i=38;i<=42;i++)
	{
		gotoxy(i,4);
		cprintf("Û");
		//delay(20);
	}
	for(i=38;i<=41;i++)
	{
		gotoxy(i,6);
		cprintf("Û");
		//delay(20);
	}
	for(i=38;i<=42;i++)
	{
		gotoxy(i,9);
		cprintf("Û");
		//delay(20);
	}


		//for O


	//sound(122+random(600));
	gotoxy(45,11);
	cprintf("Û");
	//delay(30);
	cprintf("Û");
	//delay(30);
	//sound(111+random(600));
	cprintf("Û");
	//delay(30);
	cprintf("Û");
	//delay(30);
	cprintf("Û");
	//delay(30);
	for(i=11;i<=16;i++)
	{
		k=random(115);
		//sound(k+random(600));
		gotoxy(50,i);
		cprintf("Û");
		cprintf("Û");
		//delay(30);
	}
	gotoxy(49,16);
	//sound(118+random(600));
	cprintf("Û");
	//delay(30);
	gotoxy(48,16);
	cprintf("Û");
	//delay(30);
	//sound(114+random(600));
	gotoxy(47,16);
	cprintf("Û");
	//delay(30);
	gotoxy(46,16);
	cprintf("Û");
	//delay(30);
	gotoxy(45,16);
	cprintf("Û");
	//delay(30);
	for(i=16;i>=11;i--)
	{
		k=random(110);
		//sound(k+random(600));
		gotoxy(45,i);
		cprintf("Û");
	cprintf("Û");
		//delay(30);
	}


		//for V


	for(i=11;i<=14;i++)
	{
        gotoxy(54,i);
        cprintf("Û");
	cprintf("Û");
        //delay(30);
	}
	gotoxy(55,15);
	cprintf("Û");
	cprintf("Û");
	//delay(30);
	gotoxy(56,16);
	cprintf("Û");
	cprintf("Û");
	cprintf("Û");
    //delay(30);
    gotoxy(58,15);
    cprintf("Û");
    cprintf("Û");
    //delay(30);
    for(i=14;i>=11;i--)
    {
        gotoxy(59,i);
	cprintf("Û");
        cprintf("Û");
        //delay(30);
    }


	//for E


	for(i=11;i<=16;i++)
	{
		k=random(120);
		gotoxy(63,i);
		cprintf("Û");
		cprintf("Û");
		//delay(30);
	}
	gotoxy(64,11);
	cprintf("Û");
	//delay(30);
	cprintf("Û");
	//delay(30);
	//sound(124+random(600));
	cprintf("Û");
	//delay(30);
	cprintf("Û");
	//delay(30);
	cprintf("Û");
	//delay(30);
	//sound(128+random(600));
	gotoxy(64,13);
	cprintf("Û");
	//delay(30);
	cprintf("Û");
	//delay(30);
	cprintf("Û");
	//delay(30);
	//sound(130+random(600));
	cprintf("Û");
	//delay(30);
	gotoxy(64,16);
	cprintf("Û");
	//delay(30);
	cprintf("Û");
	//delay(30);
	//sound(132+random(600));
	cprintf("Û");
	//delay(30);
	cprintf("Û");
	//delay(30);
	cprintf("Û");
	//delay(30);


	//for R


	for(i=16;i>=11;i--)
	{
		k=random(130);
		gotoxy(71,i);
		//sound(k+random(600));
        cprintf("Û");
        cprintf("Û");
		//delay(30);
	}
	gotoxy(73,11);
	cprintf("Û");
	//delay(30);
	cprintf("Û");
	//sound(121+random(600));
	//delay(30);
	cprintf("Û");
	//delay(30);
	cprintf("Û");
	//delay(30);
	cprintf("Û");
	//delay(30);
	gotoxy(76,12);
	cprintf("Û");
	//sound(125+random(600));
	//delay(30);
	cprintf("Û");
	//delay(30);
	gotoxy(77,13);
	cprintf("Û");
	//delay(30);
	gotoxy(76,13);
	cprintf("Û");
	//delay(30);
	gotoxy(75,13);
	cprintf("Û");
	//sound(120+random(600));
	//delay(30);
	gotoxy(74,13);
	cprintf("Û");
	//delay(30);
	gotoxy(73,13);
	cprintf("Û");
	//delay(30);
	gotoxy(73,14);
	cprintf("Û");
	//sound(131+random(600));
	//delay(30);
	cprintf("Û");
	//delay(30);
	gotoxy(74,15);
	cprintf("Û");
	//delay(30);
	cprintf("Û");
	//sound(129+random(600));
	//delay(30);
	gotoxy(75,16);
	cprintf("Û");
	//delay(30);
	cprintf("Û");
	//delay(30);
	cprintf("Û");
	//delay(30);
	sound(octave[6]*3);
    delay(400);
    sound(octave[5]*3);
    delay(400);
    sound(octave[2]*3);
    delay(400);
    sound(octave[1]*2);
    delay(500);
    sound(octave[0]*1);
    delay(600);
    sound(octave[0]);
    getch();
    nosound();
	textbackground(5);
	textcolor(3+BLINK);
	gotoxy(35,18);
	cprintf("TRY AGAIN....?");
	textcolor(10);
	gotoxy(42,20);
	cprintf("Y");
	textcolor(10);
	gotoxy(42,22);
	cprintf("N");
	do
	{
		w=getch();
		switch(tolower(w))
		{
		case 'y':
			b=0;
			k=1;
			textbackground(6);
			clrscr();
			gotoxy(75,4);
			printf("%d",b);
			return 1;
		case 'n':
			k=1;
			clrscr();
			thnx();
			delay(3000);
			return 0;
		default:
			k=0;
		}
	}while(k!=1);
}
void screen()
{
	textcolor(15);
	gotoxy(1,1);
	printf("%c",201);
	gotoxy(80,1);
	printf("%c",187);
	for(i=2;i<65;i++)
	{
		gotoxy(i,1);
		printf("%c",205);
	}
	gotoxy(65,1);
	printf("%c",203);
	for(i=66;i<=79;i++)
	{
		gotoxy(i,1);
		printf("%c",205);
	}
	for(i=2;i<=23;i++)
	{
		gotoxy(1,i);
		printf("%c",186);
	}
	gotoxy(1,24);
	printf("%c",200);
	for(i=2;i<65;i++)
	{
		gotoxy(i,24);
		printf("%c",205);
	}
	gotoxy(65,24);
	printf("%c",202);
	for(i=2;i<10;i++)
	{
		gotoxy(65,i);
		printf("%c",186);
	}
	for(i=11;i<=23;i++)
	{
		gotoxy(65,i);
		printf("%c",186);
	}
	gotoxy(80,10);
	printf("%c",185);
	for(i=66;i<=79;i++)
	{
		gotoxy(i,24);
		printf("%c",205);
	}
	for(i=2;i<10;i++)
		{
		gotoxy(80,i);
		printf("%c",186);

	}
	for(i=11;i<=23;i++)
	{
		gotoxy(80,i);
		printf("%c",186);
	}
	for(i=66;i<=79;i++)
	{
		gotoxy(i,10);
		printf("%c",205);
	}
	gotoxy(1,22);
	printf("Ì");
	for(i=2;i<=64;i++)
	{
		gotoxy(i,22);
		printf("Í");
	}
	gotoxy(22,64);
	printf("¹");
	gotoxy(25,23);
	cprintf(" PRESS 'o' TO EXIT ");
	gotoxy(80,24);
	printf("%c",188);
	gotoxy(68,4);
	printf("Score: ");
	gotoxy(68,6);
	printf("Level: ");
	gotoxy(73,12);
	printf("%c",30);
	gotoxy(73,16);
	printf("%c",31);
	gotoxy(69,14);
	printf("%c",17);
	gotoxy(77,14);
	printf("%c",16);
	gotoxy(65,10);
	printf("%c",204);
}
void move()
{
	sound(octave[random(7)]*4);
	if(kbhit())
		{
			ch=getch();
		}
		gotoxy(75,8);
		printf(" ");
		gotoxy(col,row);
		printf(" ");
		switch(tolower(ch))
		{
		case 'w':
			if(row==2)
			       row=22;
			f=1;
			row--;
			break;
		case 's':
			if(row==21)
				row=1;
			f=2;
			row++;
			break;
		case 'a':
			if(col==2)
				col=65;
			col--;
			break;
		case 'd':
			if(col==63)
				  col=1;
			col++;
			break;
		case 'o':
			break;
		default:
			if(f==1)
			{
				if(row==2)
				       row=23;
				row--;
			}
			if(f==2)
			{
				if(row==21)
				       row=1;
				row++;
			}
			if(f==3)
			{
				if(col==2)
				       row=65;
				col--;
			}
			if(f==4)
			{
				if(row==63)
				       row=1;
				col++;
			}
		}
		count--;
		gotoxy(68,8);
		printf("Time: %d",count);
		gotoxy(col,row);
		printf("%c",178);
}
void layout()
{
	textbackground(BLACK);
	clrscr();
	bckgrnd(4);
	textbackground(BLACK);
	for(i=1;i<=80;i++)
	{
		gotoxy(i,1);
		cprintf(" ");
	}
	textcolor(WHITE);
	gotoxy(1,1);
	cprintf("É");
	gotoxy(80,1);
	cprintf("»");
	for(i=2;i<=79;i++)
	{
		gotoxy(i,1);
		cprintf("Í");
	}
	for(i=2;i<=23;i++)
	{
		gotoxy(1,i);
		cprintf("º");
		gotoxy(80,i);
		cprintf("º");
		delay(20);
	}
	for(i=2;i<=79;i++)
	{
		gotoxy(i,24);
		cprintf("Í");
	}
	gotoxy(1,24);
	cprintf("È");
	gotoxy(80,24);
	cprintf("¼");
	textcolor(BLACK);
	for(i=71;i>=9;i--)
	{
		for(j=6;j>=2;j--)
		{
			gotoxy(i,j);
			cprintf(" ");
		}
		sound(octave[random(7)]*4);
		delay(10);
		nosound();
	}
	textcolor(LIGHTBLUE+BLINK);
	textbackground(CYAN);

	//for W
	sound(octave[0]*8);
	for(i=2;i<=6;i++)
	{
		gotoxy(8,i);
		cprintf("Û");
		cprintf("Û");
	}
	for(i=9;i<=11;i++)
	{
		gotoxy(i,6);
		cprintf("Û");
		delay(25);
	}
	for(i=11;i<=12;i++)
	{
		gotoxy(i,5);
		cprintf("Û");
		delay(25);
	}
	for(i=12;i<=13;i++)
	{
		gotoxy(i,4);
		cprintf("Û");
		delay(25);
	}
	for(i=13;i<=14;i++)
	{
		gotoxy(i,5);
		cprintf("Û");
		delay(25);
	}
	for(i=14;i<=16;i++)
	{
		gotoxy(i,6);
		cprintf("Û");
		delay(25);
	}
	for(i=6;i>=2;i--)
	{
		gotoxy(16,i);
		cprintf("Û");
		cprintf("Û");
		delay(20);
	}
	sound(octave[1]*8);

	//for E

	for(i=2;i<=6;i++)
	{
		gotoxy(20,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}
	for(i=22;i<=26;i++)
	{
		gotoxy(i,2);
		cprintf("Û");
		delay(25);
	}
	for(i=22;i<=25;i++)
	{
		gotoxy(i,4);
		cprintf("Û");
		delay(25);
	}
	for(i=22;i<=26;i++)
	{
		gotoxy(i,6);
		cprintf("Û");
		delay(20);
	}
	sound(octave[2]*8);
	//for L

	for(i=2;i<=6;i++)
	{
		gotoxy(29,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}
	for(i=30;i<=34;i++)
	{
		gotoxy(i,6);
		cprintf("Û");
		delay(25);
	}
	sound(octave[3]*8);
	//for C

	for(i=42;i>=37;i--)
	{
		gotoxy(i,2);
		cprintf("Û");
		delay(25);
	}
	for(i=2;i<=6;i++)
	{
		gotoxy(37,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}
	for(i=37;i<=42;i++)
	{
		gotoxy(i,6);
		cprintf("Û");
		delay(25);
	}
	sound(octave[4]*8);

	//for O

	for(i=50;i>=45;i--)
	{
		gotoxy(i,2);
		cprintf("Û");
		delay(25);
	}
	for(i=2;i<=6;i++)
	{
		gotoxy(45,i);
		cprintf("Û");
		delay(25);
	}
	for(i=45;i<=50;i++)
	{
		gotoxy(i,6);
		cprintf("Û");
		delay(25);
	}
	for(i=6;i>=2;i--)
	{
		gotoxy(50,i);
		cprintf("Û");
		delay(25);
	}
	sound(octave[5]*8);

	//for M

	for(i=6;i>=2;i--)
	{
		gotoxy(53,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}
	for(i=55;i<=56;i++)
	{
		gotoxy(i,2);
		cprintf("Û");
		delay(25);
	}
	for(i=56;i<=57;i++)
	{
		gotoxy(i,3);
		cprintf("Û");
		delay(25);
	}
	for(i=57;i<=59;i++)
	{
		gotoxy(i,4);
		cprintf("Û");
		delay(25);
	}
	for(i=59;i<=60;i++)
	{
		gotoxy(i,3);
		cprintf("Û");
		delay(25);
	}
	for(i=60;i<=63;i++)
	{
		gotoxy(i,2);
		cprintf("Û");
		delay(25);
	}
	for(i=2;i<=6;i++)
	{
		gotoxy(62,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}
	sound(octave[6]*8);

	//for E

	for(i=2;i<=6;i++)
	{
		gotoxy(66,i);
		cprintf("Û");
		delay(25);
	}
	for(i=66;i<=71;i++)
	{
		gotoxy(i,2);
		cprintf("Û");
		delay(25);
	}
	for(i=66;i<=70;i++)
	{
		gotoxy(i,4);
		cprintf("Û");
		delay(25);
	}
	for(i=66;i<=71;i++)
	{
		gotoxy(i,6);
		cprintf("Û");
		delay(25);
	}
	nosound();
	textbackground(BLACK);
	for(i=47;i>=30;i--)
	{
		for(j=13;j>=9;j--)
		{
			gotoxy(i,j);
			cprintf(" ");
		}
		sound(octave[random(7)]*4);
		delay(10);
		nosound();
	}
	sound(octave[6]*4);
	textbackground(CYAN);
	for(i=30;i<=37;i++)
	{
		gotoxy(i,9);
		cprintf("Û");
		delay(25);
	}
	for(i=9;i<=13;i++)
	{
		gotoxy(33,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}
	sound(octave[0]*4);

	//for O

	for(i=47;i>=42;i--)
	{
		gotoxy(i,9);
		cprintf("Û");
		delay(25);
	}
	for(i=9;i<=13;i++)
	{
		gotoxy(42,i);
		cprintf("Û");
		delay(25);
	}
	for(i=42;i<=47;i++)
	{
		gotoxy(i,13);
		cprintf("Û");
		delay(25);
	}
	for(i=13;i>=9;i--)
	{
		gotoxy(47,i);
		cprintf("Û");
		delay(25);
	}
	nosound();
	textbackground(BLACK);
	for(i=77;i>=9;i--)
	{
		for(j=20;j>=16;j--)
		{
			gotoxy(i,j);
			cprintf(" ");
		}
		sound(octave[random(7)]*4);
		delay(10);
		nosound();
	}
	sound(octave[random(7)]*4);
	textbackground(CYAN);

	//for N

	for(i=20;i>=16;i--)
	{
		gotoxy(9,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}
	for(i=10;i<=11;i++)
	{
		gotoxy(i,16);
		cprintf("Û");
		delay(25);
	}
	for(i=11;i<=12;i++)
	{
		gotoxy(i,17);
		cprintf("Û");
		delay(25);
	}
	for(i=12;i<=13;i++)
	{
		gotoxy(i,18);
		cprintf("Û");
		delay(25);
	}
	for(i=13;i<=14;i++)
	{
		gotoxy(i,19);
		cprintf("Û");
		delay(25);
	}
	gotoxy(14,20);
	cprintf("Û");
	delay(25);
	for(i=20;i>=16;i--)
	{
		gotoxy(15,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}

	//for U

	sound(octave[random(7)]*4);
	for(i=16;i<=20;i++)
	{
		gotoxy(18,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}
	for(i=18;i<=23;i++)
	{
		gotoxy(i,20);
		cprintf("Û");
		delay(25);
	}
	for(i=20;i>=16;i--)
	{
		gotoxy(23,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}

	//for M

	sound(octave[random(7)]*4);
	for(i=20;i>=16;i--)
	{
		gotoxy(26,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}
	for(i=28;i<=29;i++)
	{
		gotoxy(i,16);
		cprintf("Û");
		delay(25);
	}
	for(i=29;i<=30;i++)
	{
		gotoxy(i,17);
		cprintf("Û");
		delay(25);
	}
	for(i=30;i<=32;i++)
	{
		gotoxy(i,18);
		cprintf("Û");
		delay(25);
	}
	for(i=32;i<=33;i++)
	{
		gotoxy(i,17);
		cprintf("Û");
		delay(25);
	}
	for(i=33;i<=35;i++)
	{
		gotoxy(i,16);
		cprintf("Û");
		delay(25);
	}
	for(i=16;i<=20;i++)
	{
		gotoxy(35,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}

	//for H

	sound(octave[random(7)]*4);
	for(i=16;i<=20;i++)
	{
		gotoxy(45,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}
	for(i=16;i<=20;i++)
	{
		gotoxy(50,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}
	for(i=46;i<=50;i++)
	{
		gotoxy(i,18);
		cprintf("Û");
		delay(25);
	}

	//for U

	sound(octave[random(7)]*4);
	for(i=16;i<=20;i++)
	{
		gotoxy(53,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}
	for(i=55;i<=58;i++)
	{
		gotoxy(i,20);
		cprintf("Û");
		delay(25);
	}
	for(i=20;i>=16;i--)
	{
		gotoxy(58,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}

	//for N

	sound(octave[random(7)]*4);
	for(i=20;i>=16;i--)
	{
		gotoxy(61,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}
	for(i=62;i<=63;i++)
	{
		gotoxy(i,16);
		cprintf("Û");
		delay(25);
	}
	for(i=63;i<=64;i++)
	{
		gotoxy(i,17);
		cprintf("Û");
		delay(25);
	}
	for(i=64;i<=65;i++)
	{
		gotoxy(i,18);
		cprintf("Û");
		delay(25);
	}
	for(i=65;i<=66;i++)
	{
		gotoxy(i,19);
		cprintf("Û");
		delay(25);
	}
	gotoxy(66,20);
	cprintf("Û");
	delay(25);
	for(i=20;i>=16;i--)
	{
		gotoxy(67,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}

	//for T

	sound(octave[random(7)]*4);
	for(i=70;i<=77;i++)
	{
		gotoxy(i,16);
		cprintf("Û");
		delay(25);
	}
	for(i=16;i<=20;i++)
	{
		gotoxy(73,i);
		cprintf("Û");
		cprintf("Û");
		delay(25);
	}
	gotoxy(1,22);
	printf("Ì");
	for(i=79;i>=2;i--)
	{
		gotoxy(i,22);
		printf("Í");
		sound(octave[random(7)]*5);
		delay(20);
		nosound();
	}
	gotoxy(80,22);
	printf("¹");
	while(1)
    {
    sound(octave[random(7)]*4);
	delay(100);
    textbackground(BLACK);
	textcolor(YELLOW+BLINK);
	gotoxy(30,23);
	cprintf("PRESS ANY KEY TO CONTINUE");
	if(kbhit())
    {
       nosound();
       break;
    }
    }
	getch();
}      
void entername()
{
	textbackground(BLACK);
	clrscr();
	textcolor(WHITE);
	bckgrnd(5);
	textbackground(BLACK);
	for(i=1;i<=80;i++)
	{
		gotoxy(i,1);
		cprintf(" ");
	}
	textcolor(WHITE);
	for(i=1;i<=23;i++)
	{
		gotoxy(1,i);
		cprintf("%c",4);
	}
	for(i=1;i<=79;i++)
	{
		gotoxy(i,1);
		cprintf("%c",4);
		gotoxy(i,23);
		cprintf("%c",4);
		i++;
		delay(20);
	}
	for(i=1;i<=23;i++)
	{
		gotoxy(79,i);
		cprintf("%c",4);
	}
	textbackground(BLACK);
	for(i=66;i>=19;i--)
	{
		for(j=13;j>=9;j--)
		{
			gotoxy(i,j);
			cprintf(" ");
		}
		sound(octave[random(7)]*4);
		delay(10);
		nosound();
	}
	gotoxy(19,9);
	printf("É");
	for(i=20;i<=65;i++)
	{
		gotoxy(i,9);
		printf("Í");
	}
	gotoxy(66,9);
	printf("»");
	gotoxy(19,13);
	printf("È");
	for(i=20;i<=65;i++)
	{
		gotoxy(i,13);
		printf("Í");
	}
	gotoxy(66,13);
	printf("¼");
	gotoxy(30,10);
	printf("Enter your Name: ");
	fflush(stdin);
	gets(obj2.name);
	strupr(obj2.name);
	gotoxy(25,12);
	cprintf("Welcome to the game Mr./Ms. %s",obj2.name);
	getch();
	textcolor(WHITE);
	for(i=1;i<=80;i++)
	{
		gotoxy(i,21);
		cprintf("%c",4);
		i++;
		delay(30);
	}
		while(1)
    {
    sound(octave[random(7)]*4);
	delay(100);
	textbackground(BLACK);
	textcolor(YELLOW+BLINK);
	gotoxy(30,22);
	cprintf("PRESS ANY KEY TO CONTINUE");
	if(kbhit())
    {
       nosound();
       break;
    }
    }
	getch();
}
void bckgrnd(int x)
{
	textbackground(x);
	for(i=1;i<=13;i++)
	{
		gotoxy(3,i);
		cprintf("Ý");
		delay(2);

	}
	for(i=1;i<=12;i++)
	{
		gotoxy(4,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=11;i++)
	{
		gotoxy(5,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=10;i++)
	{
		gotoxy(6,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=9;i++)
	{
		gotoxy(7,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=8;i++)
	{
		gotoxy(8,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=9;i++)
	{
		gotoxy(9,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=10;i++)
	{
		gotoxy(10,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=11;i++)
	{
		gotoxy(11,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=12;i++)
	{
		gotoxy(12,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=13;i++)
	{
		gotoxy(13,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=18;i++)
	{
		gotoxy(14,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=17;i++)
	{
		gotoxy(15,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=16;i++)
	{
		gotoxy(16,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=15;i++)
	{
		gotoxy(17,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=14;i++)
	{
		gotoxy(18,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=13;i++)
	{
		gotoxy(19,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=11;i++)
	{
		gotoxy(20,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=10;i++)
	{
		gotoxy(21,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=9;i++)
	{
		gotoxy(22,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=8;i++)
	{
		gotoxy(23,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=7;i++)
	{
		gotoxy(24,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=6;i++)
	{
		gotoxy(25,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=8;i++)
	{
		gotoxy(26,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=9;i++)
	{
		gotoxy(27,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=10;i++)
	{
		gotoxy(28,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=11;i++)
	{
		gotoxy(29,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=12;i++)
	{
		gotoxy(30,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=13;i++)
	{
		gotoxy(31,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=14;i++)
	{
		gotoxy(32,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=16;i++)
	{
		gotoxy(33,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=17;i++)
	{
		gotoxy(34,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=15;i++)
	{
		gotoxy(35,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=14;i++)
	{
		gotoxy(36,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=13;i++)
	{
		gotoxy(37,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=12;i++)
	{
		gotoxy(38,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=11;i++)
	{
		gotoxy(39,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=12;i++)
	{
		gotoxy(40,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=13;i++)
	{
		gotoxy(41,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=14;i++)
	{
		gotoxy(42,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=15;i++)
	{
		gotoxy(43,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=14;i++)
	{
		gotoxy(44,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=13;i++)
	{
		gotoxy(45,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=12;i++)
	{
		gotoxy(46,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=11;i++)
	{
		gotoxy(47,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=10;i++)
	{
		gotoxy(48,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=9;i++)
	{
		gotoxy(49,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=8;i++)
	{
		gotoxy(50,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=9;i++)
	{
		gotoxy(51,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=10;i++)
	{
		gotoxy(52,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=11;i++)
	{
		gotoxy(53,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=12;i++)
	{
		gotoxy(54,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=13;i++)
	{
		gotoxy(55,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=14;i++)
	{
		gotoxy(56,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=15;i++)
	{
		gotoxy(57,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=14;i++)
	{
		gotoxy(58,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=13;i++)
	{
		gotoxy(59,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=11;i++)
	{
		gotoxy(60,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=13;i++)
	{
		gotoxy(61,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=14;i++)
	{
		gotoxy(62,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=15;i++)
	{
		gotoxy(63,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=16;i++)
	{
		gotoxy(64,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=17;i++)
	{
		gotoxy(65,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=20;i++)
	{
		gotoxy(66,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=19;i++)
	{
		gotoxy(67,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=18;i++)
	{
		gotoxy(68,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=17;i++)
	{
		gotoxy(69,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=15;i++)
	{
		gotoxy(70,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=14;i++)
	{
		gotoxy(71,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=13;i++)
	{
		gotoxy(72,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=11;i++)
	{
		gotoxy(73,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=12;i++)
	{
		gotoxy(74,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=13;i++)
	{
		gotoxy(75,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=14;i++)
	{
		gotoxy(76,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=15;i++)
	{
		gotoxy(77,i);
		cprintf("Ý");
		delay(2);
	}
	for(i=1;i<=16;i++)
	{
		gotoxy(78,i);
		cprintf("Ý");
		delay(2);
	}
}
void thnx()
{
	textbackground(BLACK);
	clrscr();
	textcolor(WHITE);

	//for T

	for(i=14;i<=21;i++)
	{
		gotoxy(i,7);
		cprintf("°");
		delay(20);
	}
	for(i=7;i<=11;i++)
	{
		gotoxy(17,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}

	//for H

	for(i=7;i<=11;i++)
	{
		gotoxy(24,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=7;i<=11;i++)
	{
		gotoxy(29,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=26;i<=28;i++)
	{
		gotoxy(i,9);
		cprintf("°");
		delay(20);
	}

	//for A

	for(i=14;i<=34;i++)
	{
		gotoxy(i,13);
		cprintf("°");
		delay(20);
	}
	for(i=12;i>=7;i--)
	{
		gotoxy(33,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=35;i<=37;i++)
	{
		gotoxy(i,7);
		cprintf("°");
		delay(20);
	}
	for(i=7;i<=12;i++)
	{
		gotoxy(38,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=38;i<=66;i++)
	{
		gotoxy(i,13);
		cprintf("°");
		delay(20);
	}
	for(i=35;i<=37;i++)
	{
		gotoxy(i,10);
		cprintf("°");
		delay(20);
	}

	//for N

	for(i=11;i>=7;i--)
	{
		gotoxy(42,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=7;i<9;i++)
	{
		gotoxy(44,i);
		cprintf("°");
		delay(20);
	}
	for(i=8;i<10;i++)
	{
		gotoxy(45,i);
		cprintf("°");
		delay(20);
	}
	for(i=9;i<11;i++)
	{
		gotoxy(46,i);
		cprintf("°");
		delay(20);
	}
	for(i=7;i<=11;i++)
	{
		gotoxy(47,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}

	//for K

	for(i=7;i<=11;i++)
	{
		gotoxy(51,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=55;i<=57;i++)
	{
		gotoxy(i,7);
		cprintf("°");
		delay(20);
	}
	for(i=54;i<=55;i++)
	{
		gotoxy(i,8);
		cprintf("°");
		delay(20);
	}
	for(i=53;i<=54;i++)
	{
		gotoxy(i,9);
		cprintf("°");
		delay(20);
	}
	for(i=54;i<=55;i++)
	{
		gotoxy(i,10);
		cprintf("°");
		delay(20);
	}
	for(i=55;i<=57;i++)
	{
		gotoxy(i,11);
		cprintf("°");
		delay(20);
	}

	//for S

	for(i=66;i>=60;i--)
	{
		gotoxy(i,7);
		cprintf("°");
		delay(20);
	}
	for(i=8;i<=9;i++)
	{
		gotoxy(60,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=60;i<=64;i++)
	{
		gotoxy(9,i);
		cprintf("°");
		delay(20);
	}
	for(i=10;i<=11;i++)
	{
		gotoxy(65,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=66;i>=60;i--)
	{
		gotoxy(i,11);
		cprintf("°");
		delay(20);
	}
	gotoxy(66,13);
	cprintf("°");
 	strupr(obj2.name);
	gotoxy(25,15);
	cprintf(" Mr./Ms. %s ",obj2.name);
  	gotoxy(14,17);
	cprintf(" F ");
	delay(20);
	cprintf(" O ");
	delay(20);
	cprintf(" R  ");
	delay(20);
	cprintf(" P ");
	delay(20);
	cprintf(" L ");
	delay(20);
	cprintf(" A ");
	delay(20);
	cprintf(" Y ");
	delay(20);
	cprintf(" I ");
	delay(20);
	cprintf(" N ");
	delay(20);
	cprintf(" G  ");
	delay(20);
	cprintf(" N ");
	delay(20);
	cprintf(" U ");
	delay(20);
	cprintf(" M ");
	delay(20);
	cprintf("  H ");
	delay(20);
	cprintf(" U ");
	delay(20);
	cprintf(" N ");
	delay(20);
	cprintf(" T ");
	delay(20);
	gotoxy(45,20);
	cprintf("Developed By:- Mohit Yadav ");
	gotoxy(45,22);
	cprintf("Guided By:- Mr. Ashok Bhardwaj ");
}
void congo()
{
	//textbackground(MAGENTA);
	textcolor(MAGENTA);
	for(i=1;i<=80;i++)
	{
		for(j=1;j<=24;j++)
		{
			gotoxy(i,j);
			cprintf("Û");
		}
		delay(20);
	}
	bckgrnd(15);
	textbackground(MAGENTA);
	for(i=76;i>=5;i--)
	{
		for(j=6;j<=15;j++)
		{
			gotoxy(i,j);
			cprintf(" ");
		}
		delay(10);
	}
	textcolor(RED+BLINK);
	textbackground(BLUE);

	//for c

	for(i=11;i>=5;i--)
	{
		gotoxy(i,7);
		cprintf("°");
		delay(20);
	}
	for(i=7;i<=12;i++)
	{
		gotoxy(5,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=5;i<=11;i++)
	{
		gotoxy(i,12);
		cprintf("°");
		delay(20);
	}

	//for o

	for(i=20;i>=14;i--)
	{
		gotoxy(i,7);
		cprintf("°");
		delay(20);
	}
	for(i=7;i<=12;i++)
	{
		gotoxy(14,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=14;i<=20;i++)
	{
		gotoxy(i,12);
		cprintf("°");
		delay(20);
	}
	for(i=12;i>=7;i--)
	{
		gotoxy(19,i);
		cprintf("°");
		cprintf("°");
	}
	delay(20);

	//for N

	for(i=12;i>=7;i--)
	{
		gotoxy(23,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=7;i<9;i++)
	{
		gotoxy(25,i);
		cprintf("°");
		delay(20);
	}
	for(i=8;i<10;i++)
	{
		gotoxy(26,i);
		cprintf("°");
		delay(20);
	}
	for(i=9;i<11;i++)
	{
		gotoxy(27,i);
		cprintf("°");
		delay(20);
	}
	for(i=10;i<12;i++)
	{
		gotoxy(28,i);
		cprintf("°");
		delay(20);
	}
	for(i=7;i<=12;i++)
	{
		gotoxy(29,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}

	//for G

	for(i=39;i>=33;i--)
	{
		gotoxy(i,7);
		cprintf("°");
		delay(20);
	}
	for(i=7;i<=12;i++)
	{
		gotoxy(33,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=33;i<=39;i++)
	{
		gotoxy(i,12);
		cprintf("°");
		delay(20);
	}
	for(i=12;i>=10;i--)
	{
		gotoxy(38,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=39;i>=37;i--)
	{
		gotoxy(i,10);
		cprintf("°");
		delay(20);
	}

	//for R

	for(i=12;i>=7;i--)
	{
		gotoxy(42,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=43;i<=48;i++)
	{
		gotoxy(i,7);
		cprintf("°");
		delay(20);
	}
	for(i=7;i<=9;i++)
	{
		gotoxy(47,i);
		cprintf("°");
		cprintf("°");
	}
	for(i=48;i>=43;i--)
	{
		gotoxy(i,10);
		cprintf("°");
		delay(20);
	}
	for(i=45;i<=46;i++)
	{
		gotoxy(i,11);
		cprintf("°");
		delay(20);
	}
	for(i=46;i<=48;i++)
	{
		gotoxy(i,12);
		cprintf("°");
		delay(20);
	}

	//for A

	for(i=12;i>=7;i--)
	{
		gotoxy(51,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=53;i<=55;i++)
	{
		gotoxy(i,7);
		cprintf("°");
		delay(20);
	}
	for(i=7;i<=12;i++)
	{
		gotoxy(56,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=53;i<=55;i++)
	{
		gotoxy(i,10);
		cprintf("°");
		delay(20);
	}

	//for T

	for(i=60;i<=67;i++)
	{
		gotoxy(i,7);
		cprintf("°");
		delay(20);
	}
	for(i=7;i<=12;i++)
	{
		gotoxy(63,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}

	//for S

	for(i=76;i>=70;i--)
	{
		gotoxy(i,7);
		cprintf("°");
		delay(20);
	}
	for(i=8;i<=10;i++)
	{
		gotoxy(70,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=70;i<=74;i++)
	{
		gotoxy(10,i);
		cprintf("°");
		delay(20);
	}
	for(i=10;i<=14;i++)
	{
		gotoxy(75,i);
		cprintf("°");
		cprintf("°");
		delay(20);
	}
	for(i=76;i>=5;i--)
	{
		gotoxy(i,14);
		cprintf("°");
		delay(20);
	}
	strupr(obj2.name);
	gotoxy(10,14);
	cprintf(" Mr./Ms. %s Y O U  C O M P L E T E D  T H E  G A M E  :) ",obj2.name);
}

void database()
{
	 int l,k,p;
      clrscr();
      textcolor(YELLOW);
	gotoxy(34,5);
	obj2.score=b;
	cprintf("HIGH SCORE");
	int c,j,i,flag=10,v=0;
		fin.open("SCORE.TXT",ios::in);
		fin.seekg(0,ios::end);
		int rec=fin.tellg()/sizeof(obj);
		fin.seekg(0,ios::beg);
		if(rec>=5)
		{



	for(i=0;i<5;i++)
	{
		fin.read((char*)&obj,sizeof(obj));
		obj1[i].score=obj.score;                       // sort the already data in increasing order
		strcpy(obj1[i].name,obj.name);
	}
	/*for(i=0;i<5;i++)
	{
		for(j=i;j<5;j++)
		{
			if(obj1[i].score<obj1[j].score)
			{
				c=obj1[i].score;
				obj1[i].score=obj1[j].score;           //sorting
				obj1[j].score=c;
			}
		}
	}*/
	for(i=0;i<4;i++)
	{
		if(obj2.score<obj1[i].score && obj2.score>obj1[i+1].score)
		{
			flag=i+1;
			break;
		}
	}
	if(obj2.score<obj1[4].score || obj2.score==0)
	{
		flag=13;
	}
	fin.close();

      if(obj2.score>obj1[4].score) // only if it is more than the last one
      {

      	fin.open("SCORE.TXT",ios::out);
		   /*for(i=5;i>=0;i--)
		   {
			if(obj2.score>obj1[i].score && obj2.score<obj1[i+1].score)  // to check the appropriate position

			{
			       cout<<"kaa";
			       getch();
			       flag=i;
			       break;
			}
		}*/
		if(flag==10)          // highest score
		{
			for(i=0;i<5;i++)
			{
			       if(i==0)
			       {
					fin.write((char*)&obj2,sizeof(obj2));     // at top position
				   }
				   else
				   {
					  fin.write((char*)&obj1[i],sizeof(obj1[i]));
				   }
			    }
			    fin.close();
			fin.open("SCORE.TXT",ios::in);
			l=10;
	gotoxy(34,9);
	for(i=0;i<5;i++)
	{
		gotoxy(34,9+(i*2));
		fin.read((char*)&obj,sizeof(obj));
		if(i%2==0)
		{
			for(k=10;k<25;k++)
			{
			     for(p=0;p<80;p++)
			     {
				cprintf(" ");
				 }
				gotoxy(k,l);
				cprintf("%s  --> ",obj.name);

				delay(70);

			}
			gotoxy(47,l);
			cprintf("%d",obj.score);
			l+=2;
		}
		else
		{
			for(k=41;k>=24;k--)
			{
			    for(p=80;p>=0;p--)
			    {
			    	gotoxy(p,l);
			    	cprintf(" ");
				}
				gotoxy(k,l);
				cprintf("%s     -->    ",obj.name);
				
				delay(70);

			}
			gotoxy(47,l);
			cprintf("%d",obj.score);
			l+=2;
		}
	}
		    }
		    else if(flag==13)
		    {
		    	for(i=0;i<5;i++)
			{
			       if(i==4)
			       {
					fin.write((char*)&obj2,sizeof(obj2));     // at top position
				   }
				   else
				   {
					  fin.write((char*)&obj1[i],sizeof(obj1[i]));
				   }
			    }
			    fin.close();
			fin.open("SCORE.TXT",ios::in);
			l=10;
	gotoxy(34,9);
	for(i=0;i<5;i++)
	{
		gotoxy(34,9+(i*2));
		fin.read((char*)&obj,sizeof(obj));
		if(i%2==0)
		{
			for(k=10;k<25;k++)
			{
			     for(p=0;p<80;p++)
			     {
				cprintf(" ");
				 }
				gotoxy(k,l);
				cprintf("%s  --> ",obj.name);

				delay(70);

			}
			gotoxy(47,l);
			cprintf("%d",obj.score);
			l+=2;
		}
		else
		{
			for(k=41;k>=24;k--)
			{
			    for(p=80;p>=0;p--)
			    {
			    	gotoxy(p,l);
			    	cprintf(" ");
				}
				gotoxy(k,l);
				cprintf("%s     -->    ",obj.name);
				
				delay(70);

			}
			gotoxy(47,l);
			cprintf("%d",obj.score);
			l+=2;
		}
	}
			}
		    else
		    {
			int v=0;
			for(i=0;i<5;i++)
		{
			if(i==flag)
			{
				fin.write((char*)&obj2,sizeof(obj2));
				v=1;
			}
			else if(v==1)
			{
				fin.write((char*)&obj1[i-1],sizeof(obj1[i-1]));
			}
			else if(v==0)
			{
				fin.write((char*)&obj1[i],sizeof(obj1[i]));
			}
		     }
		     fin.close();
		     fin.open("SCORE.TXT",ios::in);
			l=10;
	gotoxy(34,9);
	for(i=0;i<5;i++)
	{
		gotoxy(34,9+(i*2));
		fin.read((char*)&obj,sizeof(obj));
		if(i%2==0)
		{
			for(k=10;k<25;k++)
			{
			    for(p=0;p<80;p++)
			    {
			    	gotoxy(p,l);
			    	cprintf(" ");
				}
				gotoxy(k,l);
				cprintf("%s     -->    ",obj.name);
				
				delay(70);

			}
			gotoxy(47,l);
			cprintf("%d",obj.score);
			l+=2;
		}
		else
		{
			for(k=41;k>=24;k--)
			{
			    for(p=80;p>=0;p--)
			    {
			    	gotoxy(p,l);
			    	cprintf(" ");
				}
				gotoxy(k,l);
				cprintf("%s     -->    ",obj.name);
				
				delay(70);
			}
			gotoxy(47,l);
			cprintf("%d",obj.score);
			l+=2;
		}
	}
		   }


     }
     else
     {
	fin.close();
	fin.open("SCORE.TXT",ios::in);
	l=10;
	gotoxy(34,9);
	for(i=0;i<5;i++)
	{
		gotoxy(34,9+(i*2));
		fin.read((char*)&obj,sizeof(obj));
		if(i%2==0)
		{
			for(k=10;k<25;k++)
			{
			    for(p=0;p<80;p++)
			    {
			    	gotoxy(p,l);
				cprintf(" ");
				}
				gotoxy(k,l);
				cprintf("%s    -->   ",obj.name);
				
				delay(70);
			}
			gotoxy(47,l);
			cprintf("%d",obj.score);
			l+=2;
		}
		else
		{
			for(k=41;k>=24;k--)
			{
			    for(p=80;p>=0;p--)
			    {
				gotoxy(p,l);
				cprintf(" ");
				}
				gotoxy(k,l);
				cprintf("%s    -->    ",obj.name);
				
				delay(70);

			}
			gotoxy(47,l);
			cprintf("%d",obj.score);
			l+=2;
		}
	}
      }

 }
 else
 {
	for(i=0;i<rec;i++)
	{
		fin.read((char*)&obj,sizeof(obj));
		obj1[i].score=obj.score;
		strcpy(obj1[i].name,obj.name);
	}
	for(i=0;i<rec;i++)
	{
		if(obj2.score<obj1[i].score && obj2.score>obj1[i+1].score)
		{
			flag=i+1;
			break;
		}
	}
	if(obj2.score<obj1[rec-1].score)
	{
		flag=13;
	}
	if(obj2.score==0)
	{
		flag=13;
	}
	fin.close();
	fin.open("SCORE.TXT",ios::out);
	if(flag==10)
	{
		for(i=0;i<rec+1;i++)
		{
			if(i==0)
			{
				fin.write((char*)&obj2,sizeof(obj2));
			}
			else
			{
				fin.write((char*)&obj1[i-1],sizeof(obj1[i-1]));
			}
		}
	}
	else if(flag==13)
	{
			for(i=0;i<rec+1;i++)
		{
			if(i==rec)
			{
				fin.write((char*)&obj2,sizeof(obj2));
			}
			else
			{
				fin.write((char*)&obj1[i],sizeof(obj1[i]));
			}
		}
	}
	else
	{
		for(i=0;i<rec+1;i++)
		{
			if(i==flag)
			{
				fin.write((char*)&obj2,sizeof(obj2));
				v=1;
			}
			else if(v==1)
			{
				fin.write((char*)&obj1[i-1],sizeof(obj1[i-1]));
			}
			else if(v==0)
			{
				fin.write((char*)&obj1[i],sizeof(obj1[i]));
			}
		}
	}
	fin.close();
	fin.open("SCORE.TXT",ios::in);
	l=10;
	gotoxy(34,9);
	for(i=0;i<rec+1;i++)
	{
		gotoxy(34,9+(i*2));
		fin.read((char*)&obj,sizeof(obj));
		if(i%2==0)
		{
			for(k=10;k<25;k++)
			{
				for(p=0;p<80;p++)
				{
					gotoxy(p,l);
					cprintf(" ");
				}
				gotoxy(k,l);
				cprintf("%s     -->    ",obj.name);
				delay(70);
			}
			gotoxy(47,l);
			cprintf("%d",obj.score);
			l+=2;
		}
		else
		{
			for(k=41;k>=24;k--)
			{
				for(p=80;p>=0;p--)
				{
					gotoxy(p,l);
					cprintf(" ");
				}
				gotoxy(k,l);
				cprintf("%s     -->     ",obj.name);
				delay(70);
			}
			gotoxy(47,l);
			cprintf("%d",obj.score);
			l=l+2;
		}
	}

 }
    delay(500);
    for(i=5;i<20;i++)
    {
	gotoxy(50,i);
	cprintf("|");
	}
	gotoxy(62,10);
	textcolor(CYAN+BLINK);
	cprintf("CURRENT SCORE");
	gotoxy(61,13);
	cprintf("%s  -->  %d",obj2.name,obj2.score);
	getch();
	getch();
}