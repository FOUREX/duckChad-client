#include "welcome.h"
#include "yep.h"

void duck::welcome::loginButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	duck::yep^ form = gcnew duck::yep();
	form->Show();
	this->Hide();
}
