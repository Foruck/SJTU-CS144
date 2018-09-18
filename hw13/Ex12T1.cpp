#include "std_lib_facilities.h"
template <class T>
class number {
	friend istream& operator>>(istream &is, number &obj) {
		is >> obj.value;
		return is;
	}
	friend ostream& operator<<(ostream &os, const number &obj) {
		os << obj.value;
		return os;
	}
	
	friend number<double> operator%(const number<double> &x, const number<int> &y); 
	
private:
	T value;
public:
	number() = default;
	number(T x) :value(x) {}
	number operator+(const number &obj) {
		return number<T>(value + obj.value);
	}
	number operator-(const number &obj) {
		return number<T>(value - obj.value);
	}
	number operator*(const number &obj) {
		return number<T>(value * obj.value);
	}
	number operator/(const number &obj) {
		if (obj.value == 0) throw 2;
		return number<T>(value / obj.value);
	}
	number operator%(const number &obj) {
		if (obj.value == 0) throw 2;
		return number<T>(value - int(value / obj.value)*obj.value);
	}
	number operator/=(const number &obj) {
		if (obj.value == 0) throw 2;
		value /= obj.value;
		return *this;
	}
	/*number operator%=(const number &obj) {
		if (obj.value == 0) throw 2;
		value = value - int(value / obj.value)*obj.value;
		return *this;
	}*/
	number operator+=(const number &obj) {
		value += obj.value;
		return *this;
	}
	number operator*=(const number &obj) {
		value *= obj.value;
		return *this;
	}
	number operator-=(const number &obj) {
		value -= obj.value;
		return *this;
	}
	bool operator>(const number &obj) {
		return value > obj.value;
	}
	bool operator<(const number &obj) {
		return value < obj.value;
	}
	bool operator>=(const number &obj) {
		return value >= obj.value;
	}
	bool operator<=(const number &obj) {
		return value <= obj.value;
	}
	bool operator==(const number &obj) {
		return value == obj.value;
	}
	bool operator!=(const number &obj) {
		return value != obj.value;
	}

	number &operator=(const number &obj) {
		if (this == &obj) return *this;
		value = obj.value;
		return *this;
	}
	number &operator++() {
		value += 1;
		return *this;
	}
	number operator++(int x) {
		value += 1;
		return number<T>(value - 1);
	}
};
template <class T>
number<T> multi(vector<number<T>> &x, vector<number<T>> &y) {
	if (x.size() != y.size()) throw 'a';
	number<T> ans(0);
	for (int i = 0; i < x.size(); i++) {
		ans = (x[i] * y[i]) + ans;
	}
	return ans;
}


number<double> operator%(const number<double> &x, const number<int> &y) {
	if (y.value == 0) throw 2;
	return number<double>(x.value - y.value*int(x.value / y.value));
}

int main() {
	number<int> x(3),y;
	number<int> z;
	number<double> w;
	cin >> z>>w;
	try {
		cout << z%x << endl;
		cout << z / x << endl;
		cout << w%x << endl;
	}
	catch (int) { cout << "Divided by 0!!!" << endl; }

	vector<number<int>> p, q;
	int n, m, i;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> x;
		p.push_back(x);
	}
	for (i = 0; i < m; i++) {
		cin >> x;
		q.push_back(x);
	}
	try {
		cout << multi(p, q) << endl;
	}
	catch (char) { cout << "Different sizes!!"; }

	system("pause");
}