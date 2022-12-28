#include <iostream>
#include <ctime>

#include "Json.h"

using namespace std;

int main()
{
    system("chcp 65001");

    qjson::u8JObject json = qjson::JParser::u8fastParse(u8"{\"hi\":\"你好\"}");
    cout<<(char*)qjson::JWriter::u8fastWrite(json).c_str();

    return 0;
}
