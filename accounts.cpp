#include<iostream>
#include<string>
#include"certificateOfDeposit.h"
#include"highInterestSavings.h"
#include"serviceChargeChecking.h"
#include"highInterestChecking.h"
using namespace std;

//Implemntation for BankAccount.h

BankAccount::BankAccount(string AccountHoldersName,int AccNo,  double AccBal){  
	name = AccountHoldersName;  
	accountNumber = AccNo;    
	balance = AccBal;
	};

string BankAccount::getName() { 
	return name;
 	}

int BankAccount::getAccountNumber(){ 
	return accountNumber;
	}

double BankAccount::getBalance(){ 
	return balance; 
	}
void BankAccount::Deposit(){
        double am;
        cout << "Please enter you want to deposit : " << endl;
        cin >> am;

        if (am >= 0) {
        	balance += am;
               cout << "The balance after the deposit : " << balance << endl;
               }
	


}
void BankAccount::WithDraw(){
	double am;
        cout << "Please enter you want to withdrwal : " << endl;
        cin >> am;

        if (am >= 0) {
                        if(balance >= am){
                                balance -= am;
                                cout << "The balance" << balance << endl;
                        }
        }

        else
{
                cout<<" Overdraft. Below Minimum Balance."<<am;
        }
}
double BankAccount::setBalance(double AccBal){
	if(balance >=0){
		return balance = AccBal;
		}
	else{	
		cout << "NO balance found :" << endl;
	}
		return 0;
	}
			
void BankAccount::printStatement() {}


// Implemntation for CheckingAccount.h
CheckingAccount::CheckingAccount(string AccountHoldersName, double AccBal, int AccNo) : BankAccount(AccountHoldersName, AccBal, AccNo){}


// Implemntataion for ServiceChargeChecking.h

ServiceChargeChecking::ServiceChargeChecking(string AccountHoldersName, double AccBal, int AccNo):
 CheckingAccount(AccountHoldersName, AccBal, AccNo){
	checksWritten = 0;
	}

void ServiceChargeChecking::writeCheck()
{
	double checkW = checksWritten;
	double checkAm;
	double b = getBalance();
	cout << "Enter the value of the check : " << endl;
	cin >> checkAm;
	if( checkW > 0)
	{
		if( checkAm <=b)
		{
			checkW  = checkW - 1;
			b = b - checkAm;	
			cout << "Balcne after withdrawing the check =  " <<b<< endl;
		}
		else 
		{
			cout << "no enough  alance " << b <<endl;
		}
}	
	else
	{
		cout << "check withdrawled :"  << b << endl;
	}
}


void ServiceChargeChecking::printStatement(){
cout << "Service Charge Checking: " << endl;
cout << "Name: " << getName() << endl;
cout << "Account Number: " << getAccountNumber() << endl;
cout << "Final Balance: " << getBalance() << endl;

}

//noServiceChecking.h file implentation

NoServiceChargeChecking::NoServiceChargeChecking(string AccountHoldersName, double AccBal, int AccNo): 
 CheckingAccount(AccountHoldersName, AccBal, AccNo) 
{
	MinBalance = 2000;
        IntRate = 0.03;
	checksWritten = 0;
}
double NoServiceChargeChecking::getIR(){
        return IntRate;
}
int NoServiceChargeChecking::getMB(){
        return MinBalance;
}

void NoServiceChargeChecking::writeCheck() { 
	
	double checkW = checksWritten;
        double checkAm;
        double AccBal = getBalance();
        cout << "Enter the value of the check : " << endl;
        cin >> checkAm;
        if( checkW > 0)
        {
                if( checkAm <=AccBal)
                {
                        checkW  = checkW - 1;
                        AccBal = AccBal - checkAm;
			setBalance(AccBal);        
                        cout << "Balcne after withdrawing the check =  " <<AccBal<< endl;
                }
                else
                {
                        cout << "no enough  alance " << AccBal <<endl;
                }
}
        else
        {
                cout << " check withdrawled :"  << AccBal << endl;
        }
}


void NoServiceChargeChecking::printStatement(){
cout << "No service charge checking" << endl;
cout << "Name: " << getName() << endl;
cout << "Account Number: " << getAccountNumber() << endl;
cout << "Final Balance: " << getBalance()  << endl;
cout <<"Intrest Rate:"<< getIR() << endl;
cout << " Minimum Balance:" << getMB() << endl << endl;

}

