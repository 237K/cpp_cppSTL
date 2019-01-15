//
//  STL_Algorithm_Mutating.cpp
//  cpp_study
//
//  Created by 형성모 on 15/01/2019.
//
//  STL 알고리즘 #include <algorithm>
//      4. 변경 알고리즘
//          1) next_permutation(v.begin, v.end, (func)) : 다음 조합으로 변경(디폴트:사전순). bool타입 반환
//          2) prev_permutation(v.begin, v.end, (func))
//          3) partition, iterator = partition(v.begin, v.end, func) : func이 참인 원소는 [begin, iterator) 거짓인 원소는 [iterator, end)로 분리. 퀵소트에서 pivot값을 기준으로 큰 값과 작은 값을 분류하듯
//          4) stable_partition(v.begin, v.end, func) : 원소의 상대적인 순서를 유지하며 분리
//          5) random_shuffle(v.begin, v.end, (func)) : 순차열을 랜덤으로 뒤섞음
//          6) reverse(v.begin, v.end) : 순차열 뒤집음
//          7) reverse_copy(v1.begin, v1.end, v2.begin) : 순차열 뒤집어서 복사. v2 마지막 반복자 반환
//          8) rotate(v.begin, middle_iterator, v.end) : 각 원소를 middle_iterator - v.begin 만큼 왼쪽으로 이동
//          9) rotate_copy(v1.begin, middle_iterator, v1.end, v2.begin) : 이동 복사. v2 마지막 반복자 반환
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <ctime>
using namespace std;

/*
template <typename T>
class Point
{
private:
    T xpos, ypos;
public:
    Point(T x=0, T y=0) :xpos(x), ypos(y) {}
    T GetX() const { return xpos; }
    T GetY() const { return ypos; }
    Point& operator()() { return *this; }
    friend ostream& operator<< (ostream& os, const Point<T>& pnt);
};
template <typename T>
ostream& operator<< (ostream& os, const Point<T>& pnt)
{
    os<<"("<<pnt.xpos<<", "<<pnt.ypos<<")"<<endl;
    return os;
}
*/

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) {}
    friend bool Func_Comp(const Point& pnt1, const Point& pnt2);
    friend ostream& operator<< (ostream& os, const Point& pnt);
};
ostream& operator<< (ostream& os, const Point& pnt)
{
    os<<"("<<pnt.xpos<<", "<<pnt.ypos<<")"<<' ';
    return os;
}
bool Func_Comp(const Point& pnt1, const Point& pnt2)
{
    return pnt1.ypos < pnt2.ypos;
}

template <typename T>
void Print(T data)
{
    cout<<data<<' ';
}

template <typename T>
class PrintVector
{
private:
public:
    void operator()(const vector<T>& v)
    {
        for_each(v.begin(), v.end(), Print<T>);
        cout<<endl;
    }
};

bool Func_40under(int n)
{
    return n < 40;
}

