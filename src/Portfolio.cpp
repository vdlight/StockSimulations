#include "Portfolio.h"

void Portfolio::investSeparate() 
{
	/*
	Iterera igenom investeringarna. 
	Kör dem från början till slut
	summera resultatet


	portfolio
	    har plånboken  och ett antal investeringar.


	*/

	for (auto i : _investments) {
		if (i) {
			i->investAccordingToStrategy(10000);
		}
		
	}

	printPortfolio();
}

void Portfolio::startInvest() 
{
	for (auto i : _investments) {
		if (i) {
			int invested = i->initialInvestment(_balance);
			_balance -= invested;
		}
	}
}

void Portfolio::invest(int value) {
	_invested += value;
	_balance += value;
}

void Portfolio::nextMonth() {
	for (auto i : _investments) {
		if (i) {
			_balance += i->nextMonth(_balance);
		}
	}
}

void Portfolio::printPortfolio() 
{
	std::cout << std::endl << "-------------- PORTFOLIO -------------" << std::endl;
	int currentValue = 0, startValue = 0, lastValue = 0;
	
	for (auto i : _investments) 
	{
		if (i) {
			i->printSummary();
			startValue += i->_startPrice;
			lastValue += i->_lastPrice;
			
			currentValue += i->getCurrentValue();
		}
	}

	std::cout << "stockMarket data development" << (((float)startValue - lastValue) / (float)startValue) * 100.0 << 
		" (" << startValue << "/" << lastValue << ")" << std::endl;
	std::cout << "Stocks value: " << currentValue << std::endl;
	std::cout << "Invested money: " << _invested << std::endl;
	int development = currentValue + _balance - _invested;
	float result = (float)development / _invested;
	float percentage = result * (float)100;

	std::cout << "Stocks Development: " << percentage << "%" << std::endl;
	std::cout << "Balance: " << _balance << std::endl;
}