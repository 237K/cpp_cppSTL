//
//  WhyInitisCool.cpp
//  cpp_study
//
//  Created by 형성모 on 1/1/2019.
//
//  이니셜라이즈를 사용하는 것이 왜 성능향상에 도움이 되는지 확인해보았습니다.
//

#include <iostream>

using namespace std;

class AAA
{
private:
    int num;
public:
    AAA() : num(0) {}
    AAA(int n) :num(n)
    {
        cout<<"AAA생성자 호출"<<endl;
    }
    AAA(const AAA &ref) :num(ref.num)
    {
        cout<<"AAA복사생성자 호출"<<endl;
    }
    AAA& operator=(const AAA &ref)
    {
        num = ref.num;
        cout<<"AAA 대입연산자 호출"<<endl;
        return *this;
    }
};

class BBB
{
private:
    AAA mem;
public:
    BBB(const AAA &ref) : mem(ref){}
};

class CCC
{
private:
    AAA mem;
public:

    CCC(const AAA& ref)
    {
        mem = ref;
    }
};

int main(void)
{
    AAA obj1(12);
    cout<<"AAA객체를 생성했습니다."<<endl;
    
    BBB obj2(obj1);
    cout<<"'BBB obj2(obj1)'BBB객체를 생성하고 obj1로 초기화했습니다.obj1의 타입인 AAA의 복사생성자가 호출되겠습니다."<<endl;
    
    CCC obj3(obj1);
    cout<<"'CCC obj3(obj1)'CCC객체를 생성하고 obj1로 초기화했습니다.obj1의 타입인 AAA의 생성자와 AAA의 대입연산자가 호출되겠습니다."<<endl;
    
    cout<<"**********************************************************************************"<<endl;
    cout<<"이렇듯 이니셜라이즈를 이용해 초기화를 진행하면 함수의 호출횟수를 줄일 수 있고, 초기화 과정을 단순화시킬 수 있어서 약간의 성능향상을 기대할 수 있습니다."<<endl;
}
