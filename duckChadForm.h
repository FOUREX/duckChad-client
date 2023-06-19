#pragma once

#include "client.h"
#include "database.h"
#include "runningManager.h"

namespace duck {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace DuckClient;

	/// <summary>
	/// —водка дл€ duckChadForm
	/// </summary>
	public ref class duckChadForm : public System::Windows::Forms::Form
	{
	public:
		Session *session;
		Client^ client;
		Form^ welcomeForm;
		Thread^ getMessagesThread;

	private: System::Windows::Forms::Button^ sendMessageButton;
	public:

	public:
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::TextBox^ messageTextBox;

	private: System::Windows::Forms::FlowLayoutPanel^ messageContainer;


	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;




































	public:










	public:
		RunningManager^ runningManager;

		duckChadForm(Session* session, Client^ client, RunningManager^ runningManager)
		{
			InitializeComponent();
			
			this->session = session;
			this->client = client;
			this->runningManager = runningManager;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~duckChadForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ topDock;
	protected:

	protected:

	private: System::Windows::Forms::Label^ dockFirstName;
	private: System::Windows::Forms::Button^ signOutButton;
	protected:

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
			this->topDock = (gcnew System::Windows::Forms::Panel());
			this->dockFirstName = (gcnew System::Windows::Forms::Label());
			this->signOutButton = (gcnew System::Windows::Forms::Button());
			this->sendMessageButton = (gcnew System::Windows::Forms::Button());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->messageTextBox = (gcnew System::Windows::Forms::TextBox());
			this->messageContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->topDock->SuspendLayout();
			this->panel8->SuspendLayout();
			this->SuspendLayout();
			// 
			// topDock
			// 
			this->topDock->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->topDock->Controls->Add(this->dockFirstName);
			this->topDock->Controls->Add(this->signOutButton);
			this->topDock->Dock = System::Windows::Forms::DockStyle::Top;
			this->topDock->Location = System::Drawing::Point(0, 0);
			this->topDock->Margin = System::Windows::Forms::Padding(0);
			this->topDock->Name = L"topDock";
			this->topDock->Padding = System::Windows::Forms::Padding(1);
			this->topDock->Size = System::Drawing::Size(762, 32);
			this->topDock->TabIndex = 0;
			// 
			// dockFirstName
			// 
			this->dockFirstName->Dock = System::Windows::Forms::DockStyle::Right;
			this->dockFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dockFirstName->Location = System::Drawing::Point(557, 1);
			this->dockFirstName->Margin = System::Windows::Forms::Padding(0);
			this->dockFirstName->Name = L"dockFirstName";
			this->dockFirstName->Size = System::Drawing::Size(136, 28);
			this->dockFirstName->TabIndex = 1;
			this->dockFirstName->Text = L"dockFirstName";
			this->dockFirstName->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// signOutButton
			// 
			this->signOutButton->Dock = System::Windows::Forms::DockStyle::Right;
			this->signOutButton->Location = System::Drawing::Point(693, 1);
			this->signOutButton->Margin = System::Windows::Forms::Padding(0);
			this->signOutButton->Name = L"signOutButton";
			this->signOutButton->Size = System::Drawing::Size(66, 28);
			this->signOutButton->TabIndex = 0;
			this->signOutButton->Text = L"Sign out";
			this->signOutButton->UseVisualStyleBackColor = true;
			this->signOutButton->Click += gcnew System::EventHandler(this, &duckChadForm::signOutButton_Click);
			// 
			// sendMessageButton
			// 
			this->sendMessageButton->Dock = System::Windows::Forms::DockStyle::Right;
			this->sendMessageButton->Location = System::Drawing::Point(685, 0);
			this->sendMessageButton->Margin = System::Windows::Forms::Padding(6);
			this->sendMessageButton->Name = L"sendMessageButton";
			this->sendMessageButton->Size = System::Drawing::Size(75, 24);
			this->sendMessageButton->TabIndex = 0;
			this->sendMessageButton->Text = L"Send";
			this->sendMessageButton->UseVisualStyleBackColor = true;
			this->sendMessageButton->Click += gcnew System::EventHandler(this, &duckChadForm::sendMessageButton_Click);
			// 
			// panel8
			// 
			this->panel8->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel8->Controls->Add(this->messageTextBox);
			this->panel8->Controls->Add(this->sendMessageButton);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel8->Location = System::Drawing::Point(0, 663);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(762, 26);
			this->panel8->TabIndex = 3;
			// 
			// messageTextBox
			// 
			this->messageTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->messageTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->messageTextBox->Location = System::Drawing::Point(0, 0);
			this->messageTextBox->MaxLength = 512;
			this->messageTextBox->Name = L"messageTextBox";
			this->messageTextBox->Size = System::Drawing::Size(685, 26);
			this->messageTextBox->TabIndex = 0;
			// 
			// messageContainer
			// 
			this->messageContainer->AutoScroll = true;
			this->messageContainer->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->messageContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->messageContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->messageContainer->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->messageContainer->Location = System::Drawing::Point(0, 32);
			this->messageContainer->Name = L"messageContainer";
			this->messageContainer->Size = System::Drawing::Size(762, 631);
			this->messageContainer->TabIndex = 0;
			this->messageContainer->WrapContents = false;
			// 
			// duckChadForm
			// 
			this->AcceptButton = this->sendMessageButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(762, 689);
			this->Controls->Add(this->messageContainer);
			this->Controls->Add(this->panel8);
			this->Controls->Add(this->topDock);
			this->Name = L"duckChadForm";
			this->Text = L"DuckChad";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &duckChadForm::duckChadForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &duckChadForm::duckChadForm_Load);
			this->topDock->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void signOutButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void duckChadForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void duckChadForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void sendMessageButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void getMessages();
	private: System::Void onMessage(String^ from, String^ text);
	private: System::Void messageContainerUpdate(FlowLayoutPanel^ container);
	private: System::Void messageContainerScrollDown(FlowLayoutPanel^ container);
};
}
