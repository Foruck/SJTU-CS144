#include "Simple_Window.h"
#include "Graph.h"
#include <cstdlib>
#include <ctime>
using namespace Graph_lib;
class hexagon {
private:
	Polygon hexa;
public:
	hexagon(Point p, double r) {
		hexa.add(Point(p.x + r / 2, p.y + r*0.866));
		hexa.add(Point(p.x - r / 2, p.y + r*0.866));
		hexa.add(Point(p.x - r, p.y));
		hexa.add(Point(p.x - r / 2, p.y - r*0.866));
		hexa.add(Point(p.x + r / 2, p.y - r*0.866));
		hexa.add(Point(p.x + r, p.y));
	}
	void show_in(Simple_window &win) {
		win.attach(hexa);
		return;
	}

	void set_color(Color c) {
		hexa.set_color(c);
		return;
	}

	void set_fill_color(Color c) {
		hexa.set_fill_color(c);
		return;
	}
};

Color vec[8]{ Color::red,Color::blue,Color::green,Color::yellow,Color::white,Color::black,Color::magenta,Color::cyan };
void fill_with_hexagon_ul(Simple_window &win,int x,int y,int r) {
	if (x-0.866*r > win.x_max() || y-0.866*r > win.y_max() || x < 0 || y < 0 ) return;
	hexagon *h;
	h = new hexagon(Point(x, y), r);
	h->set_fill_color(vec[rand()%8]);
	h->show_in(win);

	fill_with_hexagon_ul(win, x, y + r*1.732, r);
	fill_with_hexagon_ul(win, x + 1.5*r, y + r*0.866, r);
}

void fill_with_hexagon_ur(Simple_window &win, int x, int y, int r) {

	if (x - 0.866*r > win.x_max() || y - 0.866*r > win.y_max() || x < 0 || y < 0 ) return;
	hexagon *h;
	h = new hexagon(Point(x, y), r);
	h->set_color(vec[rand() % 8]);
	h->set_fill_color(vec[rand() % 8]);
	h->show_in(win);

	fill_with_hexagon_ur(win, x, y + r*1.732, r);
	fill_with_hexagon_ur(win, x - 1.5*r, y + r*0.866, r);
	fill_with_hexagon_ur(win, x - 1.5*r, y - r*0.866, r);
}


int main() {
	srand(time(NULL));
	Simple_window win(Point(100, 100), 500, 500, "Hexagon");
	hexagon h(Point(100, 100), 100);
	//h.show_in(win);
	//fill_with_hexagon_ul(win, 0, 0, 100);
	fill_with_hexagon_ur(win, 500, 0, 100);
	win.wait_for_button();
	
	return 0;
}