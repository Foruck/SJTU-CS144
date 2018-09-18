#include "my_document.h"

int main(){
	Document my_doc;
	Line l;
	bool b = true;
	
	cin >> my_doc;
	cout << my_doc;
	system("pause");

	Text_iterator p = find_text(my_doc.begin(), my_doc.end(), "LINE");
	if (p == my_doc.end()) cout << "not found" << endl;
	else {
		b = replace_text(my_doc.begin(), my_doc.end(), "LINE", "line");
		//if (b) b = replace_text(my_doc.begin(), my_doc.end(), "12", "3");

	}

	cout << my_doc;

	system("pause");
}

//------------------------------------------------------------------------------
