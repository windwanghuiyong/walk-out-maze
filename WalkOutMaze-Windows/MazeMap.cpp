#include "MazeMap.h"
#include <iostream>

using namespace std;

/****************
    ���캯��
****************/
MazeMap::MazeMap(char wall, char road) : m_cWall(wall), m_cRoad(road)
{
    m_pMapArr = NULL;
}

/****************
    ��������
****************/
MazeMap::~MazeMap()
{
	// �ͷŶ�̬����Ķ�ά����
    if (m_pMapArr)
	{
        for (int i = 0; i < m_iMapRow; i++)
        {
            delete m_pMapArr[i];	// ���ͷ���������
            m_pMapArr[i] = NULL;
        }
        delete m_pMapArr;			// ���ͷ�ָ������
    }
}

/***********************
	���ô���ǽ���ַ�
***********************/
void MazeMap::setWallChar(char wall)
{
    m_cWall = wall;
}

/***********************
	��ȡ����ǽ���ַ�
***********************/
char MazeMap::getWallChar()
{
    return m_cWall;
}

/***********************
    ���ô���·���ַ�
***********************/
void MazeMap::setRoadChar(char road)
{
    m_cRoad = road;
}

/***********************
    ��ȡ����·���ַ�
***********************/
char MazeMap::getRoadChar()
{
    return m_cRoad;
}

/*******************************
    ��̬���䲢��ʼ����ά����
*******************************/
void MazeMap::setMapArray(int *map, int row, int col)
{
    m_iMapRow = row;
    m_iMapCol = col;

	// ��̬�����ά����
    m_pMapArr = new int *[m_iMapRow];		// ��̬����ָ������, ����ָ�������ÿһ��

    for (int i = 0; i < m_iMapRow; i++)
    {
        m_pMapArr[i] = new int[m_iMapCol];	// ��̬������������, ���ڱ�ʾ�����ÿһ��
    }

    // ��ʼ����ά����
    int *p = map;
    for (int i = 0; i < m_iMapRow; i++)
    {
        for (int j = 0; j < m_iMapCol; j++)
        {
            m_pMapArr[i][j] = *p;
            p++;					// ��������Ķ�ά����
        }
    }
}

/***************************
	��ȡָ���ά����ָ��
***************************/
int **MazeMap::getMapArray()
{
    return m_pMapArr;
}

/*******************
	���ó���λ��
*******************/
void MazeMap::setExitPosition(COORD coo)
{
    m_ExitPosition = coo;
}

/*******************
	��ȡ����λ��
*******************/
COORD MazeMap::getExitPosition()
{
    return m_ExitPosition;
}

/*****************
    ���Ƶ�ͼ
*****************/
void MazeMap::drawMap()
{
    for (int i = 0; i < m_iMapRow; i++)
    {
        for (int j = 0; j < m_iMapCol; j++)
        {
            if (m_pMapArr[i][j])	// ����Ԫ����Ϊ1�����ӡ����ǽ���ַ�
            {
                cout << m_cWall;
            }
			else					// ����Ԫ����Ϊ0�����ӡ����·���ַ�
            {
                cout << m_cRoad;
            }
        }
        cout << endl;
    }
}