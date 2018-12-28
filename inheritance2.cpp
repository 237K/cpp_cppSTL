//
//  inheritance2.cpp
//  cpp_study
//
//  Created by 형성모 on 28/12/2018.
//
//  상속과 관련된 예시문제를 풀어보았습니다.
//  가솔린차, 가솔린과 전기를 사용하는 하이브리드차, 가솔린, 전기 그리고 물을 사용하는 하이브리드워터차에 대한 클래스를 상속관계로 구현합니다.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Car
{
private:
    int gasolineGuage;
public:
    Car() :gasolineGuage(0) {}
    Car(int gasoline) :gasolineGuage(gasoline) {}
    ~Car(){}
    int GetGasolineGuage()
    {
        return gasolineGuage;
    }
};

class HybridCar : public Car
{
private:
    int electricGuage;
public:
    HybridCar() :Car(), electricGuage(0) {}
    HybridCar(int elec) :Car(), electricGuage(elec) {}
    HybridCar(int gasoline, int elec) :Car(gasoline), electricGuage(elec) {}
    ~HybridCar(){}
    int GetElecGuage()
    {
        return electricGuage;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGuage;
public:
    HybridWaterCar() :HybridCar(), waterGuage(0) {}
    HybridWaterCar(int water) :HybridCar(), waterGuage(water) {}
    HybridWaterCar(int elec, int water) :HybridCar(elec), waterGuage(water) {}
    HybridWaterCar(int gasoline, int elec, int water) :HybridCar(gasoline, elec), waterGuage(water) {}
    ~HybridWaterCar(){}
    void ShowCurrentGuage()
    {
        cout<<"잔여 가솔린 : "<<GetGasolineGuage()<<endl;
        cout<<"잔여 전기량 : "<<GetElecGuage()<<endl;
        cout<<"잔여 워터량 : "<<waterGuage<<endl<<endl;
    }
};

int main(void)
{
    Car car1;
    cout<<"Car car1 가솔린 : "<<car1.GetGasolineGuage()<<endl;
    Car car2(100);
    cout<<"Car car2 가솔린 : "<<car2.GetGasolineGuage()<<endl<<endl<<endl;;
    
    HybridCar hybrid1;
    cout<<"HybridCar hybrid1 가솔린 : "<<hybrid1.GetGasolineGuage()<<endl;
    cout<<"HybridCar hybrid1 전기량 : "<<hybrid1.GetElecGuage()<<endl<<endl;
    HybridCar hybrid2(100);
    cout<<"HybridCar hybrid2 가솔린 : "<<hybrid2.GetGasolineGuage()<<endl;
    cout<<"HybridCar hybrid2 전기량 : "<<hybrid2.GetElecGuage()<<endl<<endl;
    HybridCar hybrid3(100, 100);
    cout<<"HybridCar hybrid3 가솔린 : "<<hybrid3.GetGasolineGuage()<<endl;
    cout<<"HybridCar hybrid3 전기량 : "<<hybrid3.GetElecGuage()<<endl<<endl<<endl;
    
    HybridWaterCar water1;
    water1.ShowCurrentGuage();
    HybridWaterCar water2(100);
    water2.ShowCurrentGuage();
    HybridWaterCar water3(100, 100);
    water3.ShowCurrentGuage();
    HybridWaterCar water4(100, 100, 100);
    water4.ShowCurrentGuage();
    
    return 0;
}
