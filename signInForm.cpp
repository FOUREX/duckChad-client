#include "signInForm.h"

void duck::signInForm::backButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    parentForm->Show();
    this->Hide();
}

void duck::signInForm::signInForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    parentForm->Show();
}

void duck::signInForm::phoneNumberCode_Leave(System::Object^ sender, System::EventArgs^ e)
{
    if (phoneNumberCode->Text == "")
    {
        phoneNumberCode->Text = "+380";
    }
}

void duck::signInForm::phoneNumber_Enter(System::Object^ sender, System::EventArgs^ e)
{
    if (phoneNumber->Text == "Phone number")
    {
        phoneNumber->Text = "";
        phoneNumber->ForeColor = Drawing::SystemColors::WindowText;
    }
}

void duck::signInForm::phoneNumber_Leave(System::Object^ sender, System::EventArgs^ e)
{
    if (phoneNumber->Text == "")
    {
        phoneNumber->Text = "Phone number";
        phoneNumber->ForeColor = Drawing::SystemColors::WindowFrame;
    }
}

void duck::signInForm::password_Enter(System::Object^ sender, System::EventArgs^ e)
{
    // statusBar->Text = "Yqp!";
    if (password->Text == "Password")
    {
        password->Text = "";
        password->UseSystemPasswordChar = true;
        password->ForeColor = Drawing::SystemColors::WindowText;
    }
}

void duck::signInForm::password_Leave(System::Object^ sender, System::EventArgs^ e)
{
    if (password->Text == "")
    {
        password->Text = "Password";
        password->UseSystemPasswordChar = false;
        password->ForeColor = Drawing::SystemColors::WindowFrame;
    }
}

void duck::signInForm::signInButton_Callback()
{
    int iResult = 0;
    json data = client->Accept(2048);

    if (data["ok"])
    {
        std::cout << data.dump();
        
        int id = data["data"]["id"].get<int>();
        std::string token = data["data"]["token"].get<std::string>();
        std::string firstName = data["data"]["first_name"].get<std::string>();
        std::string lastName = data["data"]["last_name"].get<std::string>();
        std::string nickname = data["data"]["nickname"].get<std::string>();
        std::string phoneNumber = data["data"]["phone_number"].get<std::string>();

        iResult = createSession(token, id, firstName, lastName, nickname, phoneNumber);
        if (iResult != 0)
        {
            MessageBox::Show(stdStringToSystemString(dbLastError), "Sign in error");
        }
    }
    else
    {
        MessageBox::Show(stdStringToSystemString(data["message"]), "Sign in error");
    }
    
    signInButton->Enabled = true;

    if (data["ok"])
    {
        iResult = getSession(session);
        if (iResult != 0)
        {
            MessageBox::Show(stdStringToSystemString(dbLastError), "Get session error");
        }

        this->Close();
        parentForm->Close();
    }
}

void duck::signInForm::signInButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::size_t passwordHash = generateHash(systemStringToStdString(password->Text));

    json data = {
        {"type", "sign_in"},
        {"data", {
            {"phone_number", systemStringToChar(phoneNumberCode->Text + phoneNumber->Text)},
            {"password", passwordHash}
        }}
    };

    client->Send(data);

    Thread^ thread = gcnew Thread(gcnew ThreadStart(this, &duck::signInForm::signInButton_Callback));
    thread->Start();

    signInButton->Enabled = false;
}
