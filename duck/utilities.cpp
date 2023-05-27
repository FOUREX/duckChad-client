#include "utilities.h"

char* stdStringToChar(std::string s)
{
    return (char*)s.c_str();
}

char* systemStringToChar(System::String^ s)
{
    return (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(s);
}

System::String^ charToSystemString(char* s)
{
    std::string stdStr(s);
    return msclr::interop::marshal_as<System::String^>(s);
}

System::String^ stdStringToSystemString(std::string s)
{
    return msclr::interop::marshal_as<System::String^>(s);
}

std::string systemStringToStdString(System::String^ s) {
    return msclr::interop::marshal_as<std::string>(s);
}

std::string packData(nlohmann::json data)
{
    return data.dump();
}

System::String^ unpackData(char* data)
{
    std::string stdStr(data);
    return msclr::interop::marshal_as<System::String^>(data);
}

std::size_t generateHash(const std::string& s) {
    std::hash<std::string> hasher;
    return hasher(s);
}
