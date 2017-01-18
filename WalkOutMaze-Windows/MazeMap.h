#ifndef MazeMap_H
#define MazeMap_H

#include <windows.h>

class MazeMap
{
public:
    MazeMap(char wall, char road);						// ���캯��
    ~MazeMap();

    void	setWallChar(char wall);						// ���ô���ǽ���ַ�
	char	getWallChar();								// ��ȡ����ǽ���ַ�
    void	setRoadChar(char road);						// ���ô���·���ַ�
	char	getRoadChar();								// ��ȡ����·���ַ�
	void	setMapArray(int *map, int row, int col);	// ����ָ���ά�����ָ��
    int		**getMapArray();							// ��ȡָ���ά�����ָ��
    void	setExitPosition(COORD coo);					// ���ó���λ��
    COORD	getExitPosition();							// ��ȡ����λ��
	void	drawMap();									// �����Թ���ͼ
private:
    char	m_cWall;			// ǽ���ַ�
    char	m_cRoad;			// ͨ·�ַ�
    int		**m_pMapArr;		// ָ���ά�����ָ��
    int		m_iMapRow;			// ��ά���������
    int		m_iMapCol;			// ��ά���������
	COORD	m_ExitPosition;		// �Թ����ڵ�����
};

#endif
