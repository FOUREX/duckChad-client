#include "formManager.h"

FormManager::FormManager(Client^ client, Session* session)
{
	this->session = session;
	this->client = client;
	this->runningManager = gcnew RunningManager();
}

void FormManager::Start()
{
	while (runningManager->isRunning)
	{
		if (session->ok)
		{
			_duckChadForm = gcnew duckChadForm(session, client, runningManager);

			Application::Run(_duckChadForm);
			delete _duckChadForm;
		}
		else
		{
			_welcomeForm = gcnew welcomeForm(session, runningManager);
			_signInForm = gcnew signInForm(_welcomeForm, client, session);
			_signUpForm = gcnew signUpForm(_welcomeForm, client);

			_welcomeForm->signInForm = _signInForm;
			_welcomeForm->signUpForm = _signUpForm;

			Application::Run(_welcomeForm);
			delete _signInForm;
			delete _signUpForm;
		}
	}
}
