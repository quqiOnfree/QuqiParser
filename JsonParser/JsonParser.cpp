#include <iostream>
#include <ctime>

#include "Json.h"

using namespace std;

int main()
{
    string jsonString = R"(
{
    "a":"hello\n",
    "b":[1,2,3,4],
    "c":false,
    "d":null,
}
)";

    qjson::u8JObject json = qjson::JParser::u8fastParse(u8"{\"hi\":{}}");
    cout<<(char*)qjson::JWriter::u8fastWrite(json).c_str();

    return 0;
}
