//
//  ObjArray.cpp
//  cpp_study
//
//  Created by 형성모 on 02/01/2019.
//
//  객체를 저장하는 배열을 공부했습니다.
//  두 가지 형태로 정의할 수 있는데, 1. 객체를 저장, 2. 객체의 주소 값을 저장
//  1. 객체를 저장하는 형태로 구현해보았습니다.
//

#include <iostream>
#include <cstdlib>

using namespace std;

class Point
{
private:
    int xpos;
    int ypos;
public:
    Point() : xpos(0), ypos(0) {}
    Point(int x, int y) : xpos(x), ypos(y) {}
    friend ostream& operator<<(ostream& os, const Point &pnt);
};

ostream& operator<<(ostream& os, const Point &pnt)
{
    os<<"["<<pnt.xpos<<", "<<pnt.ypos<<"]"<<endl;
    return os;
}

class BoundCheckArray
{
private:
    Point *PointArray;
    int arr_len;
private:
    BoundCheckArray(const BoundCheckArray &copy) {}
    BoundCheckArray& operator=(const BoundCheckArray &assign) {return *this;}
public:
    BoundCheckArray(int len) : arr_len(len)
    {
        PointArray = new Point[len];
    }
    Point& operator[](int index)
    {
        if(index < 0 || index >= arr_len)
        {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        return PointArray[index];
    }
    Point operator[](int index) const
    {
        if(index < 0 || index >= arr_len)
        {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        return PointArray[index];
    }
    int GetLen() const { return arr_len; }
    ~BoundCheckArray()
    {
        delete []PointArray;
    }
};

int main(void)
{
    BoundCheckArray array(3);
    array[0] = Point(0, 0);
    array[1] = Point(3, 4);
    array[2] = Point(6, 8);
    
    for(int i = 0; i < array.GetLen(); i++)
    {
        cout<<array[i];
    }
    
    return 0;
}
