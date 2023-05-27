#pragma once

#include <iostream>
#include <Windows.h>
#include <msclr/marshal_cppstd.h>
#include "nlohmann/json.hpp"

char* stdStringToChar(std::string s);

char* systemStringToChar(System::String^ s);

System::String^ charToSystemString(char* s);

System::String^ stdStringToSystemString(std::string s);

std::string systemStringToStdString(System::String^ s);

std::string packData(nlohmann::json data);

System::String^ unpackData(char* data);

std::size_t generateHash(const std::string& s);
