#include "gtest/gtest.h"
#include "person.h"

// this class is used for testing public methods in class Person
class test_person: public ::testing::Test {
protected:
	Person person;
	Person* recipient = new Person("alpha1", "Ash", "Ketchum", 2, 18, "Pikachu");
	Person* illegal = new Person("!Illegal", "Ash", "Ketchum", 2, 18, "Pikachu");
	Person* loaded = new Person("beta2", "Officer", "Jenny", 1, 18, "Chansey");
};

// test constructors
TEST_F(test_person, test_constructors) {
	EXPECT_EQ(person.get_username(), "");
	EXPECT_EQ(person.get_firstname(), "");
	EXPECT_EQ(person.get_lastname(), "");
	EXPECT_EQ(person.get_gender(), 0);
	EXPECT_EQ(person.get_age(), 0);
	EXPECT_EQ(person.get_tagline(), "");

	EXPECT_EQ(illegal -> get_username(), "");
	EXPECT_EQ(illegal -> get_firstname(), "");
	EXPECT_EQ(illegal -> get_lastname(), "");
	EXPECT_EQ(illegal -> get_gender(), 0);
	EXPECT_EQ(illegal -> get_age(), 0);
	EXPECT_EQ(illegal -> get_tagline(), "");

	EXPECT_EQ(loaded -> get_username(), "beta2");
	EXPECT_EQ(loaded -> get_firstname(), "Officer");
	EXPECT_EQ(loaded -> get_lastname(), "Jenny");
	EXPECT_EQ(loaded -> get_gender(), 1);
	EXPECT_EQ(loaded -> get_age(), 18);
	EXPECT_EQ(loaded -> get_tagline(), "Chansey");
}

// test get_username and set_username
TEST_F(test_person, test_username) {
	EXPECT_FALSE(person.set_username(""));
	EXPECT_EQ(person.get_username(), "");

	EXPECT_FALSE(person.set_username("abc,"));
	EXPECT_EQ(person.get_username(), "");

	EXPECT_FALSE(person.set_username(std::string (129, 'x')));
	EXPECT_EQ(person.get_username(), "");

	EXPECT_FALSE(person.set_username("a"));
	EXPECT_EQ(person.get_username(), "");

	EXPECT_FALSE(person.set_username("1a"));
	EXPECT_EQ(person.get_username(), "");

	EXPECT_FALSE(person.set_username("nodigits"));
	EXPECT_EQ(person.get_username(), "");

	EXPECT_TRUE(person.set_username("a1"));
	EXPECT_EQ(person.get_username(), "a1");

	EXPECT_TRUE(person.set_username("alpha1"));
	EXPECT_EQ(person.get_username(), "alpha1");

	EXPECT_TRUE(person.set_username("beta2"));
	EXPECT_EQ(person.get_username(), "beta2");

	EXPECT_TRUE(person.set_username("th1sw0rk5"));
	EXPECT_EQ(person.get_username(), "th1sw0rk5");

	EXPECT_TRUE(person.set_username(std::string (127, 'x') + '0'));
	EXPECT_EQ(person.get_username(), std::string (127, 'x') + '0');
}

// test get_firstname and set_firstname
TEST_F(test_person, test_firstname) {
	EXPECT_FALSE(person.set_firstname(""));
	EXPECT_EQ(person.get_firstname(), "");

	EXPECT_FALSE(person.set_firstname("abcde12"));
	EXPECT_EQ(person.get_firstname(), "");

	EXPECT_FALSE(person.set_firstname("abcdefg0"));
	EXPECT_EQ(person.get_firstname(), "");

	EXPECT_FALSE(person.set_firstname("abcdefg;"));
	EXPECT_EQ(person.get_firstname(), "");

	EXPECT_FALSE(person.set_firstname(std::string (65, 'x')));
	EXPECT_EQ(person.get_firstname(), "");

	EXPECT_TRUE(person.set_firstname("alpha"));
	EXPECT_EQ(person.get_firstname(), "alpha");

	EXPECT_TRUE(person.set_firstname("beta"));
	EXPECT_EQ(person.get_firstname(), "beta");

	EXPECT_TRUE(person.set_firstname("gamma"));
	EXPECT_EQ(person.get_firstname(), "gamma");

	EXPECT_TRUE(person.set_firstname(std::string (64, 'x')));
	EXPECT_EQ(person.get_firstname(), std::string (64, 'x'));
}

