#ifndef _ILANDS_H_
#define _ILANDS_H_
#include "../dispoint_sets_union/dispoint_sets_union.h"
#include <iostream>
#include <cmath>
#include <vector>
//struct Point {
//	double x, y;
//};
//
//bool areAdjacent(Point p1, Point p2, double sideLength) {
//	double distance = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
//	return distance == sideLength;
//}
//int Search(int** matrix, int N, int M, Point point, CDispointSetsUnion* DSU) {
//	bool flag = true;
//	while () {
//	
//	
//	}
//
//}


int IlandsCount(int matrix[][], int N, int M) {
	CDispointSetsUnion DSU(N * M+1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (matrix[i][j] == 0) {
				DSU.setUnion(0, (i * N + j));
			}
			else {
				if (i - 1 >= 0 && matrix[i - 1][j] == 1) {
					DSU.setUnion(M * (i - 1) + j + 1, M * i + j + 1);
				
				}
				if (j - 1 >= 0 && matrix[i][j - 1] == 1) {
					DSU.setUnion(M * (i) + j, M * i + j);
				}
			}
		}
	}
	return DSU.getCountGroops();

}


#endif