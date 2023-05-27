#include "yep.h"

#include "client.h"
#include "utilities.h"

using json = nlohmann::json;

void duck::yep::registerButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::size_t password = generateHash(systemStringToStdString(passwordRegistration->Text));

    json jsonData = {
        {"type", "register"},
        {"data", {
            {"first_name", systemStringToChar(firstNameRegistration->Text)},
            {"last_name", systemStringToChar(lastNameRegistration->Text)},
            {"nickname", systemStringToChar(nicknameRegistration->Text)},
            {"phone_number", systemStringToChar(phoneNumberRegistration->Text)},
            {"password", password}
        }}
    };
    std::string stringData = packData(jsonData);
    send(Connection, stringData.c_str(), stringData.length(), 0);

    char buf[512];
    recv(Connection, buf, 512, 0);

    json receivedJson = json::parse(buf);
    String^ message;

    if (receivedJson["ok"])
    {
        message = "Yep!";
    }
    else
    {
        message = stdStringToSystemString(receivedJson["message"]);
    }

    MessageBox::Show(message);
}

void duck::yep::loginButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::size_t password = generateHash(systemStringToStdString(passwordLogin->Text));

    json jsonData = {
        {"type", "login"},
        {"data", {
            {"phone_number", systemStringToChar(phoneNumberLogin->Text)},
            {"password", password}
        }}
    };

    std::string stringData = packData(jsonData);
    send(Connection, stringData.c_str(), stringData.length(), 0);

    char buf[512];
    recv(Connection, buf, 512, 0);

    json receivedJson = json::parse(buf);
    String^ message;

    if (receivedJson["ok"])
    {
        message = stdStringToSystemString(receivedJson.dump());
    }
    else
    {
        message = stdStringToSystemString(receivedJson["message"]);
    }

    MessageBox::Show(message);
}
