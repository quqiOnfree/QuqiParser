#include "Ini.h"
#include <QuqiParser/Ini.h>

#define INI_NAMESPACE_START namespace qini {
#define INI_NAMESPACE_END }

INI_NAMESPACE_START

INIObject::Section::Section(std::unordered_map<std::string, std::string>& section) :
	m_keys(section)
{}

INIObject::Section::iterator::iterator(const std::unordered_map<std::string, std::string>::iterator& itor) :
	m_itor(itor)
{}

INIObject::Section::iterator::iterator(std::unordered_map<std::string, std::string>::iterator&& itor) :
	m_itor(std::move(itor))
{}

INIObject::Section::iterator& INIObject::Section::iterator::operator ++()
{
	m_itor++;
	return *this;
}

std::string INIObject::Section::iterator::operator *()
{
	return std::move(m_itor->second);
}

std::string& INIObject::Section::operator [](const std::string& keyName)
{
	return m_keys[keyName];
}

const std::string& INIObject::Section::operator [](const std::string& keyName) const
{
	if (m_keys.find(keyName) == m_keys.end()) throw std::logic_error("Invalid Keyword");
	return m_keys[keyName];
}

INIObject::Section::iterator INIObject::Section::begin()
{
	return { std::move(m_keys.begin()) };
}

INIObject::Section::iterator INIObject::Section::end()
{
	return { std::move(m_keys.end()) };
}

bool operator ==(const INIObject::Section::iterator& a, const INIObject::Section::iterator& b)
{
	return a.m_itor == b.m_itor;
}

bool operator !=(const INIObject::Section::iterator& a, const INIObject::Section::iterator& b)
{
	return a.m_itor != b.m_itor;
}

INIObject::iterator::iterator(const std::unordered_map<std::string, std::unordered_map<std::string, std::string>>::iterator& itor) :
	m_itor(itor)
{}

INIObject::iterator::iterator(std::unordered_map<std::string, std::unordered_map<std::string, std::string>>::iterator&& itor) :
	m_itor(std::move(itor))
{}

INIObject::iterator& INIObject::iterator::operator ++()
{
	m_itor++;
	return *this;
}

INIObject::Section INIObject::iterator::operator *()
{
	return { m_itor->second };
}

bool operator ==(const INIObject::iterator& a, const INIObject::iterator& b)
{
	return a.m_itor == b.m_itor;
}

bool operator !=(const INIObject::iterator& a, const INIObject::iterator& b)
{
	return a.m_itor != b.m_itor;
}

INIObject::INIObject(const INIObject& ob) :
	m_sections(ob.m_sections)
{}

INIObject::INIObject(INIObject&& ob) noexcept :
	m_sections(std::move(ob.m_sections))
{}

INIObject& INIObject::operator =(const INIObject& ob)
{
	if (this == &ob)
		return *this;

	m_sections = ob.m_sections;
	return *this;
}

INIObject& INIObject::operator =(INIObject&& ob) noexcept
{
	if (this == &ob)
		return *this;

	m_sections = std::move(ob.m_sections);
	return *this;
}

INIObject::Section INIObject::operator [](const std::string sectionName)
{
	if (m_sections.find(sectionName) == m_sections.end()) throw std::logic_error("Invalid Section Name");
	return Section(m_sections[sectionName]);
}

INIObject::iterator INIObject::begin()
{
	return { std::move(m_sections.begin()) };
}

INIObject::iterator INIObject::end()
{
	return { std::move(m_sections.end()) };
}

bool operator ==(const INIObject& ia, const INIObject& ib)
{
	return ia.m_sections == ib.m_sections;
}

bool operator !=(const INIObject& ia, const INIObject& ib)
{
	return ia.m_sections != ib.m_sections;
}

INIObject INIParser::parse(std::string_view data)
{
	INIObject localObject;
	long long error_line = 0;

	std::string localSection;
	for (auto i = data.begin(); i != data.end(); i++)
	{
		if (!skipSpace(i, data, error_line))
			break;

		if (*i == '[')
		{
			i++;
			if (!skipSpace(i, data, error_line))
				throw std::logic_error(get_logic_error_string(error_line));

			localSection = getString(i, data, error_line);

			if (!skipSpace(i, data, error_line))
				throw std::logic_error(get_logic_error_string(error_line));

			if (*i == ']')
				i++;
			else
				throw std::logic_error(get_logic_error_string(error_line));
		}
		else if (*i == '=')
		{
			throw std::logic_error(get_logic_error_string(error_line));
		}
		else
		{
			if (localSection.empty())
				throw std::logic_error(get_logic_error_string(error_line));

			std::string localKey = getString(i, data, error_line);

			if (!skipSpace(i, data, error_line))
				throw std::logic_error(get_logic_error_string(error_line));

			if (*i == '=')
				i++;
			else
				throw std::logic_error(get_logic_error_string(error_line));

			if (!skipSpace(i, data, error_line))
				throw std::logic_error(get_logic_error_string(error_line));

			localObject.m_sections[localSection][localKey] = getString(i, data, error_line);
		}
	}

	return localObject;
}

INIObject qini::INIParser::fastParse(std::string_view data)
{
	static INIParser parser;
	return parser.parse(data);
}

INIObject qini::INIParser::fastParse(std::ifstream& infile)
{
	infile.seekg(0, std::ios_base::end);
	size_t size = infile.tellg();
	infile.seekg(0, std::ios_base::beg);
	std::string buffer;
	buffer.resize(size);
	infile.read(buffer.data(), size);
	infile.close();

	return std::move(INIParser::fastParse(buffer));
}

bool INIParser::skipSpace(std::string_view::iterator& i, std::string_view data, long long& error_line)
{
	while (i != data.end() && (*i == ' ' || *i == '\n' || *i == '\t' || *i == ';' || *i == '#'))
	{
		if (*i == ';' || *i == '#')
		{
			for (; i != data.end() && *i != '\n'; i++) {}
		}
		else
		{
			if (*i == '\n') error_line++;
			i++;
		}
	}

	return i != data.end();
}

std::string INIParser::getString(std::string_view::iterator& i, std::string_view data, long long error_line)
{
	std::string localString;
	while (i != data.end() && (*i != ' ' && *i != '\n' && *i != '\t' && *i != '[' && *i != ']' && *i != '=' && *i != ';'))
	{
		localString += *i;
		i++;
	}
	return localString;
}

std::string qini::INIParser::get_logic_error_string(long long error_line)
{
	return std::format("Invalid Input, in line {}", error_line);
}

std::string INIWriter::write(const INIObject& ob)
{
	std::string localString;
	for (const auto& [section, keys] : ob.m_sections)
	{
		localString += std::format("[{}]\n", section);
		for (const auto& [key, value] : keys)
		{
			localString += std::format("{}={}\n", key, value);
		}
	}
	return localString;
}

bool INIWriter::write(const INIObject& ob, std::ofstream& file)
{
	if (!file)
		return false;

	file.clear();
	for (const auto& [section, keys] : ob.m_sections)
	{
		file << std::format("[{}]\n", section);
		for (const auto& [key, value] : keys)
		{
			file << std::format("{}={}\n", key, value);
		}
	}
	file << std::endl;

	return true;
}

std::string INIWriter::fastWrite(const INIObject& ob)
{
	static INIWriter writer;
	return writer.write(ob);
}

bool INIWriter::fastWrite(const INIObject& ob, std::ofstream& file)
{
	static INIWriter writer;
	return writer.write(ob, file);
}

INI_NAMESPACE_END