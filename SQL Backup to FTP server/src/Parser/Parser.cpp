#include <iostream>
#include<ctype.h>
#include<stdio.h>

#include "Parser.h"

namespace parser
{

Parser::Parser(int argc, char** argv) : m_argc(argc), m_argv(argv)
{
}

bool Parser::SanityCheck()
{
	const char* p = m_ftpHost.data();
	while (*p != '\0')
	{
		if (isxdigit(*p) == 0)
		{
			if (ispunct(*p) == 0)
			{
				return false;
			}
		}
		p++;
	}

	return true;
}

bool Parser::Start()
{
	po::options_description desc("Allowed options");
	desc.add_options()
		("help", "produce help message")
		("dbName", po::value<std::string>(&m_dbName)->default_value("HelpSystemsDB"), "set DB name")
		("userName", po::value<std::string>(&m_userName)->default_value("User123"), "set username")
		("password", po::value<std::string>(&m_password)->default_value("Pass123"), "set password")
		("ftpHost", po::value<std::string>(&m_ftpHost)->default_value("127.0.0.1"), "set host")
		("ftpPort", po::value<uint8_t>(&m_ftpPort)->default_value(1u), "set port")
		("ftpHost", po::value<std::string>(&m_remotePath)->default_value("C:\\"), "set remote path");
	po::variables_map vm;
	try 
	{
		po::store(po::parse_command_line(m_argc, m_argv, desc), vm);
	}
	catch (...)
	{
		return false;
	}
	po::notify(vm);

	if (vm.count("help"))
	{
		std::cout << desc << "\n";
		std::exit(0);
	}
	
	return SanityCheck();
}

std::string Parser::GetDbName() const
{
	return m_dbName;
}

std::string Parser::GetUserName() const
{
	return m_userName;
}

std::string Parser::GetPassword() const
{
	return m_password;
}

std::string Parser::GetFTPHost() const
{
	return m_ftpHost;
}

uint8_t Parser::GetFTPPort() const
{
	return m_ftpPort;
}

std::string Parser::GetRemotePath() const
{
	return m_remotePath;
}

} // namespace parser
