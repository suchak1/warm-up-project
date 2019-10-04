# A sample Makefile for building Google Test and using it in user
# tests.  Please tweak it to suit your environment and project.  You
# may want to move it to your project's root directory.
#
# SYNOPSIS:
#
#   make [all]  - makes everything.
#   make TARGET - makes the given target.
#   make clean  - removes all files generated by make.

# Please tweak the following variable definitions as needed by your
# project, except GTEST_HEADERS, which you can use in your own targets
# but shouldn't modify.

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = ./googletest-release-1.7.0

# Where to find user code.
SRC_DIR = ./src
TEST_DIR = ./test
INC_DIR = ./inc

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = run

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
								$(GTEST_DIR)/include/gtest/internal/*.h

# House-keeping build targets.

all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o

# Builds gtest.a and gtest_main.a.

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
		$(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
		$(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

community.o : $(SRC_DIR)/community.cpp  $(GTEST_HEADERS)
	$(CXX) -I $(INC_DIR) $(CPPFLAGS) $(CXXFLAGS) -c $(SRC_DIR)/community.cpp

person.o : $(SRC_DIR)/person.cpp  $(GTEST_HEADERS)
	$(CXX) -I $(INC_DIR) $(CPPFLAGS) $(CXXFLAGS) -c $(SRC_DIR)/person.cpp

test_person.o : $(TEST_DIR)/test_person.cpp  $(GTEST_HEADERS)
	$(CXX) -I $(INC_DIR) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_DIR)/test_person.cpp

test_community.o : $(TEST_DIR)/test_community.cpp  $(GTEST_HEADERS)
	$(CXX) -I $(INC_DIR) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_DIR)/test_community.cpp

run.o : $(TEST_DIR)/run.cpp  $(GTEST_HEADERS)
	$(CXX) -std=c++0x -I $(INC_DIR) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_DIR)/run.cpp

run : community.o person.o test_community.o test_person.o run.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
