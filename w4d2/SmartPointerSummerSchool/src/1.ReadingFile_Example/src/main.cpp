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

auto ReadFile(const std::string& fileName) -> void {
    FILE* file = fopen(fileName.c_str(), "r");
    if (file) {
        char line[256] = { '\0' };
        fread(line, 1, sizeof(line), file);

        if (JonSnowDies(line))
            throw "But... But... King in the North...";

        else if (TyrionDies(line))
            throw "I'm not watching this show anymore";

        else if (CerseiDies(line))
            throw "A party";

        else std::cout << "OK, now show me those dragons" << std::endl;

        fclose(file);
    }
}

auto main() -> int {
    try {
        ReadFile("..\..\..\..\src\1.ReadingFile_Example\src\GameOfThrones.txt");
        ReadFile("..\..\..\..\src\1.ReadingFile_Example\src\GameOfThronesYAY.txt");
    } catch (...) {
        std::cout << "Don't worry, I GOT this" << std::endl;
    }

    return 0;
}