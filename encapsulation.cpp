//
//  encapsulation.cpp
//  cpp_study
//
//  Created by 형성모 on 2018. 12. 23..
//
//  정보은닉과 캡슐화를 기본으로 두 개의 원으로 구성된 'Ring' Class를 구현
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Point
{
private:
    int xpos, ypos;
public:
    void Init(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    void ShowPoint() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
};

class Circle
{
private:
    Point pnt1;
    int radius;
public:
    void Init(int x1, int y1, int r1)
    {
        pnt1.Init(x1, y1);
        radius = r1;
    }
    void ShowCircle() const
    {
        pnt1.ShowPoint();
        cout<<"radius : "<<radius<<endl;
    }
};

class Ring
{
private:
    Circle circle1;
    Circle circle2;
public:
    void Init(int x1, int y1, int r1, int x2, int y2, int r2)
    {
        circle1.Init(x1, y1, r1);
        circle2.Init(x2, y2, r2);
    }
    void ShowRing() const
    {
        circle1.ShowCircle();
        circle2.ShowCircle();
    }
};

int main(void)
{
    Ring ring;
    ring.Init(1, 1, 4, 2, 2, 9);
    ring.ShowRing();
    return 0;
}
