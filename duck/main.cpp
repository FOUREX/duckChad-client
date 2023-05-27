#include "welcome.h"
#include "yep.h"

#include "client.h"
#include "database.h"
#include "utilities.h"

#include <iostream>
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
    int iResult;

    iResult = connectDatabase();
    if (iResult != SQLITE_OK)
    {
        MessageBox::Show(stdStringToSystemString(dbLastError), "Database error");
        return iResult;
    }

    iResult = createDatabase();
    if (iResult != SQLITE_OK)
    {
        MessageBox::Show(stdStringToSystemString(dbLastError), "Database error");
        return iResult;
    }

    iResult = runClient();
    if (iResult != 0)
    {
        MessageBox::Show(stdStringToSystemString(clientLastError), "Client error");
        return iResult;
    }

    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();

    duck::welcome^ welcome = gcnew duck::welcome();

    Application::Run(welcome);
}