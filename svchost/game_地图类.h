#pragma once
struct ���
{
	DWORD �� = 0;
	DWORD �� = 0;
};
class game_��ͼ��
{
public:
	DWORD �׵�ַ, β��ַ, ���� = NULL;
	game_��ͼ��(DWORD dwObjectPointer = NULL);
	~game_��ͼ��();
	const char * GetName();
	std::vector<int> ��ͼͨ��();
	��� ��ȡ���();
	bool �Ƿ��ѿ���();
	bool �Ƿ�BOSS����();
	bool �Ƿ���ͨ��();
	void ����();
	std::vector<DWORD> ȡ�����б�();
	bool �Ƿ��й���();
};

