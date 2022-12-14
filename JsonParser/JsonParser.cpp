#include <iostream>
#include <ctime>

#include "Json.h"

using namespace std;

int main()
{
    qjson::JObject json;
    json["qwq"] = true;
    json["awa"][1] = 0;
    json["awa"].push_back("你好");
    json["awa"].push_back(1);
    json["awa"].push_back(0.1);

    cout << qjson::JWriter::fastFormatWrite(json) << '\n';

    /*
    clock_t st = clock();
    for (int i = 0;i<1000000;++i)
    {
        qjson::JWriter::fastWrite(json);
    }
    cout << static_cast<double>(clock() - st) / CLOCKS_PER_SEC / 1000000 << '\n';
    */

    return 0;
}
