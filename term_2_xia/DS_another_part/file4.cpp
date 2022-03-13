#include <windows.h>
#include <iostream>
#include "Shlobj.h"
#include "tchar.h" 
using namespace std;
void TcharToChar(const TCHAR * tchar, char * _char)
{
	int iLength;
	//获取字节长度   
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
	//将tchar值赋给_char    
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}
int main(int argc, char** argv)
{
	TCHAR szBuffer[MAX_PATH] = {0};   //存放选择文件的路径 
	BROWSEINFO bi;   
	ZeroMemory(&bi,sizeof(BROWSEINFO));   
	bi.hwndOwner = NULL;   
	bi.pszDisplayName = szBuffer;   
	bi.lpszTitle = _T("从下面选择文件或文件夹:");   //_T()是在头文件tchar.h下的一个宏定义。 
	bi.ulFlags = BIF_BROWSEINCLUDEFILES;   
	LPITEMIDLIST idl = SHBrowseForFolder(&bi);   //开始选择文件或文件夹
	if (NULL == idl)   
	{   
	    return 0;   
	}   
	SHGetPathFromIDList(idl,szBuffer);	//获取完整路径，否则szBuffer只会存储当前选择的文件或文件夹名称
	char sz[MAX_PATH];
	TcharToChar(szBuffer, sz);
	cout << "您选择的文件或文件夹的路径为：\n" << sz << endl; 
	return 0;
}
