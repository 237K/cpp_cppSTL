//
//  Template2.cpp
//  cpp_study
//
//  Created by 형성모 on 03/01/2019.
//
//  템플릿에 대해 공부했습니다.
//  템플릿 관련 예시문제 2
//

#include <iostream>

using namespace std;

template <class T>
T SumArray(T array[], int len)
{
    T sum = 0;
    for(int i = 0; i<len; i++)
    {
        sum+=array[i];
    }
    return sum;
}

int main(void)
{
    int array1[3] = {1, 2, 3};
    double array2[3] = {1.1, 2.2, 3.3};
    
    cout<<SumArray(array1, 3)<<endl;
    cout<<SumArray(array2, 3)<<endl;
}
