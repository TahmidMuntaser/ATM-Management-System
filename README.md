# ATM-Management-System

This Project is to make an Automated Teller Machine(ATM) with user's Account Number, 
and PIN, with that users can withdraw, deposit, and view their 
account balance.

This is a C++ program for an ATM Management System. The program includes several classes 
representing different components of an ATM, such as Screen, Keypad, 
CashDispenser, DepositSlot, BankDatabase, and ATMController. 

The Screen class is responsible for displaying messages to the user, such as prompts 
and results of transactions. The Keypad class handles user input from the keypad, 
including PINs and monetary amounts. The CashDispenser class is responsible for 
dispensing cash during a withdrawal transaction. The DepositSlot class accepts 
envelopes from users during a deposit transaction. The BankDatabase class 
represents the database of user accounts and provides methods for authenticating 
users, getting available balance, and performing transactions such as debiting and 
crediting an account. 

The ATMController class is the main controller of the system and is responsible for 
coordinating the different components to perform transactions. It includes a selectTransactionType() 
method that prompts the user to select a transaction type, and then performs the corresponding 
transaction using methods from the other components. The available transaction types are balance 
inquiry, withdrawal, deposit, and quit. 

The program includes some sample user accounts in the BankDatabase constructor for testing 
purposes. Overall, this program provides a basic framework for an ATM Management System, and 
could be extended to include additional features such as multiple languages, different account 
types, and more complex transaction types.



     +------------------+           +------------------+
    |      Screen       |           |      Keypad      |
    +-------------------+           +------------------+
    | -displayMessage() |           | -getInput()      |
    | -displayMessageL()|           | -getAmountInput()|
    | -displayMoneyAmo()|           +------------------+
    +--------+---------+
             ^
             |
    +--------+---------+
    |  CashDispenser   |
    +------------------+
    | -dispenseCash()  |
    +--------+---------+
             ^
             |
    +--------+---------+
    |  DepositSlot     |
    +------------------+
    | -accenptEnvelope()|
    +--------+---------+
             ^
             |
    +--------+-----------+
    |   BankDatabase     |
    +--------------------+
    | -accounts: vector  |
    | -authenticateUser()|
    | -getAvailableBala()|
    | -credit()          |
    | -debit()           |
    +--------+-----------+
             ^
             |
    +--------+-----------+
    |   Deposit          |
    +--------------------+
    | -amount: double    |
    | +getAmount(): double|
    +--------+-----------+
             ^
             |
    +--------+-----------+
    |  ATMController     |
    +--------------------+
    | -screen: Screen    |
    | -keypad: Keypad    |
    | -cashDispenser: Ca.|
    | -depositSlot: Depos|
    | -bankDatabase: Ban.|
    | -accountNumber: int|
    | -userAuthenticated:|
    |    bool            |
    | +selectTransactionT|
    | +performBalanceInq.|
    | +performWithdrawal()|
    | +performDeposit()  |
    +--------------------+
