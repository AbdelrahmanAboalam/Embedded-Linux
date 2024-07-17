#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_


class Account
{
    private:

    static int m_noOfAccounts;
    static int m_totalAmount;
    static int m_totalNbDeposits;
    static int m_totalNbWithdrawals;

    static void m_displayTimestamp(void);

    int m_accountIndex;
    int m_amount;
    int m_noOfWithdrawals;
    int m_noOfDeposits;

    Account(void);

   public:
   using acc =Account;

    static int getNoOfAccounts(void);
    static int getTotalAmount(void);
    static int getNbDeposits(void);
    static int getNoOfWithdrawals(void);
    static void displayAccountsInfos(void);
    

    Account(int intial_deposit);
    ~Account(void);

    void makeDeposit(int deposit);
    bool makeWithdrawal(int withdrawal);
    int checkAmount(void) const;
    void displayStatus(void) const;



};


#endif