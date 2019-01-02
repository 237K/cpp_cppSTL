//
//  ObjArrayRef.cpp
//  cpp_study
//
//  Created by 형성모 on 02/01/2019.
//
//  객체를 저장하는 배열을 공부했습니다.
//  두 가지 형태로 정의할 수 있는데, 1. 객체를 저장, 2. 객체의 주소 값을 저장
//  1. 객체를 저장하는 방법은 대입연산자를 기반으로 객체 간 멤버 대 멤버 복사로 진행됩니다.
//  2. 객체의 주소 값을 저장하는 형태로 구현해보았습니다.
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
    Point(int x=0, int y=0) :xpos(x), ypos(y) {}
    Point(const Point &pnt) :xpos(pnt.xpos), ypos(pnt.ypos) {}
    friend ostream& operator<<(ostream& os, const Point& pnt);
};

ostream& operator<<(ostream& os, const Point& pnt)
{
    os<<"["<<pnt.xpos<<", "<<pnt.ypos<<"]"<<endl;
    return os;
}

typedef Point *POINT_POINTER;

class BoundCheckArray
{
private:
    POINT_POINTER *array;
    int arr_len;
private:
    BoundCheckArray(const BoundCheckArray &arr) {}
    BoundCheckArray& operator=(const BoundCheckArray &arr) { return *this; }
public:
    BoundCheckArray(int len) :arr_len(len)
    {
        array = new POINT_POINTER[len];
    }
    POINT_POINTER& operator[](int index)
    {
        if(index < 0 || index >= arr_len)
        {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        return array[index];
    }
    POINT_POINTER& operator[](int index) const
    {
        if(index < 0 || index >= arr_len)
        {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        return array[index];
    }
    int GetLen() const { return arr_len; }
    ~BoundCheckArray() { delete []array; }
};

int main(void)
{
    BoundCheckArray array(3);
    array[0] = new Point(0, 0);
    array[1] = new Point(3, 4);
    array[2] = new Point(6, 8);
    
    for(int i = 0; i < array.GetLen(); i++)
    {
        cout<<*(array[i]);
    }
    
    for(int i = 0; i < array.GetLen(); i++)
    {
        delete array[i];
    }
    return 0;
}
