//CertificateOfDeposit.h filea
//Anas Alsayed 202020067 JAN11
#include<iostream>
#include"bankAccount.h"
using namespace std;
class CertificateOfDeposit : public BankAccount
{
	 private:
                int maturityMonths;
                double interestRate;
                int currentCDMonth;
	public:
		CertificateOfDeposit(string, double,int);
		int getMaturityMonths();
		double getInterestRate();
		int getCurrentCDMonth();
		void withdraw() ;
		void deposit();
		void printStatement();
};
