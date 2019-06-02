
#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "badkan.hpp"
#include "Member.h"
using ariel::Member;

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE

    ariel::Member avi, beni, chana;
    ariel::Member dana;
	chana.follow(dana);
	dana.follow(avi);

    testcase
    .setname("size of followers")
    .CHECK_OUTPUT(beni.numFollowers(), "0")
    .CHECK_OUTPUT(avi.numFollowers(), "1")


    .setname("size of following")
    .CHECK_OUTPUT(chana.numFollowing(), "1")
    .CHECK_OUTPUT(dana.numFollowing(), "1")
    .CHECK_OUTPUT(avi.numFollowing(), "0")

    .setname("counter")
    .CHECK_OUTPUT(avi.count() , "4")

    .setname("remove")
    .CHECK_OK(chana.unfollow(dana))
    .CHECK_OUTPUT(chana.numFollowing(), "0")
    .CHECK_OUTPUT(dana.numFollowers(), "0")

    .setname("add")
    .CHECK_OK(avi.follow(beni))
    .CHECK_OUTPUT(beni.numFollowers(), "1")
    .CHECK_OUTPUT(avi.numFollowing(), "1")


    // YOUR TESTS - INSERT AS MANY AS YOU WANT

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}