#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include<iostream>
#include"bankAccount.h"
using namespace std;

class CheckingAccount: public BankAccount{
		public:
			
			CheckingAccount(string , double , int );
			virtual void writeCheck() = 0;
};
#endif
