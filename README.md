Implement a simple ATM controller
========
Code for a simple ATM. The order of operation: Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw

Implementing description
====
Follow the order of Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw. Implemented class ATM, Card and Account looks like the UML Diagram below. 
![Alt text](/screenshot/classUMLdiagram.JPG "Class UML Diagram") <br/>
ATM class holds bank data. When the card number is verify in bank data through `isCardValid`. If the card is valid, we move forward and do the authentication in Card class `isPinCorrect`. Customer can perform see balance, do the deposit or withdraw(when they have enough money to do so). 

How to run
====
First compile the test.cpp by `C/C++: g++.exe`.The test can be conducted through console with some sample bank database provided.

