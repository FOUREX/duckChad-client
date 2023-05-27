#pragma once

namespace duck {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ welcome
	/// </summary>
	public ref class welcome : public System::Windows::Forms::Form
	{
	public:
		welcome(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~welcome()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ mainLabel;
	private: System::Windows::Forms::Button^ registerButton;

	private: System::Windows::Forms::Button^ loginButton;

	protected:

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
			this->mainLabel = (gcnew System::Windows::Forms::Label());
			this->registerButton = (gcnew System::Windows::Forms::Button());
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// mainLabel
			// 
			this->mainLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->mainLabel->Location = System::Drawing::Point(12, 9);
			this->mainLabel->Name = L"mainLabel";
			this->mainLabel->Size = System::Drawing::Size(260, 50);
			this->mainLabel->TabIndex = 2;
			this->mainLabel->Text = L"DuckChad";
			this->mainLabel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// registerButton
			// 
			this->registerButton->Location = System::Drawing::Point(75, 129);
			this->registerButton->Name = L"registerButton";
			this->registerButton->Size = System::Drawing::Size(134, 32);
			this->registerButton->TabIndex = 4;
			this->registerButton->Text = L"Register";
			this->registerButton->UseVisualStyleBackColor = true;
			// 
			// loginButton
			// 
			this->loginButton->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->loginButton->Location = System::Drawing::Point(75, 91);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(134, 32);
			this->loginButton->TabIndex = 3;
			this->loginButton->Text = L"Login";
			this->loginButton->UseVisualStyleBackColor = true;
			this->loginButton->Click += gcnew System::EventHandler(this, &welcome::loginButton_Click);
			// 
			// welcome
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->loginButton);
			this->Controls->Add(this->registerButton);
			this->Controls->Add(this->mainLabel);
			this->Name = L"welcome";
			this->Text = L"Welcome";
			this->Load += gcnew System::EventHandler(this, &welcome::welcome_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void welcome_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
