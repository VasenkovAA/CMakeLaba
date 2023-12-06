#include "gtest.h"
#include <climits>
//#include "../ilands_count/ilands_count.h"
#include "../dispoint_sets_union/dispoint_sets_union.h"
int ilendCount(int mass[], size_t N, size_t M) {
	CDispointSetsUnion dsu(M * N+1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mass[M * i + j] == 0) {
				dsu.setUnion(0, M * i + j + 1);
			}
			else{
				if (i - 1 >= 0 && mass[M * (i - 1) + j] == 1) {
					dsu.setUnion(M * (i - 1) + j + 1, M * i + j + 1); ;
				
				}
			
				if (j-1>=0 && mass[M*i+j-1] == 1) {
					dsu.setUnion(M * i + j, M * i + j - 1 + 1);  ;
				}
			}
		}


	}
	return dsu.getCountGroops();
}
//
//
//
//
TEST(temptest, test5555) {
	int mass[25]  { 
		1, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		1, 1, 0, 0, 0,
		0, 0, 0, 1, 0,
		0, 0, 0, 0, 0
	};
	EXPECT_EQ(ilendCount(mass, 5, 5), 3);
}
