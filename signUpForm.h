#pragma once

#include "client.h"
#include "utilities.h"
#include "nlohmann/json.hpp"

#include <iostream>

using json = nlohmann::json;

namespace duck {

	using namespace DuckClient;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Ñâîäêà äëÿ signUpForm
	/// </summary>
	public ref class signUpForm : public System::Windows::Forms::Form
	{
	public:
		System::Windows::Forms::Form^ parentForm;
		Client^ client;

		signUpForm(Form^ parentForm, Client^ client)
		{
			InitializeComponent();

			this->parentForm = parentForm;
			this->client = client;
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ðåñóðñû.
		/// </summary>
		~signUpForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ secondLabel;
	protected:
	private: System::Windows::Forms::Label^ mainLabel;
	private: System::Windows::Forms::TextBox^ firstName;
	private: System::Windows::Forms::TextBox^ lastName;
	private: System::Windows::Forms::TextBox^ phoneNumber;



	private: System::Windows::Forms::TextBox^ nickname;
	private: System::Windows::Forms::TextBox^ password;


	private: System::Windows::Forms::Button^ backButton;
	private: System::Windows::Forms::Button^ signUpButton;


	private: System::Windows::Forms::TextBox^ phoneNumberCode;




	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåðåìåííàÿ êîíñòðóêòîðà.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òðåáóåìûé ìåòîä äëÿ ïîääåðæêè êîíñòðóêòîðà — íå èçìåíÿéòå 
		/// ñîäåðæèìîå ýòîãî ìåòîäà ñ ïîìîùüþ ðåäàêòîðà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->secondLabel = (gcnew System::Windows::Forms::Label());
			this->mainLabel = (gcnew System::Windows::Forms::Label());
			this->firstName = (gcnew System::Windows::Forms::TextBox());
			this->lastName = (gcnew System::Windows::Forms::TextBox());
			this->phoneNumber = (gcnew System::Windows::Forms::TextBox());
			this->nickname = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->signUpButton = (gcnew System::Windows::Forms::Button());
			this->phoneNumberCode = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// secondLabel
			// 
			this->secondLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->secondLabel->Location = System::Drawing::Point(12, 59);
			this->secondLabel->Name = L"secondLabel";
			this->secondLabel->Size = System::Drawing::Size(260, 24);
			this->secondLabel->TabIndex = 15;
			this->secondLabel->Text = L"Sign up";
			this->secondLabel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// mainLabel
			// 
			this->mainLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->mainLabel->Location = System::Drawing::Point(12, 9);
			this->mainLabel->Name = L"mainLabel";
			this->mainLabel->Size = System::Drawing::Size(260, 50);
			this->mainLabel->TabIndex = 14;
			this->mainLabel->Text = L"DuckChad";
			this->mainLabel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// firstName
			// 
			this->firstName->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->firstName->Location = System::Drawing::Point(12, 112);
			this->firstName->MaxLength = 24;
			this->firstName->Name = L"firstName";
			this->firstName->Size = System::Drawing::Size(127, 20);
			this->firstName->TabIndex = 1;
			this->firstName->Text = L"First name";
			this->firstName->Enter += gcnew System::EventHandler(this, &signUpForm::firstName_Enter);
			this->firstName->Leave += gcnew System::EventHandler(this, &signUpForm::firstName_Leave);
			// 
			// lastName
			// 
			this->lastName->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->lastName->Location = System::Drawing::Point(145, 112);
			this->lastName->MaxLength = 24;
			this->lastName->Name = L"lastName";
			this->lastName->Size = System::Drawing::Size(127, 20);
			this->lastName->TabIndex = 2;
			this->lastName->Text = L"Last name";
			this->lastName->Enter += gcnew System::EventHandler(this, &signUpForm::lastName_Enter);
			this->lastName->Leave += gcnew System::EventHandler(this, &signUpForm::lastName_Leave);
			// 
			// phoneNumber
			// 
			this->phoneNumber->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->phoneNumber->Location = System::Drawing::Point(184, 138);
			this->phoneNumber->MaxLength = 9;
			this->phoneNumber->Name = L"phoneNumber";
			this->phoneNumber->Size = System::Drawing::Size(88, 20);
			this->phoneNumber->TabIndex = 5;
			this->phoneNumber->Text = L"Phone number";
			this->phoneNumber->Enter += gcnew System::EventHandler(this, &signUpForm::phoneNumber_Enter);
			this->phoneNumber->Leave += gcnew System::EventHandler(this, &signUpForm::phoneNumber_Leave);
			// 
			// nickname
			// 
			this->nickname->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->nickname->Location = System::Drawing::Point(12, 138);
			this->nickname->MaxLength = 32;
			this->nickname->Name = L"nickname";
			this->nickname->Size = System::Drawing::Size(127, 20);
			this->nickname->TabIndex = 3;
			this->nickname->Text = L"Nickname";
			this->nickname->Enter += gcnew System::EventHandler(this, &signUpForm::nickname_Enter);
			this->nickname->Leave += gcnew System::EventHandler(this, &signUpForm::nickname_Leave);
			// 
			// password
			// 
			this->password->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->password->Location = System::Drawing::Point(78, 164);
			this->password->MaxLength = 64;
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(128, 20);
			this->password->TabIndex = 6;
			this->password->Text = L"Password";
			this->password->Enter += gcnew System::EventHandler(this, &signUpForm::password_Enter);
			this->password->Leave += gcnew System::EventHandler(this, &signUpForm::password_Leave);
			// 
			// backButton
			// 
			this->backButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->backButton->Location = System::Drawing::Point(12, 203);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(127, 23);
			this->backButton->TabIndex = 0;
			this->backButton->Text = L"Back";
			this->backButton->UseVisualStyleBackColor = true;
			this->backButton->Click += gcnew System::EventHandler(this, &signUpForm::backButton_Click);
			// 
			// signUpButton
			// 
			this->signUpButton->Location = System::Drawing::Point(145, 203);
			this->signUpButton->Name = L"signUpButton";
			this->signUpButton->Size = System::Drawing::Size(127, 23);
			this->signUpButton->TabIndex = 7;
			this->signUpButton->Text = L"Sign up!";
			this->signUpButton->UseVisualStyleBackColor = true;
			this->signUpButton->Click += gcnew System::EventHandler(this, &signUpForm::signUpButton_Click);
			// 
			// phoneNumberCode
			// 
			this->phoneNumberCode->ForeColor = System::Drawing::SystemColors::WindowText;
			this->phoneNumberCode->Location = System::Drawing::Point(145, 138);
			this->phoneNumberCode->MaxLength = 4;
			this->phoneNumberCode->Name = L"phoneNumberCode";
			this->phoneNumberCode->Size = System::Drawing::Size(33, 20);
			this->phoneNumberCode->TabIndex = 4;
			this->phoneNumberCode->Text = L"+380";
			this->phoneNumberCode->Leave += gcnew System::EventHandler(this, &signUpForm::phoneNumberCode_Leave);
			// 
			// signUpForm
			// 
			this->AcceptButton = this->signUpButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->backButton;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->phoneNumberCode);
			this->Controls->Add(this->signUpButton);
			this->Controls->Add(this->backButton);
			this->Controls->Add(this->password);
			this->Controls->Add(this->phoneNumber);
			this->Controls->Add(this->nickname);
			this->Controls->Add(this->lastName);
			this->Controls->Add(this->firstName);
			this->Controls->Add(this->secondLabel);
			this->Controls->Add(this->mainLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"signUpForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sign up";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &signUpForm::signUpForm_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void backButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void signUpForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void firstName_Enter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void firstName_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void lastName_Enter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void lastName_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nickname_Enter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nickname_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void phoneNumber_Enter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void phoneNumber_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void password_Enter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void password_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void phoneNumberCode_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void signUpButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void signUpButton_Callback();
	};
}
