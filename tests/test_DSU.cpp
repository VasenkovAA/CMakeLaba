#include "gtest.h"
#include <climits>
#include "../dispoint_sets_union/dispoint_sets_union.h"

TEST(CDispointSetsUnion, can_create_CDispointSetsUnion) {
	// Arrange & Act
	//CDispointSetsUnion DSU(50);

	// Assert
	EXPECT_NO_THROW(CDispointSetsUnion(500));
}

TEST(CDispointSetsUnion, can) {
	// Arrange & Act
	CDispointSetsUnion DSU(8);

	// Assert
	EXPECT_EQ(5,DSU.find(5));
}

TEST(CDispointSetsUnion, can_Union) {
	// Arrange & Act
	CDispointSetsUnion DSU(8);
	DSU.setUnion(5, 3);
	// Assert
	EXPECT_EQ(5, DSU.find(3));
}



TEST(CDispointSetsUnion, can_overload_CDispointSetsUnion_MaxSize) {
	// Arrange & Act
	//CDispointSetsUnion DSU(5001);

	// Assert
	ASSERT_ANY_THROW(CDispointSetsUnion(5001));
}