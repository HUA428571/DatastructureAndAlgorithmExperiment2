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

int AdminMENU_MENUChoose()
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
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//��갴��˳���������
				return 51;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//��갴�ڶ԰��������
				return 52;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//��갴�ڷֿ�������������
				return 53;
		}
	}
}

int AdminMENU_AddMENU_MENUChoose()
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
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//��갴��ȷ���������
				return 21;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//��갴��ȡ������
				return 22;
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
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//��갴��ȷ��ɾ������
				return 31;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//��갴��ȡ������
				return 32;
		}
	}
}

int AdminMENU_ChangeMENU_MENUChoose()
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
			if (m.x > 400 && m.y > 240 && m.x < 600 && m.y < 270)//��갴�ڸ��ĳ�������
				return 101;
			if (m.x > 400 && m.y > 380 && m.x < 700 && m.y < 410)//��갴�ڸ��ĳ��ܺ�����
				return 102;
			if (m.x > 400 && m.y > 490 && m.x < 550 && m.y < 520)//��갴�ڸ��ĳ�����������
				return 103;
			if (m.x > 400 && m.y > 520 && m.x < 600 && m.y < 550)//��갴�ڸ��ĳ����ֻ�������
				return 104;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//��갴��ȷ���������
				return 21;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//��갴��ȡ������
				return 22;
		}
	}
}

int CustomMENU_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//��갴��˳���������
				return 51;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//��갴�ڶ԰��������
				return 52;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//��갴�ڷֿ�������������
				return 53;
			if (m.x > 100 && m.y > 600 && m.x < 300 && m.y < 640)//��갴��ֱ���˳�����
				return 62;
		}
	}
}
