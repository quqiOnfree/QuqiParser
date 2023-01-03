#include <iostream>
#include <ctime>

#include "Json.h"

using namespace std;

int main()
{
    system("chcp 65001");

    qjson::JObject json = "abcde";
    cout << qjson::JWriter::fastWrite(json) << '\n';

    return 0;
}
