//#include "stdafx.h"
#include "FileLog.h"

//template<> FileLog* Singleton<FileLog>::ms_Singleton = 0;

FileLog::FileLog()
{
	
}


FileLog::~FileLog()
{
}

/*
FileLog& FileLog::getSingleton()
{
	return (*ms_Singleton);
}

FileLog* FileLog::getSingletonPtr()
{
	return ms_Singleton;
}
*/

void FileLog::setFilePath(vstr filePath)
{
	mFilePath = filePath;
}

void FileLog::log(vstr content, vstr title, LogLevel level)
{
	vstr lvlstr;
	switch (level)
	{
	case standard:
		lvlstr = TEXT("Standard");
	case warn:
		lvlstr = TEXT("Warning");
	case error:
		lvlstr = TEXT("Error");
	default:
		lvlstr = TEXT("Standard");
	}
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	
	std::ofstream fs;
	fs.open(mFilePath,std::ios::out);
	if (fs){
		fs << title <<"(" <<lvlstr <<")" << sys.wYear<<"-"<<sys.wMonth<<"-"<<sys.wDay<<" " <<sys.wHour<<":"<<sys.wMinute<<" "<< std::endl;
		fs << content << std::endl;
		fs.close();
	}
	
	/*
	vstring timestr,ystr,mstr,dstr,hstr,minstr,secstr;
	ystr.Format(_T("%d"), sys.wYear);
	mstr.Format(_T("%d"), sys.wMonth);
	dstr.Format(_T("%d"), sys.wDay);
	hstr.Format(_T("%d"), sys.wHour);
	minstr.Format(_T("%d"), sys.wMinute);
	secstr.Format(_T("%d"), sys.wSecond);
	timestr = ystr + _T("-") + mstr + _T(":") + dstr + _T(":") + hstr + _T("：") + minstr + _T("：") + secstr + _T(":");
	vstring titlestr("");
	titlestr = titlestr + title + " (" + lvlstr + ") " + timestr+":";
	vstring cdtstr(content);
	cdtstr += "\r\n";

	TCHAR sFullFilename[_MAX_PATH];
	TCHAR sDrive[_MAX_DRIVE];
	TCHAR sDir[_MAX_DIR];
	TCHAR sFname[_MAX_FNAME];
	TCHAR sExt[_MAX_EXT];
	GetModuleFileName(NULL, sFullFilename, MAX_PATH);
	_wsplitpath_s(sFullFilename, sDrive, sDir, sFname, sExt);
	CString szFilePath(CString(sDrive) + CString(sDir) + CString(mFilePath));
	CFile logfile(szFilePath, CFile::modeNoTruncate | CFile::modeReadWrite | CFile::typeUnicode | CFile::shareDenyNone);
	
	WORD unicode = 0xFEFF;
	CString strEnter("\r\n");
	logfile.SeekToEnd();
	logfile.Write(&unicode, 2);
	logfile.Write(titlestr, wcslen(titlestr)*sizeof(wchar_t));
	logfile.Write(strEnter, 4);
	logfile.Write(cdtstr, wcslen(cdtstr)*sizeof(wchar_t));
	
	logfile.Close();
	*/
	
}
