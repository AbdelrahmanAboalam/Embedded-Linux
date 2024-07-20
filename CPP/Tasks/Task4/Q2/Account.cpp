#include <iostream>
#include "Account.h"
#include<ctime>


int Account::m_noOfAccounts = 0;
int Account::m_totalAmount = 0;
int Account::m_totalNbDeposits = 0;
int Account::m_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : m_accountIndex(m_noOfAccounts), m_amount(initial_deposit), m_noOfDeposits(0), m_noOfWithdrawals(0) 
{
    m_noOfAccounts++;
    m_totalAmount = m_totalAmount + initial_deposit;
    m_displayTimestamp();
    std::cout << "index:" << m_accountIndex << ";amount:" << m_amount << ";created" << std::endl;

}

Account::~Account(void) 
{
    m_displayTimestamp();
    std::cout << "index:" << m_accountIndex << ";amount:" << m_amount << ";closed" << std::endl;
    m_noOfAccounts--;
    m_totalAmount = m_totalAmount - m_amount;
}

void Account::makeDeposit(int deposit) 
{
    m_displayTimestamp();
    m_amount += deposit;
    m_totalNbDeposits++;
    m_totalAmount += deposit;
    m_totalNbDeposits++;
    std::cout << "index:" << m_accountIndex << ";p_amount:" << m_amount - deposit << ";deposit:" << deposit << ";amount:" << m_amount << ";nb_deposits:" << m_totalNbDeposits << std::endl;

}

bool Account::makeWithdrawal(int withdrawal) 
{

    m_displayTimestamp();
    if (withdrawal > m_amount) {
        std::cout << "index:" << m_accountIndex << ";p_amount:" << m_amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    m_amount = m_amount -withdrawal;
    m_noOfWithdrawals++;
    m_totalAmount = m_totalAmount - withdrawal;
    m_totalNbWithdrawals++;
    std::cout << "index:" << m_accountIndex << ";p_amount:" << m_amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << m_amount << ";nb_withdrawals:" << m_noOfWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const 
{
    return m_amount;
}

void Account::displayStatus(void) const 
{
    m_displayTimestamp();
    std::cout << "index:" << m_accountIndex << ";amount:" << m_amount << ";deposits:" << m_noOfDeposits << ";withdrawals:" << m_noOfWithdrawals << std::endl;
}

void Account::m_displayTimestamp(void) 
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::cout << "[" << 1900 + ltm->tm_year << "-"
              << 1 + ltm->tm_mon << "-"
              << ltm->tm_mday << " "
              << 1 + ltm->tm_hour << ":"
              << 1 + ltm->tm_min << ":"
              << 1 + ltm->tm_sec << "] ";
}

int Account::getNoOfAccounts(void)
{
    return m_noOfAccounts;
}

int Account::getTotalAmount(void) 
{
    return m_totalAmount;
}

int Account::getNbDeposits(void) 
{
    return m_totalNbDeposits;
}

int Account::getNoOfWithdrawals(void)
{
    return m_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    m_displayTimestamp();
    std::cout << "accounts:" << m_noOfAccounts << ";total:" << m_totalAmount << ";deposits:" << m_totalNbDeposits << ";withdrawals:" << m_totalNbWithdrawals << std::endl;
}
