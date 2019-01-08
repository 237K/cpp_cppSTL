//
//  CopyTemplate.cpp
//  cpp_study
//
//  Created by 형성모 on 08/01/2019.
//
//  배열의 원소를 복사하는 함수 템플릿 Copy()를 구현해보았습니다.
//

#include <iostream>
using namespace std;

template <typename T>
void Copy(T target, const T source, int size)
{
    for(int i = 0; i < size; i++)
    {
        target[i] = source[i];
    }
}

int main(void)
{
    int arr1[5] = {11, 22, 33, 44, 55};
    int arr2[5];
    //Copy<int*>(arr2, arr1, 5);
    Copy(arr2, arr1, 5);
    cout<<"arr1 = {";
    for(int i = 0; i < 5; i++)
    {
        cout<<arr1[i]<<", ";
    }
    cout<<"}"<<endl;
    
    cout<<"arr2 = {";
    for(int i = 0; i < 5; i++)
    {
        cout<<arr2[i]<<", ";
    }
    cout<<"}"<<endl;
    
}
