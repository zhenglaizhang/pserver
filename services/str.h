//
// Created by darinzh on 10/27/2015.
//

#ifndef CXX_STR_H
#define CXX_STR_H

#include <string>
#include <algorithm>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/compare.hpp>
#include <boost/algorithm/string/case_conv.hpp>

bool iequal(const std::string &str1, const std::string &str2) {
#ifdef SIMPLE
    return boost::iequals(s1, s2);
#else
    return str1.size() == str2.size() && std::equal(
            str1.begin(),
            str1.end(),
            str2.begin(),
            boost::is_iequal());
    //  boost::is_iequal predicate compares two characters in a case-insensitive way.
#endif
}

std::string to_lower(const std::string &str) {
    return boost::to_lower_copy(str);
}

std::string to_upper(const std::string &str) {
    return boost::to_upper_copy(str);
}


#endif //CXX_STR_H
