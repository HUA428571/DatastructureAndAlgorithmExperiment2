#include"MENUchoose.h"

int StartMENU_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.y > 280 && m.y < 340 && m.x>470 && m.x < 810)//��갴�������˺�����
				return 1;
			if (m.y > 380 && m.y < 440 && m.x>470 && m.x < 810)//��갴��������������
				return 2;
		}
	}
}

int AdminMENU_HomeMENU_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//��갴����ҳ����
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//��갴�ڲ�������
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//��갴���������
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//��갴��ɾ������
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//��갴�ڸ�������
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//��갴�ڵ��복����������
				return 51;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//��갴�ڵ���������������
				return 52;
			if (m.x > 100 && m.y > 550 && m.x < 300 && m.y < 590)//��갴���˳�����������
				return 61;
			if (m.x > 100 && m.y > 600 && m.x < 300 && m.y < 640)//��갴��ֱ���˳�����
				return 62;
		}
	}
}
int AdminMENU_HomeMENU_Import_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//��갴����ҳ����
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//��갴�ڲ�������
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//��갴���������
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//��갴��ɾ������
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//��갴�ڸ�������
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//��갴�ڵ��복����������
				return 51;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//��갴�ڵ���������������
				return 52;
			if (m.x > 400 && m.y > 300 && m.x < 550 && m.y < 390)//��갴��ȷ�ϵ�������
				return 57;
			if (m.x > 550 && m.y > 300 && m.x < 700 && m.y < 390)//��갴��ȡ����������
				return 58;
			if (m.x > 700 && m.y > 300 && m.x < 850 && m.y < 390)//��갴���޸�·������
				return 59;
		}
	}
}


int AdminMENU_SearchMENU_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//��갴�ڲ�������
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//��갴���������
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//��갴��ɾ������
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//��갴�ڸ�������
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//��갴���˳�����
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//��갴��˳���������
				return 51;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//��갴�ڶ԰��������
				return 52;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//��갴�ڷֿ�������������
				return 53;
		}
	}
}





int AdminMENU_DeleteMENU_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//��갴�ڲ�������
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//��갴���������
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//��갴��ɾ������
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//��갴�ڸ�������
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//��갴���˳�����
				return 4;
		}
	}
}