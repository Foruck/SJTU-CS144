#include "std_lib_facilities.h"
#include <algorithm>
void convert(list<int> &line, vector<double> &vec) {
	auto x = line.begin();
	for (; x != line.end(); x++) {
		vec.push_back(*x);
	}
	return;
}
void print(vector<double> &vec) {
	for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
}
void sort_print(vector<double> &vec) {
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
	return;
}
int main() {
	list<int> line;
	vector<double> vec;
	int x;
	while (cin >> x)  line.push_back(x); 
	convert(line, vec);
	print(vec);
	cout << endl;
	sort_print(vec);
	system("pause");
	return 0;
}