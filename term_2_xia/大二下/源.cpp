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
        ofn.lpstrFilter = _T("Exe文件(*.exe)\0*.exe\0所有文件(*.*)\0*.*\0");//要选择的文件后缀 
        ofn.lpstrInitialDir = _T("D:\\Program Files");//默认的文件路径 
        ofn.lpstrFile = szBuffer;//存放文件的缓冲区 
        ofn.nMaxFile = sizeof(szBuffer) / sizeof(*szBuffer);
        ofn.nFilterIndex = 0;
        ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;//标志如果是多选要加上OFN_ALLOWMULTISELECT
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
        bi.lpszTitle = _T("从下面选文件夹目录:");
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
    bi.lpszTitle = _T("从下面选择文件或文件夹:");
    bi.ulFlags = BIF_BROWSEINCLUDEFILES;
    LPITEMIDLIST idl = SHBrowseForFolder(&bi);
    if (NULL == idl)
    {
        return;
    }
    SHGetPathFromIDList(idl, szBuffer);



}
