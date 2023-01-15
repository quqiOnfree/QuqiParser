# JsonParser Json解析器

## 解析器的基本性质
- 支持c++20以上版本
- 在网上看到了一个b站up主的[json解析器](https://github.com/ACking-you/MyUtil/tree/master/json-parser)，觉得很不错，就按照他的思想做了一个新的
- 还没测效率，估计不低（比jsoncpp快就行）
- 报错使用std::exception，如果linux报错就替换成logic_error
- 有三个Class，分别是JObject（用于存Json数据）、JParser（Json数据读取）、JWriter（Json数据写出）

## 解析器的使用
### json的数据类型
- enum类型
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

```
- enum对应下面的数据类型
```
using null_t = bool;
using int_t = long long;
using bool_t = bool;
using double_t = long double;
using string_t = std::string;
using list_t = std::vector<JObject>;
using dict_t = std::unordered_map<std::string, JObject>;
```

### class JObject
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
//判断数据类型
json.getType()
返回enum class JValueType

//int类型（long long）
JObject json = 1;
long long get = json.getInt();
//or
long long get = json;

//double类型（long double）
long double get = json.getDouble();
//or
long double get = json;

//bool类型（bool）
JObject json = true;
bool get = json.getBool();
//or
bool get = json;

//string类型（std::string）
JObject json = "Hello world!";
std::string get = json.getString();
//or
std::string get = json;

//list类型（std::vector<JObject>）
JObject json[0] = 1;

long long get = json[0].getInt();
long long get = json[0];
//或者
std::vector<JObject> get = json.getList();
list_t get = json.getList();
//or
list_t get = json;
long long getnum = get[0];

//dict类型（std::unordered_map<std::string, JObject>）
JObject json["awa"] = 1;
long long get = json["awa"].getInt();
//or
long long get = json["awa"];
//或者
std::unordered_map<std::string, JObject> get = json.getDict();
dict_t get = json.getDict();
//or
dict_t get = json;
```

### class JParser
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

### class JWriter
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