// test get_lastname and set_lastname
TEST_F(test_person, test_lastname) {
	EXPECT_FALSE(person.set_lastname(""));
	EXPECT_EQ(person.get_lastname(), "");

	EXPECT_FALSE(person.set_lastname("abcde12"));
	EXPECT_EQ(person.get_lastname(), "");

	EXPECT_FALSE(person.set_lastname("abcdefg0"));
	EXPECT_EQ(person.get_lastname(), "");

	EXPECT_FALSE(person.set_lastname("abcdefg;"));
	EXPECT_EQ(person.get_lastname(), "");

	EXPECT_FALSE(person.set_lastname(std::string (65, 'x')));
	EXPECT_EQ(person.get_lastname(), "");

	EXPECT_TRUE(person.set_lastname("alpha"));
	EXPECT_EQ(person.get_lastname(), "alpha");

	EXPECT_TRUE(person.set_lastname("beta"));
	EXPECT_EQ(person.get_lastname(), "beta");

	EXPECT_TRUE(person.set_lastname("gamma"));
	EXPECT_EQ(person.get_lastname(), "gamma");

	EXPECT_TRUE(person.set_lastname(std::string (64, 'x')));
	EXPECT_EQ(person.get_lastname(), std::string (64, 'x'));
}

/**you may need to write more test functions.
 *  What we provide here is just for your reference
 */

// test get_age and set_age
//   test_person is the name of class your inherit from the base Test class
//   test_age is the name of this test case, which will show up in the test
//     results
//   make sure you cover every subroutine and branches
//   here we test edge cases of invalid ages
//   also, we test the get_age() method
//   avoid using ASSERT_FALSE here; if there is something wrong in ASSERT,
//   it will abort the whole testing which will hinder the grading process
TEST_F(test_person, test_age) {
	EXPECT_FALSE(person.set_age(-1));
	EXPECT_EQ(person.get_age(), 0);

	EXPECT_FALSE(person.set_age(100));
	EXPECT_EQ(person.get_age(), 0);

	EXPECT_FALSE(person.set_age(17));
	EXPECT_EQ(person.get_age(), 0);

	EXPECT_TRUE(person.set_age(18));
	EXPECT_EQ(person.get_age(), 18);

	EXPECT_TRUE(person.set_age(99));
	EXPECT_EQ(person.get_age(), 99);
}

//test get_gender and set_gender
TEST_F(test_person,test_gender) {
	EXPECT_FALSE(person.set_gender(-1));
	EXPECT_EQ(person.get_gender(), 0);

	EXPECT_FALSE(person.set_gender(0));
	EXPECT_EQ(person.get_gender(), 0);

	EXPECT_FALSE(person.set_gender(3));
	EXPECT_EQ(person.get_gender(), 0);

	EXPECT_TRUE(person.set_gender(1));
	EXPECT_EQ(person.get_gender(), 1);

	EXPECT_TRUE(person.set_gender(2));
	EXPECT_EQ(person.get_gender(), 2);
}

// test get_tagline and set_tagline
TEST_F(test_person, test_tagline) {
	EXPECT_FALSE(person.set_tagline(""));
	EXPECT_EQ(person.get_tagline(), "");

	EXPECT_FALSE(person.set_tagline(std::string (513, 'x')));
	EXPECT_EQ(person.get_tagline(), "");

	EXPECT_TRUE(person.set_tagline("xyz"));
	EXPECT_EQ(person.get_tagline(), "xyz");

	EXPECT_TRUE(person.set_tagline(std::string (512, 'x')));
	EXPECT_EQ(person.get_tagline(), std::string (512, 'x'));
}

