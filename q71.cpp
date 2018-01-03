#include<iostream.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
class shape
{
public:
int x1,y1;
	void entry()
	{
	cout<<"\nEnter the coordinates of the point";
	cin>>x1>>y1;
	}
	void peri()
	{
	float p=0;
	cout<<"\nPerimeter :"<<p;
	}
	void area()
	{
	float a=0;
	cout<<"\nArea: "<<a;
	}
	void display();
	{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	circle(x1,y1,0);
	getch();
	closegraph();
	}
};
class Circle:public shape
{
public:
	int r1;
	void entry()
	{
	cout<<"Enter the radius and centre of the circle\n";
	cin>>r1>>x1>>y1;
	}
	void peri()
	{
	float p=6.28*r1;
	cout<<"Perimeter of the circle is "<<p;
	}
	void area()
	{
	float a=3.14*r1*r1;
	cout<<"Area of the circle is :"<<a;
	}
	void display()
	{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	circle(x1,y1,r1);
	getch();
	closegraph();
	}
};
class Ellipse:public Circle
{
public:
	int r2;
	void entry()
	{
	cout<<"Enter the center,length of semi major and minor axis\n";
	cin>>x1>>y1>>r1>>r2;
	}
	void peri()
	{
	float p=6.28*sqrt((r1*r1+r2*r2)/2);
	cout<<"Perimeter of ellipse is:"<<p;
	}
	void area()
	{
	float a=3.14*r1*r2;
	cout<<"Area of the ellipse is:"<<a;
	}
	void display()
	{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	ellipse(x1,y1,0,360,r1,r2);
	getch();
	closegraph();
	}
};
class ccircle:public Ellipse
{
public:
	void entry()
	{
	cout<<"Enter the radii and centre of the concentric circle r1>r2:\n";
	cin>>r1>>r2>>x1>>y1;
	}
	void peri()
	{
	float p=6.28*(r1+r2);
	cout<<"Perimeter of the concentric circles is "<<p;
	}
	void area()
	{
	float a=3.14*(r1*r1-r2*r2);
	cout<<"Area of the concentric circles is :"<<a;
	}
	void display()
	{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	circle(x1,y1,r1);
	circle(x1,y1,r2);
	getch();
	closegraph();
	}
};
class Line:public shape
{
public:
	int x2,y2;
	void entry()
	{
	cout<<"Enter coordinates of the line\n";
	cin>>x1>>y1>>x2>>y2;
	}
	void peri()
	{
	float p=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	cout<<"Length of the line is:"<<p;
	}
	void area()
	{
	float a=0;
	cout<<"\nArea of the line is :"<<a;
	}
	void display()
	{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	line(x1,y1,x2,y2);
	getch();
	closegraph();
	}

};
class square:public Line
{
public:
	void entry()
	{
	cout<<"Enter the Coordinates of top left and bottom right of the square\n";
	cin>>x1>>y1>>x2>>y2;
	}
	void peri()
	{
	float l;
	l=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	float p=2.828*l;
	cout<<"Perimeter of the Square is :"<<p;
	}
	void area()
	{
	float l;
	l=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	float a=0.5*l*l;
	cout<<"\nArea of the Square is :"<<a;
	}
	void display()
	{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	rectangle(x1,y1,x2,x2);
	getch();
	closegraph();
	}

};
class triangle:public square
{
public:
	int x3,y3;
	void entry()
	{
	cout<<"Enter coordinates of the Triangle\n";
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	}
	void peri()
	{
	float l1,l2,l3;
	l1=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
	l2=sqrt(((x3-x1)*(x3-x1))+((y3-y1)*(y3-y1)));
	l3=sqrt(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));
	float p=l1+l2+l3;
	cout<<"Perimeter of the Triangle is :"<<p;
	}
	void area()
	{
	float a=0.5*abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	cout<<"\nArea of the Triangle is :"<<a;
	}
	void display()
	{
	int p[]={x1,y1,x2,y2,x3,y3,x1,y1};
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	drawpoly(4,p);
	getch();
	closegraph();
	}
};
class rectangle:public triangle
{
public:
	void entry()
	{
	cout<<"Enter the top left and bottom right coordinates and length & breadth\n";
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	}
	void peri()
	{
	float p=2*(x3+y3);
	cout<<"Perimeter of the Rectangle is :"<<p;
	}
	void area()
	{
	float a=x3*y3;
	cout<<"\nArea of the Rectangle is :"<<a;
	}
	void display()
	{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	rectangle(x1,y1,x2,y2);
	getch();
	closegraph();
	}
};
class rhombus:public triangle
{
public: 
	int x4,y4;
	void entry()
	{
	cout<<"Enter coordinates\n";
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	}
	void peri()
	{
	float l1;
	l1=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
	float p=4*l1;
	cout<<"Perimeter of the Rhombus is :"<<p;
	}
	void area()
	{
	float a=0.5*abs((x1*y2-x2*y1)+(x2*y3-x3*y2)+(x3*y4-x4*y3)+(x4*y1-x1*y4));
	cout<<"\nArea of the figure:"<<a;
	}
	void display()
	{
	int p[]={x1,y1,x2,y2,x3,y3,x4,y4,x1,y1};
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	drawpoly(5,p);
	getch();
	closegraph();
	}
};
class parellelogram:public rhombus
{
public: 
	void peri()
	{
	float l1,l2;
	l1=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
	l2=sqrt(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));
	float p=2*(l1+l2);
	cout<<"Perimeter of the Parellelogram is :"<<p;
	}
};
class quadrilateral:public parellelogram
{
public: 
	void peri()
	{
	float l1,l2,l3,l4;
	l1=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
	l2=sqrt(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));
	l3=sqrt(((x3-x4)*(x3-x4))+((y3-y4)*(y3-y4)));
	l4=sqrt(((x4-x1)*(x4-x1))+((y4-y1)*(y4-y1)));
	float p=l1+l2+l3+l4;
	cout<<"Perimeter of the Quadrilateral is :"<<p;
	}
};
class pentagon:public rhombus
{
public:
	int x5,y5;
	void entry()
	{
	cout<<"Enter coordinates of Pentagon\n";
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5;
	}
	void peri()
	{
	float l1,l2,l3,l4,l5;
	l1=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
	l2=sqrt(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));
	l3=sqrt(((x3-x4)*(x3-x4))+((y3-y4)*(y3-y4)));
	l4=sqrt(((x4-x5)*(x4-x5))+((y4-y5)*(y4-y5)));
	l5=sqrt(((x5-x1)*(x5-x1))+((y5-y1)*(y5-y1)));
	float p=l1+l2+l3+l4+l5;
	cout<<"Perimeter of the Pentagon is :"<<p;
	}
	void area()
	{
	float a=0.5*abs((x1*y2-x2*y1)+(x2*y3-x3*y2)+(x3*y4-x4*y3)+(x4*y5-x5*y4)+(x5*y1-x1*y5));
	cout<<"\nArea of the Pentagon:"<<a;
	}
	void display()
	{
	int p[]={x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x1,y1};
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	drawpoly(6,p);
	getch();
	closegraph();
	}	
};
class hexagon:public pentagon
{
public:
	int x6,y6;
	void entry()
	{
	cout<<"Enter coordinates of Hexagon\n";
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6;
	}
	void peri()
	{
	float l1,l2,l3,l4,l5,l6;
	l1=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
	l2=sqrt(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));
	l3=sqrt(((x3-x4)*(x3-x4))+((y3-y4)*(y3-y4)));
	l4=sqrt(((x4-x1)*(x4-x1))+((y4-y1)*(y4-y1)));
	l5=sqrt(((x4-x5)*(x4-x5))+((y4-y5)*(y4-y5)));
	l6=sqrt(((x6-x1)*(x6-x1))+((y6-y1)*(y6-y1)));
	float p=l1+l2+l3+l4+l5+l6;
	cout<<"Perimeter of the Hexagon is :"<<p;
	}
	void area()
	{
	float a=0.5*abs((x1*y2-x2*y1)+(x2*y3-x3*y2)+(x3*y4-x4*y3)+(x4*y5-x5*y4)+(x5*y6-x6*y5)+(x6*y1-x1*y6));
	cout<<"\nArea of the figure:"<<a;
	}
	void display()
	{
	int poly[]={x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x1,y1};
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	drawpoly(7,p);
	getch();
	closegraph();
	}	
};
class heptagon:public hexagon
{
public:
	int x7,y7;
	void entry()
	{
	cout<<"Enter coordinates of Hexagon\n";
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6>>x7>>y7;
	}
	void peri()
	{
	float l1,l2,l3,l4,l5,l6,l7;
	l1=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
	l2=sqrt(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));
	l3=sqrt(((x3-x4)*(x3-x4))+((y3-y4)*(y3-y4)));
	l4=sqrt(((x4-x1)*(x4-x1))+((y4-y1)*(y4-y1)));
	l5=sqrt(((x4-x5)*(x4-x5))+((y4-y5)*(y4-y5)));
	l6=sqrt(((x6-x7)*(x6-x7))+((y6-y7)*(y6-y7)));
	l7=sqrt(((x7-x1)*(x7-x1))+((y7-y1)*(y7-y1)));
	float p=l1+l2+l3+l4+l5+l6+l7;
	cout<<"Perimeter of the Hexagon is :"<<p;
	}
	void area()
	{
	float a=0.5*abs((x1*y2-x2*y1)+(x2*y3-x3*y2)+(x3*y4-x4*y3)+(x4*y5-x5*y4)+(x5*y6-x6*y5)+(x6*y7-x7*y6)+(x7*y1-x1*y7));
	cout<<"\nArea of the figure:"<<a;
	}
	void display()
	{
	int p[]={x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x1,y1};
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	drawpoly(8,p);
	getch();
	closegraph();
	}	
};

