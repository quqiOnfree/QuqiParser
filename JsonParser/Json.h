#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>
#include <variant>
#include <string_view>
#include <exception>

namespace qjson
{
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

	class JObject;

	using null_t = bool;
	using int_t = long long;
	using bool_t = bool;
	using double_t = long double;
	using string_t = std::string;
	using list_t = std::vector<JObject>;
	using dict_t = std::unordered_map<std::string, JObject>;

	class JObject
	{
	public:
		JObject()
			:m_type(JValueType::JNull),
			m_value(new value_t)
		{
		}
		JObject(const JObject& jo)
			:m_type(jo.m_type),
			m_value(new value_t)
		{
			switch (jo.m_type)
			{
			case JValueType::JString:
				*m_value = *std::get_if<string_t>(jo.m_value);
				break;
			case JValueType::JList:
				*m_value = *std::get_if<list_t>(jo.m_value);
				break;
			case JValueType::JDict:
				*m_value = *std::get_if<dict_t>(jo.m_value);
				break;
			default:
				*m_value = *jo.m_value;
				break;
			}
		}
		JObject(JObject&& jo) noexcept
			:m_type(jo.m_type)
		{
			m_value = jo.m_value;
			jo.m_value = nullptr;
		}
		JObject(long long value)
			:m_type(JValueType::JInt),
			m_value(new value_t)
		{
			*m_value = value;
		}
		JObject(long value)
			:m_type(JValueType::JInt),
			m_value(new value_t)
		{
			*m_value = static_cast<long long>(value);
		}
		JObject(int value)
			:m_type(JValueType::JInt),
			m_value(new value_t)
		{
			*m_value = static_cast<long long>(value);
		}
		JObject(short value)
			:m_type(JValueType::JInt),
			m_value(new value_t)
		{
			*m_value = static_cast<long long>(value);
		}
		JObject(bool value)
			:m_type(JValueType::JBool),
			m_value(new value_t)
		{
			*m_value = value;
		}
		JObject(long double value)
			:m_type(JValueType::JDouble),
			m_value(new value_t)
		{
			*m_value = value;
		}
		JObject(double value)
			:m_type(JValueType::JDouble),
			m_value(new value_t)
		{
			*m_value = static_cast<long double>(value);
		}
		JObject(float value)
			:m_type(JValueType::JDouble),
			m_value(new value_t)
		{
			*m_value = static_cast<long double>(value);
		}
		JObject(std::string_view data)
			:m_type(JValueType::JString),
			m_value(new value_t)
		{
			*m_value = std::string(data);
		}

		~JObject()
		{
			if (m_value != nullptr)
				delete m_value;
		}

		operator long double() const
		{
			return getDouble();
		}
		operator double() const
		{
			return getDouble();
		}
		operator float() const
		{
			return getDouble();
		}
		operator long long() const
		{
			return getInt();
		}
		operator long() const
		{
			return getInt();
		}
		operator int() const
		{
			return getInt();
		}
		operator short() const
		{
			return getInt();
		}
		operator bool() const
		{
			return getBool();
		}
		operator std::string() const
		{
			return getString();
		}
		operator list_t() const
		{
			return getList();
		}
		operator dict_t() const
		{
			return getDict();
		}

		JObject& operator =(const JObject& jo)
		{
			if (this == &jo)
				return *this;

			m_type = jo.m_type;
			switch (jo.m_type)
			{
			case JValueType::JString:
				*m_value = *std::get_if<string_t>(jo.m_value);
				break;
			case JValueType::JList:
				*m_value = *std::get_if<list_t>(jo.m_value);
				break;
			case JValueType::JDict:
				*m_value = *std::get_if<dict_t>(jo.m_value);
				break;
			default:
				*m_value = *jo.m_value;
				break;
			}

			return *this;
		}
		JObject& operator =(JObject&& jo) noexcept
		{
			if (this == &jo)
				return *this;

			m_type = jo.m_type;
			m_value = jo.m_value;
			jo.m_value = nullptr;

			return *this;
		}
		/*bool operator ==(const JObject& jo)
		{
			return true;
		}*/
		bool operator ==(JValueType type)
		{
			if (m_type == type)
				return true;
			return false;
		}

