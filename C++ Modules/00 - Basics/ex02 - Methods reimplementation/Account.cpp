#include "Account.hpp"

#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) // Account Constructor
{
	_accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
     _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
}

Account::~Account(void) // Account Destructor
{
    _nbAccounts--;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
}

// Getters:
int Account::getNbAccounts(void)
{
    return(_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return(_totalAmount);
}

int Account::getNbDeposits(void)
{
    return(_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return(_totalNbWithdrawals);
}

int Account::checkAmount(void) const
{
    return(_amount);
}

// Getter adapters to display info:

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// Conventional functions:

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() << ";deposit:" << deposit;
    _amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << checkAmount() << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() << ";withdrawal:"; 
    if (withdrawal > checkAmount())
    {
        std::cout << "refused" << std::endl;
        return(false);
    }
    std::cout << withdrawal;
    _amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";amount:" << checkAmount() << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}

void Account::_displayTimestamp(void)
{
    time_t time_struct = time(0);
	tm *current_time = std::localtime(&time_struct);
    std::cout << "[" << 1900 + current_time->tm_year;
    if (1 + current_time->tm_mon < 10)
        std::cout << "0";
    std::cout << 1 + current_time->tm_mon;
    if (1 + current_time->tm_mday < 10)
        std::cout << "0";
    std::cout << 1 + current_time->tm_mday << "_";
    if (1 + current_time->tm_hour < 10)
        std::cout << "0";
    std::cout << 1 + current_time->tm_hour;
    if (1 + current_time->tm_min < 10)
        std::cout << "0";
    std::cout << 1 + current_time->tm_min;
    if (1 + current_time->tm_sec < 10)
        std::cout << "0";
    std::cout << 1 + current_time->tm_sec << "] ";
}