#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
using namespace Graph_lib;
double f(double x) {
	return sin(x)*sin(x) + cos(x)*cos(x);
}
double pluus(double x) {
	return sin(x) + cos(x);
}
int main() {
	Point tl(100, 100);
	Simple_window win(tl, 600, 700, "Canvas");
	int ux, uy, num;
	cout << "Ux,Uy,Num:";
	cin >> ux >> uy >> num;
	Axis xa(Axis::x, Point(50, 500), ux*num, num, "x axis");
	Axis ya(Axis::y, Point(50, 500), ux*num, num, "y axis");
	
	Function sine(sin, 0, num, Point(50, 500), 1000, ux, uy);
	sine.set_color(Color::black);
	Function cosine(cos, 0, num, Point(50, 500), 1000, ux, uy);
	cosine.set_color(Color::blue);
	Function c_s(pluus, 0, num, Point(50, 500), 1000, ux, uy);
	c_s.set_color(Color::magenta);
	Function l(f, 0, num, Point(50, 500), 1000, ux, uy);
	l.set_color(Color::red);
	
	Text t1(Point(100, 100), "Black:sin()"), t2(Point(100, 130), "Blue:cos()"), t3(Point(100, 160), "Magenta:sin()+cos()"), t4(Point(100, 190), "Red:sin()^2+cos()^2");
	win.attach(t1); win.attach(t2); win.attach(t3); win.attach(t4);
	win.attach(xa); win.attach(ya);
	win.attach(sine);
	win.attach(c_s);
	win.attach(cosine);
	win.attach(l);
	win.wait_for_button();
}