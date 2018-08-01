#include <iostream>
#include <fstream>
#include <string>

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
    File(const std::string& fileName)
        : m_file(fopen(fileName.c_str(), "r")) { }

    auto IsOpen() -> bool { return m_file != nullptr; }

    auto ReadLine() -> std::string {
        char line[256] = { '\0' };
        fread(line, 1, sizeof(line), m_file);
        return line;
    }

    ~File() {
        if (this->IsOpen())
            fclose(m_file);
    }

private:
    FILE* m_file;
};


/**********************************************************************************************/

template<typename Resource, typename Constructor, typename ConstructorArg, typename Destructor> 
class Handler {
public:
    Handler(Constructor ctr, Destructor dtr, ConstructorArg arg1, ConstructorArg arg2) 
    : m_constructor(ctr)
    , m_destructor(dtr)
    , m_resource(m_constructor(arg1, arg2))
    { }

    ~Handler() { 
        if(m_resource) 
            m_destructor(m_resource); 
    }

private:
    Resource* m_resource;
    Constructor m_constructor;
    Destructor m_destructor;
};

/**********************************************************************************************/

auto ReadFile(const std::string& fileName) -> void {
	auto file = File(fileName);
    if (file.IsOpen()) {
        auto line = file.ReadLine();

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
        ReadFile("..\\..\\src\\5.ReadingFile_Exercise\\Public\\GameOfThrones.txt");
        ReadFile("..\\..\\src\\5.ReadingFile_Exercise\\Public\\GameOfThronesYAY.txt");
    } catch (...) {
        std::cout << "Don't worry, I GOT this" << std::endl;
    }

    {
        Handler<FILE, FILE*(*)(const char*, const char*), const char*, int(*)(FILE*)> 
        file(fopen, fclose, "..\\..\\src\\5.ReadingFile_Exercise\\Public\\GameOfThrones.txt", "r");

        int a = 0;
    }

    return 0;
}