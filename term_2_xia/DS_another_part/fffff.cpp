#include<iostream>
#include "cderr.h"  
#include "atlstr.h"
#include <afxtempl.h>

using namespace std;
int main()
{

	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_ALLOWMULTISELECT,
		NULL, this);

	dlg.m_ofn.lpstrInitialDir = (BSTR)directoryName;  //���öԻ���Ĭ�ϳ��ֵ�·��

	CString strFilePath;
	if (dlg.DoModal() == IDOK)
	{
		CArray<CString, CString> aryFilename;
		POSITION posFile = dlg.GetStartPosition();
		while (posFile != NULL)
		{
			aryFilename.Add(dlg.GetNextPathName(posFile));
		}
		for (int i = 0; i < aryFilename.GetSize(); i++)
		{
			if (strFilePath.GetLength() > 0)
			{
				strFilePath.AppendChar(';');//����ļ���;���ֿ�
			}
			strFilePath += aryFilename.GetAt(i);
		}
	}
}
