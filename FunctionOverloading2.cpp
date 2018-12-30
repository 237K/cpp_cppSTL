//
//  FunctionOverloading2.cpp
//  cpp_study
//
//  Created by 형성모 on 30/12/2018.
//
//  연산자 오버로딩을 공부하고 있습니다.
//  단항연산자 (++, --)를 멤버함수와 전역함수의 형태로 구현해보았습니다.
//  절대값은 같고 부호만 반대로 바꾸는 - 함수를 멤버함수로 구현해보았습니다.
//  x좌표와 y좌표를 바꾸는 ~ 함수를 전역함수로 구현해보았습니다.
//  단항연산자 (++, --)를 후위함수 형태로 구현해보았습니다.
//

#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x, int y) :xpos(x), ypos(y) {}
    //Point(Point &pnt) : xpos(pnt.xpos), ypos(pnt.ypos) {}
    void ShowPosition() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
    Point& operator++()
    {
        xpos+=1;
        ypos+=1;
        return *this;
    }
    
    Point operator-()
    {
        Point point(-xpos, -ypos);
        return point;
    }
    
    const Point operator++(int)
    {
        const Point temp(xpos, ypos);
        xpos += 1;
        ypos += 1;
        return temp;
    }
    
    friend Point& operator--(Point &pnt);
    friend Point operator~(const Point &pnt);
    friend const Point operator--(Point &pnt, int);
};

Point& operator--(Point &pnt)
{
    pnt.xpos-=1;
    pnt.ypos-=1;
    return pnt;
}

Point operator~(const Point &pnt)
{
    Point temp(pnt.ypos, pnt.xpos);
    return temp;
}

const Point operator--(Point &pnt, int)
{
    const Point temp(pnt.xpos, pnt.ypos);
    pnt.xpos -= 1;
    pnt.ypos -= 1;
    return temp;
}

int main(void)
{
    /*
    Point point1(0, 0);
    point1.ShowPosition();
    ++point1;
    point1.ShowPosition();
    --point1;
    point1.ShowPosition();
    */
    
    Point point2(2, 3);
    Point point3 = -point2;
    point3.ShowPosition();
    
    Point point5(5, 7);
    Point point6 = ~(point5);
    point6.ShowPosition();
    
    Point point7(0, 0);

    
    return 0;
}
