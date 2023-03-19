#pragma once
#include <stdlib.h>
#include <string> 
#include <iostream>
#include <memory>

using namespace std;

class Contact {
private:
	string address;
	string city;
	string state;
	string zip_code;
	string phone_number;
	// shared_ptr<Contact> pointer;

public:
	Contact();
	Contact(string address, string city, string state, string zip_code, string phone_number);
	void contact_info(string address, string city, string state, string zip_code, string phone_number);
	void display_contact_info(string address, string city, string state, string zip_code, string phone_number);
};