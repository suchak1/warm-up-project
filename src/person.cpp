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
    while (it != s.end() && std::isalnum(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool str_hasnum(string str) {
  for (int i = 0; i < str.length(); i++) {
    if (isdigit(str[i])) {
      return true;
    }
  }
  return false;
}

Person::Person()
  : username(""), firstname(""), lastname(""), gender(0), age(0), tagline("") {
}

bool valid_username(string _username) {
  return (_username != "" &&
    str_isalnum(_username) &&
    _username.length() <= 128 &&
    isalpha(_username[0]) &&
    str_hasnum(_username));
}

bool valid_name(string name) {
  return (name != "" && str_isalpha(name) && name.length() <= 64);
}

bool valid_gender(int _gender) {
  return (_gender == 1 || _gender == 2);
}

bool valid_age(int _age) {
  return (_age >= 18 && _age <= 99);
}

bool valid_tag(string _tagline) {
  return (_tagline != "" && _tagline.length() <= 512);
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
    vector<string> fields =
        {"username", "first name", "last name", "gender", "age", "tagline"};

    vector<string> info =
        {get_username(), get_firstname(), get_lastname(),
        (get_gender() == 0 ? "0" : get_gender() - 1 ? "Male" : "Female"),
        std::to_string(get_age()), get_tagline()};

    string ret = "";

    for (int i = 0; i < fields.size(); i++) {
      ret += fields[i] + ": " + info[i] + (i < fields.size() - 1 ? ", " : "");
    }

    return ret;
}

bool Person::set_username(string _username) {
  if (valid_username(_username)) {
      username = _username;
      return true;
    }

	return false;
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
    if (valid_gender(_gender)) {
      gender = _gender;
      return true;
    }

    return false;
}

bool Person::set_age(int _age) {
    if (valid_age(_age)) {
        age = _age;
        return true;
    }
    else {
        return false;
    }
}
bool Person::set_tagline(string _tagline) {
    if (valid_tag(_tagline)) {
        tagline = _tagline;
        return true;
    }
    else {
        return false;
    }
}


bool Person::set_info(string _username, string _firstname, string _lastname,
                      int _age, string _tagline, int _gender) {

  bool success =
    valid_username(_username) && valid_name(_firstname) && valid_name(_lastname)
    && valid_age(_age) && valid_tag(_tagline) && valid_gender(_gender);

  if(success) {
    set_username(_username);
    set_firstname(_firstname);
    set_lastname(_lastname);
    set_age(_age);
    set_tagline(_tagline);
    set_gender(_gender);
  }

  return success;
}

void Person::add_to_block_list(string username){
	block_list.insert(username);
}

bool Person::in_block_list(string username){
	return block_list.find(username) != block_list.end();
}

void Person::add_msg(pair <string, Person> new_msg) {
  inbox_stat.push(new_msg);
}

bool Person::send_msg(Person &recipient, string msg) {

	if (recipient.get_msgstat(*this) < 5 && !recipient.in_block_list(username)) {
    pair <string, Person> new_msg = make_pair(msg, *this);
    recipient.add_msg(new_msg);
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
