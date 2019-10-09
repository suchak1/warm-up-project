#include "community.h"
#include "person.h"

Community::Community()
  : name(""), people(map<string,Person>()) {
}

Community::Community(string _name, map<string,Person> _people)
  : name(_name), people(_people) {
}

string Community::get_name() {
	return name;
}

bool Community::set_name(string _name) {
  if(_name != "" && _name.length() <= 128 && !isdigit(_name[0]) && str_isalnum(_name)) {
    name = _name;
    return true;
  }

    return false;
}

bool Community::add_person(Person _person) {
    string username = _person.get_username();

    if (people.count(username) == 0 && username != "") {
      people.insert(pair<string,Person> (username, _person));
      return true;
    }

    return false;
}

// return the person object for a given username
Person& Community::get_member(string username) {
    if (people.find(username) != people.end()) {
    	return people[username];
    }

    Person* p = new Person();
    return *p;
}

list<string> Community::get_all_usernames() {
    list<string> usernames;

    for (auto const& person : people) {
      usernames.push_back(person.first);
    }

    return usernames;
}

void Community::print_all_usernames() {
    list<string> usernames = get_all_usernames();

    string ret = "[";
    list<string>:: iterator it;

    for(it = usernames.begin(); it != usernames.end(); ++it) {
      ret += *it + (it != usernames.end() ? ", " : "");
    }

    ret += "]";

    cout << "Usernames: " << ret;
}

list<Person> Community::find_member(string firstname) {
    list<Person> ret;

    for (auto person : people) {
      if (person.second.get_firstname() == firstname) {
        ret.push_back(person.second);
      }
    }
    return ret;
}

list<Person> Community::find_member(int age_lb, int age_ub) {
  list<Person> ret;

  for (auto person : people) {
    int age = person.second.get_age();
    if (age >= age_lb && age <= age_ub) {
      ret.push_back(person.second);
    }
  }
  return ret;
}

bool Community::send_msg(list<string> usernames, string msg) {
  list<string>:: iterator it;
  bool success = true;

  for(it = usernames.begin(); it != usernames.end(); ++it) {
    if (people.count(*it) == 1) {
      Person().send_msg(people.at(*it), msg);
    }
    else {
      success = false;
    }
  }

	return success;
}