int main(void)
{
    bool bool1, bool2;
    int count = 0, count2 = 0;
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    
    //next_permutation
    cout<<"1) next_permutation"<<endl;
    cout<<"v1 : "; PrintVector<int>()(v1);
    cout<<endl;
    
    while (1)
    {
        bool1 = next_permutation(v1.begin(), v1.end());
        if(bool1 == 1)
        {
            cout<<"bool : "<<bool1<<endl;
            cout<<"v1 : "; PrintVector<int>()(v1);
            cout<<"count : "<<++count<<endl<<endl;
        }
        else if(bool1 == 0)
        {
            cout<<"bool : "<<bool1<<endl;
            cout<<"count : "<<count<<endl;
            break;
        }
    }
    
    //next_permutation (func)
    cout<<"next_permutation (func)"<<endl;
    vector<Point> v2;
    v2.push_back(Point(5, 1));
    v2.push_back(Point(7, 2));
    v2.push_back(Point(5, 3));
    cout<<"v2 : "; PrintVector<Point>()(v2);
    cout<<endl;
    
    while (1)
    {
        bool2 = next_permutation(v2.begin(), v2.end(), Func_Comp);
        if(bool2 == 1)
        {
            cout<<"bool : "<<bool2<<endl;
            cout<<"v2 : "; PrintVector<Point>()(v2);
            cout<<"count : "<<++count2<<endl<<endl;
        }
        else
        {
            cout<<"bool : "<<bool2<<endl;
            cout<<"count : "<<count2<<endl;
            break;
        }
    }
    cout<<endl;
    
    //prev_permutation
    cout<<"2) prev_permutation"<<endl;
    vector<int> v3;
    int count3 = 0;
    bool bool3;
    v3.push_back(30);
    v3.push_back(20);
    v3.push_back(10);
    cout<<"v3 : "; PrintVector<int>()(v3);
    cout<<endl;
    
    while (1)
    {
        bool3 = prev_permutation(v3.begin(), v3.end());
        if(bool3 == 1)
        {
            cout<<"bool : "<<bool3<<endl;
            cout<<"v1 : "; PrintVector<int>()(v3);
            cout<<"count : "<<++count3<<endl<<endl;
        }
        else if(bool3 == 0)
        {
            cout<<"bool : "<<bool3<<endl;
            cout<<"count : "<<count3<<endl;
            break;
        }
    }
    cout<<endl;
    
    //partition
    cout<<"3) partition"<<endl;
    vector<int> v4;
    vector<int>::iterator partition_iter;
    vector<int>::iterator iter;
    v4.push_back(30);
    v4.push_back(40);
    v4.push_back(50);
    v4.push_back(10);
    v4.push_back(20);
    v4.push_back(60);
    
    cout<<"v4 : "; PrintVector<int>()(v4);
    cout<<"Partition!"<<endl;
    partition_iter = partition(v4.begin(), v4.end(), Func_40under);
    cout<<"partition_iter : "<<*partition_iter<<endl;
    cout<<"v4 : "; PrintVector<int>()(v4);
    cout<<"40미만 순차열 : ";
    for(iter = v4.begin(); iter != partition_iter; ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    cout<<"40이상 순차열 : ";
    for(iter = partition_iter; iter != v4.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    cout<<endl;
    
    //stable_partition
    cout<<"4) stable_partition"<<endl;
    vector<int> v5;
    v5.push_back(30);
    v5.push_back(40);
    v5.push_back(50);
    v5.push_back(10);
    v5.push_back(20);
    v5.push_back(60);
    
    cout<<"v5 : "; PrintVector<int>()(v5);
    partition_iter = stable_partition(v5.begin(), v5.end(), Func_40under);
    cout<<"partition_iter : "<<*partition_iter<<endl;
    cout<<"v5 : "; PrintVector<int>()(v5);
    cout<<"40미만 순차열 : ";
    for(iter = v5.begin(); iter != partition_iter; ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    cout<<"40이상 순차열 : ";
    for(iter = partition_iter; iter != v5.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    cout<<endl;
    
    //random_shuffle
    cout<<"5) random_shuffle"<<endl;
    cout<<"v5 : "; PrintVector<int>()(v5);
    random_shuffle(v5.begin(), v5.end());
    cout<<"v5 : "; PrintVector<int>()(v5);
    random_shuffle(v5.begin(), v5.end());
    cout<<"v5 : "; PrintVector<int>()(v5);
    random_shuffle(v5.begin(), v5.end());
    cout<<"v5 : "; PrintVector<int>()(v5);
    random_shuffle(v5.begin(), v5.end());
    cout<<"v5 : "; PrintVector<int>()(v5);
    random_shuffle(v5.begin(), v5.end());
    cout<<endl;
    
    srand((unsigned)time(NULL));
    random_shuffle(v5.begin(), v5.end());
    cout<<"v5 : "; PrintVector<int>()(v5);
    random_shuffle(v5.begin(), v5.end());
    cout<<"v5 : "; PrintVector<int>()(v5);
    random_shuffle(v5.begin(), v5.end());
    cout<<"v5 : "; PrintVector<int>()(v5);
    random_shuffle(v5.begin(), v5.end());
    cout<<"v5 : "; PrintVector<int>()(v5);
    random_shuffle(v5.begin(), v5.end());
    cout<<endl<<endl;
    
    //reverse
    cout<<"6) reverse"<<endl;
    cout<<"v5 : "; PrintVector<int>()(v5);
    cout<<"reverse!"<<endl;
    reverse(v5.begin(), v5.end());
    cout<<"v5 : "; PrintVector<int>()(v5);
    cout<<endl<<endl;
    
    //reverse_copy
    cout<<"7) reverse_copy"<<endl;
    vector<int> v6(6);
    vector<int>::iterator reverse_iter;
    cout<<"v5 : "; PrintVector<int>()(v5);
    cout<<"reverse_copy"<<endl;
    reverse_iter = reverse_copy(v5.begin(), v5.end(), v6.begin());
    cout<<"v5 : "; PrintVector<int>()(v5);
    cout<<"v6 : "; PrintVector<int>()(v6);
    cout<<"reverse_iter : "<<*reverse_iter<<endl;
    cout<<endl;
    
    //rotate
    cout<<"8) rotate"<<endl;
    vector<int>::iterator middle_iter = v6.begin() + 2;
    cout<<"v6 : "; PrintVector<int>()(v6);
    cout<<"rotate 2!"<<endl;
    rotate(v6.begin(), middle_iter, v6.end());
    cout<<"v6 : "; PrintVector<int>()(v6);
    cout<<endl;
    
    //rotate_copy
    cout<<"9) rotate_copy"<<endl;
    vector<int> v7(6);
    vector<int>::iterator rotate_iter;
    cout<<"v6 : "; PrintVector<int>()(v6);
    cout<<"rotate and copy!"<<endl;
    rotate_iter = rotate_copy(v6.begin(), middle_iter, v6.end(), v7.begin());
    cout<<"v6 : "; PrintVector<int>()(v6);
    cout<<"v7 : "; PrintVector<int>()(v7);
    cout<<"rotate_copy_iter : "<<*rotate_iter<<endl;
    cout<<endl;
    
}
