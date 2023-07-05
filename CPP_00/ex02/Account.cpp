/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:48:17 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/05 16:48:19 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

/* Initialize static variables */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* _displayTimestamp:
*	Displays the current timestamp in the format:
*	[YYYYMMDD_hhmmss], followed by a space.
*/
void	Account::_displayTimestamp( void )
{
	time_t		currentTime = time(NULL);
	struct tm*	tm = localtime(&currentTime);

	std::cout << "[" << std::setw(4) << 1900 + tm->tm_year
				<< std::setw(2) << std::setfill('0') << 1 + tm->tm_mon
				<< std::setw(2) << std::setfill('0') << tm->tm_wday 
				<< "_" 
				<< std::setw(2) << std::setfill('0') << tm->tm_hour 
				<< std::setw(2) << std::setfill('0') << tm->tm_min 
				<< std::setw(2) << std::setfill('0') << tm->tm_sec 
				<< "] " << std::flush;
}

/* Account (constructor):
*	Opens the account by setting the index, the amount
*	to innitial_deposit and the nbDeposits and nbWithdrawls
*	to 0.
*	Increments the total number of accounts by one and the 
*	total amount by initialial_deposit.
*	Displays a statis message that the account was created.
*/
Account::Account( int initial_deposit )
{
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;

	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";created"
				<< std::endl;
}

/* ~Account (destructor):
*	Closes the account by decreasing the static variables
*	by the values of this account, printing a status
*	message and setting the values of this account to 0.
*/
Account::~Account( void )
{
	_nbAccounts--;
	_totalAmount -= this->_amount;
	_totalNbDeposits -= this->_nbDeposits;
	_totalNbWithdrawals -= this->_nbWithdrawals;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";closed"
				<< std::endl;

	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

/* getNbAccounts:
*	Returns the number of accounts.
*/
int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

/* getTotalAmount:
*	Returns the total amount on the account.
*/
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

/* getNbDeposits:
*	Returns the number of deposits on the account.
*/
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

/* getNbWithdrawals:
*	Returns the number of withdrawls.
*/
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

/* displayAccountsInfos:
*	Displays the overall Infos of all accounts.
*/
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() 
				<< ";total:" << getTotalAmount() 
				<< ";deposits:" << getNbDeposits() 
				<<";withdrawals:" << getNbWithdrawals() 
				<< std::endl;
}

/* makeDeposit:
*	Makes a deposit by adding the argument deposit
*	from the _amount and increments the _nbDeposits and 
*	_totalNbDeposits by one.
*/
void	Account::makeDeposit( int deposit )
{
	
	this->_nbDeposits++;
	
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
				<< ";p_amount:" << this->_amount << std::flush;
	
	this->_amount += deposit;

	std::cout << ";deposits:" << deposit
				<< ";amount:" << this->_amount
				<< ";nb_deposit:" << this->_nbDeposits
				<< std::endl;
}

/* makeWithdrawal:
*	Makes a withdrawl by suctracting the argument withdrawl
*	from the _amount and increments the _nbWithdrawls and
*	_totalNbWithdrawls by one.
*	Returns true.
*/
bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
				<< ";p_amount:" << this->_amount << std::flush;

	if (withdrawal < this->_amount)
	{
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal
					<< ";amount:" << this->_amount
					<< ";nb_withdrawals:" << this->_nbWithdrawals
					<< std::endl;
		return (true);
	}
	else
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
}

/* checkAmount:
*	Returns the amount of the account.
*/
int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

/* displayStatus:
*	Displays the status of the account.
*/
void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
				<< ";amount:" << this->_amount 
				<< ";deposits:" << this->_nbDeposits 
				<< ";withdrawals:" << this->_nbWithdrawals 
				<< std::endl;
}
