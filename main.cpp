/*

Author: Tahmid Muntaser......

ATM Management System 1.0

*/

#include <bits/stdc++.h>

using namespace std;

class Screen
{

public:

    void displayMessage(string message){
        cout<<message;
    }

    void displayMessageLine(string message){
        cout << message << endl;
    }

    void displayMoneyAmount(double amount){
        cout<<amount<<" tk ";
    }


};

class Keypad
{
public:
    int getInput(){
        int input;
        cin>>input;

        return input;
    }

    double getAmountInput(){
        double input;
        cin>>input;

        return input;
    }

};

class CashDispenser
{
public:
    void dispenseCash(double amount){
        cout<<"Dispensing cash "<<amount<<" tk...."<<endl;
    }

};

class DepositSlot
{
public:

    void accenptEnvelope(){
        cout<<"Please insert your envelope..."<<endl;
    }

};

class BankDatabase
{
    private:
        struct Account{

            int accountNumber;
            int pin;
            double balance;

    };

    vector<Account> accounts;

    public:

    BankDatabase(){
        accounts.push_back({1234,5678, 1000.00});
         accounts.push_back({5678,1234, 2000.00});
          accounts.push_back({1357,2468, 3424.00});
            accounts.push_back({9999, 1111, 321.34});
              accounts.push_back({1290, 9876, 1290.00});
               accounts.push_back({3456, 1290, 4278.00});
    }

    bool authenticateUser(int accountNumber, int pin){
        for(auto& account : accounts){
            if(account.accountNumber == accountNumber && account.pin == pin){
                return true;
            }
        }
        return false;
    }

    double getAvailableBalance(int accountNumber){

        for(auto& account : accounts){
            if(account.accountNumber == accountNumber){
                return account.balance;
            }
        }
        return 0.0;
    }

    void credit(int accountNumber, double amount){
        for(auto& account : accounts){
            if(account.accountNumber == accountNumber){
                account.balance += amount;
                break;
            }
    }
    }

    void debit(int accountNumber, double amount){
        for(auto& account : accounts){
                    if(account.accountNumber == accountNumber){
                        account.balance -= amount;
                        break;
                    }

        }
    }


};

class Deposit
{
    private:

        double amount;

    public:
        Deposit(double amount): amount(amount){

        }

        double getAmount() const{
            return amount;
        }
};

class ATMController
{
    private:
        Screen screen;
        Keypad keypad;
        CashDispenser cashDispenser;
        DepositSlot depositSlot;
        BankDatabase bankDatabase;

        int accountNumber;
        bool userAuthenticated;

        enum TransactionType{
            BALANCE_INQUIRY,
            WITHDRAWAL,
            DEPOSIT,
            QUIT
        };

        TransactionType selectTransactionType(){
            screen.displayMessageLine("\nSelect a Transaction Type: ");
             screen.displayMessageLine("1. Balance inquiry");
              screen.displayMessageLine("2. Withdraw");
               screen.displayMessageLine("3. Deposit");
                screen.displayMessageLine("4. Quit");

            int choice = keypad.getInput();

            switch (choice)
            {
            case 1:
                return BALANCE_INQUIRY;
            
            case 2:
                return WITHDRAWAL;
            
            case 3:
                return DEPOSIT;
        
            case 4:
                return QUIT;
            
            default:

                 screen.displayMessageLine("\nInvalid choice. Please try again.");
                 return selectTransactionType();
                
            }
        }
    


    void performBalanceInquiry(){
     
        screen.displayMessageLine("\nBalance inquiry:");
        double availableBalance = bankDatabase.getAvailableBalance(accountNumber);

        screen.displayMessage("- Available balance: ");
        screen.displayMoneyAmount(availableBalance);
        screen.displayMessageLine("");

        // Wait for user to press Enter
        screen.displayMessageLine("\nPress Enter to continue...");
        while (cin.get() != '\n');
    }

    void performWithdrawal(){

        screen.displayMessageLine("\nWithdrawal:");

        double availableBalance = bankDatabase.getAvailableBalance(accountNumber);

        screen.displayMessage("- Available balance: ");
        screen.displayMoneyAmount(availableBalance);
        screen.displayMessageLine("");

        screen.displayMessageLine("- Enter amount to withdraw: ");
        double withdrawalAmount = keypad.getAmountInput();

        if (withdrawalAmount > availableBalance) {
            screen.displayMessageLine("\nInsufficient funds. Please try again.");
            return;
        }

        cashDispenser.dispenseCash(withdrawalAmount);
        bankDatabase.debit(accountNumber, withdrawalAmount);

        screen.displayMessageLine("\nTransaction complete.");
        screen.displayMessage("- New available balance: ");
        screen.displayMoneyAmount(bankDatabase.getAvailableBalance(accountNumber));
        screen.displayMessageLine("");

        // Wait for user to press Enter
        screen.displayMessageLine("\nPress Enter to continue...");
        while (cin.get() != '\n');

    }

    void performDeposit(){

      screen.displayMessageLine("\nDeposit:");

        screen.displayMessageLine("- Enter deposit amount: ");
        double depositAmount = keypad.getAmountInput();

        Deposit deposit(depositAmount);

        depositSlot.accenptEnvelope();

        screen.displayMessageLine("\nTransaction complete.");
        bankDatabase.credit(accountNumber, deposit.getAmount());
        screen.displayMessage("- New available balance: ");
        screen.displayMoneyAmount(bankDatabase.getAvailableBalance(accountNumber));
        screen.displayMessageLine("");

        // Wait for user to press Enter
        screen.displayMessageLine("\nPress Enter to continue...");
        while (cin.get() != '\n');


    }

    void authenticateUser(){

           
        screen.displayMessageLine("\nWelcome! ");
        screen.displayMessageLine("Please Enter your account number: ");
        accountNumber = keypad.getInput();

        screen.displayMessageLine("Please Enter your 4 digit PIN: ");
        int pin = keypad.getInput();


        userAuthenticated = bankDatabase.authenticateUser(accountNumber, pin);


        if(!userAuthenticated){
            screen.displayMessageLine("\nInvalid Account Number or PIN, Please try again...");
            authenticateUser();
        }

    }

    public:
        void run(){
            while (true)
            {
                authenticateUser();

                while (userAuthenticated)
                {
                    TransactionType transactionType = selectTransactionType();

                    switch (transactionType)
                    {
                    case BALANCE_INQUIRY:
                        performBalanceInquiry();
                        break;

                     case WITHDRAWAL:
                        performWithdrawal();
                        break;

                     case DEPOSIT:
                        performDeposit();
                        break;

                     case QUIT:
                        screen.displayMessageLine("\nThank You...");
                        return;
                    

                    }
              
                }
            
            
            }
        }

};

int main(int argc, char const *argv[])
{
    ATMController atm;
    atm.run();

    return 0;
}
