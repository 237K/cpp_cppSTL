//
//  StringProblem1.cpp
//  cpp_study
//
//  Created by 형성모 on 07/01/2019.
//
//  string 관련 예시문제 1, 2. 다음이 컴파일 될 수 있게 최소한의 String class를 작성하세요.
//  String s("Hello!");
//  const char* sz = s;

//  const char* sz = "Hello!";
//  String s("Hi~!");
//  s = sz;

#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
    char* str;
public:
    String(char* str)
    {
        this->str = new char[strlen(str)+1];
        strcpy(this->str, str);
    }
    operator const char*()
    {
        return str;
    }
    String& operator=(const char* sz)
    {
        delete []str;
        str = new char[strlen(sz)+1];
        strcpy(str, sz);
        return *this;
    }
    void ShowString() const
    {
        cout<<str<<endl;
    }
    ~String()
    {
        delete []str;
    }
};

int main(void)
{
    String s("Hello!");
    const char* sz = s;
    
    cout<<"[1번 문제]"<<endl;
    cout<<"s : "; s.ShowString();
    cout<<"sz : "<<sz<<endl;
    
    const char* st = "Hello!";
    String t("Hi~!");
    t = st;
    
    cout<<"[2번 문제]"<<endl;
    cout<<"t : "; t.ShowString();
    cout<<"st : "<<st<<endl;
    
}
