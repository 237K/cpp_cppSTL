//
//  SmartPointer.cpp
//  cpp_study
//
//  Created by 형성모 on 03/01/2019.
//
//  포인터 연산자( ->, * ) 오버로딩을 공부했습니다.
//  *스마트포인터에 대해 공부했습니다.
//

#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) { cout<<"Point객체 생성"<<endl; }
    ~Point() { cout<<"Point객체 소멸"<<endl; }
    void SetPos(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    friend ostream& operator<<(ostream& os, const Point &ptr);
    //friend ostream& operator<<(ostream& os, const Point *ptr);
};

ostream& operator<<(ostream& os, const Point &ptr)
{
    os<<"["<<ptr.xpos<<", "<<ptr.ypos<<"]"<<endl;
    return os;
}

class SmartPointer
{
private:
    Point *point;
public:
    SmartPointer(Point *ptr) : point(ptr) {}
    Point& operator*() const
    {
        return *point;
    }
    Point* operator->() const
    {
        return point;
    }
    ~SmartPointer() { delete point; }
};

int main(void)
{
    SmartPointer sptr1(new Point(3, 4));
    SmartPointer sptr2(new Point(5, 6));
    SmartPointer sptr3(new Point(7, 8));
    
    cout<<*sptr1;
    cout<<*sptr2;
    cout<<*sptr3;
    
    sptr1->SetPos(30, 40);
    sptr2->SetPos(50, 60);
    sptr3->SetPos(60, 70);
    
    cout<<*sptr1;
    cout<<*sptr2;
    cout<<*sptr3;
    
    return 0;
}
