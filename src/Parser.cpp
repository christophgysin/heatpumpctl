#include "Parser.h"
#include "values.h"

#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/finder.hpp>
#include <boost/algorithm/string/iter_find.hpp>

#include <ios>

void Parser::foo() {}

parser::result_t Parser::parse_strings(const std::string& str) const
{
    parser::result_t result;

    size_t index = 0;
    const std::string line_delimiter("\r\n");
    BOOST_FOREACH(const std::string& line, split_lines(str, line_delimiter))
    {
        parser::section section;

        typedef boost::char_separator<char> separator_t;
        typedef boost::token_iterator_generator<separator_t>::type iterator_t;
        separator_t separator(";");
        iterator_t begin = boost::make_token_iterator<std::string>(line.begin(), line.end(), separator);
        iterator_t end;

        if(begin == end)
            continue;

        std::string code = *begin++;

        if(!values::headings.count(code))
        {
            //std::cerr << "warning: no heading found for: " << code << std::endl;
            continue;
        }

        if(values::subheadings.count(code))
        {
            //std::cerr << "info: subheading found for: " << code << std::endl;
            code = *begin++;

            if(!values::headings.count(code))
            {
                //std::cerr << "warning: no heading found for: " << code << std::endl;
                continue;
            }
        }

        section.name = values::headings[code];
        //std::cerr << "info: heading found: " << code << " -> " << section.name << std::endl;

        BOOST_FOREACH(const std::string& token, std::make_pair<>(begin, end))
        {
            //std::cerr << "info: token[" << index << "]: " << token << std::endl;

            if(values::names.count(section.name))
            {
                if(index >= values::names[section.name].size())
                    continue;

                std::string key = values::names[section.name][index++];
                parser::value value(key, token);

                //std::cerr << "info: key: " << key << ", value: " << token << std::endl;

                section.values.push_back(value);
            }
        }

        result.push_back(section);
    }
    return result;
}

Parser::lines Parser::split_lines(const std::string& str, const std::string& line_delimiter) const
{
    std::list<std::string> lines;
    boost::iter_split(lines, str, boost::first_finder(line_delimiter, boost::is_iequal()));

    return lines;
}

std::ostream& operator<<(std::ostream& os, const parser::section_list_t& sections)
{
    BOOST_FOREACH(const parser::section& section, sections)
        os << section << std::endl;

    return os;
}

std::ostream& operator<<(std::ostream& os, const parser::section& section)
{
    os << "[" << section.name << "]" << std::endl << section.values;

    return os;
}

std::ostream& operator<<(std::ostream& os, const parser::value_list_t& values)
{
    BOOST_FOREACH(const parser::value& value, values)
        os << value << std::endl;

    return os;
}

std::ostream& operator<<(std::ostream& os, const parser::value& value)
{
    os << value.key << ": " << value.val;

    return os;
}

