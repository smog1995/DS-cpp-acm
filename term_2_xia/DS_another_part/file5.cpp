#include <windows.h>
#include <iostream>
#include "Shlobj.h"
#include <tchar.h>
using namespace std;
 
class Fa {
public:
	virtual void  display() { cout << "Father" << endl; }

};
class Folders :public Fa {
public:
	void display()
	{
		BROWSEINFO bi;
		TCHAR szBuffer[MAX_PATH] = { 0 };
		ZeroMemory(&bi, sizeof(BROWSEINFO));
		bi.hwndOwner = NULL;
		bi.pszDisplayName = szBuffer;
		bi.lpszTitle = _T("从下面选文件夹目录:");
		bi.ulFlags = BIF_RETURNFSANCESTORS;
		LPITEMIDLIST idl = SHBrowseForFolder(&bi);
		if (NULL == idl)
		{
			cout << "error" << endl;
		}
		else {
			cout << "-----------------" << endl;
			cout << "|        Folder      |" << endl;
			cout << "|                        |" << endl;
			cout << "-----------------" << endl;
		}
		SHGetPathFromIDList(idl, szBuffer);
	}
};
class File :public Fa
{
public:
	void display()
	{
		OPENFILENAME ofn = { 0 };
		TCHAR szBuffer[MAX_PATH] = { 0 };
		ofn.lStructSize = sizeof(ofn);
		//ofn.hwndOwner = m_hWnd;
		int nLen = 0;
		ZeroMemory(&ofn, sizeof(ofn));
		ofn.Flags = OFN_EXPLORER | OFN_ALLOWMULTISELECT;
		ofn.lStructSize = sizeof(ofn);//保存 ofn的大小 DWORD。
		ofn.lpstrFile = szBuffer;//存放文件的缓冲区
		ofn.nMaxFile = sizeof(szBuffer) / sizeof(*szBuffer);
		ofn.lpstrFilter = TEXT("All Files(*.*)/0*.*/0");
		if (GetOpenFileName(&ofn))
		{
			cout << "-----------------" << endl;
			cout << "|        File           |" << endl;
			cout << "-----------------" << endl;
		}
	}
};
int main(int argc, char** argv)
{
	
	Folders * folder = new Folders();
	File* file = new File();
	file->display();
	folder->display();
	return 0;
}