//HighIntesrtChecking.h file implementation
HighInterestChecking::HighInterestChecking(string AccountHoldersName, double AccBal, int AccNo): NoServiceChargeChecking(AccountHoldersName, AccBal, AccNo){
  	MinBalance = 3000;
        IntRate = 0.08;
}
double HighInterestChecking::getIR(){
        return IntRate;
}
int HighInterestChecking::getMB(){
        return MinBalance;
}
void HighInterestChecking::printStatement(){
cout << "High Interest Checking: " << endl;
cout << "Name: " << getName() << endl;
cout << "Account Number: " << getAccountNumber() << endl;
cout << "Final Balance: " << getBalance() << endl;
cout <<"Intrest Rate:"<< getIR() << endl;
cout << " Minimum Balance:" << getMB() << endl << endl;
}
//Implemnatation for SavingsAccount.h
SavingsAccount::SavingsAccount(string AccountHoldersName, double AccBal, int AccNo) : BankAccount(AccountHoldersName, AccBal, AccNo){
		 MinBalance = 2000;
                 IntRate = 0.03;

}
void SavingsAccount::Deposit(){
        double am;
        double b = getBalance();
        cout << "Please enter you want to deposit : " << endl;
        cin >> am;

        if (am >= 0) {
                 am+=b;
               cout << "The balance after the deposit : " << b << endl;
               }
}
void SavingsAccount::WithDraw(){
        double am;
        double b = getBalance();
        cout << "Please enter you want to withdrwal : " << endl;
        cin >> am;

        if (am >= 0) {
                        if(b >= am){
                                 am-=b;
                                cout << "The balance" << b << endl;
                        }
        }

        else
{
                cout<<" Overdraft. Below Minimum Balance."<<am;
        }
}


double SavingsAccount::getIR(){
	return IntRate;
}
int SavingsAccount::getMB(){
	return MinBalance;
}
void SavingsAccount::printStatement(){
cout << "Saving account :" << endl;
cout << "Name: " << getName() << endl;
cout << "Account Number: " << getAccountNumber() << endl;
cout << "Final Balance: " << getBalance()  << endl;
cout <<"Intrest Rate:"<< getIR() << endl;
cout << " Minimum Balance:" << getMB() << endl << endl;
}


//Implwmnnatation for highIntrestSavings.h file

HighInterestSavings::HighInterestSavings(string AccountHoldersName, double AccBal, int AccNo): SavingsAccount(AccountHoldersName, AccBal, 0.05){
	minimumBalance = 2500;
}
int HighInterestSavings::getMinimumBalance(){
	return minimumBalance;
}

void HighInterestSavings::WithDraw()

{
	double am;
	double b = getBalance();
        cout << "Please enter you want to withdrwal : " << endl;
        cin >> am;
	
	if (am >= 0) {
			if(b >= am){
				b = b - am;
				cout << "The balance" << b << endl;
			}	
	}

	else
{
		cout<<" Overdraft. Below Minimum Balance."<<am;
	}
}

void HighInterestSavings::printStatement(){
cout << "High interest savings: " << endl;
cout << "Name: " << getName() << endl;
cout << "Account Number: " << getAccountNumber() << endl;
cout << "Final Balance: " << getBalance() << endl;
cout << "Min Balance " << getMinimumBalance() << endl << endl;

}

//Implemintation for CertificateOfDeposit.h

CertificateOfDeposit::CertificateOfDeposit(string AccountHoldersName, double AccBal, int AccNo) : BankAccount(AccountHoldersName, AccBal, AccNo)
{ 
	maturityMonths = 6;  
	interestRate = 0.05;  
	currentCDMonth = 0;
} 

int CertificateOfDeposit::getCurrentCDMonth(){
 return currentCDMonth;
	}

double CertificateOfDeposit::getInterestRate(){
 return interestRate;
	}

int CertificateOfDeposit::getMaturityMonths(){  
return maturityMonths; 
	}

void CertificateOfDeposit::printStatement(){
cout << "Certifcate of deposit: " << endl;
cout << "Name: " << getName() << endl;
cout << "Account Number: " << getAccountNumber() << endl;
cout << "Interest Rate: " << getInterestRate() * 100 << "%" << endl;
cout << "Final Balance: " << getBalance() << endl << endl;
cout << "Mutrity Months: " << getMaturityMonths() << endl << endl;

}
int main (){


BankAccount **SA = new BankAccount*[1];
cout << "Certificate of Deposits" << endl;
cout<< endl;
 SavingsAccountc("Anas", 300,150 );
SA[0] = &c;
SA[0]->monthlyStatement();
SA[0]-›makeDeposits():
SA[0]->withdrawMoney();
}}
