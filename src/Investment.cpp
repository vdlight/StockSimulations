#include <iostream>
#include <string>
#include <vector>

#include "DataCollection.h"
#include "Investment.h"
#include "Portfolio.h"
#include "strategies.h"



/*
Investeringar

Beskriver en investering, håller datapunkter



*/

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int investment::initialInvestment(int maxInvest)
{
    _currentDataPoint = 0;
    try {
        dataPoint* curr = &_data._dataPoints.at(_currentDataPoint++);
        _nrStocks = min(ADJ_LEVEL, maxInvest) / curr->_price;

        _startPrice = curr->_price;
        _currentValue = _nrStocks * curr->_price;
        std::cout << "Initiatal stocks " << _nrStocks << " current val " << _currentValue << std::endl;
        return _currentValue;
    }
    catch (std::out_of_range) {
        std::cerr << "OUT OF BOUNDS" << std::endl;
        return 0;
    }
}

void investment::investAccordingToStrategy(int buy_limit) {
    /* initialInvestment();

     while (_currentDataPoint) {
         try {
             dataPoint* curr = &_data._dataPoints.at(_currentDataPoint++);
             handleCurrentDataPoint(*curr, buy_limit);
         }
         catch (std::out_of_range) {
             std::cout << "Loop done";
             _currentDataPoint = 0;
         }
     }

     printSummary();*/
}

int investment::nextMonth(int balance) {
    try {
        dataPoint* curr = &_data._dataPoints.at(_currentDataPoint++);
        _lastPrice = curr->_price;
        return handleCurrentDataPoint(*curr, balance);
    }
    catch (std::out_of_range) {
        std::cout << "data range wrap" << std::endl;
        _currentDataPoint = 0;
        dataPoint* curr = &_data._dataPoints.at(_currentDataPoint);
        // sell and rebuy for free, to adjust wrap around
        _nrStocks = _currentValue / curr->_price;
        return _currentValue % curr->_price;
    }
    return 0;
}

int investment::handleCurrentDataPoint(dataPoint point, int buy_limit) {

    _currentValue = _nrStocks * point._price;
    print(point);

    int walletEffect = 0;
    ACTION a = _strategy->action(point._price, point._ma200, _currentValue);

    switch (a) {
    case ACTION_BUY:
        walletEffect = buy(point._price, buy_limit);
        break;
    case ACTION_SELL:
        walletEffect = sell(point._price);
        break;
    case ACTION_SELL_ALL_BUT_ONE:
        walletEffect = sellAllButOne(point._price);
        break;
    default:
        break;
    }
    return walletEffect;
}

void investment::print(dataPoint point) {
    std::cout << "Name: "  << _name << " date: " << point._date << " price: " << point._price << " MA: " << point._ma200 << std::endl
        << "     stocks :" << _nrStocks << " balance: " << _currentValue << std::endl;
}

void investment::printSummary() {
    std::cout << "Investment for : " << _name << std::endl;

    
    std::cout << "stock developmenent " << (((float)_startPrice - _lastPrice) / _startPrice) * 100.0 << "(" << _startPrice << "/" << _lastPrice << ")" << std::endl;
    std::cout << "Total invested after init: " << _invested << std::endl;
    std::cout << "Total returned after init: " << _returned << std::endl;

    
    double result = ((double)_returned - _invested) / (double)ADJ_LEVEL;
    std::cout << "Printed : " << result * 100.0 << "% (" << _returned - _invested << ")";

    result = (_currentValue - ADJ_LEVEL) / (double)ADJ_LEVEL;

    std::cout << std::endl
        << "Development: " << result * 100.0 << "% (" << _currentValue << ")" << std::endl << std::endl;

}

int investment::buy(int price, int adj_limit) {
    int adj = min(abs(_currentValue - ADJ_LEVEL), adj_limit);

    if (adj < MINIMUM_BUY) {
        return 0;
    }
    int stocksTobuy = adj / price;
    int purchased = stocksTobuy * price;
    _invested += purchased;
    _nrStocks += stocksTobuy;

    std::cout << "!! Bought " << stocksTobuy << " for " << stocksTobuy * price << std::endl;

    return -purchased; // buy us an negative wallet effect
}

int investment::sell(int price) {
    if (_nrStocks == 1) {
        return 0;
    }
    int adj = abs(ADJ_LEVEL - _currentValue);
    int stocksToSell = adj / price;
    int sold = stocksToSell * price;
    _returned += sold;
    _nrStocks -= stocksToSell;

    std::cout << "!! Sold " << stocksToSell << " for " << stocksToSell * price << std::endl;
    return sold;  // returned is a increase of wallet effect
}

int investment::sellAllButOne(int price) {
    if (_nrStocks == 1) {
        return 0;
    }

    int stocksToSell = _nrStocks - 1;
    int sold = stocksToSell * price;
    _returned += sold;
    
    _nrStocks -= stocksToSell;

    std::cout << "!! Sold " << stocksToSell << " for " << stocksToSell * price << std::endl;
    return  sold;// returned is a increase of wallet effect
}
