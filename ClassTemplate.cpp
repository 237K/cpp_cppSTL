//
//  ClassTemplate.cpp
//  cpp_study
//
//  Created by 형성모 on 03/01/2019.
//
//  클래스 템플릿에 대해 공부했습니다.
//

#include <iostream>

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
    void ShowPosition() const;
};

template <class T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y) {}

template <class T>
void Point<T>::ShowPosition() const
{
    cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
}

int main(void)
{
    Point<int> pos1(3, 4);
    pos1.ShowPosition();
    
    Point<double> pos2(2.4, 3.6);
    pos2.ShowPosition();
    
    Point<char> pos3('P', 'F');
    pos3.ShowPosition();
    
    return 0;
}
