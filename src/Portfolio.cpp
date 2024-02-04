#include "Portfolio.h"

void Portfolio::investSeparate() 
{
	/*
	Iterera igenom investeringarna. 
	Kör dem från början till slut
	summera resultatet
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
			_balance -= i->initialInvestment(_balance);
		}
	}
}

void Portfolio::nextMonth() {
	for (auto i : _investments) {
		if (i) {
		//	_balance -= i->nextMonth(_balance);
		}
	}
}

void Portfolio::printPortfolio() 
{
	std::cout << std::endl << "-------------- PORTFOLIO -------------" << std::endl;
	int invested = 0, returned = 0, currentValue = 0;
	
	for (auto i : _investments) 
	{
		if (i) {
			i->printSummary();
			
			invested += i->getInvested();
			returned += i->getReturned();
			currentValue += i->getCurrentValue();
		}
	}
}