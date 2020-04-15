#ifndef CARLO_H
#define CARLO_H
#include <iostream>

using std::cout;
using std::endl;

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
    TotalWeight -= this -> BoxWeight;
    TotalPrice -= this -> BoxPrice * BoxWeight;
}

void Carlo::SetCarlo(double w , double p )
{
    if(w >= 0 && p >= 0)
    {
        this -> BoxWeight = w;
        this -> BoxPrice = p;
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


#endif