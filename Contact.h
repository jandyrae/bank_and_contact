#pragma once
#include <stdlib.h>
#include <string> 
#include <iostream>
 
using namespace std;

class Contact {
private:
	string address;
	string city;
	string state;
	string zip_code;
	string phone_number;
	
public:
	Contact();
	Contact(string address, string city, string state, string zip_code, string phone_number);
	
	string get_address() const;
	string get_city() const;
	string get_state() const;
	string get_zip() const;
	string get_phone() const;

	void enter_contact();
	void display_contact_info() const;
};