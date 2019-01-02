//
//  OperatorOverloading_problem1.cpp
//  cpp_study
//
//  Created by 형성모 on 02/01/2019.
//
//  연산자 오버로딩 예시문제 1
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
    friend ostream& operator<<(ostream& os, const Point& pnt);
    friend ostream& operator<<(ostream& os, const Point* pnt);
};

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

typedef Point *POINT_PTR;

class PointArray
{
private:
    POINT_PTR *array;
    int arr_len;
public:
    PointArray(int len) :arr_len(len)
    {
        array = new POINT_PTR[len];
    }
    POINT_PTR& operator[](int index)
    {
        if(index<0 || index >= arr_len)
        {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        return array[index];
    }
    POINT_PTR operator[](int index) const
    {
        if(index<0 || index >= arr_len)
        {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        return array[index];
    }
    int GetLen() { return arr_len; }
    
    friend ostream& operator<<(ostream& os, const POINT_PTR& pp);
    
    ~PointArray() { delete []array; }
};
/*
ostream& operator<<(ostream& os, const POINT_PTR& pp)
{
    cout<<*pp;
    return os;
}
*/
int main(void)
{
    PointArray array(3);
    array[0] = new Point(0, 0);
    array[1] = new Point(3, 4);
    array[2] = new Point(6, 8);
    
    for(int i = 0; i < array.GetLen(); i++)
    {
        cout<<*(array[i]);
    }
    
    for(int i = 0; i < array.GetLen(); i++)
    {
        cout<<array[i];
    }
    
    for(int i = 0; i < array.GetLen(); i++)
    {
        delete array[i];
    }
    return 0;
}
