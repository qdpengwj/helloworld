
LRESULT CLsyPanel::OnBnClickedOk(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_pController)
	{
		//创建SAFEARRAY
		SAFEARRAY *psa;
		SAFEARRAYBOUND rgsabound[1];
		rgsabound[0].cElements=(ULONG)6; //数组定义
		rgsabound[0].lLbound=0;
		psa=SafeArrayCreate(VT_UI1,1,rgsabound);  //分配安全数组psa内存
		BYTE *pData=nullptr;
		SafeArrayAccessData(psa,(void**)&pData);  //解锁psa的内部数据指针
		if(pData)
		{
			*(pData+0)=0x02;
			*(pData+1)=0x41;
			*(pData+2)=0x42;
			*(pData+3)=0x03;
			*(pData+4)=0x55;
			*(pData+5)=0xaa;
		};
		SafeArrayUnaccessData(psa);              //锁定psa的内部数据指针

		m_pController->Fire_Information(psa);    //发送安全数组
		SafeArrayDestroy(psa);                   //释放安全数组psa内存
	}
	return 0;
}
