#include "Graph.h"
#include "Simple_window.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace Graph_lib;

class star {
private:
	Polygon s;
public:
	star(Point cen, int num, int r) {
		double delta = 3.1415926 / num;
		int i, l; double deg = 0;
		for (i = 0; i < 2 * num; i++) {
			if (i % 2 == 0) l = r / 2;
			else l = r;
			s.add(Point(cen.x + cos(deg)*l, cen.y + sin(deg)*l));
			deg += delta;
		}
	}
	void set_color(Color c) {
		s.set_color(c);
	}
	void set_fillcolor(Color c) { s.set_fill_color(c); }
	void show_in(Simple_window &win) { win.attach(s); }
};


void draw_stars(Simple_window &win, int num) {
	if (num == 0) return;
	Color vec[8]{ Color::red,Color::blue,Color::green,Color::yellow,Color::white,Color::black,Color::magenta,Color::cyan };
	star *x;
	x = new star(Point(rand() % win.x_max(), rand() % win.y_max()), rand() % 10 + 4, rand() % 50 + 50);
	x->set_color(vec[rand() % 8]);
	x->set_fillcolor(vec[rand() % 8]);
	x->show_in(win);
	draw_stars(win, num - 1);
	return;
}

int main() {
	srand(time(NULL));
	Simple_window win(Point(100, 100), 500, 500, "Star");
	draw_stars(win,rand()%30);
	win.wait_for_button();

}