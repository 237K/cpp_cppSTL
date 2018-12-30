//
//  FuctionOverloading3.cpp
//  cpp_study
//
//  Created by 형성모 on 31/12/2018.
//
//  자료형이 다른 두 피연산자를 대상으로 하는 연산자오버로딩을 공부하고 있습니다.
//  특히 +,*연산에서 교환법칙이 성립하려면 전역함수를 사용해야만 한다는 것을 이해했습니다.

#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x, int y) :xpos(x), ypos(y) {}
    Point() :xpos(0), ypos(0) {}
    void ShowPosition() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
    Point operator*(int times)
    {
        Point pnt(xpos*times, ypos*times);
        return pnt;
    }
    friend Point operator*(int times, Point &pnt);
};

Point operator*(int times, Point &pnt)
{
    Point temp(times*pnt.xpos, times*pnt.ypos);
    return temp;
    
    //return pnt*times;
}

int main(void)
{
    Point pnt1(1, 2);
    Point pnt2;
    
    pnt2 = pnt1*2;
    pnt2.ShowPosition();
    
    pnt2 = 3*pnt1;
    pnt2.ShowPosition();
    
    pnt2 = 2*pnt1*3;
    pnt2.ShowPosition();
    
    return 0;
}
