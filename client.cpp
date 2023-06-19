#include "client.h"

namespace DuckClient
{
	Client::Client()
	{
		this->connection = gcnew TcpClient();
	}

	Client::~Client()
	{
		stream->Close();
		connection->Close();
	}

	String^ Client::GetLastError()
	{
		return lastError;
	}

	int Client::Connect(String^ host, int port)
	{
		this->host = host;
		this->port = port;

		try
		{
			connection->Connect(host, port);
			CreateStream();
			connected = true;
		}
		catch (Exception^ exception)
		{
			connected = false;
			lastError = exception->ToString();
			return 1;
		}

		return 0;
	}

	void Client::CreateStream()
	{
		stream = connection->GetStream();
	}

	void Client::CloseStream()
	{
		stream->Close();
	}

	void Client::Send(json data)
	{
		array<Byte>^ buffer = Encoding::UTF8->GetBytes(stdStringToSystemString(packData(data)));
		stream->WriteAsync(buffer, 0, buffer->Length);
	}

	json Client::Accept(int bufferLength)
	{
		array<Byte>^ buffer = gcnew array<Byte>(bufferLength);
		stream->Read(buffer, 0, bufferLength);
		json data = json::parse(systemStringToChar(Encoding::UTF8->GetString(buffer)));

		return data;
	}
}
