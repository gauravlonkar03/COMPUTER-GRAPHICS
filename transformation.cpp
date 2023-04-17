#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void display(int x1,int y1,int x2,int y2,int x3,int y3){
	int xmid=getmaxx()/2;
	int ymid=getmaxy()/2;
	
	line(0,ymid,getmaxx(),ymid);
	line(xmid,0,xmid,getmaxy());
	line(x1+xmid,y1+ymid,x2+xmid,y2+ymid);
	line(x2+xmid,y2+ymid,x3+xmid,y3+ymid);
	line(x3+xmid,y3+ymid,x1+xmid,y1+ymid);
}

class d{
private:
	int x1,y1,x2,y2,x3,y3;
	float sx,sy,tx,ty;
	
public:
	d operator+(d obj){
	outtextxy(100,100,"Before translation");
	display(x1,y1,x2,y2,x3,y3);
	delay(300);
	cleardevice();
	outtextxy(100,100,"After translation");
	display(x1+tx,y1+ty,x2+tx,y2+ty,x3+tx,y3+ty);
	}
	d operator*(d obj){
	outtextxy(100,100,"Before Sclaing");
	display(x1,y1,x2,y2,x3,y3);
	delay(300);
	cleardevice();
	outtextxy(100,100,"After scaling");
	display(x1*sx,y1*sy,x2*sx,y2*sy,x3*sx,y3*sy);
	}
	void accept(int a,int b,int c,int d,int e,int f,float g,float h){
		x1=a;
		y1=b;
		x2=c;
		y2=d;
		x3=e;
		y3=f;
		tx=g;
		ty=h;
		
	}
		void accept2(int a,int b,int c,int d,int e,int f,float g,float h){
		x1=a;
		y1=b;
		x2=c;
		y2=d;
		x3=e;
		y3=f;
		sx=g;
		sy=h;
		
	}
	
	
};



void crotate(int x1,int y1,int x2,int y2,int x3,int y3,float a){
	a=a*(3.142)/180;
	float c=cos(a);
	float s=sin(a);
	outtextxy(100,100,"Before rotation");
	display(x1,y1,x2,y2,x3,y3);
	delay(300);
	cleardevice();
	outtextxy(100,100,"After rotation");
	display((x1*c-y1*s),(x1*s+y1*c),(x2*c-y2*s),(x2*s+y2*c),(x3*c-y3*s),(x3*s+y3*c));
}
void arotate(int x1,int y1,int x2,int y2,int x3,int y3,float a){
	a=a*(3.142)/180;
	float c=cos(a);
	float s=sin(a);
	outtextxy(100,100,"Before rotation");
	display(x1,y1,x2,y2,x3,y3);
	delay(300);
	cleardevice();
	outtextxy(100,100,"After rotation");
	display((x1*c+y1*s),(-x1*s+y1*c),(x2*c+y2*s),(-x2*s+y2*c),(x3*c+y3*s),(-x3*s+y3*c));
}

int main(){
	int gd=DETECT,gm;
	int x1,y1,x2,y2,x3,y3;
	cout<<"ENter the co-ordinates of triangle :"<<endl;
	cout<<"First co-ordinate :";
	cin>>x1>>y1;
	cout<<"second co-ordinate :";
	cin>>x2>>y2;
	cout<<"Second co-ordinate :";
	cin>>x3>>y3;
	initgraph(&gd,&gm,"");
	display(x1,y1,x2,y2,x3,y3);
	
	while(1){
		int ch;
		cout<<"Enter a choice:"<<endl<<"1->T"<<"2->S"<<"3->AR"<<"4->CR"<<"0->EXIT"<<endl;
		cin>>ch;
		if(ch==1){
			float tx,ty;
			cout<<"Enter the translating factors"<<endl;
			cin>>tx>>ty;
			initgraph(&gd,&gm,"");
			d d1;
			d1.accept(x1,y1,x2,y2,x3,y3,tx,ty);
			d1=d1+d1;
			
			getch();
			closegraph();
		}
		else if(ch==2){
			float sx,sy;
			cout<<"Enter the scaling factors"<<endl;
			cin>>sx>>sy;
			initgraph(&gd,&gm,"");
			d d2;
			d2.accept2(x1,y1,x2,y2,x3,y3,sx,sy);
			d2=d2*d2;
			getch();
			closegraph();
		}
		else if(ch==3){
			float b;
			cout<<"Enter the angle"<<endl;
			cin>>b;
			initgraph(&gd,&gm,"");
			arotate(x1,y1,x2,y2,x3,y3,b);
			getch();
			closegraph();
		}
		
		else if(ch==4){
			float a;
			cout<<"Enter the angle"<<endl;			
			cin>>a;
			initgraph(&gd,&gm,"");
			crotate(x1,y1,x2,y2,x3,y3,a);
			getch();
			closegraph();
		}
		else if(ch==0){
			
			cout<<"EXITED"<<endl;
			break;
		}
	}
	getch();
	return 0;
}
