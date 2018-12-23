//
//  racing_game.cpp
//  cpp_study
//
//  Created by 형성모 on 2018. 12. 23..
//
//  매우 기초적인 레이싱 프로그램
//  ver2. 함수가 구조체에 종속적이므로, 함수를 구조체 안에 포함시켜 구현
//  ver3. struct 구조체 대신 class를 사용하여 구현
//


#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

namespace CAR_CONST
{
    enum
    {
        ID_LEN      =20,
        MAX_SPEED   =200,
        FUEL_STEP   =2,
        ACC_STEP    =10,
        BREAK_STEP  =10
    };
}

class car
{
private:
    char userID[CAR_CONST::ID_LEN];
    int fuel_gauge;
    int current_speed;
    
public:
    void InitCar(char * ID, int fuel);   //class에서 private영역에는 class내의 함수를 통해서만 접근 가능하므로, 변수 초기화를 위한 함수
    void ShowCarState();                 //현재 차의 상태를 표시하는 함수
    void Accel();                        //엑셀을 밟는 함수
    void Break();                        //브레이크를 밟는 함수
    void FuelWarning();                  //연료 부족 경고 함수
};

inline void car::InitCar(char * ID, int fuel)
{
    strcpy(userID, ID);
    fuel_gauge = fuel;
    current_speed = 0;
}

inline void car::ShowCarState()
{
    cout<<"user ID : "<<userID<<endl;
    cout<<"현재 연료량 : "<<fuel_gauge<<"%"<<endl;
    cout<<"현재 속도 : "<<current_speed<<"km/h"<<endl;
    cout<<"--------------------------"<<endl;
}

inline void car::Accel()
{
    if(fuel_gauge <= 0)
    {
        cout<<"현재 연료가 부족합니다!"<<endl;
        return;
    }
    else fuel_gauge -= CAR_CONST::FUEL_STEP;
    
    if(current_speed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPEED)
    {
        current_speed = CAR_CONST::MAX_SPEED;
        cout<<"최대 속도 입니다!"<<endl;
        return;
    }
    current_speed += CAR_CONST::ACC_STEP;
    
}

inline void car::Break()
{
    if(current_speed <= 0)
    {
        cout<<"현재 정지상태입니다."<<endl;
        return;
    }
    
    if(current_speed - CAR_CONST::BREAK_STEP <= 0)
    {
        current_speed = 0;
        return;
    }
    
    current_speed -= CAR_CONST::BREAK_STEP;
}

inline void car::FuelWarning()
{
    if(fuel_gauge < 6)
    {
        cout<<"연료가 "<<fuel_gauge<<"만큼 남았습니다. 충전해주세요."<<endl;
    }
}

int main(void)
{
    car MyCar1;
    char user1[CAR_CONST::ID_LEN] = "Mycar1";
    MyCar1.InitCar(user1, 100);
    MyCar1.Accel();
    MyCar1.Accel();
    MyCar1.Accel();
    MyCar1.Accel();
    MyCar1.ShowCarState();
    MyCar1.Break();
    MyCar1.ShowCarState();
    
    car MyCar2;
    char user2[CAR_CONST::ID_LEN] = "Mycar2";
    MyCar2.InitCar(user2, 100);
    MyCar2.Accel();
    MyCar2.Accel();
    MyCar2.Break();
    MyCar2.ShowCarState();
    
    return 0;
}
