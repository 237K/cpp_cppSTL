//
//  STL_Algorithm_SortedRange.cpp
//  cpp_study
//
//  Created by 형성모 on 16/01/2019.
//
//  STL 알고리즘 #include <algorithm>
//      5. 정렬 알고리즘
//          1) binary_search(b, e, x, (f)) : x와 같은 원소가 있는지 검색 후 bool값으로 반환
//              - 순차열이 정렬되어 있다는 가정 하에 동작
//              - a==b 연산을 사용하지 않고, !(a<b) && !(b<a) equivalence연산을 사용함
//          2) includes(v1.begin, v1.end, v2.begin, v2.end) : v2가 v1의 부분집합이면 true, 아니면 false 반환
//          3) lower_bound, upper_bound(b, e, x, (f)) :  x와 같은 첫원소와 x보다 큰 첫원소의 반복자를 반환
//          4) equal_range(b, e, x, (f)) : x와 같은 원소의 순차열에 대한 반복자쌍을 반환
//          5) merage(v1.begin, v1.end, v2.begin, v2.end, v3.begin) : v1, v2를 합병하여 v3에
//          6) inplace_merge(b, middle_iter, e) : 두 구간을 합병, 정렬
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Func_Comp(int left, int right) { return (right-left) > 3; }

class PrintV
{
public:
    void operator()(const vector<int>& v)
    {
        for(vector<int>::size_type i = 0; i < v.size(); ++i)
        {
            cout<<v[i]<<' ';
        }
        cout<<endl;
    }
};

class Accumalate
{
private:
    int data;
public:
    Accumalate(int n = 0) :data(n) {}
    void operator()(int& n)
    {
        data += 10;
        n += data;
    }
};

class Generate10
{
private:
    int data;
public:
    Generate10(int n=0) :data(n) {}
    int operator()() { return data+=10; }
};

