#include<windows.h>
#include<iostream>
#include<string>
 
using namespace std;
 
//��һ��LPCWSTRת��Ϊstring
string Lpcwstr2String(LPCWSTR lps) {
	int len = WideCharToMultiByte(CP_ACP, 0, lps, -1, NULL, 0, NULL, NULL);
	if (len <= 0) {
		return "";
	}
	else {
		char *dest = new char[len];
		WideCharToMultiByte(CP_ACP, 0, lps, -1, dest, len, NULL, NULL);
		dest[len - 1] = 0;
		string str(dest);
		delete[] dest;
		return str;
	}
}
 
//�½�һ���Ի����ڣ�ѡ���ļ�
string get_path() {
	OPENFILENAME ofn;
	char szFile[300];
	
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = (LPWSTR)szFile;
	ofn.lpstrFile[0] = '\0';
	LPTSTR        lpstrCustomFilter;
	DWORD         nMaxCustFilter;
	ofn.nFilterIndex = 1;
	LPTSTR        lpstrFile;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter =L"ALL\0*.*\0Text\0*.TXT\0";
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
 
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
 
	string path_image = "";
	if (GetOpenFileName(&ofn)) {
		path_image = Lpcwstr2String(ofn.lpstrFile);
		return path_image;
	}
	else {
		return "";
	}
}
 
 
 
int main() {
	string path_image = "";
	string path_weight = "";
	cout << "ѡ��Ȩ���ļ���";
	path_weight = get_path();
	cout << path_weight<<endl;
	cout << "��Ƶ�������1��ͼƬ�������2����������3��";
	int tag;
	cin >> tag; //���ñ��
	cout << "��ѡ���ļ���";
	path_image= get_path();
	switch (tag) {
		case 1:
			cout << path_image<<endl;
			break;
		case 2:
			cout << path_image << endl;
			break;
		case 3:
			cout << path_image << endl;
			break;
		default: break;
	}
 
	system("pause");
	return 0;
 
}
