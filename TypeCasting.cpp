//
//  TypeCasting.cpp
//  cpp_study
//
//  Created by 형성모 on 06/01/2019.
//
//  c++에서의 형변환 연산자에 대해 공부했습니다.
//  c스타일 형변환 연산자는 문제를 발생시킬 여지가 많으므로 c++에서 제공하는 4가지 형변환 연산자 중 용도에 맞는 연산자를 사용하는 것이 좋습니다.
//  1. dynamic_cast<T>( ) : 상속관계에서의 형 변환. 유도클래스의 포인터 및 참조형 데이터를 기초 클래스의 포인터 및 참조형 데이터로 형 변환
//  2. static_cast<T>( ) : 기본자료형 간 형 변환 & 상속관계에서의 형 변환 가능. dynamic_cast보다 속도 빠르지만, 더 보수적인 dynamic_cast사용 추천
//  3. const_cast<T>( ) : const를 제거할 수 있음. 단순히 인자 값을 전달하기 위해 const를 제거해야하는 등 제한된 상황에서 사용
//  4. reinterpret_cast<T>( ) : 포인터와 관련된 모든 유형의 형 변환 허용. 주소값을 출력하는 상황 등 제한적인 상황에서 사용 가능
//  dynamic_cast도 기초클래스가 하나 이상의 virtual함수를 가진 polymorphic클래스인 경우 유도클래스의 포인터나 참조형으로 형변환 할 수 있습니다.
//  dynamic_cast는 실행시간에 안정성을 검사하도록 컴파일러가 이진코드를 생성하므로 실행속도는 느리지만 안정적인 형 변환이 가능합니다.
//  dynamic_cast 연산을 진행할 경우 bad_cast 예외가 발생할 수 있기때문에 반드시 이에 대한 예외처리를 해야 합니다.
//

#include <iostream>
using namespace std;

class Simple
{
public:
    virtual void ShowSimple()
    {
        cout<<"Simple Base Class"<<endl;
    }
};

class Complex : public Simple
{
public:
    void ShowSimple()
    {
        cout<<"Complex Derived Class"<<endl;
    }
};

int main(void)
{
    Simple simObj;
    Simple& ref = simObj;
    
    try
    {
        Complex &comRef = dynamic_cast<Complex&>(ref);
        comRef.ShowSimple();
    }
    catch(bad_cast expt)
    {
        cout<<expt.what()<<endl;
    }
    return 0;
}
