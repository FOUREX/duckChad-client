#include "database.h"

sqlite3* db;
char* dbLastError;

int connectDatabase()
{
	int iResult;

	iResult = sqlite3_open("database.db", &db);
	if (iResult != SQLITE_OK)
	{
		dbLastError = (char*)sqlite3_errmsg(db);
	}

	return iResult;
}

int createDatabase()
{
	int iResult;

	const char* querry = (
		"CREATE TABLE IF NOT EXISTS session("
		"token TEXT,"
		"id TEXT,"
		"first_name TEXT,"
		"last_name TEXT,"
		"nickname TEXT,"
		"phone_number TEXT);"
	);

	iResult = sqlite3_exec(db, querry, 0, 0, &dbLastError);
	if (iResult != SQLITE_OK)
	{
		dbLastError = (char*)sqlite3_errmsg(db);
	}

	return iResult;
}

int createSession(char* token, char* id, char* first_name, char* last_name, char* nickname, char* phone_number)
{
	int iResult;

	const char* querry = sqlite3_mprintf(
		"INSERT INTO session(token, id, first_name, last_name, nickname, phone_number) VALUES ('%q', '%q', '%q', '%q', '%q', '%q')",
		token, id, first_name, last_name, nickname, phone_number
	);

	iResult = sqlite3_exec(db, querry, 0, 0, &dbLastError);
	if (iResult != SQLITE_OK)
	{
		dbLastError = (char*)sqlite3_errmsg(db);
	}

	return iResult;
}
