#include<graphics.h>
#include<conio.h>
#include<iostream>
#include<math.h>
using namespace std;

void koch(int x1,int y1,int x2,int y2,int n){
	int x3,y3,x4,y4,x,y;
	float a=(60*3.145)/180;
	x3=(2*x1+x2)/3;
	y3=(2*y1+y2)/3;
	x4=(x1+2*x2)/3;
	y4=(y1+2*y2)/3;
	x=x3+(x4-x3)*cos(a)+(y4-y3)*sin(a);
	y=y3-(x4-x3)*sin(a)+(y4-y4)*cos(a);
	if(n>1){
		koch(x1,y1,x3,y3,n-1);
		koch(x3,y3,x,y,n-1);
		koch(x,y,x4,y4,n-1);
		koch(x4,y4,x2,y2,n-1);
	}
	else if(n==1){
		line(x1,y1,x3,y3);
		line(x3,y3,x,y);
		line(x,y,x4,y4);
		line(x4,y4,x2,y2);}
	else{
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
	}
	
}

main(){
	int gd=DETECT,gm,n;
	initgraph(&gd,&gm,"");
	int x1,y1,x2,y2,x3,y3;
	cout<<"Enter no. of iterations"<<endl;
	cin>>n;
	x1=200;
	y1=200;
	x2=400;
	y2=200;
	x3=250;
	y3=400;
	
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
	delay(300);
	cleardevice();

	koch(x1,y1,x2,y2,n);
	koch(x2,y2,x3,y3,n);
	koch(x3,y3,x1,y1,n);
	
	getch();
	
}
