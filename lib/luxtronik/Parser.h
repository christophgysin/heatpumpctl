#pragma once
#include <string>
#include <list>
#include <ostream>

namespace parser {
    struct value {
        value() {}
        value(const std::string& key_, const std::string& val_) :
            key(key_),
            val(val_)
        {}
        std::string key;
        std::string val;
    };
    typedef std::list<value> value_list_t;

    struct section {
        section() {}
        section(const std::string& name_, const value_list_t& values_) :
            name(name_),
            values(values_)
        {}
        std::string name;
        value_list_t values;
    };
    typedef std::list<section> section_list_t;
    typedef section_list_t result_t;
}

std::ostream& operator<<(std::ostream& os, const parser::section_list_t& sections);
std::ostream& operator<<(std::ostream& os, const parser::section& section);
std::ostream& operator<<(std::ostream& os, const parser::value_list_t& values);
std::ostream& operator<<(std::ostream& os, const parser::value& value);

class Parser {
public:
    parser::result_t parse_strings(const std::string& str) const;
    void foo();

private:
    typedef std::list<std::string> lines;
    lines split_lines(const std::string& str, const std::string& line_delimiter) const;
};
