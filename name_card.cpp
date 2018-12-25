//
//  name_card.cpp
//  cpp_study
//
//  Created by 형성모 on 2018. 12. 25..
//
//  동적할당을 이용하여 명함 관리 프로그램을 개발하였습니다.
//

#include <iostream>
#include <cstring>
using namespace std;
/*
using std::cout;
using std::cin;
using std::endl;
*/
 
namespace COMP_POS
{
    enum {CLERK, SENIOR, ASSIST, MANAGER};
    void ShowPosition(int pos)
    {
        switch(pos)
        {
            case CLERK:
                cout<<"사원";
                break;
            case SENIOR:
                cout<<"주임";
                break;
            case ASSIST:
                cout<<"대리";
                break;
            case MANAGER:
                cout<<"과장";
                break;
        }
    }
};

class NameCard
{
private:
    char *name, *company, *mobile;
    int position;
public:
    NameCard(char *name1, char *company1, char *mobile1, int position);
    ~NameCard();
    void ShowNameCard() const;
};

NameCard::NameCard(char *name1, char *company1, char *mobile1, int position1)
{
    //int name_len = strlen(name1) + 1;
    name = new char[strlen(name1)+1];
    strcpy(name, name1);
    
    //int company_len = strlen(company1) + 1;
    company = new char[strlen(company1)+1];
    strcpy(company, company1);
    
    //int mobile_len = strlen(mobile1) + 1;
    mobile = new char[strlen(mobile1)+1];
    strcpy(mobile, mobile1);
    
    position = position1;
}

NameCard::~NameCard()
{
    delete []name;
    cout<<"name에 할당된 동적공간을 해제하였습니다."<<endl;
    delete []company;
    cout<<"company에 할당된 동적공간을 해제하였습니다."<<endl;
    delete []mobile;
    cout<<"mobile에 할당된 동적공간을 해제하였습니다."<<endl;
}

void NameCard::ShowNameCard() const
{
    cout<<"-----------------------"<<endl;
    cout<<"이   름 : "<<name<<endl;
    cout<<"회   사 : "<<company<<endl;
    cout<<"전화번호 : "<<mobile<<endl;
    cout<<"직   급 : "; COMP_POS::ShowPosition(position);
    cout<<endl;
    cout<<"-----------------------"<<endl<<endl;
}

int main(void)
{
    NameCard manCLERK("Lee", "ABC", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSENIOR("Hong", "BCD", "010-2222-3333", COMP_POS::SENIOR);
    NameCard manASSIST("Kim", "CDF", "010-3333-4444", COMP_POS::ASSIST);
    
    manCLERK.ShowNameCard();
    manSENIOR.ShowNameCard();
    manASSIST.ShowNameCard();
    
    return 0;
}
