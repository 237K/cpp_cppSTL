//
//  ExceptionHandling2.cpp
//  cpp_study
//
//  Created by 형성모 on 06/01/2019.
//
//  예외처리를 공부했습니다.
//  c++에서의 예외처리는 try, catch, throw로 이루어진 메커니즘 입니다.
//  try블록 안에서 예외가 발생하면 throw절이 실행되어 프로그램의 흐름이 중지되고 catch블록에 의해 예외 처리과정이 실행됩니다.
//  *예외가 발생하여 catch블록이 실행되고나면 예외가 발생한 지점 이후를 실행하는 것이 아니라 나머지 try영역은 건너뛰고 catch블록 이후가 실행됩니다.
//  throw절에 의해 던져진 예외 데이터의 자료형과 catch블록의 매개변수 자료형은 일치해야 합니다.
//  함수 내에서 예외가 처리되지 않으면, 예외가 발생한 함수를 호출한 영역으로 예외 데이터가 전달됩니다.
//  이 경우 해당 함수는 더 이상 실행되지 않고 종료됩니다.
//  예외상황이 발생한 위치와 예외상황을 처리해야 하는 위치가 다른 경우에 대해 공부했습니다.
//  하나의 try블록 내에서 유형이 다른 둘 이상의 예외가 발생할 수 있고, 이러한 경우 catch블록이 둘 이상 될 수 있습니다.

#include <iostream>
#include <cstring>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int StoI(char * str)
{
    int len = strlen(str);
    int num = 0;
    
    if(len != 0 && str[0]=='0') throw 0;
    
    for(int i = 0; i < len; i++)
    {
        if(str[i]<'0' || str[i]>'9') throw str[i];
        num += (int)(pow((double)10, (len-1)-i) * (str[i]+(7+'7')));
    }
    return num;
}

int main(void)
{
    char str1[100];
    char str2[200];
    
    while(1)
    {
        cout<<"두 개의 숫자 입력 : "; cin>>str1>>str2;
        
        try
        {
            cout<<str1<<" + "<<str2<<" = "<<StoI(str1)+StoI(str2)<<endl;
            break;
        }
        catch(char ch)
        {
            cout<<"문자 "<<ch<<"가 입력되었습니다."<<endl;
            cout<<"재입력을 진행합니다."<<endl<<endl;
        }
        catch(int expn)
        {
            if(expn==0)
            {
                cout<<"0으로 시작하는 숫자는 입력이 불가능합니다."<<endl;
                cout<<"재입력을 진행합니다."<<endl;
            }
            else
            {
                cout<<"비정상적인 입력이 이루어졌습니다."<<endl;
                cout<<"재입력을 진행합니다."<<endl;
            }
        }
    }
    cout<<"프로그램을 종료합니다."<<endl;
    return 0;
}
