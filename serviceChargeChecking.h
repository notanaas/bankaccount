#include<iostream>
#include<string>
#include"checkingAccount.h"
using namespace std;
class ServiceChargeChecking: public CheckingAccount{
	public:
		ServiceChargeChecking(string, double , int);
		void writeCheck();
		void printStatement();
		int checksWritten;
	        const int checkNo = 5;



};
