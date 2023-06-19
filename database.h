#pragma once

#include <iostream>
#include "sqlite/sqlite3.h"

#pragma comment(lib, "sqlite3.lib")

extern sqlite3* db;
extern char* dbLastError;

struct Session
{
	std::string token;
	int id;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	bool ok = false;

	void del()
	{
		this->token = "";
		this->id = 0;
		this->firstName = "";
		this->lastName = "";
		this->nickname = "";
		this->phoneNumber = "";
		this->ok = false;
	}
};

// Основне
int connectDatabase();
int createTable();

// Сесії
int createSession(std::string token, int id, std::string first_name, std::string last_name, std::string nickname, std::string phone_number);
int getSession(Session* session);
int deleteSession(Session* session);

// Утиліти
int clearTable(char* name);
