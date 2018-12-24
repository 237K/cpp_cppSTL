//
//  Rectangle.cpp
//  cpp_study
//
//  Created by 형성모 on 2018. 12. 24..
//
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Point
{
private:
    int x, y;
public:
    Point(const int &xpos, const int &ypos);
    bool init(const int xpos, const int ypos) const;
    int GetX() const;
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
};

class Rectangle
{
private:
    Point upLeft;
    Point lowRight;
public:
    Rectangle(const int &x1, const int &y1, const int &x2, const int &y2);
    bool init(const Point upLeft, const Point lowRight) const;
    void ShowRectangle() const;
};

Point::Point(const int &xpos, const int &ypos)
{
    if(!Point::init(xpos, ypos))
    {
        cout<<"입력값이 범위를 초과하였습니다."<<endl;
    }
    x = xpos;
    y = ypos;
}

bool Point::init(const int xpos, const int ypos) const
{
    if(xpos < 0 || xpos > 100)
    {
        return false;
    }
    return true;
}

int Point::GetX() const
{
    return x;
}

int Point::GetY() const
{
    return y;
}

bool Point::SetX(int xpos)
{
    if(xpos < 0 || xpos > 100)
    {
        cout<<"값이 범위를 벗어났습니다."<<endl;
        return false;
    }
    x = xpos;
    return true;
}

bool Point::SetY(int ypos)
{
    if(ypos < 0 || ypos > 100)
    {
        cout<<"값이 범위를 벗어났습니다."<<endl;
        return false;
    }
    y = ypos;
    return true;
}

Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2):upLeft(x1, y1), lowRight(x2, y2)
{
    if(!Rectangle::init(upLeft, lowRight))
    {
        cout<<"좌상단과 우하단 좌표가 바뀌었거나 입력값이 잘못되었습니다."<<endl;
    }
}

bool Rectangle::init(const Point upLeft, const Point lowRight) const
{
    if(upLeft.GetX() > lowRight.GetX() || upLeft.GetY() < lowRight.GetY())
    {
        return false;
    }
    return true;
}

void Rectangle::ShowRectangle() const
{
    if(Rectangle::init(upLeft, lowRight))
    {
        cout<<"좌 상단 : "<<'['<<upLeft.GetX()<<", "<<upLeft.GetY()<<']'<<endl;
        cout<<"우 하단 : "<<'['<<lowRight.GetX()<<", "<<lowRight.GetY()<<']'<<endl;
    }
}

int main(void)
{
    Rectangle rec(1, 1, 5, 5);
    Rectangle rec2(-2, 2, 5, 5);
    Rectangle rec3(2, 2, -5, 5);
    Rectangle rec4(5, 5, 2, 2);
    Rectangle rec5(1, 5, 5, 1);
    
    rec.ShowRectangle();
    rec2.ShowRectangle();
    rec3.ShowRectangle();
    rec4.ShowRectangle();
    rec5.ShowRectangle();
    return 0;
}
