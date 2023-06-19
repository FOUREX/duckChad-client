#pragma once

#include "welcomeForm.h"
#include "signInForm.h"
#include "signUpForm.h"
#include "duckChadForm.h"

#include "client.h"
#include "database.h"
#include "runningManager.h"

using namespace duck;
using namespace System;
using namespace System::Windows::Forms;

public ref class FormManager
{
private:
	Session* session;
	Client^ client;

	welcomeForm^ _welcomeForm;
	signInForm^ _signInForm;
	signUpForm^ _signUpForm;
	duckChadForm^ _duckChadForm;

public:
	RunningManager^ runningManager;

	FormManager(Client^ client, Session* session);

	void Start();
};
