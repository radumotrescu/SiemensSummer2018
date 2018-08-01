#include <iostream>
#include <fstream>
#include <string>
#include <memory>

auto JonSnowDies(const std::string& content) -> bool {
	return content == "Jon Snow dies";
}

auto TyrionDies(const std::string& content) -> bool {
	return content == "Tyrion dies";
}

auto CerseiDies(const std::string& content) -> bool {
	return content == "Cersei dies";
}

class File {
public:
	File(const std::string& fileName, int(*closeFunction)(FILE*))
		: m_closeFunction(closeFunction) {
		m_file = fopen(fileName.c_str(), "r");
	}

	auto IsOpen() -> bool { return m_file != nullptr; }

	auto ReadLine() -> std::string {
		char line[256] = { '\0' };
		fread(line, 1, sizeof(line), m_file);
		return line;
	}

	~File() {
		m_closeFunction(m_file);
	}

private:
	FILE* m_file;
	int(*m_closeFunction)(FILE*);
};

struct FileDeleter {
    auto operator()(FILE* file) -> void {
        fclose(file);
    }
};

auto ReadFile(const std::string& fileName) -> void {
    // auto file = std::unique_ptr<FILE, int(*)(FILE*)>(fopen(fileName.c_str(), "r"), fclose);
    auto file = std::unique_ptr<FILE, FileDeleter>(fopen(fileName.c_str(), "r"));

	if (file) {
        char line[256] = { '\0' };
        fread(line, 1, sizeof(line), file.get());

		if (JonSnowDies(line))
			throw "But... But... King in the North...";

		else if (TyrionDies(line))
			throw "I'm not watching this show anymore";

		else if (CerseiDies(line))
			throw "A party";

		else std::cout << "OK, now show me those dragons" << std::endl;
	}
}

auto main() -> int {
	try {
		ReadFile("..\\..\\src\\6.ReadingFile_Smart_Exercise\\Public\\GameOfThrones.txt");
		ReadFile("..\\..\\src\\6.ReadingFile_Smart_Exercise\\Public\\GameOfThronesYAY.txt");
	}
	catch (...) {
		std::cout << "Don't worry, I GOT this" << std::endl;
	}

	return 0;
}