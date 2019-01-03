//
//  SpecialFunctionTemplate.cpp
//  cpp_study
//
//  Created by 형성모 on 03/01/2019.
//
//  함수 템플릿의 특수화에 대해 공부했습니다.
//

#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

template <class T>
T Max(T a, T b)
{
    return a > b ? a : b;
}
template<>
char* Max<char*>(char *a, char *b)
{
    return strlen(a) > strlen(b) ? a : b ;
}
template<>
const char* Max<const char*>(const char *a, const char *b)
{
    return strcmp(a, b) > 0 ? a : b ;
}

int main(void)
{
    cout<<Max(11, 15)<<endl;
    cout<<Max(3.5, 7.5)<<endl;
    cout<<Max('T', 'Q')<<endl;
    cout<<Max("Simple", "Best")<<endl;
    
    char str1[] = "Simple";
    char str2[] = "Best";
    cout<<Max(str1, str2)<<endl;
}
