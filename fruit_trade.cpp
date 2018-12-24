//
//  fruit_trade.cpp
//  cpp_study
//
//  Created by 형성모 on 2018. 12. 25..
//
//  과일상인과 과일 구매자 두 객체 사이의 메시지 교환 관점에서 거래과정을 구현하였습니다.
//  '객체지향언어' 에서 '객체'에 대해 어렴풋이나마 이해할 수 있었습니다.
//  또한 '객체'관점에서 프로그래밍 하는 것이 왜 이로운지 피상적으로나마 이해합니다.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class FruitSeller
{
private:
    const int fruit_price;
    int seller_money;
    int seller_fruits;
public:
    FruitSeller(int price, int money, int num);
    int SaleApple(int money);
    void ShowSellResult() const;
    int GetPrice() const;
};

class FruitBuyer
{
private:
    int buyer_money;
    int buyer_fruits;
public:
    FruitBuyer(int money);
    void BuyFruits(FruitSeller &seller, int money);
    void ShowBuyResult() const;
};

FruitSeller::FruitSeller(int price, int money, int num) :fruit_price(price), seller_money(money), seller_fruits(num)
{
}

int FruitSeller::SaleApple(int money)
{
    int fruits_num = money/fruit_price;
    if(fruits_num == 0)
    {
        cout<<"이 돈으론 사과 하나도 살 수 없어요!"<<endl;
        return 0;
    }
    else if(fruits_num >0)
    {
        seller_money += money;
        seller_fruits -= fruits_num;
    }
    return fruits_num;
}

void FruitSeller::ShowSellResult() const
{
    cout<<"판매 수익 : "<<seller_money<<endl;
    cout<<"남은 사과 : "<<seller_fruits<<endl;
}

int FruitSeller::GetPrice() const
{
    return fruit_price;
}

FruitBuyer::FruitBuyer(int money) : buyer_money(money), buyer_fruits(0)
{
}

void FruitBuyer::BuyFruits(FruitSeller &seller, int money)
{
    
    if(money < seller.GetPrice())
    {
        cout<<"그렇군요.. 아쉽네요.."<<endl;
        return;
    }
    
    buyer_fruits += seller.SaleApple(money);
    buyer_money -= money;
}

void FruitBuyer::ShowBuyResult() const
{
    cout<<"보유 비용 : "<<buyer_money<<endl;
    cout<<"보유 사과 : "<<buyer_fruits<<endl;
}

int main(void)
{
    FruitSeller seller(1000, 0, 20);
    FruitBuyer buyer(9000);
    
    cout<<"------구매 전------"<<endl;
    cout<<"*판매자 현황"<<endl;
    seller.ShowSellResult();
    cout<<endl;
    cout<<"*구매자 현황"<<endl;
    buyer.ShowBuyResult();
    
    cout<<"제시한 금액이 사과가격보다 낮을 경우"<<endl;
    buyer.BuyFruits(seller, 500);
    
    cout<<endl;
    buyer.BuyFruits(seller, 5000);
    
    cout<<"------구매 후------"<<endl;
    cout<<"*판매자 현황"<<endl;
    seller.ShowSellResult();
    cout<<endl;
    cout<<"*구매자 현황"<<endl;
    buyer.ShowBuyResult();
    
    return 0;
}
