
#include <gtest.h>
#include <climits>
#include "..\bit_fild_and_set\set.h"

TEST(TSet, can_combine_two_sets_of_equal_size)
{
  const int size = 5;
  TSet set1(size), set2(size), set3(size), expSet(size);
  // set1 = {1, 2, 4}
  set1.InsElem(1);
  set1.InsElem(2);
  set1.InsElem(4);
  // set2 = {0, 1, 2}
  set2.InsElem(0);
  set2.InsElem(1);
  set2.InsElem(2);
  set3 = set1 + set2;
  // expSet = {0, 1, 2, 4}
  expSet.InsElem(0);
  expSet.InsElem(1);
  expSet.InsElem(2);
  expSet.InsElem(4);

  EXPECT_EQ(expSet, set3);
}
TEST(TSet, can_combine_two_sets_of_not_equal_size)
{
	TSet set1(10), set2(30), set3(0), expSet(30);
	// set1 = {1, 2, 4, 9}
	set1.InsElem(1);
	set1.InsElem(2);
	set1.InsElem(4);
	set1.InsElem(9);
	// set2 = {0, 1, 2, 16, 24, 29}
	set2.InsElem(0);
	set2.InsElem(1);
	set2.InsElem(2);
	set2.InsElem(24);
	set2.InsElem(16);
	set2.InsElem(29);
	set3 = set1 + set2;
	// expSet = {0, 1, 2, 4, 9, 16, 24, 29}
	expSet.InsElem(0);
	expSet.InsElem(1);
	expSet.InsElem(2);
	expSet.InsElem(4);
	expSet.InsElem(9);
	expSet.InsElem(16);
	expSet.InsElem(24);
	expSet.InsElem(29);

	EXPECT_EQ(expSet, set3);
}
TEST(TSet, can_intersection_two_sets_of_equal_size)
{
	const int size = 5;
	TSet set1(size), set2(size), set3(size), expSet(size);
	// set1 = {1, 2, 4}
	set1.InsElem(1);
	set1.InsElem(2);
	set1.InsElem(4);
	// set2 = {0, 1, 2}
	set2.InsElem(0);
	set2.InsElem(1);
	set2.InsElem(2);
	set3 = set1 * set2;
	// expSet = { 1, 2 }
	expSet.InsElem(1);
	expSet.InsElem(2);

	EXPECT_EQ(expSet, set3);
}
TEST(TSet, can_intersection_two_sets_of_not_equal_size)
{
	TSet set1(10), set2(30), set3(0), expSet(10);
	// set1 = {1, 2, 4, 9}
	set1.InsElem(1);
	set1.InsElem(2);
	set1.InsElem(4);
	set1.InsElem(9);
	// set2 = {0, 1, 2, 16, 24, 29}
	set2.InsElem(0);
	set2.InsElem(1);
	set2.InsElem(2);
	set2.InsElem(24);
	set2.InsElem(16);
	set2.InsElem(29);
	set3 = set1 * set2;
	// expSet = {0, 1, 2, 4, 9, 16, 24, 29}
	expSet.InsElem(1);
	expSet.InsElem(2);
	EXPECT_EQ(expSet, set3);
}
TEST(TSet, check_negation_operator)
{
  const int size = 4;
  TSet set(size), set1(size), expSet(size);
  // set1 = {1, 3}
  set.InsElem(1);
  set.InsElem(3);
  set1 = ~set;
  // expSet = {0, 2}
  expSet.InsElem(0);
  expSet.InsElem(2);
  EXPECT_EQ(expSet, set1);
}
//TEST(TSet, check_cin)
//{
//	const int size = 10;
//	TSet set(size);
//	
//	EXPECT_NO_THROW(std::cin>>set);
//	EXPECT_NO_THROW(std::cout << set);
//}