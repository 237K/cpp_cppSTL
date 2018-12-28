//
//  EmployeeManager.cpp
//  cpp_study
//
//  Created by 형성모 on 28/12/2018.
//
//  '다형성'에 대해 공부합니다!
//  A형 객체포인터변수는 A를 직, 간접적으로 상속하는 모든 객체를 가리킬 수 있습니다!
//  이를 이용하면 컨트롤 클래스를 변경하지 않고, 프로그램의 활용범위를 확장할 수 있습니다!
//  또한 가상함수(Virtual Function)에 대해 공부했습니다!
//  이번 예제에서는 컨트롤 클래스인 'EmployeeManager'에 대한 변경 없이 'Employee'클래스를 상속함으로써 다양한 고용형태를 추가할 수 있음을 확인합니다.
//
//  ver2. 오지산간에서 영업활동하는 영업직 직원들에 대한 별도의 클래스를 추가합니다. 이들에게는 위험노출도에 따라 위험수당을 지급합니다.
//

#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

namespace RISK_LEVEL
{
    enum {RISK_A=30, RISK_B=20, RISK_C=10};
}

class Employee
{
private:
    char *name;
public:
    const static int NAME_LEN = 20;
public:
    Employee(char *name)
    {
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
    }
    virtual ~Employee()
    {
        delete []name;
    }
    void ShowName() const
    {
        cout<<"이름 : "<<name<<endl;
    }
    virtual int GetSalary() const = 0;
    virtual void ShowSalary() const = 0;
};

class PermanentWorker : public Employee
{
private:
    int salary;
public:
    PermanentWorker(char *name, int salary) :Employee(name), salary(salary) {}
    ~PermanentWorker() {}
    int GetSalary() const
    {
        return salary;
    }
    void ShowSalary() const
    {
        cout<<"[PermanentWorker]"<<endl;
        ShowName();
        cout<<"급여 : "<<GetSalary()<<endl<<endl;
    }
};

class SalesWorker : public PermanentWorker
{
private:
    int salesResult;
    double incentiveRatio;
public:
    SalesWorker(char *name, int salary, double incentiveRatio) :PermanentWorker(name, salary), incentiveRatio(incentiveRatio), salesResult(0) {}
    ~SalesWorker() {}
    
    void AddSalesResult(int sales)
    {
        salesResult += sales;
    }
    
    int GetSalary() const
    {
        return PermanentWorker::GetSalary() + (int)(salesResult * incentiveRatio);
    }
    
    void ShowSalary() const
    {
        cout<<"[SalesWorkers]"<<endl;
        cout<<"판매실적 : "<<salesResult<<"원 "<<endl;
        cout<<"Incentive : 판매실적의 "<<incentiveRatio<<endl;
        ShowName();
        cout<<"급여 : "<<GetSalary()<<endl<<endl;
    }
};

class ForeignSalesWorker : public SalesWorker
{
private:
    const int RiskLevel;
public:
    ForeignSalesWorker(char *name, int salary, double incentiveRatio, int RiskLevel) :SalesWorker(name, salary, incentiveRatio), RiskLevel(RiskLevel){}
    
    ~ForeignSalesWorker() {}
    
    int GetRiskPay() const
    {
        return (int)SalesWorker::GetSalary() * (RiskLevel/100.0);
    }
    
    int GetSalary() const
    {
        return SalesWorker::GetSalary() + GetRiskPay();
    }
    
    void ShowSalary() const
    {
        cout<<"[ForeignSalesWorker]"<<endl;
        cout<<"해당 직원의 위험 노출도는 "<<RiskLevel<<" 입니다"<<endl;
        ShowName();
        cout<<"위험수당 : "<<GetRiskPay()<<endl;
        cout<<"급여 : "<<GetSalary()<<endl<<endl;
    }
};

class TemporaryWorker : public Employee
{
private:
    int workingTime;
    int PayPerHour;
public:
    TemporaryWorker(char *name, int PayPerHour) : Employee(name), PayPerHour(PayPerHour), workingTime(0) {}
    ~TemporaryWorker() {}
    
    void AddWorkingTime(int workingTime)
    {
        this->workingTime += workingTime;
    }
    
    int GetSalary() const
    {
        return workingTime * PayPerHour;
    }
    
