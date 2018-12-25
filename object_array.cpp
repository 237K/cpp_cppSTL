//
//  object_arrary.cpp
//  cpp_study
//
//  Created by 형성모 on 2018. 12. 25..
//
//  객체배열을 공부하고 있습니다.
//  ver2. 객체포인터배열까지 공부했습니다.
//

#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

class Person
{
private:
    char *name;
    int age;
public:
    Person(char * myname, int myage)
    {
        name = new char[strlen(myname)+1];
        strcpy(name, myname);
        age = myage;
    }
    
    Person()
    {
        name = NULL;
        age = 0;
        cout<<"디폴트 생성자를 호출하였습니다."<<endl;
    }
    
    ~Person()
    {
        delete []name;
        cout<<"name에 할당된 동적공간을 해제하였습니다."<<endl;
    }
    
    void SetPerson(char *myname, int myage)
    {
        name = myname;
        age = myage;
    }
    
    void ShowPerson()
    {
        cout<<"이름 : "<<name<<endl;
        cout<<"나이 : "<<age<<endl<<endl;
    }
};

int main(void)
{
    Person *parr[3];
    char namestr[100];
    //char *strptr;
    int age;
    //int len;
    
    for(int i = 0; i < 3; i++)
    {
        cout<<"이름 : ";
        cin>>namestr;
        cout<<"나이 : ";
        cin>>age;
        
        //len = strlen(namestr) + 1;
        //strptr = new char[len];
        //strcpy(strptr, namestr);
        parr[i] = new Person(namestr, age);
    }
    
    for(int i = 0; i < 3; i++)
    {
        parr[i]->ShowPerson();
    }
    
    for(int i = 0; i < 3; i++)
    {
        delete parr[i];
    }
    return 0;
}
