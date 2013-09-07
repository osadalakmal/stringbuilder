#ifndef INCLUDED_STRINGBUILDER_H
#define INCLUDED_STRINGBUILDER_H

#include <string>  // for std::string
#include <vector>  // for std::vector
#include <numeric> // for std::accumulate

class StringBuilder {

    std::string d_str;

    //NOT IMPLEMENTED
    StringBuilder(const StringBuilder&);
    StringBuilder & operator=(const StringBuilder&);
public:

    StringBuilder() : d_str("") {
    }

    StringBuilder(const std::string& str) : d_str(str) {
    }

    const std::string& getString() {
        return d_str;
    }

};

#endif
