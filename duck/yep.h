#pragma once

namespace duck {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для yep
	/// </summary>
	public ref class yep : public System::Windows::Forms::Form
	{
	public:
		yep(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~yep()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ firstNameRegistration;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;



	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ phoneNumberRegistration;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ nicknameRegistration;



	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ passwordRegistration;



	private: System::Windows::Forms::Button^ registerButton;
	private: System::Windows::Forms::TextBox^ lastNameRegistration;



	private: System::Windows::Forms::GroupBox^ registrationBox;
	private: System::Windows::Forms::GroupBox^ loginBox;
	private: System::Windows::Forms::Button^ loginButton;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ passwordLogin;
	private: System::Windows::Forms::TextBox^ phoneNumberLogin;



	private: System::Windows::Forms::Label^ label10;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->firstNameRegistration = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->phoneNumberRegistration = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->nicknameRegistration = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->passwordRegistration = (gcnew System::Windows::Forms::TextBox());
			this->registerButton = (gcnew System::Windows::Forms::Button());
			this->lastNameRegistration = (gcnew System::Windows::Forms::TextBox());
			this->registrationBox = (gcnew System::Windows::Forms::GroupBox());
			this->loginBox = (gcnew System::Windows::Forms::GroupBox());
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->passwordLogin = (gcnew System::Windows::Forms::TextBox());
			this->phoneNumberLogin = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->registrationBox->SuspendLayout();
			this->loginBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// firstNameRegistration
			// 
			this->firstNameRegistration->Location = System::Drawing::Point(6, 32);
			this->firstNameRegistration->MaxLength = 24;
			this->firstNameRegistration->Name = L"firstNameRegistration";
			this->firstNameRegistration->Size = System::Drawing::Size(126, 20);
			this->firstNameRegistration->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"First name";
			this->label1->Click += gcnew System::EventHandler(this, &yep::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(135, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Last name";
			this->label2->Click += gcnew System::EventHandler(this, &yep::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(135, 55);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Phone number";
			// 
			// phoneNumberRegistration
			// 
			this->phoneNumberRegistration->Location = System::Drawing::Point(138, 71);
			this->phoneNumberRegistration->MaxLength = 13;
			this->phoneNumberRegistration->Name = L"phoneNumberRegistration";
			this->phoneNumberRegistration->Size = System::Drawing::Size(126, 20);
			this->phoneNumberRegistration->TabIndex = 6;
			this->phoneNumberRegistration->Text = L"+380";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 55);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Nickname";
			// 
			// nicknameRegistration
			// 
			this->nicknameRegistration->Location = System::Drawing::Point(6, 71);
			this->nicknameRegistration->MaxLength = 24;
			this->nicknameRegistration->Name = L"nicknameRegistration";
			this->nicknameRegistration->Size = System::Drawing::Size(126, 20);
			this->nicknameRegistration->TabIndex = 4;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 94);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Password";
			this->label5->Click += gcnew System::EventHandler(this, &yep::label5_Click);
			// 
			// passwordRegistration
			// 
			this->passwordRegistration->Location = System::Drawing::Point(6, 110);
			this->passwordRegistration->MaxLength = 64;
			this->passwordRegistration->Name = L"passwordRegistration";
			this->passwordRegistration->PasswordChar = '*';
			this->passwordRegistration->Size = System::Drawing::Size(126, 20);
			this->passwordRegistration->TabIndex = 8;
			// 
			// registerButton
			// 
			this->registerButton->Location = System::Drawing::Point(138, 108);
			this->registerButton->Name = L"registerButton";
			this->registerButton->Size = System::Drawing::Size(126, 23);
			this->registerButton->TabIndex = 10;
			this->registerButton->Text = L"Register!";
			this->registerButton->UseVisualStyleBackColor = true;
			this->registerButton->Click += gcnew System::EventHandler(this, &yep::registerButton_Click);
			// 
			// lastNameRegistration
			// 
			this->lastNameRegistration->Location = System::Drawing::Point(138, 32);
			this->lastNameRegistration->MaxLength = 24;
			this->lastNameRegistration->Name = L"lastNameRegistration";
			this->lastNameRegistration->Size = System::Drawing::Size(126, 20);
			this->lastNameRegistration->TabIndex = 2;
			this->lastNameRegistration->TextChanged += gcnew System::EventHandler(this, &yep::textBox2_TextChanged);
			// 
			// registrationBox
			// 
			this->registrationBox->AutoSize = true;
			this->registrationBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->registrationBox->Controls->Add(this->lastNameRegistration);
			this->registrationBox->Controls->Add(this->registerButton);
			this->registrationBox->Controls->Add(this->firstNameRegistration);
			this->registrationBox->Controls->Add(this->label5);
			this->registrationBox->Controls->Add(this->label1);
			this->registrationBox->Controls->Add(this->passwordRegistration);
			this->registrationBox->Controls->Add(this->label2);
			this->registrationBox->Controls->Add(this->label3);
			this->registrationBox->Controls->Add(this->nicknameRegistration);
			this->registrationBox->Controls->Add(this->phoneNumberRegistration);
			this->registrationBox->Controls->Add(this->label4);
			this->registrationBox->Location = System::Drawing::Point(12, 12);
			this->registrationBox->Name = L"registrationBox";
			this->registrationBox->Size = System::Drawing::Size(270, 150);
			this->registrationBox->TabIndex = 11;
			this->registrationBox->TabStop = false;
			this->registrationBox->Text = L"Registration";
			this->registrationBox->Enter += gcnew System::EventHandler(this, &yep::groupBox1_Enter);
			// 
			// loginBox
			// 
			this->loginBox->AutoSize = true;
			this->loginBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->loginBox->Controls->Add(this->loginButton);
			this->loginBox->Controls->Add(this->label6);
			this->loginBox->Controls->Add(this->passwordLogin);
			this->loginBox->Controls->Add(this->phoneNumberLogin);
			this->loginBox->Controls->Add(this->label10);
			this->loginBox->Location = System::Drawing::Point(303, 12);
			this->loginBox->Name = L"loginBox";
			this->loginBox->Size = System::Drawing::Size(138, 152);
			this->loginBox->TabIndex = 12;
			this->loginBox->TabStop = false;
			this->loginBox->Text = L"Login";
			// 
			// loginButton
			// 
			this->loginButton->Location = System::Drawing::Point(6, 110);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(126, 23);
			this->loginButton->TabIndex = 10;
			this->loginButton->Text = L"Login!";
			this->loginButton->UseVisualStyleBackColor = true;
			this->loginButton->Click += gcnew System::EventHandler(this, &yep::loginButton_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 55);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(53, 13);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Password";
			// 
			// passwordLogin
			// 
			this->passwordLogin->Location = System::Drawing::Point(6, 71);
			this->passwordLogin->MaxLength = 64;
			this->passwordLogin->Name = L"passwordLogin";
			this->passwordLogin->PasswordChar = '*';
			this->passwordLogin->Size = System::Drawing::Size(126, 20);
			this->passwordLogin->TabIndex = 8;
			// 
			// phoneNumberLogin
			// 
			this->phoneNumberLogin->Location = System::Drawing::Point(6, 32);
			this->phoneNumberLogin->MaxLength = 13;
			this->phoneNumberLogin->Name = L"phoneNumberLogin";
			this->phoneNumberLogin->Size = System::Drawing::Size(126, 20);
			this->phoneNumberLogin->TabIndex = 4;
			this->phoneNumberLogin->Text = L"+380";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 16);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(76, 13);
			this->label10->TabIndex = 5;
			this->label10->Text = L"Phone number";
			// 
			// yep
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(813, 404);
			this->Controls->Add(this->loginBox);
			this->Controls->Add(this->registrationBox);
			this->Name = L"yep";
			this->Text = L"Duck";
			this->Load += gcnew System::EventHandler(this, &yep::yep_Load);
			this->registrationBox->ResumeLayout(false);
			this->registrationBox->PerformLayout();
			this->loginBox->ResumeLayout(false);
			this->loginBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void yep_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void registerButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
