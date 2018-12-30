//
//  OutputFunctionOverloading.cpp
//  cpp_study
//
//  Created by 형성모 on 31/12/2018.
//
//  cout<<point(Point 객체) 이 문맥이 가능하도록,
//  namespace std안에 있는 cout클래스의 <<함수에 대해 전역변수형태로 함수오버로딩을 구현해보았습니다.
//

#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x, int y) :xpos(x), ypos(y) {}
    void ShowPosition() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
    friend ostream& operator<<(ostream&, const Point &pnt);
};

ostream& operator<<(ostream& os, const Point &pnt)
{
    os<<'['<<pnt.xpos<<','<<' '<<pnt.ypos<<']'<<endl;
    return os;
}

int main(void)
{
    Point pnt1(1, 2);
    cout<<pnt1;
    
    Point pnt2(10, 20);
    cout<<pnt2;
    
    cout<<pnt1<<pnt2;
    
    return 0;
}
