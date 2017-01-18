#ifndef MazeWalker_H
#define MazeWalker_H

#include <windows.h>
#include "MazeMap.h"

class MazeWalker
{
public:
    MazeWalker();							// ���캯��
	void	moveForward(char direction);	// ���ݴ���ķ���ʹ��Ϸ��ɫ�ƶ�һ��
    bool	walkUp();						// �����߶�һ�������ɹ����򷵻�true����ʧ�ܣ�������ǽ�����򷵻�false
    bool	walkDown();						// �����߶�һ�������ɹ����򷵻�true����ʧ�ܣ�������ǽ�����򷵻�false
    bool	walkLeft();						// �����߶�һ�������ɹ����򷵻�true����ʧ�ܣ�������ǽ�����򷵻�false
    bool	walkRight();					// �����߶�һ�������ɹ����򷵻�true����ʧ�ܣ�������ǽ�����򷵻�false
    
    void	setWalkerPosition(COORD pos);		// ������Ϸ��ɫ��λ��
    void	setWalkerSpeed(int speed);			// ������Ϸ��ɫ���ٶ�
    void	setWalkerChar(char walker);			// ���ô�����Ϸ��ɫ���ַ�
    void	setWalkerDirection(char direction);	// ������Ϸ��ɫ�ĳ���
    void	setMazeMap(MazeMap *map);			// ���õ�ͼ����
    int		getSteps();							// ��ȡ����
	void	start();							// ��Ϸ��ʼ����
private:
    char	m_cWalker;					// ������Ϸ��ɫ���ַ�
    char	m_cDirection;				// ��Ϸ��ɫ�ĳ���
    COORD	m_lastPos;					// ��Ϸ��ɫ���ϸ�λ��
    COORD	m_currentPos;				// ��Ϸ��ɫ�ĵ�ǰλ��
    MazeMap	*m_pMazeMap;				// ��ͼ����
    int		m_iSteps;					// ��¼��Ϸ��ɫ���˶��ٲ�
    int		m_iSpeed;					// �ٶ�
};

#endif