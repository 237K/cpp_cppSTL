//
//  InheritAssignOperator.cpp
//  cpp_study
//
//  Created by 형성모 on 1/1/2019.
//
//  상속 구조에서의 대입 연산자 호출에 대해 공부했습니다.
//  derived class에서 대입연산자를 정의해야할 경우, base class의 대입연산자를 명시하지 않으면 bass class 대입연산자가 호출되지 않는다는
//  것을 이해했습니다.
//

#include <iostream>

using namespace std;

class First
{
private:
    int num1;
    int num2;
public:
    First(int num1, int num2) :num1(num1), num2(num2) {}
    First(const First &first) :num1(first.num1), num2(first.num2) {}
    First& operator=(const First& first)
    {
        num1 = first.num1;
        num2 = first.num2;
        return *this;
    }
    void ShowData() const
    {
        cout<<num1<<", "<<num2<<endl;
    }
};

class Second : public First
{
private:
    int num3;
    int num4;
public:
    Second(int num1, int num2, int num3, int num4) : First(num1, num2), num3(num3), num4(num4) {}
    Second(const Second &second) : First(second), num3(second.num3), num4(second.num4) {}
    Second& operator=(const Second &second)
    {
        First::operator=(second);
        num3 = second.num3;
        num4 = second.num4;
        return *this;
    }
    void ShowData() const
    {
        First::ShowData();
        cout<<num3<<", "<<num4<<endl;
    }
};

int main(void)
{
    Second sec(111, 222, 333, 444);
    Second cpy(0, 0, 0, 0);
    cpy = sec;
    cpy.ShowData();
    return 0;
}
