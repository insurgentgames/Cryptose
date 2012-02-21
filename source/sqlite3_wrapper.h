#pragma once
#ifndef SQLITE3_WRAPPER_H
#define SQLITE3_WRAPPER_H

#include <sqlite3.h>
#include <string>
#include <vector>

class SQLite3Wrapper {
private:
	sqlite3 *db;
	char *zErrMsg;
	char **result;
	int rc;
	int nrow,ncol;
	int db_open;
	
public:
	std::vector<std::string> vcol_head;
	std::vector<std::string> vdata;
	
	SQLite3Wrapper(std::string tablename);
	int exe(std::string s_exe);
	~SQLite3Wrapper();
};

#endif // SQLITE3_WRAPPER_H