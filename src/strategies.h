#ifndef STRATEGIES_H
#define STRATEGIES_H

#include <iostream>

enum ACTION {
    ACTION_BUY,
    ACTION_SELL_ALL_BUT_ONE,
    ACTION_SELL,
    ACTION_NONE
};

class strategy {
public:
    virtual ACTION action(int price, int ma200, int balance) const = 0;
};

class strategy_buyAt10_MA_limit : public strategy {
private:

public:
    ACTION action(int price, int ma200, int balance) const override;
    strategy_buyAt10_MA_limit() { std::cout << "strategy + / -, no buy below MA" << std::endl; };
};

class strategy_buyAt_Positive_signal : public strategy {
private:

public:
    ACTION action(int price, int ma200, int balance) const override;
    strategy_buyAt_Positive_signal() { std::cout << "strategy + / -, buy if increasing since last datapoint" << std::endl; };
};

class strategy_buyAt_10_MA_Limit_Positive_signal : public strategy {
private:

public:
    ACTION action(int price, int ma200, int balance) const override;
    strategy_buyAt_10_MA_Limit_Positive_signal() { std::cout << "strategy + / -, no bey below MA, buy if increasing since last datapoint" << std::endl; };
};

class strategy_buyAt10_MA_limit_Or_Positive_signal : public strategy {
private:

public:
    ACTION action(int price, int ma200, int balance) const override;
    strategy_buyAt10_MA_limit_Or_Positive_signal() { std::cout << "strategy + / -, no buy below MA if not increasing since last datapoint" << std::endl; };
};

class strategy_buyAt10_MA_sell : public strategy {
private:

public:
    ACTION action(int price, int ma200, int balance) const override;
    strategy_buyAt10_MA_sell() { std::cout << "strategy + / -, sell all but one under MA" << std::endl; };
};

class strategy_buyAndKeep : public strategy {
private:

public:
    ACTION action(int price, int ma200, int balance) const override;
    strategy_buyAndKeep() { std::cout << "strategy buy and keep" << std::endl; };
};

#endif