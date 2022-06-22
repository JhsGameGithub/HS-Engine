#pragma once

#include <vector>

//obj의 면을 담는 구조체
struct FaceSturct
{
	std::vector<unsigned int> positionIndexs;
	std::vector<unsigned int> uvIndexs;
	std::vector<unsigned int> normalIndexs;

	unsigned int vertex_num;
}typedef Face;