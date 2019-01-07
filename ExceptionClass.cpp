//
//  ExceptionClass.cpp
//  cpp_study
//
//  Created by 형성모 on 06/01/2019.
//
//  예외클래스와 예외객체를 공부했습니다.
//  예외객체는 c++ 예외처리 메커니즘에 의해 처리되므로 직접 참조하지 않아도 되며, 일반적으로 예외객체는 임시객체의 형태로 생성합니다.
//  예외클래스 역시 상속을 구성할 수 있습니다.
//

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class AccountException
{
public:
    virtual void ExceptionMessage() = 0;
};
class DepositException : public AccountException
{
private:
    int reqDep;
public:
    DepositException(int money) : reqDep(money) {}
    void ExceptionMessage()
    {
        cout<<"[예외메시지 : "<<reqDep<<"원을 입금할 수 없습니다.]"<<endl<<endl;
    }
};

class WithdrawException : public AccountException
{
private:
    int balance;
public:
    WithdrawException(int money) : balance(money) {}
    void ExceptionMessage()
    {
        cout<<"[예외메시지 : "<<"잔액 "<<balance<<", 잔액이 부족합니다.]"<<endl<<endl;
    }
};

class Account
{
private:
    string accountID;
    int balance;
public:
    Account(string id, int money) : balance(money)
    {
        accountID = id;
    }
    void Deposit(int money) throw (AccountException)
    {
        if(money <= 0)
            throw DepositException(money);
            
        balance += money;
        cout<<money<<"원 입금을 완료했습니다."<<endl;
        cout<<"잔액 : "<<balance<<endl;
    }
    void Withdraw(int money) throw (AccountException)
    {
        if(money > balance)
            throw WithdrawException(balance);
        balance -= money;
        cout<<money<<"원 출금을 완료했습니다."<<endl;
        cout<<"잔액 : "<<balance<<endl;
    }
    void ShowAccount() const
    {
        cout<<"계좌번호 : "<<accountID<<endl;
        cout<<"계좌잔액 : "<<balance<<endl;
    }
};

int main(void)
{
    Account acc1("23456-78910", 5000);
    
    try
    {
        acc1.Deposit(2000);
        acc1.Deposit(0);
    }
    catch(AccountException &expn)
    {
        expn.ExceptionMessage();
    }
    
    try
    {
        acc1.Withdraw(4000);
        acc1.Withdraw(10000);
    }
    catch(AccountException &expn)
    {
        expn.ExceptionMessage();
    }
    
    acc1.ShowAccount();
    
    return 0;
}
