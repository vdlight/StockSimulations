#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "Investment.h"

const int MAX_INVESTMENTS = 15;
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

public:
    void setStartingBalance(int value) { _balance = value; _invested = value; }
    
    Portfolio()
    {
        _balance = 0;
        _invested = 0;
    };
    Portfolio(std::initializer_list<investment*> investments, int size, strategy* s)
    {
        _balance = 0;
        _invested = 0;
        int cnt = 0;
        for (auto i : investments) {
            _investments[cnt++] = i;
        }
    }

    void investSeparate();

    void invest(int value);
    void startInvest();
    void nextMonth();
    void printPortfolio();
};


#endif // ! PORTFOLIO_H