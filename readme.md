# QuqiParser

## 解析器的基本性质
- 需要c++20以上版本

## Json解析器的使用
### json的数据类型
- enum类型
```cpp

enum class JValueType
{
	JNull,
	JInt,
	JDouble,
	JBool,
	JString,
	JList,
	JDict
};
```
- enum对应下面的数据类型
```cpp

using null_t 	= bool;
using int_t 	= long long;
using bool_t 	= bool;
using double_t 	= long double;
using string_t 	= std::string;
using list_t 	= std::vector<JObject>;
using dict_t 	= std::unordered_map<std::string, JObject>;
```

### class JObject
- 类型的定义
```cpp

//null类型（直接生成）
JObject json;

//int类型（long long）
JObject json = 1;

//double类型（long double）
JObject json = 1.0;

//bool类型（bool）
JObject json = true;

//string类型（std::string）
JObject json = "Hello world!";

//list类型（std::vector<JObject>）
JObject json[0] = 1;
//或者
JObject json.push_back(1);

//dict类型（std::unordered_map<std::string, JObject>）
JObject json["awa"] = 1;
```
- 数据的获取
```cpp

//判断数据类型
json.getType()
返回enum class JValueType

//int类型（long long）
JObject json = 1;
long long get = json.getInt();

//double类型（long double）
long double get = json.getDouble();

//bool类型（bool）
JObject json = true;
bool get = json.getBool();

//string类型（std::string）
JObject json = "Hello world!";
std::string get = json.getString();

//list类型（std::vector<JObject>）
JObject json[0] = 1;

long long get = json[0].getInt();
//or
std::vector<JObject> get = json.getList();
list_t& get = json.getList();

//dict类型（std::unordered_map<std::string, JObject>）
JObject json["awa"] = 1;
long long get = json["awa"].getInt();
//or
std::unordered_map<std::string, JObject> get = json.getDict();
dict_t& get = json.getDict();
```

### class JParser
- 数据的读取
1. 读取字符串
```cpp

string jsonString = R"(
{
    "a":"hello",
    "b":[1,2,3,4],
    "c":false,
    "d":null,
}
)";
JObject json = JParser::fastParse(jsonString);
```

2. 读取文件
```cpp

std::ifstream infile;
JObject json = JParser::fastParse(infile);

```

### class JWriter
- 数据的写出
```cpp

JObject json["awa"];
std::string get = JWriter::fastWrite(json);
/*
{"awa":1}
*/

std::string get = JWriter::fastFormatWrite(json);
/*
{
	"awa":1
}
*/
```

## INI解析器的使用
### class INIObject
- 类型的定义和获取
```cpp
INIObject object;
object["section"]["key"] = "value";
std::string get = object["section"]["key"];
```

### class INIParser
- 数据的读取
1. 读取字符串
```cpp
INIObject object = INIParser::fastParse(/*ini data string*/);
```

2. 读取文件（还在编写）
```cpp
std::ifstream file(/*path*/);
INIObject object = INIParser::fastParse(file);
```

### class INIWriter
- 数据的写出
```cpp
INIObject object;

std::string get = INIWriter::fastWrite(object);

```

