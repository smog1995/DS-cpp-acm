#include <iostream>
#include <windows.h>  
#include <commdlg.h>
class Base {
public:
    virtual void display() = 0;
};
class File :public Base {
public:
    virtual void display() {
        TCHAR szBuffer[MAX_PATH] = { 0 };
        OPENFILENAME ofn = { 0 };
        ofn.lStructSize = sizeof(ofn);
        ofn.hwndOwner = m_hWnd;
        ofn.lpstrFilter = _T("Exe�ļ�(*.exe)\0*.exe\0�����ļ�(*.*)\0*.*\0");//Ҫѡ����ļ���׺ 
        ofn.lpstrInitialDir = _T("D:\\Program Files");//Ĭ�ϵ��ļ�·�� 
        ofn.lpstrFile = szBuffer;//����ļ��Ļ����� 
        ofn.nMaxFile = sizeof(szBuffer) / sizeof(*szBuffer);
        ofn.nFilterIndex = 0;
        ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;//��־����Ƕ�ѡҪ����OFN_ALLOWMULTISELECT
        BOOL bSel = GetOpenFileName(&ofn);
    }

};
class Folder :public Base {
public:
    virtual void display() {
        TCHAR szBuffer[MAX_PATH] = { 0 };
        BROWSEINFO bi;
        ZeroMemory(&bi, sizeof(BROWSEINFO));
        bi.hwndOwner = NULL;
        bi.pszDisplayName = szBuffer;
        bi.lpszTitle = _T("������ѡ�ļ���Ŀ¼:");
        bi.ulFlags = BIF_RETURNFSANCESTORS;
        LPITEMIDLIST idl = SHBrowseForFolder(&bi);
        if (NULL == idl)
        {
            return;
        }
        SHGetPathFromIDList(idl, szBuffer)
    }
};
int main() {
    TCHAR szBuffer[MAX_PATH] = { 0 };
    BROWSEINFO bi;
    ZeroMemory(&bi, sizeof(BROWSEINFO));
    bi.hwndOwner = NULL;
    bi.pszDisplayName = szBuffer;
    bi.lpszTitle = _T("������ѡ���ļ����ļ���:");
    bi.ulFlags = BIF_BROWSEINCLUDEFILES;
    LPITEMIDLIST idl = SHBrowseForFolder(&bi);
    if (NULL == idl)
    {
        return;
    }
    SHGetPathFromIDList(idl, szBuffer);



}
