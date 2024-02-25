
#include "Portfolio.h"
#include "StockData.h"

#include <iostream>



void InitSimulation(int startBalance) 
{
    Portfolio portfolio = Portfolio();
    portfolio.setStartingBalance(startBalance);

}

int HelloWorld() {
    return 1;
}