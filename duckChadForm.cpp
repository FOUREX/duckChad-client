#include "duckChadForm.h"

void duck::duckChadForm::duckChadForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	dockFirstName->Text = stdStringToSystemString(session->firstName);

	getMessagesThread = gcnew Thread(gcnew ThreadStart(this, &duck::duckChadForm::getMessages));
	getMessagesThread->Start();
}

void duck::duckChadForm::duckChadForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	json data = {
		{"type", "sign_out"}
	};

	client->Send(data);

	getMessagesThread->Abort();
	getMessagesThread->Join();

	if (session->ok)
	{
		runningManager->Set(false);
	}
}

void duck::duckChadForm::signOutButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	deleteSession(session);
	this->Close();
}

System::Void duck::duckChadForm::getMessages()
{
	while (true)
	{
		json data = client->Accept(2048);

		std::cout << data.dump() << std::endl;

		if (data["type"] == "sign_out")
		{
			return;
		}
		
		if (data["data"]["authorId"] == session->id || data["type"] != "message")
		{
			continue;
		}

		String^ messageAuthor = stdStringToSystemString(data["data"]["authorNickname"]);
		String^ messageText = stdStringToSystemString(data["data"]["text"]);

		onMessage(messageAuthor, messageText);
	}
}

System::Void duck::duckChadForm::messageContainerUpdate(FlowLayoutPanel^ container)
{
	if (messageContainer->InvokeRequired)
	{
		messageContainer->Invoke(gcnew Action<FlowLayoutPanel^>(this, &duck::duckChadForm::messageContainerUpdate), container);
	}
	else
	{
		messageContainer->Controls->Add(container);
	}
}

System::Void duck::duckChadForm::messageContainerScrollDown(FlowLayoutPanel^ container)
{
	if (messageContainer->InvokeRequired)
	{
		messageContainer->Invoke(gcnew Action<FlowLayoutPanel^>(this, &duck::duckChadForm::messageContainerScrollDown), container);
	}
	else
	{
		messageContainer->AutoScrollPosition = Drawing::Point(0, messageContainer->VerticalScroll->Maximum);
	}
}

System::Void duck::duckChadForm::onMessage(String^ messageAuthor, String^ messageText)
{
	FlowLayoutPanel^ messageBox = gcnew FlowLayoutPanel();

	messageBox->BorderStyle = BorderStyle::FixedSingle;
	messageBox->FlowDirection = FlowDirection::TopDown;
	messageBox->WrapContents = false;
	messageBox->AutoSize = true;

	Label^ messageSender = gcnew Label();

	messageSender->Font = gcnew Drawing::Font(messageSender->Font->FontFamily, 10);
	messageSender->ForeColor = Drawing::Color::DarkGoldenrod;
	messageSender->Text = messageAuthor;

	Label^ messageContent = gcnew Label();

	messageContent->Font = gcnew Drawing::Font(messageContent->Font->FontFamily, 10);
	messageContent->Text = messageText;
	messageContent->AutoSize = true;

	messageBox->Controls->Add(messageSender);
	messageBox->Controls->Add(messageContent);

	messageContainerUpdate(messageBox);
	messageContainerScrollDown(messageBox);
}

void duck::duckChadForm::sendMessageButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (messageTextBox->Text->Length == 0)
	{
		return;
	}

	String^ messageFrom = stdStringToSystemString(session->nickname);
	String^ messageText = messageTextBox->Text;

	onMessage(messageFrom, messageText);

	messageTextBox->Text = "";

	json data = {
		{"type", "message"},
		{"data", {
			{"authorId", session->id},
			{"authorNickname", session->nickname},
			{"text", systemStringToStdString(messageText)}
		}}
	};

	client->Send(data);
}
