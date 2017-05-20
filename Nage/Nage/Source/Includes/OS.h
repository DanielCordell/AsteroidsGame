#pragma once
#ifdef _WIN32
const std::string FONTPATH = std::string(getenv("WINDIR"))+"/Fonts/arial.ttf";
#elif __APPLE__
const std::string FONTPATH = "/System/Library/Fonts/arial.ttf"
#else
#error "UNKNOWN OS"
#endif