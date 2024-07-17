#include<iostream>
#include "Account.h"
#include <ctime>


int main(void)
{
    Account Abdelrahman(5000);
    Account::displayAccountsInfos();
    Abdelrahman.makeDeposit(2000);
    Abdelrahman.makeWithdrawal(500);
    Abdelrahman.displayStatus();
    Account::displayAccountsInfos();

    


    return 0;
}