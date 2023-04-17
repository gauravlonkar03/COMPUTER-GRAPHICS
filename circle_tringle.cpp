#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<math.h>
using namespace std;

void drawline(float x1,float y1,float x2,float y2){
	float dx,dy,x,y,len,xi,yi;
	int i;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy)){
		len=abs(dx);
	}
	else{
		len=abs(dy);
	}
	xi=dx/len;
	yi=dy/len;
	putpixel(x1,y1,15);
	x=x1;
	y=y1;
	for(i=0;i<len;i++){
		x=x+xi;
		y=y+yi;
		putpixel(x,y,15);
	}
	
}

void drawcircle(int xce,int yce,int r){
	int x,y,s;
	x=0;
	y=r;
	s=3-2*r;
	while(x<=y){
		if(s<=0){
			x=x+1;
			y=y;
			s=s+4*x+6;
		}
		else{
			x=x+1;
			y=y-1;
			s=s+4*(x-y)+10;
		}
		putpixel(xce+x,yce+y,15);
		putpixel(xce-x,yce+y,15);
		putpixel(xce+x,yce-y,15);
		putpixel(xce-x,yce-y,15);
		putpixel(xce+y,yce+x,15);
		putpixel(xce-y,yce+x,15);
		putpixel(xce+y,yce-x,15);
		putpixel(xce-y,yce-x,15);
		
	}
}



main(){
	int gd=DETECT,gm,i;
	initgraph(&gd,&gm,"");
	float x1,y1,x2,y2,x3,y3,c,r1,r2,xce,yce;
	cout<<"Enter the co-ordinates ofline :"<<endl;
	cin>>x1>>y1;
	cout<<"Enter the other co-ordinate of line :"<<endl;
	cin>>x2>>y2;
	cout<<"Enter the other co-ordinate of line :"<<endl;
	cin>>x3>>y3;
	cout<<"Enter the centre of the circle"<<endl;
	cin>>xce>>yce;
	cout<<"Enter the radius of inner circle"<<endl;
	cin>>r1;
	cout<<"Enter the radius of outer circle"<<endl;
	cin>>r2;
	drawline(x1,y1,x2,y2);
	drawline(x2,y2,x3,y3);	
	drawline(x3,y3,x1,y1);
	drawcircle(xce,yce,r1);
	drawcircle(xce,yce,r2);
	getch();
}
