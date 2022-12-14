#include <iostream>
#include <ctime>

#include "Json.h"

using namespace std;

int main()
{
    string jsonString = R"(
{
    "a":"hello",
    "b":[1,2,3,4],
    "c":false,
    "d":null,
}
)";

    cout << qjson::JWriter::fastFormatWrite(qjson::JParser::fastParse(jsonString)) << '\n';

    return 0;
}
