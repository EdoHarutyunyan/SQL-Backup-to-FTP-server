#include <iostream>
#include <exception>

#include "DB2FTPExporter.h"
#include "Parser/Parser.h"

int main(int argc, char* argv[])
{
	const auto parser = std::make_unique<parser::Parser>(argc, argv);

	if (!parser->Start())
	{
		std::cerr << "Given arguments are wrong:\n";
		std::cerr << "Please use --help command.\n";
		return 1;
	}

	const auto exporter = std::make_unique<db2ftpexporter::DB2FTPExporter>(parser->GetDbName(),
		parser->GetUserName(),
		parser->GetPassword(),
		parser->GetFTPHost(),
		parser->GetFTPPort(),
		parser->GetRemotePath());

	exporter->Start();
	return 0;
}