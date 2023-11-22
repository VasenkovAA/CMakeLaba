#ifndef _DISPOINT_SETS_UNION_H_
#define _DISPOINT_SETS_UNION_H_
#include <iostream>
#include "../dispoint_sets_union/dispoint_sets_union.h"
#define MAXSIZEMAZE 50
class CMaze {
private:
	size_t sizeX;
	size_t sizeY;
	CDispointSetsUnion* data;
	size_t complexity;
public:
	CMaze(size_t x, rsize_t y) {
		if (x > MAXSIZEMAZE || y > MAXSIZEMAZE) {
			throw std::logic_error("MAXSIZEMAZE has been owerload");
		}
		sizeX = x;
		sizeY = y;
		CDispointSetsUnion = new CDispointSetsUnion(x*y);

	}
	~CMaze() {
		delete CDispointSetsUnion;
	}
	void CreateMaze(size_t StartX, size_t StartY, size_t FinihX, size_t FinihY, size_t complexity) {
		complexity
	
	}

};


#endif _DISPOINT_SETS_UNION_H_