    void ShowSalary() const
    {
        cout<<"[TemporaryWorkers]"<<endl;
        cout<<"Working time : "<<workingTime<<endl;
        cout<<"Pay per hour : "<<PayPerHour<<endl;
        ShowName();
        cout<<"급여 : "<<GetSalary()<<endl<<endl;
    }
};

class EmployeeManager
{
private:
    Employee *employees[100];
public:
    static int employees_count;
public:
    ~EmployeeManager()
    {
        for(int i = 0; i < employees_count; i++)
        {
            delete employees[i];
        }
    }
    
    void Hire(Employee* emp)
    {
        /*
        char emp_name[Employee::NAME_LEN];
        int emp_salary;
        
        cout<<"직원 이름 : "; cin>>emp_name;
        cout<<"직원 급여 : "; cin>>emp_salary;
         */
        employees[employees_count++] = emp;
    }
    
    void ShowAllSalary() const
    {
        for(int i = 0; i < employees_count; i++)
        {
            employees[i]->ShowSalary();
        }
    }
    
    void ShowTotalSalary() const
    {
        int total = 0;
        for(int i = 0; i < employees_count; i++)
        {
            total += employees[i]->GetSalary();
        }
        cout<<"이번 달 지급 급여 총합 : "<<total<<endl;
    }
};

int EmployeeManager::employees_count = 0;

int main(void)
{
    char emp1_name[Employee::NAME_LEN] = {'K','I','M'};
    char emp2_name[Employee::NAME_LEN] = {'L','E','E'};
    char emp3_name[Employee::NAME_LEN] = {'H'};
    char *pemp1_name = emp1_name;
    char *pemp2_name = emp2_name;
    char *pemp3_name = emp3_name;
    
    int emp1_sal = 1000;
    int emp2_sal = 1500;
    int emp3_sal = 2000;
    
    char sal1_name[Employee::NAME_LEN] = {'K','I','M'};
    //char sal2_name[Employee::NAME_LEN] = {'L','E','E'};
    //char sal3_name[Employee::NAME_LEN] = {'H'};
    char *psal1_name = sal1_name;
    //char *psal2_name = sal2_name;
    //char *psal3_name = sal3_name;
    
    double incentive = 0.1;
    
    char tmp1_name[Employee::NAME_LEN] = {'K','I','M'};
    //char tmp2_name[Employee::NAME_LEN] = {'L','E','E'};
    //char tmp3_name[Employee::NAME_LEN] = {'H'};
    char *ptmp1_name = tmp1_name;
    //char *ptmp2_name = tmp2_name;
    //char *ptmp3_name = tmp3_name;
    
    int PPH = 8000;
    
    char fs1_name[Employee::NAME_LEN] = {'G','A','N'};
    char fs2_name[Employee::NAME_LEN] = {'D','A'};
    char fs3_name[Employee::NAME_LEN] = {'H','O','W','O','O'};
    char *pfs1 = fs1_name;
    char *pfs2 = fs2_name;
    char *pfs3 = fs3_name;
    
    EmployeeManager manager;
    
    manager.Hire(new PermanentWorker(pemp1_name, emp1_sal));
    manager.Hire(new PermanentWorker(pemp2_name, emp2_sal));
    manager.Hire(new PermanentWorker(pemp3_name, emp3_sal));
    
    SalesWorker *seller = new SalesWorker(psal1_name, emp2_sal, incentive);
    seller->AddSalesResult(5000);
    manager.Hire(seller);

    TemporaryWorker *PartTime = new TemporaryWorker(ptmp1_name, PPH);
    PartTime->AddWorkingTime(10);
    manager.Hire(PartTime);
    
    ForeignSalesWorker *fsworker1 = new ForeignSalesWorker(pfs1, emp3_sal, incentive, RISK_LEVEL::RISK_A);
    fsworker1->AddSalesResult(7000);
    manager.Hire(fsworker1);
    
    ForeignSalesWorker *fsworker2 = new ForeignSalesWorker(pfs2, emp3_sal, incentive, RISK_LEVEL::RISK_B);
    fsworker2->AddSalesResult(7000);
    manager.Hire(fsworker2);
    
    ForeignSalesWorker *fsworker3 = new ForeignSalesWorker(pfs3, emp3_sal, incentive, RISK_LEVEL::RISK_C);
    fsworker3->AddSalesResult(7000);
    manager.Hire(fsworker3);
    
    manager.ShowAllSalary();
    manager.ShowTotalSalary();
    
    return 0;
}
