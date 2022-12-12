#include <iostream>

#include "Json.h"

int main()
{
    qjson::JObject json;
    json["qwq"][5] = 1;
    std::cout << int(json["qwq"][0]) << ' ' << int(json["qwq"][1]) << '\n';
    return 0;
}
