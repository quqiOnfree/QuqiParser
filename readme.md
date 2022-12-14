# JsonParser Json解析器

## 解析器的基本性质
- 还没测效率，估计不低（比jsoncpp快就行）
- 报错使用std::exception
- 有三个Class，分别是JObject（用于存Json数据）、JParser（Json数据读取）、JWriter（Json数据写出）

## 解析器的使用
- json的数据类型
```
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

//上面对应下面

using null_t = bool;
using int_t = long long;
using bool_t = bool;
using double_t = long double;
using string_t = std::string;
using list_t = std::vector<JObject>;
using dict_t = std::unordered_map<std::string, JObject>;
```

## class JObject
- 类型的定义
```
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
```
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
//或者
std::vector<JObject> get = json.getList();
list_t get = json.getList();

//dict类型（std::unordered_map<std::string, JObject>）
JObject json["awa"] = 1;
long long get = json["awa"].getInt();
//或者
std::unordered_map<std::string, JObject> get = json.getDict();
dict_t get = json.getDict();
```

## class JParser
- 数据的读取
```
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

## class JWriter
- 数据的写出
```
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
