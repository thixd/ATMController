#include "ATM.h"

int main() {
  // example database
  vector<Card> cardDatabase = {
    Card(12, {Account(10000, 1),Account(10000, 2)}, "1111"),
    Card(34, {Account(0, 3),Account(50, 4)}, "3333"),
    Card(56, {Account(100000000000, 5),Account(20, 6)}, "5555"),
    Card(78, {Account(0, 7),Account(0, 8)}, "7777"),
  };

  // declaration
  ATM atm = ATM(cardDatabase);
  string pin;
  long long int cardNumber;
  Card currentCard;
  vector<Account> accounts;
  long long int accountIndex;
  Account currentAccount;
  int action;
  long long int withdrawAmmount;
  long long int depositAmmount;
  
  
  while(1){
    // 1. INSERT CARD
    cout << "========================================" << endl;
    cout << "Welcome to ATM. Please insert your card!" << endl;
    cout << "Your card number : ";
    cin >> cardNumber;
    if (!atm.isCardValid(cardNumber, currentCard)) {
      cout << "Your card does not exist. Please try again!" << endl;
      continue;
    }

    // 2. PIN NUMBER
    //Expected pin might only have 4 digits
    pin = "";
    while(pin.size() != 4 || !currentCard.isPinCorrect(pin)) {
      cout << "Please enter your PIN (4 digits): " ;
      cin >> pin;
      //Prevent case user enter more than 4 digits
      if(pin.size() != 5) {
        cout << "Please try again! Your PIN is 4 digits"<< endl;
        continue;
      }
      if(!currentCard.isPinCorrect(pin)) {
        cout << "Please try again! Your pin is not correct"<< endl;
        continue;
      }
    }
    
    if(currentCard.isAuth()){
      // 3. SELECT ACCOUNT
      cout << "Enter number to select you account : "<< endl;
      accounts = currentCard.getAccounts();
      for(int i = 0; i < accounts.size(); i ++) {
        cout << "(" << i << ") " << accounts[i].getAccountNumber() << endl; 
      }
      cin >> accountIndex;
      if(accountIndex < 0 || accountIndex >= accounts.size()) {
        cout << "Please enter a valid account"<< endl;
        continue;
      }
      currentAccount = accounts[accountIndex];

      //4. BALANCE/ DEPOSIT/ WITHDRAW
      cout << "Available actions: " << endl;
      cout << "(0) See Balance" << endl;
      cout << "(1) Deposit" << endl;
      cout << "(2) Withdraw" << endl;
      cout << "Select your action: ";
      cin >> action;
      if (action < 0 || action > 2) {
        cout << "Please enter a valid action!"<< endl;
        continue;
      }
      if(action == 0) {
        cout << "Your Balance : " << currentAccount.seeBalance() << endl;
      } else if (action == 1) {
        cout << "Enter deposit ammount : ";
        cin >> depositAmmount;
        cout << "Your are successfully deposit to your account. New balance: " << currentAccount.deposit(depositAmmount) << endl;
      } else {
        cout << "Enter withdraw ammount : ";
        cin >> withdrawAmmount;
        int newBalance = currentAccount.withdraw(withdrawAmmount);
        if(newBalance == -1){
          cout << "You do not have enough money to withdraw. Please try again " << endl;
          continue;
        } else {
          cout << "Your are successfully withdraw. New balance: " <<  newBalance << endl;
        }
      }
    }
  }
  return 0;
}