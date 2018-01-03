#include<graphics.h>
#include<math.h>
int main()
{

int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
for(int i=2880;i>0;i--)
{
ellipse(250,250,0,360,200,50);
circle(250,250,40);
circle(250+200*cos(i*(3.14/180)),250+50*sin(i*(3.14/180)),25);
ellipse(250+200*cos(i*(3.14/180)),250+50*sin(i*(3.14/180)),0,360,50,30);
circle(250+200*cos(i*(3.14/180))+50*cos(i*(12.56/180)),250+50*sin(i*(3.14/180))+30*sin(i*(12.56/180)),10);
delay(10);
cleardevice();
}
getch();
closegraph();
}
