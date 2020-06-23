// Copyright 2020 kkozlov

#include <iostream>
#include <iomanip>

#include <ctime>

#include "Account.class.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_nbCheckAmountCalls = 0;

Account::Account(int initial_deposit)
    : _accountIndex(Account::_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0), _nbWithdrawals(0) {
  ++Account::_nbAccounts;
  Account::_totalAmount += initial_deposit;
  Account::_displayTimestamp();
  std::cout << ' ';
  std::cout << "index:" << _accountIndex << ';'
            << "amount:" << _amount << ';'
            << "created\n";
}

Account::~Account(void) {
  Account::_displayTimestamp();
  std::cout << ' ';
  std::cout << "index:" << _accountIndex << ';'
            << "amount:" << _amount << ';'
            << "closed\n";
}

void Account::makeDeposit(int deposit) {
  if (deposit < 0)
    return ;
  ++Account::_totalNbDeposits;
  Account::_totalAmount += deposit;
  Account::_displayTimestamp();
  ++_nbDeposits;
  std::cout << ' ';
  std::cout << "index:" << _accountIndex << ';'
            << "p_amount:" << _amount << ';'
            << "deposit:" << deposit << ';';
  _amount += deposit;
  std::cout << "amount:" << _amount << ';'
            << "nb_deposits:" << _nbDeposits
            << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  Account::_displayTimestamp();
  std::cout << ' ';
  std::cout << "index:" << _accountIndex << ';'
            << "p_amount:" << _amount << ';';
  if (withdrawal > _amount) {
    std::cout << "withdrawal:refused\n";
    return 0;
  }
  _amount -= withdrawal;
  ++_nbWithdrawals;
  std::cout << "withdrawal:" << withdrawal << ';';
  std::cout << "amount:" << _amount << ';'
            << "nb_withdrawals:" << _nbWithdrawals << ';'
            << std::endl;
  ++Account::_totalNbWithdrawals;
  Account::_totalAmount -= withdrawal;
  return (1);
}

int Account::checkAmount(void) const {
  ++Account::_nbCheckAmountCalls;
  return (_amount);
}

void Account::displayStatus(void) const {
  Account::_displayTimestamp();
  std::cout << ' ';
  std::cout << "index:" << _accountIndex << ';'
            << "amount:" << _amount << ';'
            << "deposits:" << _nbDeposits << ';'
            << "withdrawals:" << _nbWithdrawals
            << std::endl;
  return ;
  std::cout << "\n=== ACCOUNT NO " << _accountIndex << " INFO ==="
            << "\nAmount: " << _amount
            << "\nNo Deposits: " << _nbDeposits
            << "\nNo Withdrawals: " << _nbWithdrawals
            << "\n========================="
            << std::endl;
}

int Account::getNbAccounts(void) {
  return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
  return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
  return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
  return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << ' ';
  std::cout << "accounts:" << Account::getNbAccounts() << ';'
            << "total:" << Account::getTotalAmount() << ';'
            << "deposits:" << Account::getNbDeposits() << ';'
            << "withdrawals:" << Account::getNbWithdrawals()
            << std::endl;
  return ;
  std::cout << "\n=== ACCOUNTS INFO ==="      
            << "\nNo Accounts: " << Account::getNbAccounts()
            << "\nTotal Amount: " << Account::getTotalAmount()
            << "\nNo Deposits: " << Account::getNbDeposits()
            << "\nNo Withdrawals: " << Account::getNbWithdrawals()
            << "\nNo CheckAmount Calls: " << _nbCheckAmountCalls
            << "\n====================="
            << std::endl;
}

void Account::_displayTimestamp(void) {
  std::time_t now;
  struct tm *localTime;

  now = std::time(0);
  localTime = std::localtime(&now);
  std::cout << std::put_time(localTime, "[%Y%m%d_%H%M%S]");
  return ;
  std::cout << '[' << localTime->tm_year + 1900  << localTime->tm_mon << localTime->tm_mday
            << '_' << localTime->tm_hour << localTime->tm_min << localTime->tm_sec
            << ']';
}
