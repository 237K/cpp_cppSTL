//
//  STL_Algorithm_Nonmodifying.cpp
//  cpp_study
//
//  Created by 형성모 on 11/01/2019.
//
//  STL 알고리즘 #include <algorithm>
//      1. 원소를 수정하지 않는 알고리즘
//          1) adjacent_find(v.begin(), v.end(), (func)) : 순차열에서 현재 원소와 다음 원소가 같아지는 첫 원소의 반복자 반환
//          2) count(_if)(v.begin(), v.end(), num(func)) : num의 개수를 반환 (func을 만족하는 원소 개수 반환)
//          3) equal(v1.begin(), v1.end(), v2.begin(), (func)) : v1[begin, end)구간 기준 v2의 해당 구간과 비교, bool반환
//          4) find(_if)(v.begin(), v.end(), num(func)) : [begin, end)구간에서 num과 같은 첫번째 원소 반환
//          5) find_end(v1.begin(), v1.end(), v2.begin(), v2.end(), (func)) : v1에 v2와 같은 순차열이 있는지 확인, 마지막 순차열의 첫 번째 원소반환
//          6) find_first_of(v.begin(), v.end(), v2.begin(), v2.end(), (func)) : find_end처럼 구간 검색, 모든 원소 중 같은 원소가 하나라도 발견되면 발견된 첫 번쩨 원소의 반복자 반환
//          7) for_each(v.begin(), v.end(), func()) : 구간의 모든 원소에 대해 func을 적용. 원소를 수정하는 알고리즘에도 포함
//          8) lexicographical_compare(v.begin(), v.end(), v2.begin(), v2.end(), (func)) : 사전편찬식으로 비교
//          9) max, min(v.begin(), v.end(), (func))
//          10) max_element, min_element(v.begin(), v.end(), (func))
//          11) mismatch(v1.begin(), v1.end(), v2.begin(), (func)) : 원소 값이 다른 첫 원소의 반복자 반환
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool Pred_1var(int n)
{
    return n > 30 ? true : false;
}

bool Pred_2var(int left, int right)
{
    return abs(right - left) < 15;
}

bool Pred_ffo(int left, int right)
{
    return left > right ? true : false;
}

template <typename T>
void Print(const T& t)
{
    cout<<t<<' ';
}

template <typename T>
class PrintVector
{
private:
    char ch;
public:
    explicit PrintVector(char c = ' ') :ch(c) {}
    void operator()(const T& t)
    {
        cout<<t<<ch;
    }
};

class Point
{
private:
    int xpos, ypos;
public:
    explicit Point(int x=0, int y=0) :xpos(x), ypos(y) {}
    int GetX() const { return xpos; }
    int GetY() const { return ypos; }
    void Print() const { cout<<"("<<xpos<<", "<<ypos<<")"<<endl; }
    friend ostream& operator<<(ostream& os, const Point& pnt);
};
ostream& operator<<(ostream& os, const Point& pnt)
{
    os<<"("<<pnt.xpos<<", "<<pnt.ypos<<")"<<endl;
    return os;
}
bool Xcompare(const Point& pnt1, const Point& pnt2)
{
    return pnt1.GetX() < pnt2.GetX() ? true : false;
}
bool Ycompare(const Point& pnt1, const Point& pnt2)
{
    return pnt1.GetY() < pnt2.GetY() ? true : false;
}
bool Pcompare(const Point& pnt1, const Point& pnt2)
{
    if(pnt1.GetX() < pnt2.GetX()) return true;
    else if(pnt1.GetX() == pnt2.GetX() && pnt1.GetY() <= pnt2.GetY()) return true;
    else return false;
}

