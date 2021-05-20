#pragma once
#include "CMyString.h"

class CMyStringEx : public CMyString
{
public:
	CMyStringEx();
	CMyStringEx(const char* pszParam);
	~CMyStringEx();

	int GetLength() const;
	int Append(const char* pszParam);
	int Find(const char* pszParam);

	//++
	CMyStringEx operator+(const CMyStringEx& rhs);
	CMyStringEx& operator+=(const CMyStringEx& rhs);
	char& operator[](int nIndex);
	char operator[](int nIndex) const;
	int operator==(const CMyStringEx& rhs);
	int operator!=(const CMyStringEx& rhs);
};