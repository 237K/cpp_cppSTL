//
//  Pair.cpp
//  cpp_study
//
//  Created by 형성모 on 08/01/2019.
//
//  STL에서 데이터쌍을 표현할 때 사용하는 pair를 구현한 후 STL과 비교해보았습니다.
//

#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
class Pair
{
public:
    T1 first;
    T2 second;
public:
    Pair(const T1& ft, const T2& sc) : first(ft), second(sc) {}
};

int main(void)
{
    cout<<"[STL의 pair]"<<endl;
    pair<int, int> p1(10, 20);
    cout<<p1.first<<", "<<p1.second<<endl;
    pair<int, string> p2(1, "STL pair");
    cout<<p2.first<<", "<<p2.second<<endl<<endl;
    
    cout<<"[직접 구현한 Pair]"<<endl;
    Pair<int, int> p3(10, 20);
    cout<<p3.first<<", "<<p3.second<<endl;
    Pair<int, string> p4(1, "User Pair");
    cout<<p4.first<<", "<<p4.second<<endl;
    
    return 0;
}
