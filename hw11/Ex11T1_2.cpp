#include "Binary.h"
Binary_tree::Binary_tree(int x) :n(x), line_color(fl_color()), node_color(fl_color()), line_style(0), font_size(fl_size()), font_(fl_font()), font_color(fl_color()), r(20) {
	if (n < 0) throw err();

	with_arrow = false;
	int i, dx, dy, t = 0;
	tot = 2;
	for (i = 0; i < n; i++) tot *= 2; tot--;
	dy = 600 / (n + 1); dx = 1000 / (tot - 1);
	for (i = 0; i <= tot; i++) {
		p.push_back(Point());
		s.push_back("");
		time.push_back(0);
	}
	dfs(tot, time, 1, t);
	p[1].y = 2 * r;
	s[1].push_back('r');

	for (i = 1; i <= tot; i++) {
		p[i].x = time[i] * dx;

		if (2 * i <= tot) {
			s[2 * i] = s[i] + '0';
			p[2 * i].y = p[i].y + dy;
		}
		if (2 * i + 1 <= tot) {
			s[2 * i + 1] = s[i] + '1';
			p[2 * i + 1].y = p[i].y + dy;
		}
	}
}
void Binary_tree::draw_lines() const
{
	if (line_color.visibility() && node_color.visibility()) {
		int i;
		
		Fl_Color oldc = fl_color();// there is no good portable way of retrieving the current style
		fl_color(node_color.as_int());            // set color

		for (i = 1; i <= tot; i++) {
			fl_arc(p[i].x - r, p[i].y, 2 * r, 2 * r, 0, 360);
		}

		fl_color(font_color.as_int());            // set color
		int ofnt = fl_font();
		int osz = fl_size();
		fl_font(font_.as_int(), font_size);

		for (i = 1; i <= tot; i++) {
			fl_draw(s[i].c_str(), p[i].x, p[i].y);
		}

		fl_font(ofnt, osz); fl_color(oldc);      // reset color (to previous)

		oldc = fl_color(); fl_color(line_color.as_int());// set color
		fl_line_style(line_style.style(), line_style.width()); // set style

		for (i = 1; i <= tot / 2; i++) {
			if (with_arrow) {
				fl_line(p[2 * i].x, p[2 * i].y - r, p[2 * i].x, p[2 * i].y - r - 10);
				fl_line(p[2 * i + 1].x, p[2 * i + 1].y - r, p[2 * i + 1].x, p[2 * i + 1].y - r - 10);
				fl_line(p[2 * i + 1].x, p[2 * i + 1].y - r, p[2 * i + 1].x - 10, p[2 * i + 1].y - r);
				fl_line(p[2 * i].x, p[2 * i].y - r, p[2 * i].x + 10, p[2 * i].y - r);
			}
			fl_line(p[i].x, p[i].y + 2 * r, p[2 * i].x, p[2 * i].y);
			fl_line(p[i].x, p[i].y + 2 * r, p[2 * i + 1].x, p[2 * i + 1].y);
		}

		fl_color(oldc); fl_line_style(0);    // reset line style to default

	}
}
void Tri_bi::draw_lines() const {
	int i;
	if (line_color.visibility() && node_color.visibility() && n >= 0) {
		Fl_Color oldc = fl_color();// there is no good portable way of retrieving the current style
		fl_color(node_color.as_int());            // set color

		for (i = 1; i <= tot; i++) {
			fl_line(p[i].x, p[i].y - r, p[i].x - r / 2, p[i].y + r);
			fl_line(p[i].x, p[i].y - r, p[i].x + r / 2, p[i].y + r);
			fl_line(p[i].x - r / 2, p[i].y + r, p[i].x + r / 2, p[i].y + r);
		}

		fl_color(font_color.as_int());            // set color
		int ofnt = fl_font();
		int osz = fl_size();
		fl_font(font_.as_int(), font_size);

		for (i = 1; i <= tot; i++) {
			fl_draw(s[i].c_str(), p[i].x, p[i].y-r);
		}

		fl_font(ofnt, osz);
		fl_color(oldc);      // reset color (to previous)

		oldc = fl_color();// there is no good portable way of retrieving the current style
		fl_color(line_color.as_int());            // set color
		fl_line_style(line_style.style(), line_style.width()); // set style
		for (i = 1; i <= tot / 2; i++) {
			if (with_arrow) {
				fl_line(p[2 * i].x, p[2 * i].y - r, p[2 * i].x, p[2 * i].y - r - 10);
				fl_line(p[2 * i + 1].x, p[2 * i + 1].y - r, p[2 * i + 1].x, p[2 * i + 1].y - r - 10);
				fl_line(p[2 * i + 1].x, p[2 * i + 1].y - r, p[2 * i + 1].x - 10, p[2 * i + 1].y - r);
				fl_line(p[2 * i].x, p[2 * i].y - r, p[2 * i].x + 10, p[2 * i].y - r);
			}
			fl_line(p[i].x, p[i].y + r, p[2 * i].x, p[2 * i].y - r);
			fl_line(p[i].x, p[i].y + r, p[2 * i + 1].x, p[2 * i + 1].y - r);
		}
		fl_color(oldc);      // reset color (to previous)
		fl_line_style(0);    // reset line style to default
	}
}
void Binary_tree::dfs(int tot, vector<int> &t, int dep, int &x) const {
	if (dep > tot) return;
	dfs(tot, t, dep * 2, x);
	t[dep] = x; x++;
	dfs(tot, t, dep * 2 + 1, x);
}