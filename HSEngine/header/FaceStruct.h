#pragma once

#include <vector>

//obj�� ���� ��� ����ü
struct FaceSturct
{
	std::vector<unsigned int> positionIndexs;
	std::vector<unsigned int> uvIndexs;
	std::vector<unsigned int> normalIndexs;

	unsigned int vertex_num;
}typedef Face;