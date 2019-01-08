//
//  Less_Greater.cpp
//  cpp_study
//
//  Created by 형성모 on 08/01/2019.
//
//  less, greater 템플릿을 구현하여 STL과 비교해보았습니다.
//

#include <iostream>
#include <functional>
using namespace std;

template <typename T>
class Less
{
public:
    bool operator() (T a, T b)
    {
        return a<b;
    }
};

template <typename T>
class Greater
{
public:
    bool operator() (T a, T b)
    {
        return a>b;
    }
};

int main(void)
{
    cout<<"user's Less : "<<Less<int>()(10, 20)<<endl;
    cout<<"STL's less : "<<less<int>()(10, 20)<<endl;
    cout<<"user's Greater : "<<Greater<int>()(10, 20)<<endl;
    cout<<"STL's greater : "<<greater<int>()(10, 20)<<endl;
    
    return 0;
}
