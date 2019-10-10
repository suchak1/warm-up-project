#include "gtest/gtest.h"
#include "person.h"
#include "community.h"

// this class is used for testing public methods in class Community
class test_community: public ::testing::Test {
protected:
	Community community;
	Community* loaded = new Community("Summerbrooke", map<string,Person>
		{{"alpha1", Person("alpha1", "Ash", "Ketchum", 2, 18, "Pikachu")}});
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
}

// test get_all_usernames
//   there's no EXPERT functions for comparing non-built-in types, you need to
//   do some parsing by yourself
TEST_F(test_community, get_all_usernames) {
}

// test find_member by first name and age range
TEST_F(test_community, find_member) {
}

// test get_member
TEST_F(test_community, get_member) {
}

// test send_msg
TEST_F(test_community, send_msg) {
}
