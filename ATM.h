#include "Card.h"

class ATM{
  private:
    vector<Card> bankDatabase;

  public:
    ATM(vector<Card> database) {
      bankDatabase = database;
    }
    bool isCardValid(long long int cardNumber, Card& currentCard) {
      for (int i = 0; i < bankDatabase.size(); i++) {
        if(bankDatabase[i].getCardNumber() == cardNumber) {
          currentCard = bankDatabase[i];
          return true;
        }
      }
      return false;
    }
};