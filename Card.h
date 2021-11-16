#include "Account.h"

class Card {
  private:
    long long int cardNumber;
    vector<Account> accounts;
    string pin;
    bool isAuthenticated;

  public:
    Card(){}
    Card(long long int cardNum, vector<Account> acc, string inputedPin){
      cardNumber = cardNum;
      accounts = acc;
      pin = inputedPin;
      isAuthenticated = false;
    }
    long long int getCardNumber() {
      return cardNumber;
    }
    bool isAuth(){
      return isAuthenticated;
    }
    // function supposed to call to bank API to check whether the pin is correct
    bool isPinCorrect(string enteredPin) {
      cout << "PIN : " << pin << " : " << enteredPin << endl;
      if (pin == enteredPin) {
        isAuthenticated = true;
        return true;
      }
      return false;
    }
    vector<Account>& getAccounts() {
      return accounts;
    } 
};