		JObject& operator[](size_t itor)
		{
			if (m_type == JValueType::JNull)
			{
				m_type = JValueType::JList;
				*m_value = list_t();
				std::get_if<list_t>(m_value)->resize(itor + 1);
				return (*std::get_if<list_t>(m_value))[itor];
			}
			else if (m_type == JValueType::JList)
			{
				list_t* local = std::get_if<list_t>(m_value);
				if (itor >= local->size())
					local->resize(itor + 1);
				return (*local)[itor];
			}
			else
			{
				throw std::exception("The type isn't JList, 类型不是JList.");
			}
		}
		JObject& operator[](int itor)
		{
			return operator[](size_t(itor));
		}
		JObject& operator[](const char* str)
		{
			if (m_type == JValueType::JNull)
			{
				m_type = JValueType::JDict;
				*m_value = dict_t();
				return (*std::get_if<dict_t>(m_value))[str];
			}
			else if (m_type == JValueType::JDict)
			{
				return (*std::get_if<dict_t>(m_value))[str];
			}
			else
			{
				throw std::exception("The type isn't JDict, 类型不是JDict.");
			}
		}

		void push_back(const JObject& jo)
		{
			if (m_type == JValueType::JNull)
			{
				m_type = JValueType::JList;
				*m_value = list_t();
				std::get_if<list_t>(m_value)->push_back(jo);
			}
			else if (m_type == JValueType::JList)
			{
				std::get_if<list_t>(m_value)->push_back(jo);
			}
			else
			{
				throw std::exception("The type isn't JList, 类型不是JList.");
			}
		}

		void push_back(JObject&& jo)
		{
			if (m_type == JValueType::JNull)
			{
				m_type = JValueType::JList;
				*m_value = list_t();
				std::get_if<list_t>(m_value)->push_back(std::move(jo));
			}
			else if (m_type == JValueType::JList)
			{
				std::get_if<list_t>(m_value)->push_back(std::move(jo));
			}
			else
			{
				throw std::exception("The type isn't JList, 类型不是JList.");
			}
		}

		void pop_back()
		{
			if (m_type == JValueType::JNull)
			{
				throw std::exception("The type isn't JList, 类型不是JList.");
			}
			else if (m_type == JValueType::JList)
			{
				list_t* local = std::get_if<list_t>(m_value);
				if (local->empty())
					throw std::exception("The JList is empty, JList为空.");
				local->pop_back();
			}
			else
			{
				throw std::exception("The type isn't JList, 类型不是JList.");
			}
		}

		JValueType getType() const
		{
			return m_type;
		}

		list_t& getList() const
		{
			if (m_type == JValueType::JList)
			{
				return *std::get_if<list_t>(m_value);
			}
			else
				throw std::exception("The type isn't JList, 类型不是JList.");
		}

		dict_t& getDict() const
		{
			if (m_type == JValueType::JDict)
			{
				return *std::get_if<dict_t>(m_value);
			}
			else
				throw std::exception("The type isn't JDict, 类型不是JDict.");
		}

		long long& getInt() const
		{
			if (m_type == JValueType::JInt)
			{
				return *std::get_if<int_t>(m_value);
			}
			else
			{
				throw std::exception("This JObject isn't int, 此JObject不是整形");
			}
		}

		long double& getDouble() const
		{
			if (m_type == JValueType::JDouble)
			{
				return *std::get_if<double_t>(m_value);
			}
			else
			{
				throw std::exception("This JObject isn't double, 此JObject不是浮点数");
			}
		}

		bool& getBool() const
		{
			if (m_type == JValueType::JBool)
			{
				return *std::get_if<bool_t>(m_value);
			}
			else
			{
				throw std::exception("This JObject isn't bool, 此JObject不是布尔值");
			}
		}

		std::string& getString() const
		{
			if (m_type == JValueType::JString)
			{
				return *std::get_if<string_t>(m_value);
			}
			else
			{
				throw std::exception("This JObject isn't string, 此JObject不是字符串");
			}
		}

	protected:
		using value_t = std::variant<int_t, bool_t, double_t, string_t, list_t, dict_t>;
	private:
		value_t* m_value;
		JValueType m_type;
	};
}
