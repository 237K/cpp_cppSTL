//
//  STL_ch9_#5.cpp
//  cpp_study
//
//  Created by 형성모 on 21/01/2019.
//
//  STL chapter 9 5번 문제 풀이
//  컨테이너 모든 원소의 x, y를 5씩 증가시키는 코드를 완성하시오
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) :xpos(x), ypos(y) {}
    void Print() const { cout<<"("<<xpos<<", "<<ypos<<")"<<endl; }
    void Integer5()
    {
        xpos += 5;
        ypos += 5;
    }
};

int main(void)
{
    vector<Point> vp;
    vp.push_back(Point(1, 1));
    vp.push_back(Point(2, 2));
    vp.push_back(Point(3, 3));
    vp.push_back(Point(4, 4));
    vp.push_back(Point(5, 5));
    
    cout<<"Print Vector"<<endl;
    for_each(vp.begin(), vp.end(), mem_fun_ref(&Point::Print));
    cout<<endl<<"모든 원소의 x, y 5 씩 증가"<<endl;
    for_each(vp.begin(), vp.end(), mem_fun_ref(&Point::Integer5));
    cout<<"Print Vector"<<endl;
    for_each(vp.begin(), vp.end(), mem_fun_ref(&Point::Print));
    
    return 0;
}
