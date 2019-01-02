//
//  OperatorOverloading_problem2.cpp
//  cpp_study
//
//  Created by 형성모 on 02/01/2019.
//
//  연산자 오버로딩 예시문제 2. 2차원 배열접근에 대한 연산자 오버로딩
//

#include <iostream>
#include <cstdlib>

using namespace std;

class BoundCheckArray
{
private:
    int *arr;
    int arr_len;
public:
    BoundCheckArray(int len=0) : arr_len(len)
    {
        arr = new int[len];
    }
    int& operator[](int index)
    {
        if(index < 0 || index >= arr_len)
        {
            cout<<"Row index out of bound"<<endl;
            exit(1);
        }
        return arr[index];
    }
    int operator[](int index) const
    {
        if(index < 0 || index >= arr_len)
        {
            cout<<"Row index out of bound"<<endl;
            exit(1);
        }
        return arr[index];
    }
    ~BoundCheckArray()
    {
        delete []arr;
    }
};

typedef BoundCheckArray* BoundCheckArrayPtr;

class BoundCheck2DArray
{
private:
    BoundCheckArray **arr;
    int arr_len;
public:
    BoundCheck2DArray(int column, int row) : arr_len(column)
    {
        arr = new BoundCheckArrayPtr[column];
        for(int i = 0; i < column; i++)
        {
            arr[i] = new BoundCheckArray(row);
        }
    }
    BoundCheckArray& operator[](int index)
    {
        if(index < 0 || index >= arr_len)
        {
            cout<<"Row index out of bound"<<endl;
            exit(1);
        }
        return *(arr[index]);
    }
    ~BoundCheck2DArray()
    {
        for(int i = 0; i < arr_len; i++) delete arr[i];
        delete []arr;
    }
};

int main(void)
{
    BoundCheck2DArray arr2d(3, 4);
    
    for(int n = 0; n < 3; n++)
    {
        for(int m = 0; m < 4; m++)
        {
            arr2d[n][m] = n+m;
        }
    }
    
    for(int n = 0; n < 3; n++)
    {
        for(int m = 0; m < 4; m++)
        {
            cout<<arr2d[n][m]<<' ';
        }
        cout<<endl;
    }
    
}