// test get_info and set_info
TEST_F(test_person, test_info) {
	// set_info(string _username, string _firstname, string _lastname,
	//                       int _age, string _tagline, int _gender)
	EXPECT_FALSE(person.set_info("alpha", "Ash1", "Ketchum1", 17, "", -1));
	EXPECT_EQ(person.get_info(), "username: , first name: , last name: , gender: 0, age: 0, tagline: ");

	EXPECT_FALSE(person.set_info("alpha1", "Ash1", "Ketchum1", 17, "", -1));
	EXPECT_EQ(person.get_info(), "username: , first name: , last name: , gender: 0, age: 0, tagline: ");

	EXPECT_FALSE(person.set_info("alpha1", "Ash", "Ketchum1", 0, "", -1));
	EXPECT_EQ(person.get_info(), "username: , first name: , last name: , gender: 0, age: 0, tagline: ");

	EXPECT_FALSE(person.set_info("alpha1", "Officer", "Jenny", 17, "", -1));
	EXPECT_EQ(person.get_info(), "username: , first name: , last name: , gender: 0, age: 0, tagline: ");

	EXPECT_FALSE(person.set_info("alpha1", "Officer", "Jenny", 18, "", -1));
	EXPECT_EQ(person.get_info(), "username: , first name: , last name: , gender: 0, age: 0, tagline: ");

	EXPECT_FALSE(person.set_info("alpha1", "Officer", "Jenny", 18, "Chansey", -1));
	EXPECT_EQ(person.get_info(), "username: , first name: , last name: , gender: 0, age: 0, tagline: ");

	EXPECT_TRUE(person.set_info("alpha1", "Ash", "Ketchum", 18, "Pikachu", 2));
	EXPECT_EQ(person.get_info(), "username: alpha1, first name: Ash, last name: Ketchum, gender: Male, age: 18, tagline: Pikachu");
}

// test get_msgstat, send_msg, get_msg_with_info and read_msg
//   to make your code shorter, we suggest combining these tests together; you
//   can also separate them into several test cases
TEST_F(test_person, test_msg) {
	EXPECT_EQ(person.get_msgstat(Person()), 0);

	EXPECT_EQ(recipient -> get_msgstat(*loaded), 0);
	EXPECT_EQ(recipient -> in_block_list("beta2"), false);

	EXPECT_EQ(loaded -> send_msg(*recipient, "Hi."), true);
	EXPECT_EQ(recipient -> get_msgstat(*loaded), 1);

	EXPECT_EQ(loaded -> send_msg(*recipient, "These"), true);
	EXPECT_EQ(recipient -> get_msgstat(*loaded), 2);

	EXPECT_EQ(loaded -> send_msg(*recipient, "are"), true);
	EXPECT_EQ(recipient -> get_msgstat(*loaded), 3);

	EXPECT_EQ(loaded -> send_msg(*recipient, "messages"), true);
	EXPECT_EQ(recipient -> get_msgstat(*loaded), 4);

	EXPECT_EQ(loaded -> send_msg(*recipient, "from beta2."), true);
	EXPECT_EQ(recipient -> get_msgstat(*loaded), 5);

	EXPECT_EQ(recipient -> in_block_list("beta2"), false);
	EXPECT_EQ(loaded -> send_msg(*recipient, "6th message"), false);
	EXPECT_EQ(recipient -> get_msgstat(*loaded), 5);

	EXPECT_EQ(recipient -> read_msg(), true);
	EXPECT_EQ(recipient -> get_msgstat(*loaded), 4);

	EXPECT_EQ(recipient -> read_msg(), true);
	EXPECT_EQ(recipient -> get_msgstat(*loaded), 3);

	EXPECT_EQ(recipient -> read_msg(), true);
	EXPECT_EQ(recipient -> get_msgstat(*loaded), 2);

	EXPECT_EQ(recipient -> read_msg(), true);
	EXPECT_EQ(recipient -> get_msgstat(*loaded), 1);

	EXPECT_EQ(recipient -> read_msg(), true);
	EXPECT_EQ(recipient -> get_msgstat(*loaded), 0);

	EXPECT_EQ(recipient -> read_msg(), false);
	EXPECT_EQ(recipient -> get_msgstat(*loaded), 0);

	EXPECT_EQ(recipient -> in_block_list("beta2"), false);
	EXPECT_EQ(loaded -> send_msg(*recipient, "Block me."), true);
	EXPECT_EQ(recipient -> get_msgstat(*loaded), 1);
	EXPECT_EQ(recipient -> read_msg(), true);
	EXPECT_EQ(recipient -> get_msgstat(*loaded), 0);


	recipient -> add_to_block_list("beta2");
	EXPECT_EQ(recipient -> in_block_list("beta2"), true);
	EXPECT_EQ(loaded -> send_msg(*recipient, "This message is blocked"), false);
	EXPECT_EQ(recipient -> read_msg(), false);
	EXPECT_EQ(recipient -> get_msgstat(*loaded), 0);
}
