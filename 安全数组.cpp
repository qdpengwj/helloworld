
LRESULT CLsyPanel::OnBnClickedOk(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_pController)
	{
		//����SAFEARRAY
		SAFEARRAY *psa;
		SAFEARRAYBOUND rgsabound[1];
		rgsabound[0].cElements=(ULONG)6; //���鶨��
		rgsabound[0].lLbound=0;
		psa=SafeArrayCreate(VT_UI1,1,rgsabound);  //���䰲ȫ����psa�ڴ�
		BYTE *pData=nullptr;
		SafeArrayAccessData(psa,(void**)&pData);  //����psa���ڲ�����ָ��
		if(pData)
		{
			*(pData+0)=0x02;
			*(pData+1)=0x41;
			*(pData+2)=0x42;
			*(pData+3)=0x03;
			*(pData+4)=0x55;
			*(pData+5)=0xaa;
		};
		SafeArrayUnaccessData(psa);              //����psa���ڲ�����ָ��

		m_pController->Fire_Information(psa);    //���Ͱ�ȫ����
		SafeArrayDestroy(psa);                   //�ͷŰ�ȫ����psa�ڴ�
	}
	return 0;
}
