#pragma once
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <algorithm>
#include <memory>
#include "Contact.h"

using namespace std;
using std::shared_ptr;

class Account {
private:
	int account_ID;
	string account_name;
	float account_balance;
	static int next_ID;
	std::shared_ptr<Contact> pContact;

public:
	Account();
	Account(int account_ID, string account_name, float account_balance);
	int get_id();
	float get_balance();
	void account_info(void);
	void account_display(void) const;
	void account_deposit(float deposit);
	void account_withdrawl(float withdrawl);
	void account_create(list<Account>& account_list);
	void display_account_list(list<Account>& account_list);
	void update_balance(float new_balance);
	void add_contact(void);

};