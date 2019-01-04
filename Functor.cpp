//
//  Functor.cpp
//  cpp_study
//
//  Created by 형성모 on 03/01/2019.
//
//  ()연산자 오버로딩과 '펑터(Functor)'에 대해 공부했습니다.
//  펑터 또는 함수오브젝트는 함수처럼 동작하는 클래스를 말합니다.
//

#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) {}
    Point(const Point& cpy) : xpos(cpy.xpos), ypos(cpy.ypos) {}
    Point operator+(const Point &ptr1) const
    {
        return Point(xpos+ptr1.xpos, ypos+ptr1.ypos);
    }
    friend ostream& operator<<(ostream& os, Point& ptr1);
    ~Point() {}
};

ostream& operator<<(ostream& os, Point& ptr1)
{
    os<<"["<<ptr1.xpos<<", "<<ptr1.ypos<<"]"<<endl;
    return os;
}

class Adder
{
public:
    int operator()(const int& num1, const int& num2)
    {
        return num1+num2;
    }
    double operator()(const double& db1, const double& db2)
    {
        return db1+db2;
    }
    Point operator()(const Point& ptr1, const Point& ptr2)
    {
        return ptr1+ptr2;
    }
};

int main(void)
{
    Adder adder;
    cout<<adder(2, 3)<<endl;
    cout<<adder(2.3, 3.6)<<endl;
    Point add = adder(Point(2, 3), Point(3, 7));
    cout<<add<<endl;
    return 0;
}
