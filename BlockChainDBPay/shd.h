#pragma once

#include "thr_safe.h"
#include "tsmap.h"
#include "libh.h"
#include "Block.h"

// ���������� ����� ��� ��������
const int numStrokiKvant = 128 * 8;

// �������� ����� � ����������� WorkThread
const std::chrono::milliseconds sleepTimer = 500ms;

// �������� ������� �������� � �������� ���������
const std::chrono::milliseconds sleepTimerMain = 750ms;

// ����� �������� ����������� ������ � ������ 
class InfoTransaction
{
public:
    Block* hackBlock;
    int pos; // ������� � ������
    int num; // ����� ������
    string line; // ������ 
};

// ��� ���������������� ����� ��� �������� ���� ��������� �����
//typedef contfree_safe_ptr<std::map<int, InfoTransaction>> map_InfoSearchStroki;
typedef tsmap<int, InfoTransaction> map_InfoSearchStroki;


// ���� �����  ��� ��������� ���������
class SearchTextData
{
public:
    std::string stroki[numStrokiKvant];
    //int pos[numStrokiKvant];
    int numStroki; // ����� ����� � ����� 
    int nn; // ����� �����:: ���������� ����� � ����� nn*numStrokiKvant+i
};

//typedef contfree_safe_ptr< std::map<int, SearchTextData>> _SearchTextData;

// ��� ���������������� ������� ��������� ���� ������ �����
//typedef contfree_safe_ptr<std::list<SearchTextData>> _SearchTextData;
typedef ThreadSafeQ<SearchTextData> _SearchTextData;

