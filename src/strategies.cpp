#include <iostream>

#include "strategies.h"
#include "DataCollection.h"


ACTION strategy_buyAt10_MA_limit_Or_Positive_signal::action(int price, int ma200, int balance) const
{
    static int old_price = 0;

    if (balance > ADJ_LEVEL * (ADJ_PERCENTAGE + 1)) // 10% up
    {
        old_price = price;
        return ACTION_SELL;
    }
    else if (balance < ADJ_LEVEL * (1 - ADJ_PERCENTAGE)) // 10% down
    {

        if (price >= ma200 || price > old_price)  // >= MA or current price better than last point
        {
            return ACTION_BUY;
        }
    }
    old_price = price;
    return ACTION_NONE;
}

ACTION strategy_buyAt10_MA_limit::action(int price, int ma200, int balance) const
{
    if (balance > ADJ_LEVEL * (ADJ_PERCENTAGE + 1)) // 10% up
    {
        return ACTION_SELL;
    }
    else if (balance < ADJ_LEVEL * (1 - ADJ_PERCENTAGE)) // 10% down
    {
        if (price >= ma200)  // >= MA
        {
            return ACTION_BUY;
        }
    }
    return ACTION_NONE;
}

ACTION strategy_buyAt10_MA_sell::action(int price, int ma200, int balance) const
{
    if (balance > ADJ_LEVEL * (ADJ_PERCENTAGE + 1)) // 10% up
    {
        return ACTION_SELL;
    }
    else if (balance < ADJ_LEVEL * (1 - ADJ_PERCENTAGE)) // 10% down
    {
        if (price >= ma200)  // >= MA
        {
            return ACTION_BUY;
        }
        else {
            return ACTION_SELL_ALL_BUT_ONE;
        }
    }
    return ACTION_NONE;
}

ACTION strategy_buyAndKeep::action(int price, int ma200, int balance) const
{
    return ACTION_NONE;
}
