#pragma once

#include "sqlite/sqlite3.h"

#pragma comment(lib, "sqlite3.lib")

extern sqlite3* db;
extern char* dbLastError;

int connectDatabase();
int createDatabase();
