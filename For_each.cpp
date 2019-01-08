//
//  For_each.cpp
//  cpp_study
//
//  Created by 형성모 on 08/01/2019.
//
//  For_each 템플릿을 구현해보았습니다.
//

#include <iostream>
#include <string>
using namespace std;

template <typename T, typename Func>
void For_each(T begin, T end, Func pf)
{
    while(begin!=end)
    {
        pf(*begin++);
    }
}

template <typename T>
class Print
{
private:
    string sep;
public:
    explicit Print(const string& str=" ") :sep(str) {}
    void operator() (T data) const
    {
        cout<<data<<sep;
    }
};

int main(void)
{
    int int_arr[5] = {11, 22, 33, 44, 55};
    string str_arr[3] = {"Hello", "Hi", "NTY"};
    
    //For_each<int*, void (*)(int)>(int_arr, int_arr+5, Print<int>);
    For_each(int_arr, int_arr+5, Print<int>());
    cout<<endl;
    //For_each<string* void (*)(string)>(str_arr, str_arr+5, Print<string>);
    For_each(str_arr, str_arr+3, Print<string>("*\n"));
    cout<<endl;
    
    return 0;
}
