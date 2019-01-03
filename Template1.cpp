//
//  Template.cpp
//  cpp_study
//
//  Created by 형성모 on 03/01/2019.
//
//  템플릿에 대해 공부했습니다.
//  템플릿 관련 예시문제 1
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) {}
    void ShowPosition() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
};

template <class T>
void Swap(T &pnt1, T &pnt2)
{
    T temp = pnt1;
    
    pnt1 = pnt2;
    pnt2 = temp;
}

int main(void)
{
    Point pnt1(1, 5);
    Point pnt2(237, 888);
    pnt1.ShowPosition();
    pnt2.ShowPosition();
    cout<<"------Swap------"<<endl;
    Swap(pnt1, pnt2);
    pnt1.ShowPosition();
    pnt2.ShowPosition();
    
    return 0;
}
