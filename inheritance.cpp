//
//  inheritance.cpp
//  cpp_study
//
//  Created by 형성모 on 27/12/2018.
//
//  *드디어 상속에 대해 공부하였습니다!
//  유도(derived) 클래스의 생성자 호출 시에 기초(base) 클래스의 멤버변수를 초기화해야 합니다.(이니셜라이즈를 통해 기초클래스 생성자를 호출해야 합니다.)
//  만약 기초클래스 멤버변수의 초기화에 대해 명시되어있지 않다면, 기초클래스의 void형 생성자가 자동으로 호출됩니다.

#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

class Person
{
private:
    int age;
    char *name;
public:
    static int PersonCount;
public:
    Person(){ PersonCount++; }
    Person(int myage, char *myname) :age(myage)
    {
        
        name = new char[strlen(myname)+1];
        strcpy(name, myname);
        //name = (char*)myname;
        PersonCount++;
    }
    ~Person()
    {
        delete []name;
    }
    void PrintName() const
    {
        cout<<"My name is "<<name<<endl;
    }
    void PrintAge() const
    {
        cout<<"I'm "<<age<<" years old."<<endl;
    }
    /*
    static void PrintPerCount()
    {
        cout<<"Person Count : "<<PersonCount<<endl;
    }
     */
};

int Person::PersonCount = 0;

class UnivStudent : public Person
{
private:
    char *major;
public:
    static int StudentCount;
public:
    UnivStudent(){ StudentCount++; }
    UnivStudent(int myage, char *myname, char *mymajor) : Person(myage, myname)
    {
        major = new char[strlen(mymajor)+1];
        strcpy(major, mymajor);
        //major = (char*)mymajor;
        StudentCount++;
    }
    ~UnivStudent()
    {
        delete []major;
    }
    void PrintInfo()
    {
        PrintName();
        PrintAge();
        cout<<"My major is "<<major<<endl<<endl;
    }
    /*
    static void PrintStuCount()
    {
        cout<<"Student Count : "<<StudentCount<<endl;

    }
     */
};

int UnivStudent::StudentCount = 0;
/*
void PrintCount()
{
    Person::PrintPerCount();
    UnivStudent::PrintStuCount();
}
*/

int main(void)
{
    /*
    UnivStudent stu1;
    //PrintCount();
    cout<<"Person Count : "<<Person::PersonCount<<endl;
    cout<<"Student Count : "<<UnivStudent::StudentCount<<endl;
    stu1.PrintInfo();
    */
    
    char name1[50] = {'L','E','E'};
    char name2[50] = {'H','Y','E','O','N','G'};
    char major1[50] = {'E','C','O','N','O','M','I','C','S'};
    char major2[100] = {'C','O','M','P','U','T','E','R',' ','E','N','G','I','N','E','E','R','I','N','G'};
    
    /*
    cout<<"name : "; cin>>name1;
    cout<<"major : "; cin>>major1;
    cout<<endl;
    cout<<"name : "; cin>>name2;
    cout<<"major : "; cin>>major2;
    */
    
    UnivStudent stu2(24, name1, major1);
    //PrintCount();
    cout<<"Person Count : "<<Person::PersonCount<<endl;
    cout<<"Student Count : "<<UnivStudent::StudentCount<<endl;
    stu2.PrintInfo();
   
    UnivStudent stu3(24, name2, major2);
    //PrintCount();
    cout<<"Person Count : "<<Person::PersonCount<<endl;
    cout<<"Student Count : "<<UnivStudent::StudentCount<<endl;
    stu3.PrintInfo();
}
