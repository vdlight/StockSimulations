#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "Investment.h"

const int MAX_INVESTMENTS = 10;
const int MINIMUM_BUY = 500;


class Portfolio {
private:
    int _balance;
    int _returned;
    int _invested;
    investment* _investments[MAX_INVESTMENTS] = { NULL };

public:
    void setStartingBalance(int value) { _balance = value; }
    
    Portfolio()
    {
        _balance = 0;
        _returned = 0;
        _invested = 0;
    };
    Portfolio(std::initializer_list<investment*> investments, int size, strategy* s)
    {
        int cnt = 0;
        for (auto i : investments) {
            _investments[cnt++] = i;
        }
    }

    void investSeparate();
    void startInvest();
    void nextMonth();
    void printPortfolio();
};


#endif // ! PORTFOLIO_H