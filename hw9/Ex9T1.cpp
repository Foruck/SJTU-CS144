#include "Simple_Window.h"
#include "Graph.h"
#include <iostream>
class err {};
class Poly {
private:
	Polygon p;
public:
	Poly() = default;
	Poly(int n, Point *a) throw (err) {
		int i, j, k; bool b = true;
		if (n <= 2) {
			std::cout << "Not a poly with " <<n<<" sides. "<< std::endl;
			throw err();
			return;
		}
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				for (k = j + 1; k < n; k++) {
					if ((a[i].x - a[k].x)*(a[j].y - a[k].y) == (a[j].x - a[k].x)*(a[i].y - a[k].y)) {
						b = false; break;
					}
				}
		if (!b) {
			std::cout << "Not a poly with " << n << " sides. " << std::endl;
			throw err();
			return;
		}
		for (i = 0; i < n; i++) p.add(a[i]);
	}
	void add(Point x) {
		p.add(x);
	}
	void set_color(Color c) {
		p.set_color(c);
	}
	void set_fill_color(Color c) {
		p.set_fill_color(c);
	}
	void show_in_window(Simple_window &w) {
		w.attach(p);
	}
};

struct pp : Polygon {
private:
	int max(int x, int y) { return x > y ? x : y; }
	int min(int x, int y) { return x < y ? x : y; }
	int direction(Point &p1, Point &p2, Point &p3) {
		return (p1.x - p3.x)*(p2.y - p3.y) - (p2.x - p3.x)*(p1.y - p3.y);
	}
	bool check(Point &a1, Point &a2, Point &b1, Point &b2) {
		if (min(a1.x, a2.x) <= max(b1.x, b2.x) &&
			min(a1.y, a2.y) <= max(b1.y, b2.y) &&
			min(b1.x, b2.x) <= max(a1.x, a2.x) &&
			min(b1.y, b2.y) <= max(a1.y, a2.y) &&
			direction(a1, a2, b1)*direction(a1, a2, b2) <= 0 &&
			direction(b1, b2, a1)*direction(b1, b2, a2) <= 0)
			return true;
		else return false;
	}
public:
	pp(int n, Point *a) throw(err) {
		if (n <= 2) {
			std::cout << "Not a poly with " << n << " sides. " << std::endl;
			throw err();
			return;
		}
		int i, j, k;
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				if (a[i].x == a[j].x && a[i].y == a[j].y) throw err();
			}
		}
		for (i = 2; i < n; i++) {
			for (j = 0; j < i - 2; j++) {
				if (check(a[j], a[j + 1], a[i - 1], a[i])) throw err();
				if (i == n - 1 && j != 0 && check(a[j], a[j + 1], a[0], a[i])) throw err();
			}
		}
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				for (k = j + 1; k < n; k++) {
					if ((a[i].x - a[k].x)*(a[j].y - a[k].y) == (a[j].x - a[k].x)*(a[i].y - a[k].y)) {
						throw err(); break;
					}
				}
		for (i = 0; i < n; i++) add(a[i]);
	}
};

int main() {
	Simple_window win(Point(100, 100), 500, 500, "Poly");
	int n, i;
	Point *a;
	Poly *p;
	while (true) {
		try {
			std::cin >> n;
			a = new Point[n];
			for (i = 0; i < n; i++) std::cin >> a[i].x >> a[i].y;
			p = new Poly(n, a);
			throw 1;
		}
		catch (err) { std::cout << "N again:"; delete[] a; }
		catch (int) { break; }
	}
	//win.attach((*p));
	p->show_in_window(win);
	win.wait_for_button();
	delete[] a; delete p;
}