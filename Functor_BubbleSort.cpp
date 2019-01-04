//
//  Functor_BubbleSort.cpp
//  cpp_study
//
//  Created by 형성모 on 03/01/2019.
//
//  펑터를 이용하여 버블정렬을 구현해보았습니다.
//

#include <iostream>
using namespace std;

class SortRule
{
public:
    virtual bool operator()(int num1, int num2) const =0;
};

class AscendingSort : public SortRule
{
public:
    bool operator()(int num1, int num2) const
    {
        if(num1>num2) return true;
        else return false;
    }
};

class DescendingSort : public SortRule
{
public:
    bool operator()(int num1, int num2) const
    {
        if(num1<num2) return true;
        else return false;
    }
};

class DataStorage
{
private:
    int *array;
    int index;
    const int MAX_LEN;
public:
    DataStorage(int len) : index(0), MAX_LEN(len)
    {
        array = new int[MAX_LEN];
    }
    void AddNum(int num)
    {
        if(MAX_LEN <= index)
        {
            cout<<"배열이 가득찼습니다."<<endl;
            return;
        }
        array[index++] = num;
    }
    void ShowData() const
    {
        for(int i = 0; i < index; i++)
        {
            cout<<array[i]<<' ';
        }
        cout<<endl;
    }
    void SortData(const SortRule& functor)
    {
        for(int i = 0; i < index; i++)
        {
            for(int j = 0; j < (index-1); j++)
            {
                if(functor(array[j], array[j+1]))
                {
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                    cout<<"정렬 중.."<<i<<','<<j<<','<<j+1<<endl;
                }
            }
        }
    }
    ~DataStorage() { delete []array; }
};

int main(void)
{
    DataStorage storage(5);
    storage.AddNum(20);
    storage.AddNum(40);
    storage.AddNum(10);
    storage.AddNum(50);
    storage.AddNum(30);
    cout<<"[정렬 전]"<<endl;
    storage.ShowData();
    
    cout<<"[오름차순 정렬]"<<endl;
    storage.SortData(AscendingSort());
    storage.ShowData();
    
    cout<<"[내림차순 정렬]"<<endl;
    storage.SortData(DescendingSort());
    storage.ShowData();
    
    return 0;
}
