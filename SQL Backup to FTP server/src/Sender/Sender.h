#pragma once

#include <string>

#include "ISender.h"

namespace sender
{

class Sender : public ISender
{
public:
	Sender(const std::string& userName,
		const std::string& password,
		const std::string& ftpHost,
		uint8_t ftpPort,
		const std::string& remotePath);
	~Sender() override = default;

	void Start(const std::string& path) override;

private:
	std::string m_userName;
	std::string m_password;
	std::string m_ftpHost;
	uint8_t m_ftpPort;
	std::string m_remotePath;
};

} // namespace sender