#include "my_document.h"

Text_iterator& Text_iterator::operator++() {
	if (pos == (*ln).end()) {
		++ln;            // proceed to next line
		pos = (*ln).begin();
	}
	else ++pos;                // proceed to next character
	return *this;
}

bool Text_iterator::operator==(const Text_iterator& other) const
{
	return ln == other.ln && pos == other.pos;
}

ostream& operator<<(ostream& os, Document& d) {
	Text_iterator p = d.begin();
	while (p != d.end()) {
		if (p.pos == p.ln->end()) { p.ln++; p.pos = p.ln->begin(); continue; }
		os << *p.pos;
		p.pos++;
	}
	return os;
}

istream& operator>>(istream& is, Document& d) {
	Line v;
	char c;
	while (d.line.size() != 0) d.line.pop_back();
	d.line.push_back(v);
	while (is.get(c)) {
		if (c == '#') break;
		v.push_back(c);
		if (c == '\n') {
			d.line.push_back(v);
			v = Line();
		}
	}
	return is;
}

void erase_line(Document& d, int n) {
	if (n<0 || d.line.size() <= n) return;    // ignore out-of-range lines
	d.line.erase(advance(d.line.begin(), n));
}

bool match(Text_iterator first, Text_iterator last, const string& s) {
	string::const_iterator p;

	for (p = s.begin();
		p != s.end() && first != last && *p == *first;
		++p, ++first) {
	}

	return p == s.end(); // if we reached end of string, we matched it all
}

Text_iterator find__(Text_iterator first, Text_iterator last, const char& c) {
	while (first != last) {
		if (first.pos == first.ln->end()) { first.ln++; first.pos = first.ln->begin(); continue; }
		if (*first == c) return first;
		first.pos++;
	}
	return last;
}

Text_iterator find_text(Text_iterator first, Text_iterator last, const string& s) {
	if (s.size() == 0) return last;    // can't find an empty string
	char first_char = s[0];
	while (true) {
		Text_iterator p = find__(first, last, first_char);
		if (p == last || match(p, last, s)) return p;
		first = (++p);
	}
}

bool replace_text(Text_iterator first, Text_iterator last, const string& s, const string& rs) {
	Text_iterator p = find_text(first, last, s);
	if (p == last) return false;
	int j = 0;
	Line tmp, &con = p.get_line();
	for (j = 0; j < s.size(); j++) p.pos++;
	while (p.pos != p.ln->end()) {
		tmp.push_back(*p);
		p.pos++;
	}
	for (j = 0; j < tmp.size() + s.size(); ++j) con.pop_back();
	for (j = 0; j < rs.size(); j++) con.push_back(rs[j]);
	for (j = 0; j < tmp.size(); j++) con.push_back(tmp[j]);
	return true;
}

/*
bool replace_lines(Text_iterator first, Text_iterator last, const string& s, const string& rs) {
	Text_iterator p = find_text(first, last, s);
	if (p == last) return false;
	int j, k;
	Line tmp;
	vector<Line*> con;
	vector<int> a;
	for (j = 0; j < s.size(); j++) p.pos++;
	con.push_back(&(*p.ln)); a.push_back(0);
	while (p.pos != p.ln->end()) {
		p.pos++; a[con.size() - 1]++;
		if (p.pos == p.ln->end()) {
			p.ln++; p.pos = p.ln->begin();
			a[con.size() - 1]--;
			con.push_back(&(*p.ln));
			a.push_back(0);
			a[con.size() - 1]++;
		}
	}
	for (j = 0; j < con.size() - 1; j++)
		for (k = 0; k < a[j]; k++)
			if (j != con.size() - 1) con[j]->pop_back();

	k = con.size() - 1;
	for (j = a[k]; j < con[k]->size(); j++) tmp.push_back((*con[k])[j]);
	*con[k] = tmp;
	for (j = 0; j < rs.size(); j++) con[0]->push_back(rs[j]);
	return true;
}
*/