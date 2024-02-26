#include "../src/Investment.h"
#include "../src/Portfolio.h"

#include <fstream>


/*


start av simulering, ska skapa en portfölj, och sätta en kassa att starta med.

Skapa upp händelsedata, som skickas över till GUI

1, ABB, MA200, Value, Aktier, Invested, Returned
1, Volvo, MA200, VALue, aktier, invested, returned
1, Volvo, Köp, Värde
1, Wallet, Value, Invested
2, ABB, MA200, Value, Aktier, Invested, Returned
2, Volvo, MA200, VALue, aktier, invested, returned
2, Volvo, Sälj, Värde
2, Wallet, Value, Invested

Om jag lagt in 90 000 och värde på plånbok är 100 000, så är avkastning 10%
90 000 * X = 100 000 => ~1.11



*/



int main()
{
    strategy_buyAt_10_MA_Limit_Positive_signal strat;

    investment investPossibilities[] =
    {
        investment("Nibe", nibe, &strat),
        investment("Investor", investor, &strat),
        investment("Better collective", betterCollective, &strat),
        investment("SBB", SBB, &strat),
        investment("SAAB", SAAB, &strat),
        investment("SEB", SEB, &strat),
        investment("Latour", Latour, &strat),
        investment("Volati", Volati, &strat),
        investment("AtlasCopco", AtlasCopco, &strat),
        investment("NewWave", NewWave, &strat),
        investment("Alligo", Alligo, &strat),
        investment("Volvo", Volvo, &strat),
        investment("Castellum", Castellum, &strat),
        investment("Tele2", Tele2, &strat),
        investment ("Axfood", Axfood, &strat),
    };

    
    Portfolio bank;
    int j = 0;
    for (int i = 0; i < MAX_INVESTMENTS; i++ ) {

        bank.addInvestment(&investPossibilities[j]);
        j++;
        j %= 15;
    }


    bank.setStartingBalance(100000);

    bank.startInvest();

    for (int i = 0; i < 12*10; i++) {

        bank.nextMonth();
        bank.invest(1500);

        //if (i % 6 == 0) {
        //    bank.halfYearDivident();
        //}
    }
    
    bank.printPortfolio();
    char buff;
    std::cin >> buff;
}
