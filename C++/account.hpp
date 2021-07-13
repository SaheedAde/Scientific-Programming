#ifndef _ACCOUNT_
#define _ACCOUNT_
#include <iostream>

class Account {
    private:
		int account_number;
		double current_balance;
		double fee;

    public:
		Account();
		Account(int, double, double);
		~Account();
		// Copy Constructor
		Account(const Account&);
		Account& operator=(const Account&);
		void setAccNum(int);
		int getAccNum() const;
		void setCurrBal(double);
		double getCurrBal() const;
		void setFee(double);
		double getFee() const;

		void deposit(double);
		void withdraw(double);
		void chargeFee();
		virtual void print();
		//virtual void update();
};

class SavingsAccount : public Account {
    private:
        double interest_rate;
    public:
        SavingsAccount();
        SavingsAccount(int, double, double, double);
        ~SavingsAccount();
        // Copy Constructor
        SavingsAccount(const SavingsAccount&);
        void setIntRate(double);
        double getIntRate() const;
        void addInterest();
        void print();
        //void update();
};

class CurrentAccount : public Account {
    private:
        double overdraft_limit;

    public:
        CurrentAccount();
        CurrentAccount(double, int, double, double);
        ~CurrentAccount();
        // Copy Constructor
        CurrentAccount(const CurrentAccount&);
        void setOverdraft(double);
        double getOverdraft() const;
        void printMessage();
        void print();
        //void update();
};

#endif
