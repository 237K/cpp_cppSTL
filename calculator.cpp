//
//  calculator.cpp
//  cpp_study
//
//  Created by 형성모 on 2018. 12. 23..
//
//  기본적인 계산기 프로그램
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

enum
{
    Add = 1,
    Min,
    Mul,
    Div
};

class Calculator
{
private:
    int add_count;
    int min_count;
    int mul_count;
    int div_count;
    
public:
    void Init();
    void Add(double &num1, double &num2);
    void Min(double &num1, double &num2);
    void Mul(double &num1, double &num2);
    void Div(double &num1, double &num2);
    void ShowOpCount();
};

void Calculator::Init()
{
    add_count = 0;
    min_count = 0;
    mul_count = 0;
    div_count = 0;
}

void Calculator::Add(double &num1, double &num2)
{
    double result;
    result = num1 + num2;
    cout<<num1<<" + "<<num2<<" = "<<result<<" 입니다."<<endl;
    cout<<"-------------------------------------"<<endl;
    add_count++;
}

void Calculator::Min(double &num1, double &num2)
{
    double result;
    result = num1 - num2;
    cout<<num1<<" - "<<num2<<" = "<<result<<" 입니다."<<endl;
    cout<<"-------------------------------------"<<endl;
    min_count++;
}

void Calculator::Mul(double &num1, double &num2)
{
    double result;
    result = num1 * num2;
    cout<<num1<<" * "<<num2<<" = "<<result<<" 입니다."<<endl;
    cout<<"-------------------------------------"<<endl;
    mul_count++;
}

void Calculator::Div(double &num1, double &num2)
{
    double result;
    result = num1 / num2;
    cout<<num1<<" / "<<num2<<" = "<<result<<" 입니다."<<endl;
    cout<<"-------------------------------------"<<endl;
    div_count++;
}

void Calculator::ShowOpCount()
{
    cout<<"+ 연산 횟수는 : "<<add_count<<"회 입니다"<<endl;
    cout<<"- 연산 횟수는 : "<<min_count<<"회 입니다"<<endl;
    cout<<"* 연산 횟수는 : "<<mul_count<<"회 입니다"<<endl;
    cout<<"/ 연산 횟수는 : "<<div_count<<"회 입니다"<<endl;
}

void print_menu()
{
    cout<<"==============CALCULATOR=============="<<endl;
    cout<<"1. +"<<endl;
    cout<<"2. -"<<endl;
    cout<<"3. X"<<endl;
    cout<<"4. /"<<endl;
    cout<<"5. 연산자 별 연산 횟수 출력"<<endl;
    cout<<"6. 프로그램 종료"<<endl;
}

int main(void)
{
    /*
    Calculator cal;
    cal.Init();
    cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
    cout<<"3.5 / 1.7 = "<<cal.Div(3.5, 1.7)<<endl;
    cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
    cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl;
    cal.ShowOpCount();
    */
    
    Calculator cal;
    cal.Init();
    
    double num1, num2;
    double &ref_num1 = num1;
    double &ref_num2 = num2;
    int select = 0;
    
    while(1)
    {
        print_menu();
        cout<<"-------------------------------------"<<endl;
        cout<<"원하시는 연산 혹은 메뉴를 선택하세요 : ";
        cin>>select;
        cout<<endl;
    
        switch(select)
        {
            case Add :
                cout<<"연산하고자 하는 2개의 수를 입력하세요 : ";
                cin>>num1>>num2;
                cout<<"-------------------------------------"<<endl;
                cal.Add(ref_num1, ref_num2);
                break;
            case Min :
                cout<<"연산하고자 하는 2개의 수를 입력하세요 : ";
                cin>>num1>>num2;
                cout<<"-------------------------------------"<<endl;
                cal.Min(ref_num1, ref_num2);
                break;
            case Mul :
                cout<<"연산하고자 하는 2개의 수를 입력하세요 : ";
                cin>>num1>>num2;
                cout<<"-------------------------------------"<<endl;
                cal.Mul(ref_num1, ref_num2);
                break;
            case Div :
                cout<<"연산하고자 하는 2개의 수를 입력하세요 : ";
                cin>>num1>>num2;
                cout<<"-------------------------------------"<<endl;
                cal.Div(ref_num1, ref_num2);
                break;
            case 5 :
                cal.ShowOpCount();
                break;
            case 6 :
                return 0;
        }
    }
    return 0;
}
