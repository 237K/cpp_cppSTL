//
//  racing_game.cpp
//  cpp_study
//
//  Created by 형성모 on 2018. 12. 23..
//
//  매우 기초적인 레이싱 프로그램
//  ver2. 함수가 구조체에 종속적이므로, 함수를 구조체 안에 포함시켜 구현


#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/* 기존에는 함수를 구조체 밖에 구현하였음.
 
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
*/

//함수를 구조체 안에 포함시킨 형태

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

struct car
{
    char userID[CAR_CONST::ID_LEN];
    int fuel_gauge;
    int current_speed;

    void ShowCarState()
    {
        cout<<"user ID : "<<userID<<endl;
        cout<<"현재 연료량 : "<<fuel_gauge<<"%"<<endl;
        cout<<"현재 속도 : "<<current_speed<<"km/h"<<endl;
        cout<<"--------------------------"<<endl;
    }
    
    void Accel()
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
    
    void Break()
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
    
    void FuelWarning()
    {
        if(fuel_gauge < 6)
        {
            cout<<"연료가 "<<fuel_gauge<<"만큼 남았습니다. 충전해주세요."<<endl;
        }
    }
};

int main(void)
{
    car MyCar1 = {"Mycar1", 100, 0};
    MyCar1.Accel();
    MyCar1.Accel();
    MyCar1.Accel();
    MyCar1.Accel();
    MyCar1.ShowCarState();
    MyCar1.Break();
    MyCar1.ShowCarState();
    
    car MyCar2 = {"Mycar2", 100, 0};
    MyCar2.Accel();
    MyCar2.Accel();
    MyCar2.Break();
    MyCar2.ShowCarState();
    
    return 0;
}
