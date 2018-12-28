//
//  IS_A_inheritance.cpp
//  cpp_study
//
//  Created by 형성모 on 28/12/2018.
//
//  상속을 사용하는 경우는 base클래스와 derived클래스의 관계가 'IS-A' 관계일 때!
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Rectangle
{
private:
    int horizon;
    int vertical;
public:
    Rectangle() {}
    Rectangle(int _horizon, int _vertical) :horizon(_horizon), vertical(_vertical) {}
    ~Rectangle() {}
    void ShowArea()
    {
        cout<<"면적은 "<<horizon * vertical<<" 입니다."<<endl;
    }
};

class Square : public Rectangle
{
public:
    Square() {}
    Square(int length) :Rectangle(length, length) {}
    ~Square() {}
};

int main(void)
{
    Rectangle rec(4, 3);
    rec.ShowArea();
    
    Square sqr(7);
    sqr.ShowArea();
    
    return 0;
}
