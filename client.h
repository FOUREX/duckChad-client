#pragma once

#include <iostream>

#include "utilities.h"

#include "nlohmann/json.hpp"

namespace DuckClient
{

	using json = nlohmann::json;
	using namespace System;
	using namespace System::Text;
	using namespace System::Net::Sockets;
	using namespace System::Windows::Forms;

	public ref class Client
	{
	public:
		bool connected = false;

		Client();
		~Client();

		String^ GetLastError();

		int Connect(String^ host, int port);

		void CreateStream();

		void CloseStream();

		void Send(json data);

		json Accept(int bufferLength);

	private:
		TcpClient^ connection;
		NetworkStream^ stream;
		String^ lastError;

		String^ host;
		int port;
	};
}
