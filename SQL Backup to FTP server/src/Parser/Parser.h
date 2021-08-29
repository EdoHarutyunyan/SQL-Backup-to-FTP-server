#pragma once

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>

#include <string>

namespace parser
{

namespace po = boost::program_options;

class Parser
{
public:
	Parser(int argc, char** argv);

	bool SanityCheck();

	bool Start();

	std::string GetDbName() const;
	std::string GetUserName() const;
	std::string GetPassword() const;
	std::string GetFTPHost() const;
	uint8_t GetFTPPort() const;
	std::string GetRemotePath() const;

private:
	int m_argc;
	char** m_argv;
	std::string m_dbName;
	std::string m_userName;
	std::string m_password;
	std::string m_ftpHost;
	uint8_t m_ftpPort;
	std::string m_remotePath;
};

} // namespace parser