int main()
{
clrscr();
int a;
shape p;
Circle c;
Ellipse e;
ccircle c1;
square s;
Rectangle r;
Line l;
triangle t;
rhombus r1;
parellelogram p1;
quadrilateral q;
pentagon p2;
hexagon h;
heptagon h1;
cout<<"Enter your Choice\n1.Point\n2.Circle\n3.Ellipse\n4.Line\n5.Square\n6.Triangle";
cout<<"\n7.Rectangle\n8.Rhombus\n9.Parrellelogram\n10.Quadrilateral\n11.Pentagon\n12.Hexagon\n";
cout<<"13.Concentric circles\n14.Heptagon";
cin>>a;
switch(a)
{
	case 1:p.entry();
		 p.peri();
		 p.area();
		 p.display();
		 break;
	case 2:c.entry();
		 c.peri();
		 c.area();
		 c.display();
		 break;
	case 3:e.entry();
		 e.peri();
		 e.area();
		 e.display();
		 break;
	case 4:l.entry();
		 l.peri();
		 l.area();
		 l.display();
		 break;
	case 5:s.entry();
		 s.peri();
		 s.area();
		 s.display();
		 break;
	case 6:t.entry();
		 t.peri();
		 t.area();
		 t.display();
		 break;
	case 7:r.entry();
		 r.peri();
		 r.area();
		 r.display();
		 break;
	case 8:  r1.entry();
		 r1.peri();
		 r1.area();
		 r1.display();
		 break;
	case 9:  p1.rhombus::entry();
		 p1.peri();
		 p1.rhombus::area();
		 p1.rhombus::display();
		 break;
	case 10: q.rhombus::entry();
		 q.peri();
		 q.rhombus::area();
		 q.rhombus::display();
		 break;
	case 11: p2.entry();
		 p2.peri();
		 p2.area();
		 p2.display();
		 break;
	case 12: h.entry();
		 h.peri();
		 h.area();
		 h.display();
		 break;
	case 13:c1.entry();
		 c1.peri();
		 c1.area();
		 c1.display();
		 break;
	case 14: h1.entry();
		 h1.peri();
		 h1.area();
		 h1.display();
		 break;
	default: cout<<"Wrong Choice\n";
		 break;
}
getch();
}
