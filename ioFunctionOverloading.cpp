//
//  ioFunctionOverloading.cpp
//  cpp_study
//
//  Created by 형성모 on 31/12/2018.
//
//  'cout<<객체', 'cin>>객체' 문맥이 가능하도록,
//  namespace std안에 있는 cout클래스의 <<, >>함수에 대해 전역변수형태로 함수오버로딩을 구현해보았습니다.
//

#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x, int y) :xpos(x), ypos(y) {}
    Point() :xpos(0), ypos(0) {}

    friend ostream& operator<<(ostream&, const Point &pnt);
    friend istream& operator>>(istream&, Point &pnt);
};

ostream& operator<<(ostream& os, const Point &pnt)
{
    os<<'['<<pnt.xpos<<','<<' '<<pnt.ypos<<']'<<endl;
    return os;
}
istream& operator>>(istream& is, Point &pnt)
{
    is>>pnt.xpos>>pnt.ypos;
    return is;
}

int main(void)
{
    Point pnt1;
    cout<<"X좌표, Y좌표 : "; cin>>pnt1;
    
    Point pnt2(10, 20);
    
    cout<<pnt1<<pnt2;
    
    return 0;
}
