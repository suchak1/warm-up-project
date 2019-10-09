#include "person.h"

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
    string ret =
      "username: " + get_username() +
      " first name: " + get_firstname() +
      " last name: " + get_lastname() +
      " gender: " + std::to_string(get_gender()) +
      " age: " + std::to_string(get_age()) +
      " tagline: " + get_tagline();
    return ret;
}

bool str_hasnum(string str) {
  for (int i = 0; i < str.length(); i++) {
    if (isdigit(str[i])) {
      return true;
    }
  }
  return false;
}

bool Person::set_username(string _username) {
  if (_username != "" &&
    str_isalnum(_username) &&
    _username.length() <= 128 &&
    isalpha(_username[0]) &&
    str_hasnum(_username)) {
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


bool valid_gender(int gen){
  if (gen == 1 || gen == 2) {
    return true;
  }
  else
    return false;
}

bool Person::set_gender(int _gender){
    if (valid_gender(_gender)){
        gender = _gender;
        return true;
    }
    else
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

  return
    set_username(_username) &&
    set_firstname(_firstname) &&
    set_lastname(_lastname) &&
    set_age(_age) &&
    set_tagline(_tagline) &&
    set_gender(_gender);
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
  queue<pair<string,Person>> temp = inbox_stat;
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
