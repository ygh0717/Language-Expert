#pragma once

class CMyString
{
public:
	CMyString();

	// ��ȯ ������
	CMyString(const char* pszParam);

	// ���� ������
	CMyString(const CMyString& rhs);

	// �̵� ������
	CMyString(CMyString&& rhs);

	~CMyString();

protected:
	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;

	// ����� ���ڿ��� ����
	int m_nLength;

public:
	int SetString(const char* pszParam);

	// ��� �б⸸ �����ϹǷ� �޼��带 ���ȭ�Ѵ�.
	const char* GetString() const;

	void Release();

	CMyString& operator=(const CMyString& rhs);
};

