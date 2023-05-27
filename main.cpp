#include <iostream>
#include <format>

#include "Json.hpp"

int main()
{
	std::string data = "{\"id\":1,\"name\":\"张三\",\"age\":18}";

	qjson::JObject jobject = qjson::JParser::fastParse(data);

	long long id = jobject["id"].getInt();
	std::string name = jobject["name"].getString();
	long long age = jobject["age"].getInt();

	std::cout << std::format("id: {}, name: {}, age: {}\n", id, name, age);

	std::cout << "一行json数据：" << qjson::JWriter::fastWrite(jobject) << '\n';
	std::cout << "多行json数据：" << qjson::JWriter::fastFormatWrite(jobject) << '\n';

	return 0;
}
