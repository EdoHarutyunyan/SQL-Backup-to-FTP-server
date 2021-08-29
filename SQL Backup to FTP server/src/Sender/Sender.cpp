#include "Sender.h"

#include <iostream>

#include <windows.h>
#include <wininet.h>

#pragma comment( lib, "wininet" )

namespace sender
{

Sender::Sender(const std::string& userName,
	const std::string& password,
	const std::string& ftpHost,
	const uint8_t ftpPort,
	const std::string& remotePath)
	: m_userName{userName}
	, m_password{password}
	, m_ftpHost{ftpHost}
	, m_ftpPort{ftpPort}
	, m_remotePath{remotePath}
{
}

void Sender::Start(const std::string& path)
{
	HINTERNET hInternet = InternetOpen(NULL, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);

	HINTERNET hFtpSession = InternetConnect(hInternet,
		reinterpret_cast<wchar_t*>(m_ftpHost.data()),
		m_ftpPort,
		reinterpret_cast<wchar_t*>(m_userName.data()),
		reinterpret_cast<wchar_t*>(m_password.data()),
		INTERNET_SERVICE_FTP,
		INTERNET_FLAG_PASSIVE,
		0);
	
	FtpPutFile(hFtpSession,
		reinterpret_cast<wchar_t*>(const_cast<char*>(path.data())),
		reinterpret_cast<wchar_t*>(m_remotePath.data()),
		FTP_TRANSFER_TYPE_BINARY,
		0);
	
	std::cout << "File Uploaded." << std::endl;
	InternetCloseHandle(hFtpSession);
	InternetCloseHandle(hInternet);
}

} // namespace sender