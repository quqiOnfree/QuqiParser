#include <iostream>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <string>

#include "Json.h"

using namespace std;

int main()
{
    //system("chcp 65001");

    std::ifstream file("./testdata.json");
    auto get = qjson::JParser::fastParse(file);
    cout << qjson::JWriter::fastFormatWrite(get) << '\n';

    return 0;
}
