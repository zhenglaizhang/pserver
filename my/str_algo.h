//
// Created by darinzh on 10/27/2015.
//

#ifndef CXX_STR_ALGO_H
#define CXX_STR_ALGO_H

#include <bits/stringfwd.h>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/compare.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <algorithm>
#include "conf.h"


MY_NAMESPACE_BEGIN

    bool str_iequals(const std::string &str1, const std::string &str2) {
        return boost::iequals(str1, str2);
    }

    bool str_iequals2(const std::string &str1, const std::string &str2) {
        return str1.size() == str2.size() && std::equal(
                str1.begin(),
                str1.end(),
                str2.begin(),
                boost::is_iequal()
        );
    }

    std::string to_upper_copy(const std::string &str) {
        return std::move(boost::to_upper_copy(str));
    }

MY_NAMESPACE_END


#endif //CXX_STR_ALGO_H
