#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
string tos(double x) {
	string s;
	char buffer[200];
	sprintf_s(buffer, "%.2lf", x);
	s = string(buffer);
	return s;
}
string tos(int x) {
	string s;
	char buffer[200];
	sprintf_s(buffer, "%d", x);
	s = string(buffer);
	return s;
}
int main() {
	Point tl(100, 100);
	Simple_window win(tl, 600, 700, "Canvas");
	Axis xa(Axis::x, Point(50, 600), 500, 10);
	Axis ya(Axis::y, Point(50, 600), 500, 10, "y axis");
	Text te(Point(550, 630), "x axis");
	win.attach(te);
	int i, n;
	double y = 0, dx, dy, x;
	vector<double> a;
	Rectangle **r;
	Text **t;
	while (cin >> x) a.push_back(x);
	n = a.size();
	r = new Rectangle*[n];
	t = new Text*[n * 2];
	for (i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0) i--;
		if (a[i] > y) y = a[i];
	}
	dy = 500 / y; dx = 250 / n;
	y = 50 + dx*1.5;
	for (i = 0; i < n; i++) {
		r[i] = new Rectangle(Point(y - dx / 2, 600 - a[i] * dy), Point(y + dx / 2, 600));
		t[2 * i] = new Text(Point(y, 600 - a[i] * dy), tos(a[i]));
		t[2 * i + 1] = new Text(Point(y, 620), tos(i + 1));
		y += dx*1.5;
		win.attach(*r[i]); win.attach(*t[2 * i]); win.attach(*t[2 * i + 1]);
	}
	win.attach(xa);
	win.attach(ya);
	win.wait_for_button();
}