int main(void)
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    
    vector<int>::iterator iter;
    for(iter = v.begin(); iter != v.end(); ++iter)
    {
        cout<<*iter<<" ";
    }
    cout<<endl<<endl;
    
    //adjacent_find
    vector<int>::iterator adjacent_iter;
    adjacent_iter = adjacent_find(v.begin(), v.end());
    
    if(adjacent_iter != v.end()) cout<<"adjacent_iter : "<<*adjacent_iter<<endl;
    
    for( ; adjacent_iter != v.end(); ++adjacent_iter)
    {
        cout<<*adjacent_iter<<" ";
    }
    cout<<endl<<endl;
    
    //count, count_if
    cout<<"40의 개수 : "<<count(v.begin(), v.end(), 40)<<endl;
    
    cout<<"30보다 큰 원소 개수 : "<<count_if(v.begin(), v.end(), Pred_1var)<<endl;
    cout<<endl;
    
    //equal
    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    
    bool bl = equal(v2.begin(), v2.end(), v.begin());
    cout<<"v2 [begin, end) 구간과 v 비교 : "<<bl<<endl;
    cout<<"v2, v 각 원소의 차이가 15보다 작은지 비교 : "<<equal(v2.begin(), v2.end(), v.begin(), Pred_2var)<<endl;
    cout<<endl;
    
    //find, find_if
    vector<int>::iterator find_iter;
    find_iter = find(v.begin(), v.end(), 40);
    cout<<"40과 같은 원소를 찾습니다 "<<*find_iter<<endl;
    find_iter = find_if(v.begin(), v.end(), Pred_1var);
    cout<<"30보다 큰 첫 번째 원소를 찾습니다 "<<*find_iter<<endl;
    cout<<endl;
    
    //find_end
    for(iter = v.begin(); iter != v.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    for(iter = v2.begin(); iter != v2.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    vector<int>::iterator find_end_iter;
    find_end_iter = find_end(v.begin(), v.end(), v2.begin(), v2.end());
    if(find_end_iter != v.end())
    {
        cout<<"find_end_iter = "<<*find_end_iter<<endl;
        cout<<"find_end_iter - 1 = "<<*(find_end_iter-1)<<endl;
        cout<<"find_end_iter + 1 = "<<*(find_end_iter+1)<<endl;
    }
    cout<<endl;
    
    //find_first_of
    for(iter = v.begin(); iter != v.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    for(iter = v2.begin(); iter != v2.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    vector<int>::iterator find_first_iter;
    find_first_iter = find_first_of(v.begin(), v.end(), v2.begin(), v2.end());
    if(find_first_iter == v.end()) cout<<"같은 원소가 없습니다"<<endl;
    cout<<"find_first_iter = "<<*find_first_iter<<endl;
    cout<<endl;
    
    //find_first_of(func)
    find_first_iter = find_first_of(v.begin(), v.end(), v2.begin(), v2.end(), Pred_ffo);
    if(find_first_iter == v.end()) cout<<"조건과 일치하는 원소가 없습니다"<<endl;
    cout<<"find_first_iter = "<<*find_first_iter<<endl;
    cout<<endl;
    
    //for_each
    cout<<"for_each를 이용한 출력"<<endl;
    for_each(v.begin(), v.end(), Print<int>);
    cout<<endl;
    for_each(v2.begin(), v2.end(), Print<int>);
    cout<<endl<<endl;
    
    //for_each functor 호출
    cout<<"for_each에서 functor를 호출"<<endl;
    for_each(v.begin(), v.end(), PrintVector<int>());
    cout<<endl;
    for_each(v.begin(), v.end(), PrintVector<int>(','));
    cout<<endl;
    for_each(v2.begin(), v2.end(), PrintVector<int>('\n'));
    cout<<endl<<endl;
    
    //lexicographical_compare
    cout<<"lexicographical_compare"<<endl;
    vector<int> v3;
    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(50);
    for(iter = v.begin(); iter != v.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    for(iter = v2.begin(); iter != v2.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    for(iter = v3.begin(); iter != v3.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    bool bl2 = lexicographical_compare(v.begin(), v.end(), v3.begin(), v3.end());
    bool bl3 = lexicographical_compare(v.begin(), v.end(), v2.begin(), v2.end());
    bool bl4 = lexicographical_compare(v.begin(), v.end(), v3.begin(), v3.end(), greater<int>());
    bool bl5 = lexicographical_compare(v.begin(), v.end(), v2.begin(), v2.end(), greater<int>());
    
    if(bl2) cout<<"v < v3"<<endl;
    else cout<<"v >= v3"<<endl;
    
    if(bl3) cout<<"v < v2"<<endl;
    else cout<<"v >= v2"<<endl;
    cout<<endl;
    
    //lexicographical_compare, greater
    cout<<"lexicographical_compare을 greater로 비교"<<endl;
    if(bl4) cout<<"v > v3 ? True"<<endl;
    else cout<<"v > v3 ? False"<<endl;
    
    if(bl5) cout<<"v > v2 ? True"<<endl;
    else cout<<"v > v2 ? False"<<endl;
    cout<<endl;
    
    //max, min
    cout<<"max, min"<<endl;
    Point pt1(5, 8), pt2(3, 9), pt3;
    cout<<"Point1 : "<<pt1;
    cout<<"Point2 : "<<pt2;
    pt3 = max(pt1, pt2, Xcompare);
    cout<<"max(Point1, Point2, X) : "<<pt3;
    pt3 = max(pt1, pt2, Ycompare);
    cout<<"max(Point1, Point2, Y) : "<<pt3;
    pt3 = min(pt1, pt2, Xcompare);
    cout<<"min(Point1, Point2, X) : "<<pt3;
    pt3 = min(pt1, pt2, Ycompare);
    cout<<"min(Point1, Point2, Y) : "<<pt3;
    cout<<endl;
    
    //max_element, min_element
    vector<int>::iterator max_iter;
    vector<int>::iterator min_iter;
    max_iter = max_element(v.begin(), v.end());
    min_iter = min_element(v.begin(), v.end());
    cout<<"max_iter : "<<*max_iter<<endl;
    cout<<"min_iter : "<<*min_iter<<endl;
    cout<<endl;
    
    //max_element, min_element (func)
    vector<Point> v4;
    v4.push_back(Point(3,2));
    v4.push_back(Point(2,5));
    v4.push_back(Point(1,5));
    v4.push_back(Point(3,3));
    v4.push_back(Point(3,2));
    vector<Point>::iterator point_iter;
    for(point_iter = v4.begin(); point_iter != v4.end(); ++point_iter)
    {
        cout<<*point_iter;
    }
    cout<<endl;
    vector<Point>::iterator point_max_iter;
    vector<Point>::iterator point_min_iter;
    
    point_max_iter = max_element(v4.begin(), v4.end(), Pcompare);
    point_min_iter = min_element(v4.begin(), v4.end(), Pcompare);
    cout<<"max_element : "<<*point_max_iter;
    cout<<"min_element : "<<*point_min_iter;
    cout<<endl;
    
    //mismatch
    pair<vector<int>::iterator, vector<int>::iterator> mismatch_pair;
    mismatch_pair = mismatch(v3.begin(), v3.end(), v.begin());
    for(iter = v.begin(); iter != v.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    for(iter = v3.begin(); iter != v3.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    
    cout<<"mismatch in v3 : "<<*(mismatch_pair.first)<<endl;
    cout<<"mismatch in v : "<<*(mismatch_pair.second)<<endl;
    cout<<endl;
    
    return 0;
}
