//    Copyright 2023-2024 Xuan Xiao
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.

#include <iostream>
#include <format>

#include <QuqiParser/Json.h>
#include <QuqiParser/Ini.h>

int main()
{
    std::string json =
        "{\n"
        "    \"id\": 10000,\n"
        "    \"name\": \"张三\",\n"
        "    \"age\": 50\n"
        "}\n";

    try
    {
        qjson::JObject jobject = qjson::JParser::fastParse(json);

        long long id = jobject["id"].getInt();
        std::string name = jobject["name"].getString();
        long long age = jobject["age"].getInt();

        std::cout << std::format("id: {}, name: {}, age: {}\n", id, name, age);

        std::cout << "一行json数据：" << qjson::JWriter::fastWrite(jobject) << '\n';
        std::cout << "多行json数据：" << qjson::JWriter::fastFormatWrite(jobject) << '\n';
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    try
    {
        std::string data = R"(
[hello]
key=1 ; asdasdasd
word=hello #asdasdas
    )";

        qini::INIObject ob = qini::INIParser::fastParse(data);

        std::cout << ob["hello"]["key"] << '\n';
        std::cout << qini::INIWriter::fastWrite(ob) << '\n';

    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    try
    {
        qini::INIObject ob;
        ob["a"]["b"] = "1231";
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}
