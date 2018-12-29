//
//  FunctionOverloading1.cpp
//  cpp_study
//
//  Created by 형성모 on 30/12/2018.
//
//  연산자 오버로딩을 공부했습니다.
//

#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x, int y) :xpos(x), ypos(y) {}
    //Point(Point &pnt) :xpos(pnt.xpos), ypos(pnt.ypos) {}
    void ShowPosition() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
    Point operator+(const Point &pnt)
    {
        Point pos(xpos+pnt.xpos, ypos+pnt.ypos);
        return pos;
    }
    //friend Point operator+(const Point &p1, const Point &p2);
};
/*
Point operator+(const Point &p1, const Point &p2)
{
    Point p3(p1.xpos+p2.xpos, p1.ypos+p2.ypos);
    return p3;
}
*/
int main(void)
{
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1+pos2;
    
    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
}
