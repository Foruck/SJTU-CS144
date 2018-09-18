#ifndef MY_DOCUMENT
#define MY_DOCUMENT
#include"std_lib_facilities.h"

//
// This is example code from Chapter 20.6.2 "Iteration" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

typedef vector<char> Line;    // a line is a vector of characters

class Text_iterator { // keep track of line and character position within a line
public:
	list<Line>::iterator ln;
	Line::iterator pos;
	int x;
	typedef forward_iterator_tag iterator_category;
	typedef char value_type;
	typedef size_t difference_type;
	typedef char* pointer;
	typedef char& reference;

	// start the iterator at line ll's character position pp:
	Text_iterator(list<Line>::iterator ll, Line::iterator pp)
		:ln(ll), pos(pp), x(0) { }

	char& operator*() { return *pos; }
	Text_iterator& get_line_end() const { return Text_iterator(ln, (*ln).end()); }
	Text_iterator& get_line_start() const { return Text_iterator(ln, (*ln).begin()); }
	Line& get_line() { return *ln; }

	Line::iterator &get_pos() { return pos; }
	Text_iterator& operator++();
	bool operator==(const Text_iterator& other) const;
	bool operator!=(const Text_iterator& other) const { return !(*this == other); }
};

struct Document {
	list<Line> line;
	Document() { line.push_back(Line()); }
	Text_iterator begin() { return Text_iterator(line.begin(), line.begin()->begin()); }
	Text_iterator end() {
		list<Line>::iterator last = line.end();
		--last;
		return Text_iterator(last, last->end());
	}
	friend istream& operator>>(istream& is, Document& d);
	friend ostream& operator<<(ostream& os, Document& d);
};

template<class Iter> Iter advance(Iter p, int n) {
	while (n>0) { ++p; --n; }    // go forwards
	return p;
}

void erase_line(Document& d, int n);
//------------------------------------------------------------------------------

bool match(Text_iterator first, Text_iterator last, const string& s);

//------------------------------------------------------------------------------

Text_iterator find__(Text_iterator first, Text_iterator last, const char& c);

Text_iterator find_text(Text_iterator first, Text_iterator last, const string& s);

bool replace_text(Text_iterator first, Text_iterator last, const string& s, const string& rs);

//bool replace_lines(Text_iterator first, Text_iterator last, const string& s, const string& rs);

#endif //  MY_DOCUMENT
