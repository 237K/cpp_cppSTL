//
//  AssignOperation.cpp
//  cpp_study
//
//  Created by 형성모 on 1/1/2019.
//
//  대입연산자 오버로딩에 대해 공부했습니다.
//  대입연산자를 정의하지 않아 디폴트 대입연산자가 호출되었을 경우, 복사생성자의 경우와 마찬가지고 얕은 복사가 일어난다는 것을 이해했습니다.
//  생성자 내에서 동적할당을 한 경우에 얕은복사가 일어나면 2가지 문제가 발생하는데,
//  Person person1 = person2를 예로 들면, 하나의 변수를 두개가 포인터참조하게 됩니다. 이로 인해
//  1. 우변의 person2가 가리키던 변수의 주소를 잃어버려서 delete할 수 없으므로 메모리누수가 발생합니다.
//  2. person2의 delete로 변수가 삭제되고나서 person1의 delete가 중복으로 해당 주소를 삭제합니다. 결과적으로 소멸자가 한 번만 호출됩니다.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Person
{
private:
    char *name;
    int age;
public:
    Person(char *name, int age) : age(age)
    {
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
    }
    
    Person& operator=(const Person &cpy)
    {
        delete []name;                              //메모리누수를 방지하기 위함입니다***
        name = new char[strlen(cpy.name)+1];
        strcpy(name, cpy.name);
        age = cpy.age;
        return *this;
    }
    
    void ShowPerson() const
    {
        cout<<"이름 : "<<name<<endl;
        cout<<"나이 : "<<age<<endl;
    }
    
    ~Person()
    {
        delete []name;
        cout<<"소멸자가 호출되었습니다."<<endl;
    }
};

int main(void)
{
    char name1[20] = {'L','E','E'};
    char name2[20] = {'H','Y','E','O','N','G'};
    
    Person person1(name1, 29);
    Person person2(name2, 29);
    
    person2 = person1;
    
    person1.ShowPerson();
    person2.ShowPerson();
    
    return 0;
}
