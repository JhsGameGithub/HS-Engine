#pragma once
#include <iostream>
#include <windows.h>

//�߻�ȭ
//���ʿ��� ������ ����� �߿��� ������ ǥ���ؼ� ���� �Ӽ��̳� ����� ���� �̸��� ���̴� ��

//ĸ��ȭ
//Ư���� ������ Ŭ������� ĸ���� �з��ؼ� �ڵ带 ����� ���� ��Ȱ�� �Ϸ��� ��

//��Ӽ�
//�θ�Ŭ������ �Ӽ��� ����� �״�� �̾�޾� ����� �� �ְ� �ϰ� ����� �Ϻκ��� ���浵 ���� �� ��

//������
//�ϳ��� ������, �Լ��� ���� ��Ȳ�� ���� �ٸ� �ǹ̷� �ؼ� �� �� �ִ� �� 
 
//�ð������ ���� �������� ����ü
struct TimeStruct {
	LARGE_INTEGER currentTime;
	LARGE_INTEGER previousTime;
	LARGE_INTEGER myFrequency;
	double elapsedTime;
} typedef TimeStruct;
