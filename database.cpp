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

int createTable()
{
	int iResult;

	const char* querry = (
		"CREATE TABLE IF NOT EXISTS session("
		"token TEXT,"
		"id INTEGER,"
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

int createSession(std::string token, int id, std::string first_name, std::string last_name, std::string nickname, std::string phone_number)
{
	int iResult, rc;
	sqlite3_stmt* stmt;

	const char* querry = "INSERT INTO session(token, id, first_name, last_name, nickname, phone_number) VALUES (?, ?, ?, ?, ?, ?)";

	iResult = sqlite3_prepare_v2(db, querry, -1, &stmt, 0);
	if (iResult == SQLITE_OK)
	{
		sqlite3_bind_int(stmt, 2, id);
		sqlite3_bind_text(stmt, 1, token.c_str(), token.length(), SQLITE_STATIC);
		sqlite3_bind_text(stmt, 3, first_name.c_str(), first_name.length(), SQLITE_STATIC);
		sqlite3_bind_text(stmt, 4, last_name.c_str(), last_name.length(), SQLITE_STATIC);
		sqlite3_bind_text(stmt, 5, nickname.c_str(), nickname.length(), SQLITE_STATIC);
		sqlite3_bind_text(stmt, 6, phone_number.c_str(), phone_number.length(), SQLITE_STATIC);

		rc = sqlite3_step(stmt);
		if (rc != SQLITE_DONE)
		{
			dbLastError = (char*)sqlite3_errmsg(db);
			return rc;
		}
		sqlite3_finalize(stmt);
	}
	else
	{
		dbLastError = (char*)sqlite3_errmsg(db);
	}

	return iResult;
}

int getSession(Session* session)
{
	int iResult;
	sqlite3_stmt* stmt;

	const char* querry = "SELECT token, id, first_name, last_name, nickname, phone_number FROM session";

	iResult = sqlite3_prepare_v2(db, querry, -1, &stmt, 0);
	if (iResult != SQLITE_OK)
	{
		dbLastError = (char*)sqlite3_errmsg(db);
		return iResult;
	}

	while (sqlite3_step(stmt) == SQLITE_ROW)
	{
		session->token = (char*)sqlite3_column_text(stmt, 0);
		session->id = sqlite3_column_int(stmt, 1);
		session->firstName = (char*)sqlite3_column_text(stmt, 2);
		session->lastName = (char*)sqlite3_column_text(stmt, 3);
		session->nickname = (char*)sqlite3_column_text(stmt, 4);
		session->phoneNumber = (char*)sqlite3_column_text(stmt, 5);
		session->ok = true;
	}

	return iResult;
}

int deleteSession(Session* session)
{
	int iResult;

	session->del();

	const char* querry = sqlite3_mprintf("DELETE FROM session");

	iResult = sqlite3_exec(db, querry, 0, 0, &dbLastError);
	if (iResult != SQLITE_OK)
	{
		dbLastError = (char*)sqlite3_errmsg(db);
	}

	return iResult;
}

int clearTable(char* name)
{
	int iResult;

	const char* querry = sqlite3_mprintf("DELETE FROM %q", name);

	iResult = sqlite3_exec(db, querry, 0, 0, &dbLastError);
	if (iResult != SQLITE_OK)
	{
		dbLastError = (char*)sqlite3_errmsg(db);
	}

	return iResult;
}
