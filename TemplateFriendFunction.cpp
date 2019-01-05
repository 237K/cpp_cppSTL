//
//  TemplateFriendFunction.cpp
//  cpp_study
//
//  Created by 형성모 on 04/01/2019.
//
//  Point<int> 혹은 Point<double>과 같은 템플릿 클래스의 자료형을 대상으로도 일반함수 정의가 가능하며,
//  이러한 함수를 대상으로 템플릿 클래스 내에서 friend 선언도 가능하다.
//

#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

template <class T>
class Point
{
private:
    T xpos;
    T ypos;
public:
    Point(T x=0, T y=0);
    void ShowPosition() const;
    
    friend Point<int> operator+(const Point<int>& ptr1, const Point<int>& ptr2);
    friend ostream& operator<<(ostream& os, const Point<int>& ptr);
};

template <class T>
Point<T>::Point(T x, T y) :xpos(x), ypos(y) {}
template <class T>
void Point<T>::ShowPosition() const { cout<<"["<<xpos<<", "<<ypos<<"]"<<endl; }

//template <class T>
Point<int> operator+(const Point<int>& ptr1, const Point<int>& ptr2)
{
    return Point<int>(ptr1.xpos+ptr2.xpos, ptr1.ypos+ptr2.ypos);
}

//template <class T>
ostream& operator<<(ostream& os, const Point<int>& ptr)
{
    //os<<"["<<ptr.xpos<<", "<<ptr.ypos<<"]"<<endl;
    ptr.ShowPosition();
    return os;
}

int main(void)
{
    Point<int> point1(2, 3);
    Point<int> point2(4, 5);
    Point<int> point3 = point1+point2;
    cout<<point1<<point2<<point3<<endl;
    /*
    Point<double> double1(1.2, 2.3);
    Point<double> double2(2.3, 3.7);
    Point<double> double3 = double1+double2;
    cout<<double1<<double2<<double3<<endl;
    */
    return 0;
}
