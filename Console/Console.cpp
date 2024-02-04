#include "../src/Investment.h"
#include "../src/Portfolio.h"

int main()
{
    strategy_buyAt10_MA_limit strat;

    investment invest("Nibe", nibe, &strat);
    investment invest2("Investor", investor, &strat);
    investment invest3("Better collective", betterCollective, &strat);

    Portfolio bank({ &invest, &invest2, &invest3 }, 3, &strat);


    const int startingBalance = 30 * 1000;
    bank.setStartingBalance(startingBalance);
    bank.startInvest();

    for (int i = 0; i < 24; i++) {
        // bank.nexMonth();
    }
}
