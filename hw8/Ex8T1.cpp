#include "Graph.h"
#include "Simple_Window.h"
int main() {
	using namespace Graph_lib;
	Point tl(100, 100);
	Simple_window win(tl, 800, 500, "Canvas");
	
	Rectangle r1(Point(300, 0), Point(400, 30));
	Text t1(Point(300, 20), "FLTK headers");
	Line l2(Point(350, 110), Point(400, 30)), l1(Point(500, 110), Point(400, 30)),l3(Point(100,170),Point(300,30)),l4(Point(700,170),Point(400,0));
	win.attach(l1); win.attach(l2); win.attach(l3); win.attach(l4);

	Rectangle r2(Point(500, 110), Point(600, 140));
	Text t2(Point(500, 130), "FLTK code");

	Text t3(Point(0, 110), "Point.h:");
	Rectangle r3(Point(0, 110), Point(150, 140));
	Text t4(Point(0, 130), "struct Point{...}");
	Line l5(Point(250, 160), Point(75, 140)),l6(Point(100,170),Point(75,140));
	win.attach(l5); win.attach(l6);

	Text t5(Point(250, 110), "Window.h:");
	Rectangle r4(Point(250, 110), Point(450, 160));
	Text t6(Point(250, 130), "//window interface:");
	Text t6_(Point(250, 150), "class Window{...};...");
	Line l7(Point(350,180), Point(350,160)),l8(Point(400,250),Point(450,160)),l9(Point(500,170),Point(450,160));
	win.attach(l7); win.attach(l8); win.attach(l9);

	Text t7(Point(0, 170), "Graph.h:");
	Rectangle r5(Point(0, 170), Point(200, 220));
	Text t8(Point(0, 190), "//graphing interface:");
	Text t8_(Point(0, 210), "class Graph{...};...");
	Line l12(Point(50, 250), Point(100, 220)),l13(Point(200,370),Point(100,220));
	win.attach(l12); win.attach(l13);

	Text t9(Point(500, 170), "GUI.h:");
	Rectangle r6(Point(500, 170), Point(700, 220));
	Text t10(Point(500, 190), "//GUI interface:");
	Text t10_(Point(500, 210), "struct in_box{...};...");
	Line l10(Point(400, 250), Point(500, 220)),l11(Point(560,280),Point(600,220));
	win.attach(l10); win.attach(l11);

	Text t11(Point(300, 180), "Window.cpp:");
	Rectangle r7(Point(300, 180), Point(400, 210));
	Text t12(Point(300, 200), "Window code");

	Text t13(Point(500, 280), "GUI.cpp:");
	Rectangle r8(Point(500, 280), Point(620, 310));
	Text t14(Point(500, 300), "GUI code");

	Text t15(Point(0, 250), "Graph.cpp:");
	Rectangle r9(Point(0, 250), Point(100, 280));
	Text t16(Point(0, 270), "Graph code");

	Text t17(Point(200, 250), "Simple_Window:");
	Rectangle r10(Point(200, 250), Point(400, 300));
	Text t18(Point(200, 270), "//Window interference;");
	Text t18_(Point(200, 290), "class Simple_Window{...};...");
	Line l(Point(300,370), Point(300,300));
	win.attach(l);

	Text t19(Point(200, 370), "chapter12.cpp:");
	Rectangle r11(Point(200, 370), Point(400, 470));
	Text t20(Point(200, 390), "#include \"Graph.h\";");
	Text t21(Point(200, 410), "#include \"Simple_window.h\";");
	Text t22(Point(200, 430), "int main(){...}");


	win.attach(r1);win.attach(r2);win.attach(r3); win.attach(r4); win.attach(r5);
	win.attach(r6); win.attach(r7);win.attach(r8); win.attach(r9); win.attach(r10); win.attach(r11);

	win.attach(t1);win.attach(t2); win.attach(t3); win.attach(t4); win.attach(t5);
	win.attach(t6);win.attach(t6_);
	win.attach(t7);win.attach(t8);win.attach(t8_);
	win.attach(t9); win.attach(t10); win.attach(t10_);
	win.attach(t11); win.attach(t12); win.attach(t13); win.attach(t14); win.attach(t15);
	win.attach(t16); win.attach(t17); win.attach(t18); win.attach(t18_);
	win.attach(t19); win.attach(t20);
	win.attach(t21); win.attach(t22);

	win.wait_for_button();
}












	
