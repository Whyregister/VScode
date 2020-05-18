#include <iostream>
#include <conio.h>
using namespace std;

class Carlo
{
public:

    Carlo (double = 0,double  = 0);
    virtual ~Carlo();
    void SetCarlo(double = 0,double = 0);
    const double &GetCurrentTotalWeight() const; 
    const double &GetCurrentTotalPrice() const;  
    void BuyBox();
    void SellBox();
    void ShowBoxInfor() const;

protected:     

        static  double  TotalWeight;
        static  double  TotalPrice;       

private:
        double  BoxWeight;
        double  BoxPrice;
};

double Carlo::TotalWeight = 0;
double Carlo::TotalPrice = 0;

Carlo::Carlo(double w,double p)
{
    if(w >= 0 && p >= 0)
    {
        BoxWeight = w;
        BoxPrice = p;
        TotalWeight += BoxWeight;
        TotalPrice += BoxPrice * BoxWeight;  
    }
}
Carlo::~Carlo()
{
    TotalWeight -= BoxWeight;
    TotalPrice -= BoxPrice * BoxWeight;
}

void Carlo::SetCarlo(double w , double p )
{
    if(w >= 0 && p >= 0)
    {
        BoxWeight = w;
        BoxPrice = p;
    }
}

const double & Carlo::GetCurrentTotalPrice() const
{
    return TotalPrice;
} 

const double & Carlo::GetCurrentTotalWeight() const
{
    return TotalWeight;
}

void Carlo::BuyBox()
{
    TotalWeight += BoxWeight;
    TotalPrice += BoxWeight*BoxPrice;
}

void Carlo::SellBox()
{
    TotalWeight -= BoxWeight;
    TotalPrice -= BoxWeight*BoxPrice;
    BoxWeight = 0;
    BoxPrice = 0;
}

void Carlo::ShowBoxInfor() const
{
    cout << "BoxWeight = " << BoxWeight << endl
    << "BoxPrice = " << BoxPrice << endl;
}


int main ()
{
    Carlo c(40,1.2);

    cout << "当前总价格 = " << c.GetCurrentTotalPrice() << endl;
    cout << "当前总重量 = " << c.GetCurrentTotalWeight() << endl;
    c.ShowBoxInfor();
    cout << endl;

    c.SellBox();
    cout << "当前总价格 = " << c.GetCurrentTotalPrice() << endl;
    cout << "当前总重量 = " << c.GetCurrentTotalWeight() << endl;
    c.ShowBoxInfor();
    cout << endl;

    c.SetCarlo(20,4.3);
    c.BuyBox();
    cout << "当前总价格 = " << c.GetCurrentTotalPrice() << endl;
    cout << "当前总重量 = " << c.GetCurrentTotalWeight() << endl;
    c.ShowBoxInfor();
    cout << endl;


    Carlo d(1,1);
    cout << "当前总价格 = " << d.GetCurrentTotalPrice() << endl;
    cout << "当前总重量 = " << d.GetCurrentTotalWeight() << endl;
    d.ShowBoxInfor();    


    Carlo b(20,1.3);
    cout << "当前总价格 = " << b.GetCurrentTotalPrice() << endl;
    cout << "当前总重量 = " << b.GetCurrentTotalWeight() << endl;
    b.ShowBoxInfor();    

    getch();
    return 0;
}
