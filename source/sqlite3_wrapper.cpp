#include "sqlite3_wrapper.h"

SQLite3Wrapper::SQLite3Wrapper(std::string tablename) {
	zErrMsg = 0;
	rc = 0;
	db_open = 0;

	rc = sqlite3_open(tablename.c_str(), &db);
	if(rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	db_open=1;
}

int SQLite3Wrapper::exe(std::string s_exe) {
	rc = sqlite3_get_table(
		db,				/* An open database */
		s_exe.c_str(),	/* SQL to be executed */
		&result,		/* Result written to a char *[]  that this points to */
		&nrow,			/* Number of result rows written here */
		&ncol,			/* Number of result columns written here */
		&zErrMsg		/* Error msg written here */
	);

	if(vcol_head.size() > 0) {vcol_head.clear();}
	if(vdata.size()>0) {vdata.clear();}
	
	if( rc == SQLITE_OK ){
		for(int i=0; i < ncol; ++i)
			vcol_head.push_back(result[i]); /* First row heading */
		for(int i=0; i < ncol*nrow; ++i)
			vdata.push_back(result[ncol+i]);
	}
	sqlite3_free_table(result);
	return rc;
}

SQLite3Wrapper::~SQLite3Wrapper() {
	sqlite3_close(db);
}