int main(void)
{
    vector<int> v1(10);
    generate(v1.begin(), v1.end(), Generate10());
    
    //binary_search
    cout<<"1) binary_search"<<endl;
    cout<<"v1 : "; PrintV()(v1);
    cout<<endl;
    cout<<"30인 원소가 있는지 binary_search"<<endl;
    if(binary_search(v1.begin(), v1.end(), 30)) cout<<"30이 있습니다."<<endl;
    else cout<<"30이 없습니다."<<endl;
    cout<<endl;
    
    //binary_search(func)
    cout<<"binary_search (func)"<<endl;
    vector<int> v2;
    v2.push_back(40);
    v2.push_back(46);
    v2.push_back(12);
    v2.push_back(80);
    v2.push_back(10);
    v2.push_back(47);
    v2.push_back(30);
    v2.push_back(55);
    v2.push_back(90);
    v2.push_back(53);
    
    cout<<"v2 : "; PrintV()(v2);
    cout<<endl;
    cout<<"인접한 원소의 차이가 3이상이면 true인 조건자를 기준으로 정렬"<<endl;
    sort(v2.begin(), v2.end(), Func_Comp);
    cout<<"v2 : "; PrintV()(v2);
    cout<<endl;
    
    cout<<"32를 만족하는 원소가 있는지 binary_search(같은 조건 사용)"<<endl;
    if(binary_search(v2.begin(), v2.end(), 32, Func_Comp)) cout<<"32를 만족하는 원소가 있습니다."<<endl;
    else cout<<"32를 만족하는 원소가 없습니다."<<endl;
    cout<<endl;
       
    cout<<"35를 만족하는 원소가 있는지 검색"<<endl;
    if(binary_search(v2.begin(), v2.end(), 35, Func_Comp)) cout<<"35를 만족하는 원소가 있습니다."<<endl;
    else cout<<"35를 만족하는 원소가 없습니다."<<endl;
    cout<<endl;
    
    //includes
    cout<<"2) includes"<<endl;
    vector<int> v3(5);
    vector<int> v4;
    vector<int> v5;
    for_each(v3.begin(), v3.end(), Accumalate());
    v4.push_back(10);
    v4.push_back(20);
    v4.push_back(40);
    v5.push_back(10);
    v5.push_back(20);
    v5.push_back(60);
    cout<<"v3 : "; PrintV()(v3);
    cout<<"v4 : "; PrintV()(v4);
    cout<<"v5 : "; PrintV()(v5);
    cout<<endl;
    if(includes(v3.begin(), v3.end(), v4.begin(), v4.end())) cout<<"v4는 v3의 부분집합입니다."<<endl;
    else cout<<"v4는 v3의 부분집합이 아닙니다."<<endl<<endl;
    if(includes(v3.begin(), v3.end(), v5.begin(), v5.end())) cout<<"v5는 v3의 부분집합입니다."<<endl;
    else cout<<"v5는 v3의 부분집합이 아닙니다."<<endl<<endl;
    
    //lower_bound, upper_bound
    cout<<"3) lower_bound"<<endl;
    vector<int> v6;
    vector<int>::iterator iter;
    v6.push_back(50);
    v6.push_back(70);
    v6.push_back(10);
    v6.push_back(40);
    v6.push_back(60);
    v6.push_back(80);
    v6.push_back(20);
    v6.push_back(40);
    v6.push_back(90);
    v6.push_back(40);
    
    cout<<"v6 : "; PrintV()(v6);
    cout<<"sort"<<endl;
    sort(v6.begin(), v6.end());
    cout<<"v6 : "; PrintV()(v6);
    
    vector<int>::iterator lower_iter;
    vector<int>::iterator upper_iter;
    lower_iter = lower_bound(v6.begin(), v6.end(), 40);
    upper_iter = upper_bound(v6.begin(), v6.end(), 40);
    cout<<endl;
    cout<<"lower_iter : "<<*lower_iter<<endl;
    cout<<"upper_iter : "<<*upper_iter<<endl;
    cout<<"40 순차열 : ";
    for(iter = lower_iter; iter != upper_iter; ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
    
    //equal_range
    cout<<"4) equal_range"<<endl;
    pair<vector<int>::iterator, vector<int>::iterator> equal_iter;
    equal_iter = equal_range(v6.begin(), v6.end(), 40);
    cout<<"equal_iter.first : "<<*equal_iter.first<<endl;
    cout<<"equal_iter.second : "<<*(equal_iter.second)<<endl;
    cout<<"40순차열 : ";
    for(iter = equal_iter.first; iter != equal_iter.second; ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
    
    //merge
    cout<<"5) merge"<<endl;
    vector<int> v7(20);
    vector<int>::iterator merge_iter;
    cout<<"v3 : "; PrintV()(v3);
    cout<<"v6 : "; PrintV()(v6);
    cout<<endl;
    cout<<"merge(v3, v6, v7)"<<endl;
    merge_iter = merge(v3.begin(), v3.end(), v6.begin(), v6.end(), v7.begin());
    cout<<"v3 : "; PrintV()(v3);
    cout<<"v6 : "; PrintV()(v6);
    cout<<"v7 : "; PrintV()(v7);
    cout<<endl;
    
    //inplace_merge
    cout<<"6) inplace_merge"<<endl;
    vector<int> v8;
    v8.push_back(10);
    v8.push_back(20);
    v8.push_back(30);
    v8.push_back(40);
    v8.push_back(50);
    
    v8.push_back(20);
    v8.push_back(30);
    v8.push_back(60);
    
    vector<int>::iterator middle_iter = v8.begin() + 5;
    
    cout<<"v8 : "; PrintV()(v8);
    cout<<"inplace_merge"<<endl;
    cout<<"middle_iter : "<<*middle_iter<<endl;
    inplace_merge(v8.begin(), middle_iter, v8.end());
    cout<<"v8 : "; PrintV()(v8);
    cout<<endl;
    
}
