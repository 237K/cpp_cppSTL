//
//  PointArrayTemplate.cpp
//  cpp_study
//
//  Created by 형성모 on 04/01/2019.
//
//  템플릿으로 만들어진 Point클래스를 템플릿으로 만들어진 배열클래스에 넣어보았습니다.
//

#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

template <class T>
class Point
{
private:
    T xpos;
    T ypos;
public:
    Point(T x=0, T y=0);
    ~Point() {}
    void ShowPosition() const;
};

template <class T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y) {}
template <class T>
void Point<T>::ShowPosition() const { cout<<"["<<xpos<<", "<<ypos<<"]"<<endl; }

template <class T>
class BoundCheckArray
{
private:
    T * array;
    int index;
    int array_len;
public:
    BoundCheckArray(int len);
    ~BoundCheckArray();
    T& operator[](int index);
    T operator[](int index) const;
    int GetLen() const;
};

template <class T>
BoundCheckArray<T>::BoundCheckArray(int len) : index(0), array_len(len)
{
    array = new T[len];
}
template <class T>
T& BoundCheckArray<T>::operator[](int index)
{
    if(index < 0 || index >= array_len)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    return array[index];
}
template <class T>
T BoundCheckArray<T>::operator[](int index) const
{
    if(index < 0 || index >= array_len)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    return array[index];
}
template <class T>
BoundCheckArray<T>::~BoundCheckArray() { delete []array; }
template <class T>
int BoundCheckArray<T>::GetLen() const { return array_len; }


int main(void)
{
    BoundCheckArray< Point<int> > oarr1(3);
    oarr1[0] = Point<int>(3, 4);
    oarr1[1] = Point<int>(4, 5);
    oarr1[2] = Point<int>(5, 6);
    for(int i = 0; i < oarr1.GetLen(); i++)
    {
        oarr1[i].ShowPosition();
    }
    
    BoundCheckArray< Point<double> > oarr2(3);
    oarr2[0] = Point<double>(1.1, 2.2);
    oarr2[1] = Point<double>(3.3, 4.4);
    oarr2[2] = Point<double>(5.5, 6.6);
    for(int i = 0; i < oarr2.GetLen(); i++)
    {
        oarr2[i].ShowPosition();
    }
    
    BoundCheckArray< Point<int>* > oarr3(3);
    oarr3[0] = new Point<int>(11, 12);
    oarr3[1] = new Point<int>(13, 14);
    oarr3[2] = new Point<int>(15, 16);
    for(int i = 0; i < oarr2.GetLen(); i++)
    {
        oarr3[i]->ShowPosition();
    }
    
    for(int i = 0; i < oarr2.GetLen(); i++)
    {
        delete oarr3[i];
    }
    return 0;
}
