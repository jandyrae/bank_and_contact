#include "Account.h"

int Account::next_ID = 0;

Account::Account() : account_ID{ 0 }, account_name{ "" }, account_balance{ 0.0f }, pContact( nullptr ) {}
Account::Account(int id, string name, float balance) : account_ID(next_ID), account_name(name), account_balance(balance), pContact(nullptr)
{}

int Account::get_id()
{
	return account_ID;
}

float Account::get_balance()
{
	return account_balance;
}

void Account::account_info()
{
	cout << "\nEnter the name: ";
	cin >> account_name;
	cout << endl << "Enter the balance: ";
	cin >> account_balance;
	account_ID = ++next_ID;
}

void Account::account_display() const
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout << setprecision(2);
	cout << endl << "Account ID : " << account_ID << "   Name: " << account_name << "   Balance: $" << account_balance << endl;
	if (pContact != nullptr)
	{
		pContact->display_contact_info();
	}
}

void Account::account_deposit(float deposit)
{
	account_balance += deposit;
}

void Account::account_withdrawl(float withdrawl)
{
	account_balance -= withdrawl;
}

void Account::account_create(list<Account>& account_list)
{
	Account account(account_ID, account_name, account_balance);
	account_list.push_back(account); 
}

void Account::display_account_list(list<Account>& account_list)
{
	for_each(account_list.begin(), account_list.end(), [](auto& acct)
		{
			acct.account_display();
		});
}

void Account::update_balance(float new_balance)
{
	account_balance = new_balance;
}

void Account::add_contact()
{
	pContact = std::make_shared<Contact>();
	pContact->enter_contact();
}

