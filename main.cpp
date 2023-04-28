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

    }

    void displayMessageLine(string message){

    }

    void displayMoneyAmount(double amount){

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

    }

};

class DepositSlot
{
public:

    void accenptEnvelope(){

    }

};

class BankDatabase
{
private:


public:

    BankDatabase(){

    }

    bool authenticateUser(int accountNumber, int pin){

    }

    double getAvailableBalance(int accountNumber){

    }

    void credit(int accountNumber, double amount){

    }

    void debit(int accountNumber, double amount){


    }


};

class Deposit
{
    private:


    public:
        Deposit(double amount){

        }

        double getAmount() const{

        }
};

class ATMController
{
    private:

    public:


    void performBalanceInquiry(){

    }

    void performWithdrawal(){

    }

    void performDeposit(){

    }

    void authenticateUser(){

    }

    public:
        void run(){
            
        }

};

int main(int argc, char const *argv[])
{
    ATMController atm;
    atm.run();

    return 0;
}
