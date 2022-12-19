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

    //auto a = qjson::JParser::fastParse(jsonString);
    qjson::JObject json = "a\n1";
    auto a = qjson::JParser::fastParse(qjson::JWriter::fastWrite(json));
    cout << string(a) << '\n';

    return 0;
}
