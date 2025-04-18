#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include "Account.hpp"
#include <ctime>
#include <iomanip>

// DIsplay account infos
// make deposit
// display status const
// make withdrawal

int	Account::_nbAccounts = 0;

int	Account::_totalNbWithdrawals = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalAmount = 0;

Account::Account(int initial_deposit): _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount+=initial_deposit;
	_totalAmount+=_amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ":" << "created" << '\n';
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "closed"<< "\n";
}

void Account::_displayTimestamp()
{
	char timestamp[20];
    	std::time_t now;
	
	std::time(&now);
    	std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", std::localtime(&now));
	std::cout << "[" << timestamp << "] ";
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";" << "total:" << getTotalAmount() << ";" << "deposits:" << getNbDeposits()
		<< ";" << "withdrawals:" << getNbWithdrawals() << '\n';
}

void Account::displayStatus( ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "deposits:" << _nbDeposits << ";" << 
		"withdrawals:" << _nbWithdrawals << "\n";
}
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_nbDeposits+=1;
	_totalNbDeposits+=1;
	std::cout << "index:" << _accountIndex << ";" << "p_amount:" << _amount << ";" << "deposit:" << deposit << ";" << "amount:" << _amount+deposit << ":" <<  "nb_deposits:" << _nbDeposits << '\n';
}
bool Account::makeWithdrawal(int withdrawal)
{
	if (_amount - withdrawal < 0)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";" << "p_amount:" << _amount << ";" << "withdrawal:" << "refused" << '\n';
		return 0;
	}
	_displayTimestamp();
	_nbWithdrawals+=1;
	_totalNbWithdrawals+=1;
	std::cout << "index:" << _accountIndex << ";" << "p_amount:" << _amount << ";" << "withdrawal:" << withdrawal << ";" << "amount:" << _amount-withdrawal << ":" <<  "nb_withdrawals:" << _nbWithdrawals << '\n';
	return 1;
}

// Setters getters
//
// int Account::AccountIndex(void)
// {
// 	return this->_accountIndex;
// }
//
// int Account::Amount(void)
// {
// 	return this->_amount;
// }
//
// int Account::nbDeposits(void)
// {
// 	return this->_nbDeposits;
// }
//
// int Account::nbWithDrawals(void)
// {
// 	return this->_nbWithdrawals;
// }

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

