#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "Investment.h"

const int MAX_INVESTMENTS = 100;
const int MINIMUM_BUY = 500;


/*
    Portföljen ska hålla 
    balance = plånbok
    _invested = totalt investerat över tiden. 
    _ invemstemts[], aktierna som ägs



  _


*/


class Portfolio {
private:
    int _balance;
    int _invested;
    investment* _investments[MAX_INVESTMENTS] = { NULL };
    int investmentCnt = 0;

public:
    void setStartingBalance(int value) { _balance = value; _invested = value; }
    
    Portfolio()
    {
        _balance = 0;
        _invested = 0;
    };
    Portfolio(std::initializer_list<investment*> investments, int size)
    {
        _balance = 0;
        _invested = 0;
       
        for (auto i : investments) {
            _investments[investmentCnt++] = i;
        }
    }

    void addInvestment(investment * i) {
        _investments[investmentCnt++] = i;
    }

    void investSeparate();

    void invest(int value);
    void startInvest();
    void nextMonth();
    void printPortfolio();
};


#endif // ! PORTFOLIO_H