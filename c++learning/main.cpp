#include <iostream>
using namespace std;

class Date{
    public:
    int year;
    int month;
    int day;
    Date(int y, int m, int d): year(y), month(m), day(d) {};
};

class Person{
    public:
    string name;
    Date date;
    Person(string n_in, Date d_in): name(n_in), date(d_in) {};
};

int main(){
    int a, b, c;
    string d;
    cout << "请输入年月日姓名" <<endl;
    cin >> a >> b >> c >> d;
    Date u(a, b, c);
    Person person_tom(d, u);

    cout << person_tom.date.year << ' ' << person_tom.date.month << ' ' << person_tom.date.day << ' ' << person_tom.name;

    return 0;
}