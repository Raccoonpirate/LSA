#include <iostream>

#include "Configuration.hpp"
#include "Application.hpp"

int main() {
	try {
		Configuration::Initialize();
		Application app;
		app.run(60);
	} catch (std::exception& e) {
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
}