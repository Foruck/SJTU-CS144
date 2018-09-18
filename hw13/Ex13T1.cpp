#include "Window.h"
#include "Simple_window.h"
#include <cstring>
struct test: Window {
private:
	Rectangle *rr[25],r1,r2,*r;
	Button next_button;
	Button quit_button;
	int tot, cur;
	vector<int *> v;
	Text t;
	int c[5][5];
	void next();
	void quit();
	static void cb_next(Address, Address);
	static void cb_quit(Address, Address);
	void dfs(int now);
	int* rotate(int *q) {
		int *ans = new int[25];
		int i, j, count = 0;
		for (i = 0; i < 5; i++)
			for (j = 0; j < 5; j++)
				c[i][j] = q[i * 5 + j];
		for (i=4;i>=0;i--)
			for (j = 0; j < 5; j++) {
				ans[count] = c[j][i];
				count++;
			}
		return ans;
	}
public:
	test(Point xy, int w, int h, const string& title): Window(xy, w, h, title),
		next_button(Point(x_max() - 200, 550), 70, 20, "Next", cb_next),
		quit_button(Point(x_max() - 100, 550), 70, 20, "Quit", cb_quit),
		r1(Point(0, 0), Point(500, 500)),
		r2(Point(510, 0), Point(800, 500)),
		tot(0), cur(0),t(Point(x_max() - 400, 550),"No more solutions!") {
		int i,j;
		for (i = 0; i < 5; i++)
			for (j = 0; j < 5; j++)
				c[i][j] = 0;
		r2.set_fill_color(Color::white);
		r1.set_fill_color(Color::white);
		attach(r2);
		attach(r1);
		
		r = new Rectangle(Point(50, 50), Point(100, 100));
		r->set_fill_color(Color::green);
		attach(*r);
		r = new Rectangle(Point(50, 100), Point(100, 150));
		r->set_fill_color(Color::green);
		attach(*r);
		r = new Rectangle(Point(50, 150), Point(100, 200));
		r->set_fill_color(Color::green);
		attach(*r);
		r = new Rectangle(Point(100, 150), Point(150, 200));
		r->set_fill_color(Color::green);
		attach(*r);
		r = new Rectangle(Point(150, 150), Point(200, 200));
		r->set_fill_color(Color::green);
		attach(*r);


		r = new Rectangle(Point(200, 0), Point(250, 50));
		r->set_fill_color(Color::red);
		attach(*r);
		r = new Rectangle(Point(250, 0), Point(300, 50));
		r->set_fill_color(Color::red);
		attach(*r);
		r = new Rectangle(Point(200, 50), Point(250, 100));
		r->set_fill_color(Color::red);
		attach(*r);
		r = new Rectangle(Point(250, 50), Point(300, 100));
		r->set_fill_color(Color::red);
		attach(*r);

		r = new Rectangle(Point(350, 0), Point(400, 50));
		r->set_fill_color(Color::yellow);
		attach(*r);
		r = new Rectangle(Point(350, 50), Point(400, 100));
		r->set_fill_color(Color::yellow);
		attach(*r);
		r = new Rectangle(Point(400, 50), Point(450, 100));
		r->set_fill_color(Color::yellow);
		attach(*r);
		r = new Rectangle(Point(400, 100), Point(450, 150));
		r->set_fill_color(Color::yellow);
		attach(*r);
		r = new Rectangle(Point(400, 150), Point(450, 200));
		r->set_fill_color(Color::yellow);
		attach(*r);

		r = new Rectangle(Point(100, 250), Point(150, 300));
		r->set_fill_color(Color::magenta);
		attach(*r);
		r = new Rectangle(Point(150, 250), Point(200, 300));
		r->set_fill_color(Color::magenta);
		attach(*r);
		r = new Rectangle(Point(150, 300), Point(200, 350));
		r->set_fill_color(Color::magenta);
		attach(*r);
		r = new Rectangle(Point(150, 350), Point(200, 400));
		r->set_fill_color(Color::magenta);
		attach(*r);
		r = new Rectangle(Point(150, 400), Point(200, 450));
		r->set_fill_color(Color::magenta);
		attach(*r);

		r = new Rectangle(Point(300, 250), Point(350, 300));
		r->set_fill_color(Color::blue);
		attach(*r);
		r = new Rectangle(Point(350, 250), Point(400, 300));
		r->set_fill_color(Color::blue);
		attach(*r);
		r = new Rectangle(Point(350, 300), Point(400, 350));
		r->set_fill_color(Color::blue);
		attach(*r);
		r = new Rectangle(Point(350, 350), Point(400, 400));
		r->set_fill_color(Color::blue);
		attach(*r);
		r = new Rectangle(Point(350, 400), Point(400, 450));
		r->set_fill_color(Color::blue);
		attach(*r);
		r = new Rectangle(Point(350, 450), Point(400, 500));
		r->set_fill_color(Color::blue);
		attach(*r);
		for (i = 0; i<5; i++)
			for (j = 0; j < 5; j++) {
				rr[i * 5 + j] = new Rectangle(Point(520 + i * 50, 50 + j * 50), Point(570 + i * 50, j * 50 + 100));
				rr[i * 5 + j]->set_fill_color(Color::white);
				attach(*rr[i * 5 + j]);
			}

		attach(next_button);
		attach(quit_button);
		dfs(1);
		int sign = tot;
		for (i = 0; i < sign; i++) {
			v.push_back(rotate(v[i]));
			v.push_back(rotate(v[v.size() - 1]));
			v.push_back(rotate(v[v.size() - 1]));
		}
		tot = v.size();
		show();
	}
	void show() {
		int i, j, k;
		cout << tot << endl;
		for (i = 0; i < tot; i++) {
			for (j = 0; j < 5; j++) {
				for (k = 0; k < 5; k++)
					cout << v[i][j * 5 + k];
				cout << endl;
			}
			cout << endl;
		}
	}
};

