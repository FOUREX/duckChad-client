#include "signUpForm.h"

void duck::signUpForm::backButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	parentForm->Show();
	this->Hide();
}

void duck::signUpForm::signUpForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	parentForm->Show();
}

void duck::signUpForm::firstName_Enter(System::Object^ sender, System::EventArgs^ e)
{
	if (firstName->Text == "First name" && firstName->ForeColor == Drawing::SystemColors::WindowFrame)
	{
		firstName->Text = "";
		firstName->ForeColor = Drawing::SystemColors::WindowText;
	}
}

void duck::signUpForm::firstName_Leave(System::Object^ sender, System::EventArgs^ e)
{
	if (firstName->Text == "")
	{
		firstName->Text = "First name";
		firstName->ForeColor = Drawing::SystemColors::WindowFrame;
	}
}

void duck::signUpForm::lastName_Enter(System::Object^ sender, System::EventArgs^ e)
{
	if (lastName->Text == "Last name" && lastName->ForeColor == Drawing::SystemColors::WindowFrame)
	{
		lastName->Text = "";
		lastName->ForeColor = Drawing::SystemColors::WindowText;
	}
}

void duck::signUpForm::lastName_Leave(System::Object^ sender, System::EventArgs^ e)
{
	if (lastName->Text == "")
	{
		lastName->Text = "Last name";
		lastName->ForeColor = Drawing::SystemColors::WindowFrame;
	}
}

void duck::signUpForm::nickname_Enter(System::Object^ sender, System::EventArgs^ e)
{
	if (nickname->Text == "Nickname" && nickname->ForeColor == Drawing::SystemColors::WindowFrame)
	{
		nickname->Text = "";
		nickname->ForeColor = Drawing::SystemColors::WindowText;
	}
}

void duck::signUpForm::nickname_Leave(System::Object^ sender, System::EventArgs^ e)
{
	if (nickname->Text == "")
	{
		nickname->Text = "Nickname";
		nickname->ForeColor = Drawing::SystemColors::WindowFrame;
	}
}

void duck::signUpForm::phoneNumberCode_Leave(System::Object^ sender, System::EventArgs^ e)
{
	if (phoneNumberCode->Text == "")
	{
		phoneNumberCode->Text = "+380";
	}
}

void duck::signUpForm::phoneNumber_Enter(System::Object^ sender, System::EventArgs^ e)
{
	if (phoneNumber->Text == "Phone number" && phoneNumber->ForeColor == Drawing::SystemColors::WindowFrame)
	{
		phoneNumber->Text = "";
		phoneNumber->ForeColor = Drawing::SystemColors::WindowText;
	}
}

void duck::signUpForm::phoneNumber_Leave(System::Object^ sender, System::EventArgs^ e)
{
	if (phoneNumber->Text == "")
	{
		phoneNumber->Text = "Phone number";
		phoneNumber->ForeColor = Drawing::SystemColors::WindowFrame;
	}
}

void duck::signUpForm::password_Enter(System::Object^ sender, System::EventArgs^ e)
{
	if (password->Text == "Password" && password->ForeColor == Drawing::SystemColors::WindowFrame)
	{
		password->Text = "";
		password->UseSystemPasswordChar = true;
		password->ForeColor = Drawing::SystemColors::WindowText;
	}
}

void duck::signUpForm::password_Leave(System::Object^ sender, System::EventArgs^ e)
{
	if (password->Text == "")
	{
		password->Text = "Password";
		password->UseSystemPasswordChar = false;
		password->ForeColor = Drawing::SystemColors::WindowFrame;
	}
}

void duck::signUpForm::signUpButton_Callback()
{
	json data = client->Accept(2048);

	String^ message;

	if (data["ok"])
	{
		message = "Success!";
	}
	else
	{
		message = stdStringToSystemString(data["message"]);
	}

	MessageBox::Show(message);
	signUpButton->Enabled = true;
}

void duck::signUpForm::signUpButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (
		firstName->ForeColor == Drawing::SystemColors::WindowFrame &&
		lastName->ForeColor == Drawing::SystemColors::WindowFrame &&
		nickname->ForeColor == Drawing::SystemColors::WindowFrame &&
		phoneNumber->ForeColor == Drawing::SystemColors::WindowFrame &&
		password->ForeColor == Drawing::SystemColors::WindowFrame
		)
	{
		MessageBox::Show("Fields must be not null");
		return;
	}

	std::size_t passwordHash = generateHash(systemStringToStdString(password->Text));

	json data = {
		{"type", "sign_up"},
		{"data", {
			{"first_name", systemStringToChar(firstName->Text)},
			{"last_name", systemStringToChar(lastName->Text)},
			{"nickname", systemStringToChar(nickname->Text)},
			{"phone_number", systemStringToChar(phoneNumberCode->Text + phoneNumber->Text)},
			{"password", passwordHash}
		}}
	};

	client->Send(data);

	Thread^ thread = gcnew Thread(gcnew ThreadStart(this, &duck::signUpForm::signUpButton_Callback));
	thread->Start();

	signUpButton->Enabled = false;
}
