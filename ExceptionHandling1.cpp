//
//  ExceptionHandling.cpp
//  cpp_study
//
//  Created by 형성모 on 05/01/2019.
//
//  예외처리를 공부했습니다.
//  c++에서의 예외처리는 try, catch, throw로 이루어진 메커니즘 입니다.
//  try블록 안에서 예외가 발생하면 throw절이 실행되어 프로그램의 흐름이 중지되고 catch블록에 의해 예외 처리과정이 실행됩니다.
//  *예외가 발생하여 catch블록이 실행되고나면 예외가 발생한 지점 이후를 실행하는 것이 아니라 나머지 try영역은 건너뛰고 catch블록 이후가 실행됩니다.
//  throw절에 의해 던져진 예외 데이터의 자료형과 catch블록의 매개변수 자료형은 일치해야 합니다.
//  함수 내에서 예외가 처리되지 않으면, 예외가 발생한 함수를 호출한 영역으로 예외 데이터가 전달됩니다.
//  이 경우 해당 함수는 더 이상 실행되지 않고 종료됩니다.

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Div(int num1, int num2)
{
    if(num2==0) throw num2;
    cout<<"나눗셈의 몫 : "<<num1/num2<<endl;
    cout<<"나눗셈의 나머지 : "<<num1%num2<<endl;
}

int main(void)
{
    int num1, num2;
    cout<<"나눗셈을 실행 할 두 개의 숫자 입력 : "; cin>>num1>>num2;
    
    try
    {
        Div(num1, num2);
        cout<<"나눗셈이 완료되었습니다."<<endl;
    }
    catch(int expn)
    {
        cout<<"제수는 "<<expn<<"이 될 수 없습니다."<<endl;
        cout<<"프로그램을 다시 실행하세요."<<endl;
    }
    
    cout<<"end of main"<<endl;
    return 0;
}
