#include<windows.h>
#include<iostream>
#include<string>
 
using namespace std;
 
//将一个LPCWSTR转换为string
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
 
//新建一个对话窗口，选择文件
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
	cout << "选择权重文件：";
	path_weight = get_path();
	cout << path_weight<<endl;
	cout << "视频检测输入1，图片检测输入2，其它输入3：";
	int tag;
	cin >> tag; //设置标记
	cout << "请选择文件：";
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
