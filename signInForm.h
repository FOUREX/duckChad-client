#pragma once

#include "client.h"
#include "database.h"
#include "utilities.h"

#include "nlohmann/json.hpp"

namespace duck {

	using json = nlohmann::json;
	using namespace DuckClient;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// —водка дл€ signInForm
	/// </summary>
	public ref class signInForm : public System::Windows::Forms::Form
	{
	public:
		Form^ parentForm;
		Client^ client;
		Session* session;

		signInForm(Form^ parentForm, Client^client, Session* session)
		{
			InitializeComponent();
			
			this->parentForm = parentForm;
			this->client = client;
			this->session = session;
		}

	private: System::Windows::Forms::Label^ secondLabel;
	private: System::Windows::Forms::Label^ mainLabel;
	private: System::Windows::Forms::TextBox^ phoneNumberCode;
	private: System::Windows::Forms::TextBox^ password;
	private: System::Windows::Forms::TextBox^ phoneNumber;
	private: System::Windows::Forms::Button^ signInButton;

	private: System::Windows::Forms::Button^ backButton;

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~signInForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->secondLabel = (gcnew System::Windows::Forms::Label());
			this->mainLabel = (gcnew System::Windows::Forms::Label());
			this->phoneNumberCode = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->phoneNumber = (gcnew System::Windows::Forms::TextBox());
			this->signInButton = (gcnew System::Windows::Forms::Button());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// secondLabel
			// 
			this->secondLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->secondLabel->Location = System::Drawing::Point(12, 59);
			this->secondLabel->Name = L"secondLabel";
			this->secondLabel->Size = System::Drawing::Size(260, 24);
			this->secondLabel->TabIndex = 17;
			this->secondLabel->Text = L"Sign in";
			this->secondLabel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// mainLabel
			// 
			this->mainLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->mainLabel->Location = System::Drawing::Point(12, 9);
			this->mainLabel->Name = L"mainLabel";
			this->mainLabel->Size = System::Drawing::Size(260, 50);
			this->mainLabel->TabIndex = 16;
			this->mainLabel->Text = L"DuckChad";
			this->mainLabel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// phoneNumberCode
			// 
			this->phoneNumberCode->ForeColor = System::Drawing::SystemColors::WindowText;
			this->phoneNumberCode->Location = System::Drawing::Point(78, 112);
			this->phoneNumberCode->MaxLength = 4;
			this->phoneNumberCode->Name = L"phoneNumberCode";
			this->phoneNumberCode->Size = System::Drawing::Size(33, 20);
			this->phoneNumberCode->TabIndex = 1;
			this->phoneNumberCode->Text = L"+380";
			this->phoneNumberCode->Leave += gcnew System::EventHandler(this, &signInForm::phoneNumberCode_Leave);
			// 
			// password
			// 
			this->password->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->password->Location = System::Drawing::Point(78, 137);
			this->password->MaxLength = 64;
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(127, 20);
			this->password->TabIndex = 3;
			this->password->Text = L"Password";
			this->password->Enter += gcnew System::EventHandler(this, &signInForm::password_Enter);
			this->password->Leave += gcnew System::EventHandler(this, &signInForm::password_Leave);
			// 
			// phoneNumber
			// 
			this->phoneNumber->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->phoneNumber->Location = System::Drawing::Point(117, 112);
			this->phoneNumber->MaxLength = 9;
			this->phoneNumber->Name = L"phoneNumber";
			this->phoneNumber->Size = System::Drawing::Size(88, 20);
			this->phoneNumber->TabIndex = 2;
			this->phoneNumber->Text = L"Phone number";
			this->phoneNumber->Enter += gcnew System::EventHandler(this, &signInForm::phoneNumber_Enter);
			this->phoneNumber->Leave += gcnew System::EventHandler(this, &signInForm::phoneNumber_Leave);
			// 
			// signInButton
			// 
			this->signInButton->Location = System::Drawing::Point(145, 190);
			this->signInButton->Name = L"signInButton";
			this->signInButton->Size = System::Drawing::Size(127, 23);
			this->signInButton->TabIndex = 4;
			this->signInButton->Text = L"Sign in!";
			this->signInButton->UseVisualStyleBackColor = true;
			this->signInButton->Click += gcnew System::EventHandler(this, &signInForm::signInButton_Click);
			// 
			// backButton
			// 
			this->backButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->backButton->Location = System::Drawing::Point(12, 190);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(127, 23);
			this->backButton->TabIndex = 0;
			this->backButton->Text = L"Back";
			this->backButton->UseVisualStyleBackColor = true;
			this->backButton->Click += gcnew System::EventHandler(this, &signInForm::backButton_Click);
			// 
			// signInForm
			// 
			this->AcceptButton = this->signInButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->backButton;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->signInButton);
			this->Controls->Add(this->backButton);
			this->Controls->Add(this->phoneNumberCode);
			this->Controls->Add(this->password);
			this->Controls->Add(this->phoneNumber);
			this->Controls->Add(this->secondLabel);
			this->Controls->Add(this->mainLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"signInForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sign in";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &signInForm::signInForm_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void backButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void phoneNumberCode_Leave(System::Object^ sender, System::EventArgs^ e);
private: System::Void phoneNumber_Enter(System::Object^ sender, System::EventArgs^ e);
private: System::Void phoneNumber_Leave(System::Object^ sender, System::EventArgs^ e);
private: System::Void password_Enter(System::Object^ sender, System::EventArgs^ e);
private: System::Void password_Leave(System::Object^ sender, System::EventArgs^ e);
private: System::Void signInButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void signInButton_Callback();
private: System::Void signInForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
};
}
