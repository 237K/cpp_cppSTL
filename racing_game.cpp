//
//  racing_game.cpp
//  cpp_study
//
//  Created by 형성모 on 2018. 12. 23..
//
//  기본적인 레이싱 프로그램
//


#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define ID_LEN      20
#define MAX_SPEED   200
#define FUEL_STEP   2
#define ACC_STEP    10
#define BREAK_STEP  10

struct car
{
    char userID[ID_LEN];
    int fuel_gauge;
    int current_speed;
};

void ShowCarState(const car &car)
{
    cout<<"user ID : "<<car.userID<<endl;
    cout<<"현재 연료량 : "<<car.fuel_gauge<<"%"<<endl;
    cout<<"현재 속도 : "<<car.current_speed<<"km/h"<<endl;
    cout<<"--------------------------"<<endl;
}

void Accel(car &car)
{
    if(car.fuel_gauge <= 0)
    {
        cout<<"현재 연료가 부족합니다!"<<endl;
        return;
    }
    else car.fuel_gauge -= FUEL_STEP;
    
    if(car.current_speed + ACC_STEP >= MAX_SPEED)
    {
        car.current_speed = MAX_SPEED;
        cout<<"최대 속도 입니다!"<<endl;
        return;
    }
    car.current_speed += ACC_STEP;

}

void Break(car &car)
{
    if(car.current_speed <= 0)
    {
        cout<<"현재 정지상태입니다."<<endl;
        return;
    }
    
    if(car.current_speed - BREAK_STEP <= 0)
    {
        car.current_speed = 0;
        return;
    }
    
    car.current_speed -= BREAK_STEP;
}

void FuelWarning(const car &car)
{
    if(car.fuel_gauge < 6)
    {
        cout<<"연료가 "<<car.fuel_gauge<<"만큼 남았습니다. 충전해주세요."<<endl;
    }
}

int main(void)
{
    car MyCar1 = {"Mycar1", 50, 0};
    Accel(MyCar1);
    Accel(MyCar1);
    Accel(MyCar1);
    Accel(MyCar1);
    ShowCarState(MyCar1);
    Break(MyCar1);
    ShowCarState(MyCar1);
    
    car MyCar2 = {"Mycar2", 50, 0};
    Accel(MyCar2);
    Accel(MyCar2);
    Break(MyCar2);
    ShowCarState(MyCar2);

    return 0;
}