void test::dfs(int now) {
	bool b = true;
	int i, j;

	if (now>5) {
		tot++;
		v.push_back(new int[25]);
		for (i = 0; i < 5; i++) 
			for (j = 0; j < 5; j++) 
				v[tot-1][i * 5 + j] = c[i][j];
		return;
	}
	switch (now) {
	case 1:
		if (!c[0][0] && !c[1][0] && !c[0][1] && !c[0][2] && !c[0][3] && !c[0][4]) {
			c[0][0] = 5; c[1][0] = 5; c[0][1] = 5; c[0][2] = 5; c[0][3] = 5; c[0][4] = 5;
			dfs(now + 1);
			c[0][0] = 0; c[1][0] = 0; c[0][1] = 0; c[0][2] = 0; c[0][3] = 0; c[0][4] = 0;
		}
		break;
	case 2:
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++) {
				if (!c[i][j] && !c[i + 1][j + 1] && !c[i][j + 1] && !c[i + 1][j]) {
					c[i][j] = 2; c[i + 1][j + 1] = 2; c[i + 1][j] = 2; c[i][j + 1] = 2;
					dfs(now + 1);
					c[i][j] = 0; c[i + 1][j + 1] = 0; c[i + 1][j] = 0; c[i][j + 1] = 0;
				}
			}
		break;
	case 3:
		for (i = 0; i < 2; i++)
			for (j = 0; j < 4; j++) {
				if (!c[i][j] && !c[i + 1][j] && !c[i + 1][j + 1] && !c[i + 2][j + 1] && !c[i + 3][j + 1]) {
					c[i][j] = 3; c[i + 1][j] = 3; c[i + 1][j + 1] = 3; c[i + 2][j + 1] = 3; c[i + 3][j + 1] = 3;
					dfs(now + 1);
					c[i][j] = 0; c[i + 1][j] = 0; c[i + 1][j + 1] = 0; c[i + 2][j + 1] = 0; c[i + 3][j + 1] = 0;
				}

				if (!c[i][j] && !c[i + 1][j] && !c[i + 2][j] && !c[i + 2][j + 1] && !c[i + 3][j + 1]) {
					c[i][j] = 3; c[i + 1][j] = 3; c[i + 2][j] = 3; c[i + 2][j + 1] = 3; c[i + 3][j + 1] = 3;
					dfs(now + 1);
					c[i][j] = 0; c[i + 1][j] = 0; c[i + 2][j] = 0; c[i + 2][j + 1] = 0; c[i + 3][j + 1] = 0;
				}

				if (!c[j + 1][i] && !c[j + 1][i + 1] && !c[j][i + 1] && !c[j][i + 2] && !c[j][i + 3]) {
					c[j + 1][i] = 3; c[j][i + 1] = 3; c[j + 1][i + 1] = 3; c[j][i + 2] = 3; c[j][i + 3] = 3;
					dfs(now + 1);
					c[j + 1][i] = 0; c[j][i + 1] = 0; c[j + 1][i + 1] = 0; c[j][i + 2] = 0; c[j][i + 3] = 0;
				}

				if (!c[j + 1][i] && !c[j + 1][i + 1] && !c[j + 1][i + 2] && !c[j][i + 2] && !c[j][i + 3]) {
					c[j + 1][i] = 3; c[j + 1][i + 2] = 3; c[j + 1][i + 1] = 3; c[j][i + 2] = 3; c[j][i + 3] = 3;
					dfs(now + 1);
					c[j + 1][i] = 0; c[j + 1][i + 2] = 0; c[j + 1][i + 1] = 0; c[j][i + 2] = 0; c[j][i + 3] = 0;
				}

			}
		break;
	case 4:
		for (i = 0; i < 2; i++)
			for (j = 0; j < 4; j++) {
				if (!c[i][j] && !c[i][j + 1] && !c[i + 1][j + 1] && !c[i + 2][j + 1] && !c[i + 3][j + 1]) {
					c[i][j] = 4; c[i][j + 1] = 4; c[i + 1][j + 1] = 4; c[i + 2][j + 1] = 4; c[i + 3][j + 1] = 4;
					dfs(now + 1);
					c[i][j] = 0; c[i][j + 1] = 0; c[i + 1][j + 1] = 0; c[i + 2][j + 1] = 0; c[i + 3][j + 1] = 0;
				}

				if (!c[i][j] && !c[i + 1][j] && !c[i + 2][j] && !c[i + 3][j] && !c[i + 3][j + 1]) {
					c[i][j] = 4; c[i + 1][j] = 4; c[i + 2][j] = 4; c[i + 3][j] = 4; c[i + 3][j + 1] = 4;
					dfs(now + 1);
					c[i][j] = 0; c[i + 1][j] = 0; c[i + 2][j] = 0; c[i + 3][j] = 0; c[i + 3][j + 1] = 0;
				}

				if (!c[j][i] && !c[j][i + 1] && !c[j][i + 2] && !c[j][i + 3] && !c[j + 1][i]) {
					c[j][i] = 4; c[j][i + 1] = 4; c[j][i + 2] = 4; c[j][i + 3] = 4; c[j + 1][i] = 4;
					dfs(now + 1);
					c[j][i] = 0; c[j][i + 1] = 0; c[j][i + 2] = 0; c[j][i + 3] = 0; c[j + 1][i] = 0;
				}

				if (!c[j + 1][i] && !c[j + 1][i + 1] && !c[j + 1][i + 2] && !c[j + 1][i + 3] && !c[j][i + 3]) {
					c[j + 1][i] = 4; c[j + 1][i + 1] = 4; c[j + 1][i + 2] = 4; c[j + 1][i + 3] = 4; c[j][i + 3] = 4;
					dfs(now + 1);
					c[j + 1][i] = 0; c[j + 1][i + 1] = 0; c[j + 1][i + 2] = 0; c[j + 1][i + 3] = 0; c[j][i + 3] = 0;
				}
			}
		break;
	case 5:
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++) {
				if (!c[i][j] && !c[i + 1][j] && !c[i + 2][j] && !c[i + 2][j + 1] && !c[i + 2][j + 2]) {
					c[i][j] = 1; c[i + 1][j] = 1; c[i + 2][j] = 1; c[i + 2][j + 1] = 1; c[i + 2][j + 2] = 1;
					dfs(now + 1);
					c[i][j] = 0; c[i + 1][j] = 0; c[i + 2][j] = 0; c[i + 2][j + 1] = 0; c[i + 2][j + 2] = 0;
				}
				if (!c[i][j] && !c[i][j + 1] && !c[i][j + 2] && !c[i + 1][j + 2] && !c[i + 2][j + 2]) {
					c[i][j] = 1; c[i][j + 1] = 1; c[i][j + 2] = 1; c[i + 1][j + 2] = 1; c[i + 2][j + 2] = 1;
					dfs(now + 1);
					c[i][j] = 0; c[i][j + 1] = 0; c[i][j + 2] = 0; c[i + 1][j + 2] = 0; c[i + 2][j + 2] = 0;
				}
				if (!c[i + 2][j] && !c[i + 2][j + 1] && !c[i + 2][j + 2] && !c[i + 1][j + 2] && !c[i][j + 2]) {
					c[i + 2][j] = 1; c[i + 2][j + 1] = 1; c[i + 2][j + 2] = 1; c[i + 1][j + 2] = 1; c[i][j + 2] = 1;
					dfs(now + 1);
					c[i + 2][j] = 0; c[i + 2][j + 1] = 0; c[i + 2][j + 2] = 0; c[i + 1][j + 2] = 0; c[i][j + 2] = 0;
				}
				if (!c[i][j] && !c[i][j + 1] && !c[i][j + 2] && !c[i + 1][j] && !c[i + 2][j]) {
					c[i][j] = 1; c[i][j + 1] = 1; c[i][j + 2] = 1; c[i + 1][j] = 1; c[i + 2][j] = 1;
					dfs(now + 1);
					c[i][j] = 0; c[i][j + 1] = 0; c[i][j + 2] = 0; c[i + 1][j] = 0; c[i + 2][j] = 0;
				}
			}
	}
}

void test::cb_quit(Address, Address pw)    // "the usual"
{
	reference_to<test>(pw).quit();
}

//------------------------------------------------------------------------------

void test::quit()
{
	hide();        // curious FLTK idiom for delete window
}

//------------------------------------------------------------------------------

void test::cb_next(Address, Address pw)     // "the usual"
{
	reference_to<test>(pw).next();
}

//------------------------------------------------------------------------------

void test::next()
{
	Color vec[6]{ Color::black,Color::green,Color::red,Color::yellow,Color::magenta,Color::blue };
	int i, j;
	if (cur == tot + 2) {
		t.set_label("");
		cur = 0;
	}
	else if (cur == tot+1) {
		t.set_label("Start again?");
		cur++;
	}
	else if (cur == tot) {
		t.set_label("No more solutions!"); attach(t); cur++;
	}
	else {
		for (i=0;i<5;i++)
			for (j = 0; j < 5; j++) {
				rr[i * 5 + j]->set_fill_color(vec[v[cur][i * 5 + j]]);
			}
		cur++;
	}
	redraw();
}

int main() {
	int i,j;
	test win(Point(100, 100), 800, 600, "Square");
	return gui_main();
}