#include "welcomeForm.h"

void duck::welcomeForm::welcomeForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	if (!session->ok)
	{
		runningManager->Set(false);
	}
}

void duck::welcomeForm::loginButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	signInForm->parentForm = this;
	signInForm->Show();
	this->Hide();
}

void duck::welcomeForm::registerButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	signUpForm->parentForm = this;
	signUpForm->Show();
	this->Hide();
}
