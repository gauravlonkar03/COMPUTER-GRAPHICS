#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>
using namespace std;
static int LEFT=1,RIGHT=2,TOP=8,BOTTOM=4;
static int xmax,ymax,xmin,ymin;
int getcode(int x,int y){
	int code=0;
	if(x>xmax) code|=RIGHT;
	if(x<xmin) code|=LEFT;
	if(y<ymin) code|=BOTTOM;
	if(y>ymax) code|=TOP;
	
	return code;
}
main(){
	int gd=DETECT,gm;
	float m;
	int x1,y1,x2,y2;
	initgraph(&gd,&gm,"");
	cout<<"Enter the maximum an dminimum co-ordinates of rectangle"<<endl;
	cout<<"Xmin :"<<endl;
	cin>>xmin;
	cout<<"Ymin : "<<endl;
	cin>>ymin;
	cout<<"Xmax : "<<endl;
	cin>>xmax;
	cout<<"Ymax : "<<endl;
	cin>>ymax;
	rectangle(xmin,ymin,xmax,ymax);
	cout<<"Enetr the endpoints of the line :  "<<endl;
	cout<<"first co-ordinates :"<<endl;
	cin>>x1>>y1;
	cout<<"Second co-ordinates : "<<endl;
	cin>>x2>>y2;
	line(x1,y1,x2,y2);
	int outcode1=getcode(x1,y1),outcode2=getcode(x2,y2);
	cout<<outcode1<<endl;
	cout<<outcode2<<endl;
	int accept=0;
	while(1){
		m=(float)(y2-y1)/(x2-x1);
		if(outcode1==0&&outcode2==0){
			cout<<"Line accepted"<<endl;
			accept=1;
			break;
		}
		else if((outcode1&outcode2)!=0){
			cout<<"line rejected"<<endl;
			break;
		}
		else{
			int x,y,temp;
			if(outcode1==0){
				temp=outcode2;
			}
			else{
				temp=outcode1;
			}
			if(temp&TOP){
				x=x1+(ymax-y1)/m;
				y=ymax;
			}
			else if(temp&BOTTOM){
				x=x1+(ymin-y1)/m;
				y=ymin;
			}
			else if(temp&RIGHT){
				x=xmax;
				y=y1+(xmax-x1)*m;
			}
			else if(temp&LEFT){
				x=xmin;
				y=y1+(xmin-x1)*m;
			}
			if(temp==outcode1){
				x1=x;
				y1=y;
				outcode1=getcode(x1,y1);
			}
			else{
				x2=x;
				y2=y;
				outcode2=getcode(x2,y2);
			}
		}
	}
	if(accept){
		cout<<x1<<endl;
		cout<<y1<<endl;
		cout<<x2<<endl;
		cout<<y2<<endl;
		
		cout<<"Line accepted"<<endl;
		cleardevice();
		rectangle(xmin,ymin,xmax,ymax);
		setcolor(YELLOW);
		line(x1,y1,x2,y2);
	}
	else{
		cout<<"line rejected"<<endl;
	}
	getch();
	closegraph();
	
}
