#include <iostream>
using namespace std;

#include "CMyStringEx.h"

CMyStringEx::CMyStringEx()
{
}

CMyStringEx::CMyStringEx(const char* pszParam)
	: CMyString(pszParam)
{
}

CMyStringEx::~CMyStringEx()
{
}

int CMyStringEx::GetLength() const
{
	return m_nLength;
}

int CMyStringEx::Append(const char* pszParam)
{
	// �Ű����� ��ȿ�� �˻�
	if (pszParam == NULL)
		return 0;

	int nLenParam = strlen(pszParam);

	if (nLenParam == 0)
		return 0;

	// ��Ʈ�� ���ڿ��� ���ٸ� ���� ���ڿ��� �Ҵ��� �Ͱ� �����ϰ� ó��
	if (m_pszData == NULL)
	{
		SetString(pszParam);

		return m_nLength;
	}

	// ���� ���ڿ��� ���� ���
	int nLenCur = m_nLength;

	// �� ���ڿ��� ���ļ� ������ �� �ִ� �޸𸮸� ���� �Ҵ�
	char* pszResult = new char[nLenCur + nLenParam + 1];

	// ���ڿ� ����
	strcpy_s(pszResult, sizeof(char) * (nLenCur + 1), m_pszData);
	strcpy_s(pszResult + (sizeof(char) * nLenCur),
		sizeof(char) * (nLenParam + 1), pszParam);

	// ���� ���ڿ� ���� �� ��� ���� ����
	Release();
	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;

	return m_nLength;
}

int CMyStringEx::Find(const char* pszParam)
{
	if (pszParam == NULL || GetString() == NULL)
		return -1;

	const char* pszResult = strstr(GetString(), pszParam);

	if (pszResult != NULL)
		return pszResult - GetString();

	return -1;
}

CMyStringEx CMyStringEx::operator+(const CMyStringEx& rhs)
{
	CMyStringEx strResult(m_pszData);
	strResult.Append(rhs.GetString());

	return strResult;
}

CMyStringEx& CMyStringEx::operator+=(const CMyStringEx& rhs)
{
	Append(rhs.GetString());

	return *this;
}

char& CMyStringEx::operator[](int nIndex)
{
	return m_pszData[nIndex];
}

char CMyStringEx::operator[](int nIndex) const
{
	return m_pszData[nIndex];
}

int CMyStringEx::operator==(const CMyStringEx& rhs)
{
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 1;

	return 0;
}

int CMyStringEx::operator!=(const CMyStringEx& rhs)
{
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 0;

	return 1;
}