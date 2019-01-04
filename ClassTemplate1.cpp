//
//  ClassTemplate1.cpp
//  cpp_study
//
//  Created by 형성모 on 04/01/2019.
//
//  클래스템플릿 예시문제 1. 스마트포인터를 템플릿으로 정의하여 어떤 클래스의 객체도 참조할 수 있는 포인터가 되게 하자.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template <class T>
class SmartPointer
{
private:
    T* SP;
public:
    SmartPointer(T* ptr) : SP(ptr) {}
    T& operator*() const { return *SP; }
    T* operator->() const { return SP; }
    ~SmartPointer() { delete SP; }
};

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) {}
    void SetPos(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    void ShowPosition() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
    ~Point() {}
};

int main(void)
{
    SmartPointer<Point> sptr1(new Point(1, 2));
    SmartPointer<Point> sptr2(new Point(3, 4));
    sptr1->ShowPosition();
    sptr2->ShowPosition();
    sptr1->SetPos(10, 20);
    sptr2->SetPos(30, 40);
    sptr1->ShowPosition();
    sptr2->ShowPosition();
    
    return 0;
}
