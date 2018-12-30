//
//  FunctionOverloading2.cpp
//  cpp_study
//
//  Created by 형성모 on 30/12/2018.
//
//  연산자 오버로딩을 공부하고 있습니다. 방법은 두 가지 이며, 1. 전역함수로 구현하는 방법과 2. 멤버함수로 구현하는 방법이 있습니다.
//  +, - 연산자를 오버로딩 해보았습니다.
//  +=, -= 연산자를 오버로딩 해보았습니다.
//  ==, != 연산자를 전역함수로 오버로딩 해보았습니다.
//

#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x, int y) : xpos(x), ypos(y) {}
    void ShowPositon() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl<<endl;
    }
    Point operator+(const Point &pnt)                       //+ 연산자오버로딩
    {
        Point temp(xpos+pnt.xpos, ypos+pnt.ypos);
        return temp;
    }
    Point operator-(const Point &pnt)                       //- 연산자오버로딩
    {
        Point temp(xpos-pnt.xpos, ypos-pnt.ypos);
        return temp;
    }
    
    Point& operator+=(const Point &pnt)                     //+= 연산자오버로딩
    {
        xpos = xpos + pnt.xpos;
        ypos = ypos + pnt.ypos;
        return *this;
    }
    Point& operator-=(const Point &pnt)                     //-= 연산자오버로딩
    {
        xpos = xpos - pnt.xpos;
        ypos = ypos - pnt.ypos;
        return *this;
    }
    friend bool operator==(const Point &, const Point &);               //== 연산자오버로딩 (전역함수로)
    friend bool operator!=(const Point &, const Point &);               //!= 연산자오버로딩 (전역함수로)
};

bool operator==(const Point &pnt1, const Point &pnt2)                   //== 연산자오버로딩 (전역함수로)
{
    if(pnt1.xpos==pnt2.xpos && pnt1.ypos==pnt2.ypos) return true;
    else return false;
}

bool operator!=(const Point &pnt1, const Point &pnt2)                   //!= 연산자오버로딩 (전역함수로)
{
    if(pnt1==pnt2) return false;
    else return true;
}

int main(void)
{
    /* +, - 연산자 오버로딩 확인용
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1+pos2;
    
    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    */
    /* +=, -= 확인용
    Point point1(20, 30);
    Point point2(10, 20);
    Point point3(0, 0);
    
    point3 += point1;
    point3.ShowPositon();
    point3 += point2;
    point3.ShowPositon();
    
    point3 -= point2;
    point3.ShowPositon();
    point3 -= point1;
    point3.ShowPositon();
    */
    
    Point pos1(10, 10);
    Point pos2(11, 11);
    Point pos3(11, 11);
    
    cout<<"pos3==pos1 ? ";
    if(pos3==pos1) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    cout<<"pos3!=pos1 ? ";
    if(pos3!=pos1) cout<<"true"<<endl;
    else cout<<"flase"<<endl;
    cout<<"pos3==pos2 ? ";
    if(pos3==pos2) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}
