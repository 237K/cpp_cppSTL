//
//  STL_Algorithm_Remove.cpp
//  cpp_study
//
//  Created by 형성모 on 14/01/2019.
//
//  STL 알고리즘 #include <algorithm>
//      3. 제거 알고리즘
//          1) remove(_if)(v1.begin, v1.end, x(func)) : v1에서 x를 없앰. 다음 원소를 한 칸씩 땡겨와 덮어씀. 사이즈는 변하지 않음
//          2) v1.erase(remove_iter(remove로 반환받은 iterator), v1.end) : 원소를 제거. 사이즈까지 줄임
//          3) remove_copy(_if)(v1.begin, v1.end, v2.begin, x(funx)) : x(func)를 제거한 후 v2에 복사. v1은 변경하지 않음
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(const vector<int>& v)
{
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

bool Func_20to30(int n)
{
    return (n >= 20 && n <= 30) ? true : false;
}

template <typename T>
class Integer10
{
private:
    T data;
public:
    Integer10(int n = 0) :data(n) {}
    int operator()()
    {
        data += 10;
        return data;
    }
};

int main(void)
{
    vector<int> v1(5);
    vector<int>::iterator iter;
    generate(v1.begin(), v1.end(), Integer10<int>());
    
    //remove
    cout<<"1) remove"<<endl;
    vector<int>::iterator remove_iter;
    cout<<"v1 : "; Print(v1);
    cout<<"v1 size : "<<v1.size()<<endl;
    cout<<endl;
    cout<<"remove 30"<<endl;
    remove_iter = remove(v1.begin(), v1.end(), 30);
    cout<<"v1 : "; Print(v1);
    cout<<"v1 size : "<<v1.size()<<endl;
    cout<<endl;
    /*
    for(iter = v1.begin(); iter != remove_iter; ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    */
    
    //erase
    cout<<"2) erase"<<endl;
    cout<<"v1 : "; Print(v1);
    cout<<"v1 size : "<<v1.size()<<endl;
    cout<<endl;
    cout<<"v1.erase(remove_iter, v1.end())"<<endl;
    v1.erase(remove_iter, v1.end());
    cout<<"v1 : "; Print(v1);
    cout<<"v1 size : "<<v1.size()<<endl;
    cout<<endl;
    
    //remove_copy_if
    cout<<"3) remove_copy_if"<<endl;
    cout<<"v1 : "; Print(v1);
    cout<<"v1 size : "<<v1.size()<<endl;
    cout<<endl;
    cout<<"remove copy"<<endl;
    vector<int> v2(4);
    remove_iter = remove_copy_if(v1.begin(), v1.end(), v2.begin(), Func_20to30);
    cout<<"v1 : "; Print(v1);
    cout<<"v1 size : "<<v1.size()<<endl;
    cout<<"v2 : "; Print(v2);
    cout<<"v2 size : "<<v2.size()<<endl;
    cout<<"[v2.begin(), remove_iter) : ";
    for(iter = v2.begin(); iter != remove_iter; ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
    
    
    return 0;
}
