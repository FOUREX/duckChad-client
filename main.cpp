#include "welcomeForm.h"
#include "signInForm.h"
#include "signUpForm.h"
#include "duckChadForm.h"

#include <iostream>
#include <fstream>

#include "client.h"
#include "database.h"
#include "utilities.h"
#include "formManager.h"

using namespace System;
using namespace System::Windows::Forms;

json loadConfig()
{
	json config = {{
		"addr_list", {
			{{"host", "91.199.45.219"}, {"port", 25565}},
			{{"host", "127.0.0.1"}, {"port", 25565}}
		}
	}};

	return config;
}

[STAThreadAttribute]
int main(array<String^>^ args)
{
	int iResult;
	Session session;
	bool appRunning = true;
	bool& appRunningPrt = appRunning;
	json config = loadConfig();
	DuckClient::Client^ client = gcnew DuckClient::Client();

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	for (const json& addr : config["addr_list"])
	{
		String^ host = stdStringToSystemString(addr["host"].get<std::string>());
		int port = addr["port"].get<int>();

		iResult = client->Connect(host, port);
		if (iResult == 0)
			break;
		else
			continue;
	}

	if (!client->connected)
	{
		MessageBox::Show(client->GetLastError(), "Client error");
		return iResult;
	}

	iResult = connectDatabase();
	if (iResult != SQLITE_OK)
	{
		MessageBox::Show(stdStringToSystemString(dbLastError), "Database error");
		return iResult;
	}

	iResult = createTable();
	if (iResult != SQLITE_OK)
	{
		MessageBox::Show(stdStringToSystemString(dbLastError), "Database (create table) error");
		return iResult;
	}

	iResult = getSession(&session);
	if (iResult != 0)
	{
		MessageBox::Show(stdStringToSystemString(dbLastError), "Get session error");
		return iResult;
	}

	FormManager^ formManager = gcnew FormManager(client, &session);
	formManager->Start();

	return 0;
}

/*
* 
* 	while (appRunning)
	{
		if (session.ok)
		{
			duck::duckChadForm^ duckChadForm = gcnew duck::duckChadForm(&session, &appRunning);

			Application::Run(duckChadForm);
		}
		else
		{
			duck::welcomeForm^ welcomeForm = gcnew duck::welcomeForm(&appRunning);

			duck::signInForm^ signInForm = gcnew duck::signInForm(welcomeForm, client);
			duck::signUpForm^ signUpForm = gcnew duck::signUpForm(welcomeForm, client);

			welcomeForm->signInForm = signInForm;
			welcomeForm->signUpForm = signUpForm;

			Application::Run(welcomeForm);
		}
		std::cout << appRunning << std::endl;;
	}
* 
void yep()
{
	Session session;

	if (session.ok)
	{
		duck::duckChadForm^ duckChadForm = gcnew duck::duckChadForm(&session);

		Application::Run(duckChadForm);
	}
	else
	{
		duck::welcomeForm^ welcomeForm = gcnew duck::welcomeForm();

		duck::signInForm^ signInForm = gcnew duck::signInForm(welcomeForm, client);
		duck::signUpForm^ signUpForm = gcnew duck::signUpForm(welcomeForm, client);

		welcomeForm->signInForm = signInForm;
		welcomeForm->signUpForm = signUpForm;

		Application::Run(welcomeForm);
	}
}
*/
