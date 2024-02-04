#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <iostream>
#include <vector>
#include "strategies.h"
#include "DataCollection.h"


int min(int a, int b);
int max(int a, int b);



class stockData {

public:
    std::vector<dataPoint> _dataPoints;
    stockData(std::vector<dataPoint> data) { _dataPoints = data; }
    stockData() {};

};

class investment {
private:
    std::string _name;
    int _nrStocks;
    int _currentValue;
    int _returned;
    int _invested;
    stockData _data;
    int _currentDataPoint;
    strategy* _strategy;

public:

    investment()
    {
        _strategy = NULL;
        _currentDataPoint = NULL;
        _nrStocks = 0;
        _currentValue = 0;
        _returned = 0;
        _invested = 0;
        _name = "";
    };
    investment(std::string name, std::vector<dataPoint> data, strategy* s) : investment()
    {
        _data = stockData(data);
        _strategy = s;
        _name = name;

        // TODO: Hämta namn från stockData?
    }

    bool operator<(const investment& other) const {
        return this->_currentValue < other._currentValue;
    }
    bool operator>=(const investment& other) const {
        return this->_currentValue >= other._currentValue;
    }
    bool operator<=(const investment& other) const {
        return this->_currentValue <= other._currentValue;
    }
    bool operator==(const investment& other) const {
        return this->_currentValue == other._currentValue;
    }
    bool operator!=(const investment& other) const {
        return this->_currentValue != other._currentValue;
    }


             

    void investAccordingToStrategy(int buy_limit);
    int initialInvestment(int maxInvest);
    void handleCurrentDataPoint(dataPoint point, int buy_limit);
    void nextMonth(int buy_limit);

    void print(dataPoint point);
    void printSummary();
    void buy(int price, int buy_limit);
    void sell(int price);
    void sellAllButOne(int price);

    int getInvested() { return _invested; }
    int getReturned() { return _returned; }
    int getCurrentValue() { return _currentValue; }
};

#endif