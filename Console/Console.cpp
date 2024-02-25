#include "../src/Investment.h"
#include "../src/Portfolio.h"

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
    strategy_buyAt10_MA_limit strat;

    investment invest("Nibe", nibe, &strat);
    investment invest2("Investor", investor, &strat);
    investment invest3("Better collective", betterCollective, &strat);
    investment invest4("Nibe", nibe, &strat);
    investment invest5("Investor", investor, &strat);
    investment invest6("Better collective", betterCollective, &strat);
    investment invest7("Nibe", nibe, &strat);
    investment invest8("Investor", investor, &strat);
    investment invest9("Better collective", betterCollective, &strat);
    investment invest10("Nibe", nibe, &strat);
    investment invest11("Investor", investor, &strat);
    investment invest12("Better collective", betterCollective, &strat);
    

    Portfolio bank({ 
        &invest, 
        &invest2, 
        &invest3, 
        &invest4,
        &invest5, 
        &invest6, 
        &invest7, 
        &invest8, 
        &invest9, 
        &invest10, 
        &invest11,
        &invest12,
        }, 12, &strat);

    bank.setStartingBalance(100000);

    bank.startInvest();

    for (int i = 0; i < 24; i++) {

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
