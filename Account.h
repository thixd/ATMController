#include <bits/stdc++.h>
using namespace std;

class Account {
  private:
    long long int balance;
    long long int accountNumber;

  public:
    Account(){}
    Account(long long int bal, long long int accNum){
      balance = bal;
      accountNumber = accNum;
    }
    long long int getAccountNumber(){
      return accountNumber;
    }
    long long int seeBalance(){
      return balance;
    }
    long long int deposit(long long int depositAmmount){
      balance += depositAmmount;
      return balance;
    }
    long long int withdraw(long long int withdrawAmmount) {
      if (balance >= withdrawAmmount) {
        balance -= withdrawAmmount;
        return balance;
      }
      return -1;
    }
};
