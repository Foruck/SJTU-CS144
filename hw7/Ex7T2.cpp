#include <iostream>
#include <cstring>
#include "String.h"
#include <sstream>
using namespace std;

class Date{
public:
    int day; /* 1 .. 31 */
    int month; /* 1 .. 12 */
    int year; /* YYYY */
};
struct Person{
    String name,first;
    Date birth;
};
struct List{
    Person *data;
    List *next;
    List(){next=NULL;}
};
/* -- read on input record and return success/error -- */
bool getrecord(String &nbuf, String &fbuf, int &y, int &m, int &d) {
    bool b=true;
    string s;
    b=b && (cin>>nbuf) && (cin>>fbuf)&&(cin>>s);
    for (int i=0;i<s.size();i++) if (s[i]=='.') s[i]=' ';
    stringstream ss;
    ss<<s;
    b=b && (ss>>y) && (ss>>m) && (ss>>d);
    return b;
}

int main() {
    String nbuf,fbuf;
    int y, m, d;
    List* first = NULL;
    List* curr = NULL;
    List* last = NULL;
    List* add = NULL;
    Person *p, *old;
    /* -- read persons from stdin -- */
    while ( getrecord(nbuf, fbuf, y, m, d) ) {
        /* -- construct new person record -- */
        add = new List;
        add->data = p = new Person;
        add->next = 0;
        p->name=nbuf;
        p->first=fbuf;
        p->birth.year = y;
        p->birth.month = m;
        p->birth.day = d;
        /* -- add to list (and sort them already at insertion time) -- */
        if ( first==NULL ) {
            /* -- first record -- */
            first = add;
        }
        else {
            /* -- there are already records -- */
            curr = first;
            last = NULL;
            while (curr!=NULL) {
                old = curr->data;
                if (p->name<old->name || ((p->name==old->name) && (p->first<old->name<= 0))) {
                    break;
                }
                last = curr;
                curr = curr->next;
            }
            /* -- insert at right place -- */
            add->next = curr;
            if (last!=NULL) {
                last->next = add;
            }
            else {
                first = add;
            }
        }
    }
    /* -- print out sorted list and delete list -- */
    curr = first;
    while ( curr!=NULL ) {
        p = curr->data;
        cout<<p->name<<' '<<p->first<<' '<<p->birth.year<< '.'<<p->birth.month<<'.'<<p->birth.day<<endl;
        last = curr;
        curr = curr->next;
        delete p;
        delete last;
    }
    return 0;
}
