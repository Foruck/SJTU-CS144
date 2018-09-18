#include "Binary.h"
int main() {
	Simple_window win(Point(100, 100), 1000, 600, "Binary Tree");
	Simple_window winc(Point(100, 100), 1000, 600, "Triangle Binary");
	int n, r, s;
	Binary_tree *b;
	Tri_bi *c;

	while (std::cin >> n) {
		try {
			b = new Binary_tree(n);
			c = new Tri_bi(n);
			throw 2;
		}
		catch (err) { std::cout << "Invalid input. Again:"; }
		catch (int) { break; }
	}

	std::cout << "s,r\n";
	while (std::cin >> s >> r) {
		if (s <= 0 || r <= 0) {
			std::cout << "Invalid input. Again:";
			continue;
		}
		b->set_font_size(s);
		b->set_radius(r);
		//c->set_font_size(s);
		c->set_radius(r);
		break;
	}

	b->set_line_color(Color::blue);
	b->set_node_color(Color::red);
	b->set_line_style(Line_style::dashdotdot);
	b->set_font_color(Color::dark_yellow);

	c->set_line_color(Color::magenta);
	c->set_node_color(Color::dark_cyan);
	c->set_arrow(true);
	//c->set_line_style(Line_style::dashdot);
	c->set_font_size(12);
	//c->set_font_size(Font::courier_italic);

	win.attach(*b);
	winc.attach(*c);
	win.wait_for_button(); winc.wait_for_button();
	delete[] b; delete[] c;
	return 0;
}