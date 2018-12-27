//
//  StaticMember.cpp
//  cpp_study
//
//  Created by 형성모 on 2018. 12. 27..
//
//  c++에서의 static에 대해 공부하였습니다.
//  멤버변수와 달리 클래스 당 하나만 존재하며, 클래스 생성 시 클래스 내부에 존재하는 것이 아니라 외부에 존재하는 것입니다.
//

#include <iostream>

using namespace std;

class Simple
{
private:
    static int SimpleObjCount;
public:
    Simple()
    {
        SimpleObjCount++;
        cout<<SimpleObjCount<<"번째 Simple 객체가 생성되었습니다."<<endl;
    }
};

int Simple::SimpleObjCount = 0;     //static으로 선언된 Simple 클래스의 멤버변수를 이렇게 초기화 합니다!

class Complex
{
private:
    static int ComplexObjCount;
public:
    Complex()
    {
        ComplexObjCount++;
        cout<<ComplexObjCount<<"번째 Complex 객체가 생성되었습니다."<<endl;
    }
    Complex(const Complex &copy)
    {
        ComplexObjCount++;
        cout<<ComplexObjCount<<"번째 Complex 객체가 생성되었습니다.(복사생성자가 호출되었습니다.)"<<endl;
    }
};

int Complex::ComplexObjCount = 0;

int main(void)
{
    Simple sim1;
    Simple sim2;
    Simple();
    
    Complex com1;
    Complex com2(com1);
    Complex com3 = com1;
    Complex();
    
    return 0;
}
