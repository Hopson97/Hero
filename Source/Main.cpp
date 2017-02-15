#include <cstdlib>

#ifdef __WIN32
#include <windows.h>
#endif // __WIN32

#include "Application.h"
#include <iostream>
#include <string>


void errorMessage(const std::string& message, const std::string& error)
{
    #ifdef __WIN32
        MessageBox(nullptr, message.c_str(), "Error!", MB_OK);
    #else
        std::cerr << error;
        std::cin.ignore();
    #endif // __WIN32
}


int main() try
{
    Application app;
    app.runMainLoop();

    return EXIT_SUCCESS;
}
catch (std::exception& e)
{
    errorMessage(e.what(), "Error! Message: " + std::string(e.what()) + "\nPress enter to exit.\n");
    return EXIT_FAILURE;
}
catch(...)
{
    errorMessage("Unrecognised exception type.", "Error: Unrecognised exception type.\nPress enter to exit.\n");
    return EXIT_FAILURE;
}


