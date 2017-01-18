#include "MazeWalker.h"
#include "literals.h"
#include <windows.h>
#include <iostream>

using namespace std;

/******************************
	���캯��
	��ʼ����ɫ���ߵĲ���
******************************/
MazeWalker::MazeWalker()
{
    m_iSteps = 0;
}

/********************************************
	���ݴ���ķ���ʹ��Ϸ��ɫ�ƶ�һ��
	��ɫ�ƶ��Ĺ���:
	��������Ϸ��ɫ�ڵ�ǰλ����ʧ
	Ȼ������Ϸ��ɫ����һ��λ�ó���
********************************************/
void MazeWalker::moveForward(char direction)
{
    unsigned long numWritten;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);							// ��ȡ�����д��ڵĴ��ھ��
    FillConsoleOutputCharacter(handle, ' ', 1, m_currentPos, &numWritten);		// ����Ϸ��ɫ��ǰλ�����ո�ʹ��Ϸ��ɫ��ʧ
    switch (direction)															// ���ݴ���ķ�����������һ��λ�õ�����
    {
	case _UPWARD:
		m_currentPos.Y--;
		break;
	case _DOWN:
		m_currentPos.Y++;
		break;
	case _LEFT:
		m_currentPos.X--;
		break;
	case _RIGHT:
		m_currentPos.X++;
		break;
	default:
		break;
    }
    FillConsoleOutputCharacter(handle, m_cWalker, 1, m_currentPos, &numWritten);	// ����Ϸ��ɫ������λ�������������Ϸ��ɫ���ַ�
    m_cDirection = direction;			// �ƶ���ɺ������Ϸ��ɫ�ĳ���
}

/**********************************************
	������һ��
	�����ж���Ϸ��ɫ�Ϸ���λ����ǽ����·
	����·�������moveForward�����ƶ�
	����ǽ����ֱ�ӷ���false����ʾ�ƶ�ʧ��
**********************************************/
bool MazeWalker::walkUp()
{
    if (m_pMazeMap->getMapArray()[m_currentPos.Y - 1][m_currentPos.X])
	{
        return false;
    }
    else
	{
        moveForward(_UPWARD);	// �ɹ��ƶ��Ż���·ŷ���
        return true;
    }
}

/*******************
	������һ��
*******************/
bool MazeWalker::walkDown()
{
    if (m_pMazeMap->getMapArray()[m_currentPos.Y + 1][m_currentPos.X])
	{
        return false;
    }
    else
	{
        moveForward(_DOWN);
        return true;
    }
}

/*******************
	������һ��
*******************/
bool MazeWalker::walkLeft()
{
    if (m_pMazeMap->getMapArray()[m_currentPos.Y][m_currentPos.X - 1])
	{
        return false;
    }
    else
	{
        moveForward(_LEFT);
        return true;
    }
}

/*******************
	������һ��
*******************/
bool MazeWalker::walkRight()
{
    if (m_pMazeMap->getMapArray()[m_currentPos.Y][m_currentPos.X + 1])
	{
        return false;
    }
    else
	{
        moveForward(_RIGHT);
        return true;
    }
}

/*************************
	������Ϸ��ɫ��λ��
*************************/
void MazeWalker::setWalkerPosition(COORD pos)
{
    unsigned long numWritten;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    m_currentPos.X = pos.X;
    m_currentPos.Y = pos.Y;
    FillConsoleOutputCharacter(handle, m_cWalker, 1, m_currentPos, &numWritten);
	Sleep(2000);
	cout << "\nwalking!" << endl;
}

void MazeWalker::setWalkerSpeed(int speed)
{
	m_iSpeed = speed;
}
/*****************************
	���ô�����Ϸ��ɫ���ַ�
*****************************/
void MazeWalker::setWalkerChar(char hero)
{
    m_cWalker = hero;
}

/*****************************
	������Ϸ��ɫ�ĳ�ʼ����
*****************************/
void MazeWalker::setWalkerDirection(char direction)
{
    m_cDirection = direction;
}

/*******************
	���õ�ͼ����
*******************/
void MazeWalker::setMazeMap(MazeMap *map)
{
    m_pMazeMap = map;
}

/****************
	��ȡ����
****************/
int MazeWalker::getSteps()
{
	cout << "totally " << m_iSteps << " steps" << endl;
    return m_iSteps;
}

//��Ϸ��ʼ����
void MazeWalker::start()
{
    while (true)
    {
        switch (m_cDirection)		// ����ԭ��, ��ʼ����, ;�г���
        {
		case _UPWARD:
			walkRight() || walkUp() || walkLeft() || walkDown();	//�ƶ��ɹ�����·���
			break;
        case _DOWN:
            walkLeft() || walkDown() || walkRight() || walkUp();
            break;
		case _LEFT:
            walkUp() || walkLeft() || walkDown() || walkRight();
            break;
        case _RIGHT:
            walkDown() || walkRight() || walkUp() || walkLeft();
            break;
        default:
			cout << "direction error!" << endl;
            break;
        }
        m_iSteps++;

        //�ж���Ϸ��ɫ�ĵ�ǰλ���Ƿ����Թ�����λ�ã����������ڣ���Ϸ����
        if (   m_currentPos.X == m_pMazeMap->getExitPosition().X
			&& m_currentPos.Y == m_pMazeMap->getExitPosition().Y )
        {
			cout << "arrived!" << endl;
            break;
        }
        //ÿ��ʱ����ms
        Sleep(m_iSpeed);
    }
}
