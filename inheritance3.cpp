//
//  inheritance3.cpp
//  cpp_study
//
//  Created by 형성모 on 28/12/2018.
//
//  상속과 관련된 예시문제를 풀어보았습니다.
//
//

#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

class FriendInfo
{
private:
    char *name;
    int age;
public:
    FriendInfo() :age(0) {}
    FriendInfo(char *name, int age)
    {
        this->age = age;
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
    }
    ~FriendInfo()
    {
        delete []name;
    }
    void ShowMyFriend()
    {
        cout<<"이름 : "<<name<<endl;
        cout<<"나이 : "<<age<<endl;
    }
};

class FriendDetail : public FriendInfo
{
private:
    char *address;
    char *mobile;
public:
    FriendDetail() :FriendInfo() {}
    FriendDetail(char *name, int age, char *address, char *mobile) :FriendInfo(name, age)
    {
        this->address = new char[strlen(address)+1];
        strcpy(this->address, address);
        
        this->mobile = new char[strlen(mobile)+1];
        strcpy(this->mobile, mobile);
    }
    ~FriendDetail()
    {
        delete []address;
        delete []mobile;
    }
    void ShowMyFriendDetail()
    {
        ShowMyFriend();
        cout<<"주소 : "<<address<<endl;
        cout<<"폰번호 : "<<mobile<<endl;
    }
};

int main(void)
{
    char _name[50] = {'L','E','E'};
    char _address[50] = {'S','E','O','U','L'};
    char _mobile[50] = {'0','1','0','-','1','1','1','1','-','1','1','1','1'};
    
    char *name1 = _name;
    int age1 = 29;
    char *address1 = _address;
    char *mobile1 = _mobile;
    /*
    FriendInfo friend1;
    cout<<"FriendInfo()"<<endl;
    friend1.ShowMyFriend();
    */
    FriendInfo friend2(name1, age1);
    cout<<"FriendInfo(name, age)"<<endl;
    friend2.ShowMyFriend();
    /*
    FriendDetail friend3;
    cout<<"FriendDetail()"<<endl;
    friend3.ShowMyFriendDetail();
    */
    FriendDetail friend4(name1, age1, address1, mobile1);
    cout<<"FriendDetail(name, age, address, mobile)"<<endl;
    friend4.ShowMyFriendDetail();
    
    return 0;
}
