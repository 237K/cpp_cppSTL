//
//  NewDeleteOverloading.cpp
//  cpp_study
//
//  Created by 형성모 on 03/01/2019.
//
//  new, delete 연산자에 대한 오버로딩을 해보았습니다.
//

#include <iostream>

using namespace std;

class Point
{
private:
    int xpos;
    int ypos;
public:
    Point(int x=0, int y=0);
    static void* operator new (size_t size)
    {
        cout<<"operator new : "<<size<<endl;
        void* adr = new char[size];
        return adr;
    }
    static void operator delete(void* adr)
    {
        cout<<"operator delete"<<endl;
        delete []adr;
    }
    static void* operator new[] (size_t size)
    {
        cout<<"operator new[] : "<<size<<endl;
        void* adr = new char[size];
        return adr;
    }
    static void operator delete[] (void* adr)
    {
        cout<<"operator delete[]"<<endl;
        delete []adr;
    }
    void ShowPosition() const;
    friend ostream& operator<<(ostream& os, const Point& pnt);
    friend ostream& operator<<(ostream& os, const Point* pnt);
};

Point::Point(int x, int y) : xpos(x), ypos(y) {}

void Point::ShowPosition() const
{
    cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
}

ostream& operator<<(ostream& os, const Point& pnt)
{
    os<<"["<<pnt.xpos<<", "<<pnt.ypos<<"]"<<endl;
    return os;
}
ostream& operator<<(ostream& os, const Point* pnt)
{
    os<<"["<<pnt->xpos<<", "<<pnt->ypos<<"]"<<endl;
    return os;
}

int main(void)
{
    Point *ptr = new Point(3, 4);
    cout<<ptr;
    delete ptr;
    Point *arr = new Point[3];
    delete []arr;
    return 0;
}
