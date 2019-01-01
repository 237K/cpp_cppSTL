//
//  InheritAssignOperator1.cpp
//  cpp_study
//
//  Created by 형성모 on 1/1/2019.
//
//  상속 구조에서의 대입 연산자 호출에 대해 공부했습니다.
//  derived class에서 대입연산자를 정의해야할 경우, base class의 대입연산자를 명시하지 않으면 bass class 대입연산자가 호출되지 않는다는
//  것을 이해했습니다.
//
//  상속 구조에서 대입연산자 호출을 통해 깊은복사가 일어나도록 하는 예시문제 1
//

#include <iostream>
#include <cstring>

using namespace std;

class Gun
{
private:
    int bullet;
public:
    Gun(int bullet) :bullet(bullet) {}
    Gun(const Gun &gun) :bullet(gun.bullet) {}
    void Shot()
    {
        cout<<"BBANG!"<<endl;
        bullet--;
    }
    void ShowBullet() const
    {
        cout<<"Bullet : "<<bullet<<endl;
    }
    ~Gun()
    {
        cout<<"Gun 소멸자가 호출되었습니다."<<endl;
    }
};

class Police
{
private:
    int handcuffs;
    Gun *pistol;
public:
    Police(int bullet, int handcuffs) :handcuffs(handcuffs)
    {
        if(bullet > 0)
        {
            pistol = new Gun(bullet);
        }
        else pistol = NULL;
    }
    Police(const Police &police)
    {
        handcuffs = police.handcuffs;
        if(police.pistol != NULL)
        {
            pistol = new Gun(*(police.pistol));
        }
        else pistol = NULL;
    }
    Police& operator=(const Police &police)
    {
        handcuffs = police.handcuffs;
        if(pistol != NULL)
        {
            delete pistol;
        }
        if(police.pistol != NULL)
        {
            pistol = new Gun(*(police.pistol));
        }
        else pistol = NULL;
        return *this;
    }
    void PutHandcuff()
    {
        cout<<"SANP!"<<endl;
        handcuffs--;
    }
    void Shot()
    {
        if(pistol==NULL)
        {
            cout<<"There is no bullet!"<<endl;
        }
        else pistol->Shot();
    }
    void ShowInfo() const
    {
        cout<<"Handcuffs : "<<handcuffs<<endl;
        pistol->ShowBullet();
    }
    ~Police()
    {
        if(pistol!=NULL) delete pistol;
        cout<<"Police 소멸자가 호출되었습니다."<<endl;
    }
};

int main(void)
{
    Police PoliceOfficer1(10, 10);
    Police PoliceOfficer2 = PoliceOfficer1;
    
    PoliceOfficer1.ShowInfo();
    PoliceOfficer2.ShowInfo();
    
    Police PoliceOfficer3(5, 5);
    PoliceOfficer3 = PoliceOfficer1;
    PoliceOfficer3.ShowInfo();
}
