#include "MazeMap.h"
#include "MazeWalker.h"
#include "literals.h"
#include <windows.h>
#include <iostream>

using namespace std;

int main(void)
{
	// ���岢��ʼ���洢��ͼ���ݵĶ�ά����
	int map[_ROW][_COL] = {
		{WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
		{WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD},
		{WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, ROAD, WALL},
		{WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, WALL},
		{WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, ROAD, WALL},
		{WALL, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, WALL},
		{WALL, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ROAD, ROAD, WALL},
		{WALL, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, WALL, ROAD, WALL},
		{WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, ROAD, ROAD, WALL},
		{ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL},
		{WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}
	};

	COORD entry, exit;
	entry.X = _COL - 1;
	entry.Y = 1;
	exit.X  = 0;
	exit.Y  = _ROW - 2;

	MazeMap *myMaze = new MazeMap('E', ' ');	// ������ͼ����
	myMaze->setMapArray(&map[0][0], _ROW, _COL);// ��ʼ����ͼ
	myMaze->setExitPosition(exit);				// ���õ�ͼ����
	myMaze->drawMap();							// ���Ƶ�ͼ

	MazeWalker *myHero = new MazeWalker();		// ������ɫ����
	myHero->setWalkerChar('i');					// ���ô�����Ϸ��ɫ���ַ�
	myHero->setWalkerPosition(entry);			// ����Ϸ��ɫ�����Թ����
	myHero->setWalkerDirection(_DOWN);			// ������Ϸ��ɫ�ĳ���
	myHero->setWalkerSpeed(FAST);				// ���ý�ɫ�ٶ�
	myHero->setMazeMap(myMaze);					// ������Ϸ��ɫҪ�ߵĵ�ͼ
	myHero->start();							// ��ʼ��Ϸ
	myHero->getSteps();							// ��ȡ����

	delete myMaze;		// ���ٶ���
	myMaze = NULL;

	delete myHero;
	myHero = NULL;

	system("pause");
}
