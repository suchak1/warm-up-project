#include "person.h"
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::ostringstream


bool str_isalpha(const string str){
    for(int i = 0; i < str.size(); i++)
    	if((isalpha(str[i]) == 0) || (str[i] == ' '))
    		return false;
    return true;
}

bool str_isalnum(const string s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

Person::Person()
  : username(""), firstname(""), lastname(""), gender(0), age(0), tagline("") {
}

Person::Person(string _username, string _firstname, string _lastname,
               int _gender, int _age, string _tagline)
  : username(_username), firstname(_firstname), lastname(_lastname),
    gender(_gender), age(_age), tagline(_tagline) {
}

string Person::get_username() {
    return username;
}
string Person::get_firstname() {
    return firstname;
}
string Person::get_lastname() {
    return lastname;
}
int Person::get_gender(){
    return gender;
}
int Person::get_age() {
    return age;
}
string Person::get_tagline() {
    return tagline;
}
string Person::get_info() {
    std::ostringstream buffer; 
    buffer << "Username: "<< get_username() << '\n' 
        << "First Name: "<< get_firstname() << '\n'
        << "Last Name: "<< get_lastname() << '\n'
        << "Gender: "<< get_gender() << '\n'
        << "Age: "<< get_age() << '\n'
        << "Tagline: "<< get_tagline() << '\n';
    return buffer.str();
}

bool str_hasnum(string str) {
  for (int i = 0; i < str.length(); i++) {
    if (isdigit(str[i])) {
      return true;
    }
  }
  return false;
}

bool valid_username(string str){
  if (str != "" &&
    str_isalnum(str) &&
    str.length() <= 128 &&
    isalpha(str[0]) &&
    str_hasnum(str)) {
      return true;
    }

	return false;
} 

bool Person::set_username(string _username) {
  if (valid_username(_username)){
      username = _username;
      return true;
  }
  return false;
}

bool valid_name(string name) {
  return (name != "" && str_isalpha(name) && name.length() <= 64);
}

bool Person::set_firstname(string _firstname) {
	if (valid_name(_firstname)) {
        firstname = _firstname;
        return true;
    }
    else {
        return false;
    }
}


bool Person::set_lastname(string _lastname) {
	if (valid_name(_lastname)) {
        lastname = _lastname;
        return true;
    }
    else {
        return false;
    }
}

bool Person::set_gender(int _gender){
    if (_gender == 1 || _gender == 2) {
      gender = _gender;
      return true;
    }

    return false;
}

bool Person::set_age(int _age) {
    if (_age >= 18 && _age <= 99) {
        age = _age;
        return true;
    }
    else {
        return false;
    }
}
bool Person::set_tagline(string _tagline) {
    if (_tagline != "" && _tagline.length() <= 512) {
        tagline = _tagline;
        return true;
    }
    else {
        return false;
    }
}


bool Person::set_info(string _username, string _firstname, string _lastname,
                      int _age, string _tagline, int _gender) {
    if(valid_name(_firstname) && valid_name(_lastname))
}

void Person::add_to_block_list(string username){
	block_list.insert(username);
}

bool Person::in_block_list(string username){
	return block_list.find(username) != block_list.end();
}
// condition: receipient must have < 5 msg from self (recipient.get_msgstat(this) < 5)
// and self is not in receipient's block list => !recipient.in_block_list(username)
bool Person::send_msg(Person &recipient, string msg) {

	if (recipient.get_msgstat(*this) < 5 && !recipient.in_block_list(username)) {
    // std::pair <string, Person> msg = make_pair(msg, this);
    // recipient.inbox_stat.push(msg);
    return true;
  }

	return false;
}

void Person::get_msg_with_info(string msg, Person* sender) {
	// TODO
	// get message
}

int Person::get_msgstat(Person recipient){
  queue<pair<string,Person> > temp = inbox_stat;
  int count = 0;

  while (!temp.empty()) {
    if (temp.front().second.get_username() == recipient.get_username())
      count++;
  }
	return count;
}
// delete message (front or back?) and return inbox_stat.length() <= 1
bool Person::read_msg() {
	// TODO
	// print the message if there any message inbox
    return false;

}
