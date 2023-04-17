#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
using namespace std;
void move(int j,int h,int&x,int& y){
	if(j==1)
		y=y-h;
	else if(j==2)
		x=x+h;
	else if(j==3)
		y=y+h;
	else if(j==4)
		x=x-h;
	lineto(x,y);
}

void hilbert(int r,int d,int l,int u,int i,int h,int &x,int &y){
	if(i>0){
		i--;
		hilbert(d,r,u,l,i,h,x,y);
		move(r,h,x,y);
		hilbert(r,d,l,u,i,h,x,y);
		move(d,h,x,y);
		hilbert(r,d,l,u,i,h,x,y);
		move(l,h,x,y);
		hilbert(u,l,d,r,i,h,x,y);
	}
}
int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	int x,y,xo=50,yo=150,u=1,r=2,d=3,l=4,h=10,n;
	cout<<"No. of iterations :";
	cin>>n;
	x=xo;
	y=yo;
	moveto(x,y);
	hilbert(r,d,l,u,n,h,x,y);
	delay(100);
	getch();
}
