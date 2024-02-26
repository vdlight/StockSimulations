#ifndef DATA_REPOSITORY_H
#define DATA_REPOSITORY_H

#include <string>

struct stockDataPrint {
	std::string name;
	std::string date;
	std::string price;
	std::string ma200;
	std::string stocks;
	std::string balance;
};

struct investmentData {
	std::string investment;
	std::string stockDevelopment;
	std::string investedAfterInit;
	std::string returnedAfterInit;
	std::string printed;
	std::string development;
};

struct walletData {
	std::string marketDataDevelopment;
	std::string stocksValue;
	std::string invested;
	std::string stocksDevelopment;
	std::string balance;
};

class DataRepository {
	virtual void WriteDebugMsg(std::string msg) = 0;
	virtual void WriteStockData(stockDataPrint data) = 0;
	virtual void WriteActionData(std::string actionStr) = 0;
	virtual void WriteWalletData(walletData data) = 0;
	virtual void WriteInvestmentData(investmentData data) = 0;
};

class ConsolePrint: public DataRepository {
	void WriteDebugMsg(std::string msg);
	void WriteStockData(stockDataPrint data);
	void WriteWalletData(walletData data);
	void WriteActionData(std::string actionStr);
};

class FilePrint: public DataRepository {
	void WriteDebugMsg(std::string msg);
	void WriteStockData(stockDataPrint data);
	void WriteWalletData(walletData data);
	void WriteActionData(std::string actionStr);
};



#endif