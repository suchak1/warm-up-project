#include "gtest/gtest.h"
#include "person.h"
#include "community.h"

// this class is used for testing public methods in class Community
class test_community: public ::testing::Test {
protected:
	Community community;
	Community* loaded = new Community("Summerbrooke", map<string,Person>
		{{"alpha1", Person("alpha1", "Ash", "Ketchum", 2, 18, "Pikachu")}});
	Person* loaded_person = new Person("beta2", "Officer", "Jenny", 1, 20, "Chansey");

};

// test constructors
TEST_F(test_community, test_constructors) {
	EXPECT_EQ(community.get_name(), "");
	EXPECT_EQ(community.get_all_usernames().empty(), true);

	EXPECT_EQ(loaded -> get_name(), "Summerbrooke");
	EXPECT_EQ(loaded -> get_all_usernames().empty(), false);
	EXPECT_EQ(loaded -> get_all_usernames().front(), "alpha1");
	EXPECT_EQ(loaded -> get_member(loaded -> get_all_usernames().front()).get_username(), "alpha1");
}

// you should complete the following test cases
// you should add more if you see fit

// test get_name
TEST_F(test_community, get_name) {
	EXPECT_EQ(community.get_name(), "");
	EXPECT_EQ(loaded -> get_name(), "Summerbrooke");
}

// test set_name
TEST_F(test_community, set_name) {
	EXPECT_EQ(community.set_name(""), false);
	EXPECT_EQ(community.set_name(std::string (129, 'x')), false);
	EXPECT_EQ(community.set_name("1alpha"), false);
	EXPECT_EQ(community.set_name("alpha_"), false);
	EXPECT_EQ(community.set_name("alpha"), true);
	EXPECT_EQ(community.set_name("alpha1"), true);
}

// test add_person
TEST_F(test_community, add_person) {
	EXPECT_EQ(community.get_all_usernames().empty(), true);
	EXPECT_EQ(community.add_person(Person()), false);

	EXPECT_EQ(community.get_all_usernames().empty(), true);
	EXPECT_EQ(community.add_person(*loaded_person), true);


	EXPECT_EQ(community.get_all_usernames().empty(), false);
	EXPECT_EQ(community.get_all_usernames().size(), 1);
	EXPECT_EQ(community.add_person(*loaded_person), false);
	EXPECT_EQ(community.get_all_usernames().size(), 1);


	EXPECT_EQ(loaded -> get_all_usernames().empty(), false);
	EXPECT_EQ(loaded -> get_all_usernames().size(), 1);
	EXPECT_EQ(loaded -> add_person(*loaded_person), true);
	EXPECT_EQ(loaded -> get_all_usernames().size(), 2);
}

// test get_all_usernames
//   there's no EXPERT functions for comparing non-built-in types, you need to
//   do some parsing by yourself
TEST_F(test_community, get_all_usernames) {
	EXPECT_EQ(community.get_all_usernames().empty(), true);


	EXPECT_EQ(loaded -> get_all_usernames().empty(), false);
	EXPECT_EQ(loaded -> get_all_usernames().size(), 1);
	EXPECT_EQ(loaded -> get_all_usernames().front(), "alpha1");

	EXPECT_EQ(loaded -> add_person(*loaded_person), true);
	EXPECT_EQ(loaded -> get_all_usernames().size(), 2);
	EXPECT_EQ(loaded -> get_all_usernames().front(), "alpha1");
	EXPECT_EQ(loaded -> get_all_usernames().back(), "beta2");
}

// test find_member by first name and age range
TEST_F(test_community, find_member) {
	EXPECT_EQ(community.find_member("").empty(), true);
	EXPECT_EQ(community.find_member(0, 0).empty(), true);


	EXPECT_EQ(loaded -> find_member("Officer").empty(), true);
	EXPECT_EQ(loaded -> find_member(18, 18).empty(), false);
	EXPECT_EQ(loaded -> find_member("Ash").empty(), false);
	EXPECT_EQ(loaded -> find_member("Ash").size(), 1);
	EXPECT_EQ(loaded -> find_member(18, 18).size(), 1);
	EXPECT_EQ(loaded -> get_all_usernames().size(), 1);
	EXPECT_EQ(loaded -> find_member("Ash").front().get_firstname(), "Ash");
	EXPECT_EQ(loaded -> find_member(18, 18).front().get_firstname(), "Ash");


	EXPECT_EQ(loaded -> add_person(*loaded_person), true);
	EXPECT_EQ(loaded -> find_member("Officer").size(), 1);
	EXPECT_EQ(loaded -> get_all_usernames().size(), 2);
	EXPECT_EQ(loaded -> find_member("Officer").front().get_firstname(), "Officer");
	EXPECT_EQ(loaded -> find_member(18, 19).size(), 1);
	EXPECT_EQ(loaded -> find_member(18, 20).size(), 2);
	EXPECT_EQ(loaded -> find_member(0, 17).size(), 0);
	EXPECT_EQ(loaded -> find_member(21, 99).size(), 0);
}

// test get_member
TEST_F(test_community, get_member) {
	EXPECT_EQ(community.get_member("").get_username(), "");

	EXPECT_EQ(loaded -> get_member("beta2").get_username(), "");
	EXPECT_EQ(loaded -> get_member("alpha1").get_username(), "alpha1");

	EXPECT_EQ(loaded -> add_person(*loaded_person), true);
	EXPECT_EQ(loaded -> get_member("beta2").get_username(), "beta2");
	EXPECT_EQ(loaded -> get_member("alpha1").get_username(), "alpha1");
}

// test send_msg
TEST_F(test_community, send_msg) {
}
