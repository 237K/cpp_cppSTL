//
//  StringClass.cpp
//  cpp_study
//
//  Created by 형성모 on 02/01/2019.
//
//  표준 string 클래스의 기능 중 몇 가지를 흉내낸 string 클래스를 구현해보았습니다.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class String
{
private:
    char *str;
    int len;
public:
    String() : len(0)
    {
        str = NULL;
    }
    String(const char *str)
    {
        len = (int)(strlen(str)+1);
        this->str = new char[len];
        strcpy(this->str, str);
    }
    String(const String& cpy)
    {
        this->len = cpy.len;
        this->str = new char[len];
        strcpy(this->str, cpy.str);
    }
    String& operator=(const String &assign)
    {
        if(str != NULL) delete []str;
        len = assign.len;
        this->str = new char[len];
        strcpy(this->str, assign.str);
        return *this;
    }
    String operator+(const String &str1)
    {
        char *temp = new char[len + str1.len - 1];
        strcpy(temp, str);
        strcat(temp, str1.str);
        String Temp(temp);
        delete []temp;
        return Temp;
    }
    String& operator+=(const String &str1)
    {
        this->len += str1.len;
        char *temp = new char[len];
        strcpy(temp, str);
        strcat(temp, str1.str);
        
        if(str != NULL) delete []str;
        str = temp;
        return *this;
    }
    bool operator==(const String &str1)
    {
        return strcmp(str, str1.str) ? false : true;
    }
    ~String()
    {
        if(str != NULL) delete []str;
    }
    
    friend ostream& operator<<(ostream& os, const String &str1);
    friend istream& operator>>(istream& is, String &str1);
};

ostream& operator<<(ostream& os, const String &str1)
{
    os<<str1.str;
    return os;
}

istream& operator>>(istream& is, String &str1)
{
    char *temp = new char[100];
    is>>temp;
    String Temp(temp);
    str1 = Temp;
    delete []temp;
    return is;
    
    /*
    char *temp = new char[100];
    is>>temp;
    str1.len = strlen(temp);
    str1.str = new char[str1.len];
    strcpy(str1.str, temp);
    delete []temp;
    return is;
     */
}

int main(void)
{
    String str1 = "I like it ";
    String str2("string class");
    String str3 = str1 + str2;
    
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;
    
    str1 += str2;
    if(str3 == str1) cout<<"str1과 str3은 동일합니다!"<<endl;
    else cout<<"동일하지 않습니다."<<endl;
    
    String str4;
    cout<<"문자열 입력 : "; cin>>str4;
    cout<<"입력한 문자열은 : "<<str4<<endl;
    
    return 0;
}
