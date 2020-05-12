#include "ConsoleApplication.h"


int main(int argc, char** argv)
{
	std::string fileIn, fileOut, type;
	if (argc < 4)
	{
		std::cout << "invalid data!";
	}
	else
	{
		fileIn = std::string(argv[1]);
		fileOut = std::string(argv[2]);
		type = std::string(argv[3]);

		ConsoleApplication* app = new ConsoleApplication;
		app->Run(fileIn, fileOut, type);
		delete app;
	}

	return 0;
}