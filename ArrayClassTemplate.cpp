//
//  ArrayClassTemplate.cpp
//  cpp_study
//
//  Created by 형성모 on 03/01/2019.
//
//  배열클래스 템플릿을 공부했습니다.
//

#include <iostream>

using namespace std;

template <class T>
class BoundCheckArray
{
private:
    T *array;
    int arr_len;
private:
    BoundCheckArray(const BoundCheckArray& cpy) {}
    BoundCheckArray& operator=(const BoundCheckArray& assign) { return *this; }
public:
    BoundCheckArray(int len);
    ~BoundCheckArray();
    T& operator[](int index);
    T operator[](int index) const;
    int GetLen() const;
    void ShowArray() const;
};

template <class T>
BoundCheckArray<T>::BoundCheckArray(int len) : arr_len(len)
{
    array = new T[len];
}
template <class T>
T& BoundCheckArray<T>::operator[](int index)
{
    if(index < 0 || index >= arr_len)
    {
        cout<<"Array Index out of bound exception"<<endl;
        exit(1);
    }
    return array[index];
}
template <class T>
T BoundCheckArray<T>::operator[](int index) const
{
    if(index < 0 || index >= arr_len)
    {
        cout<<"Array Index out of bound exception"<<endl;
        exit(1);
    }
    return array[index];
}
template <class T>
int BoundCheckArray<T>::GetLen() const { return arr_len; }

template <class T>
void BoundCheckArray<T>::ShowArray() const
{
    cout<<" ";
    for(int i = 0; i < arr_len; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
template <class T>
BoundCheckArray<T>::~BoundCheckArray()
{
    delete []array;
}

class Point
{
private:
    int xpos;
    int ypos;
public:
    Point(int x=0, int y=0);
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
    BoundCheckArray<int> int_array(5);
    for(int i = 0; i < 5; i++)
    {
        int_array[i] = (i+1);
    }
    int_array.ShowArray();
    
    BoundCheckArray<Point> point_array(3);
    point_array[0] = Point(3, 4);
    point_array[1] = Point(4, 5);
    point_array[2] = Point(5, 6);
    point_array.ShowArray();
    
    typedef Point* POINT_PTR;
    BoundCheckArray<POINT_PTR> ptr_array(3);
    ptr_array[0] = new Point(3, 4);
    ptr_array[1] = new Point(4, 5);
    ptr_array[2] = new Point(5, 6);
    ptr_array.ShowArray();
    
    delete ptr_array[0];
    delete ptr_array[1];
    delete ptr_array[2];
    
    return 0;
}
