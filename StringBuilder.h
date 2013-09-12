#ifndef INCLUDED_STRINGBUILDER_H
#define INCLUDED_STRINGBUILDER_H

#include <string>  
#include <vector> 
#include <memory>
#include <array>
#include <list>
#include <iterator>
#include <algorithm>
#include <iostream>

template <typename CHAR=char, typename ALLOCATOR=std::allocator<CHAR> >
class StringBuilder {

    typedef std::vector<CHAR> STRING_HOLDER;
    typedef std::list<STRING_HOLDER> DATA_HOLDER;
    long long d_dataLen;
    DATA_HOLDER d_data;
    ALLOCATOR d_alloc;
    
    StringBuilder & append(const std::string &str) {
        d_data.emplace_back(str.begin(),str.end());
        d_dataLen += str.length();
        return *this; // allow chaining.
    }

    //NOT IMPLEMENTED
    StringBuilder(const StringBuilder&);
    StringBuilder & operator=(const StringBuilder&);
public:

    StringBuilder() : d_data(),d_dataLen(0) {
    }

    StringBuilder(const std::string& str) : d_data(),d_dataLen(0) {
        d_data.emplace_back(str.begin(),str.end());
        d_dataLen += str.length();        
    }

    StringBuilder & Append(const std::string &str) {
        return append(str);
    }
    template<class INPUT_ITERATOR>
    StringBuilder & Add(const INPUT_ITERATOR &first, const INPUT_ITERATOR &afterLast) {
         for(INPUT_ITERATOR f = first; f != afterLast; ++f) {
            append(*f);
        }
        return *this; // allow chaining.
    }
    StringBuilder & AppendLine(const std::string &src) {
        static CHAR lineEnd[] { '\n', 0 };
        return append(src).append(lineEnd);
    }

    StringBuilder & AppendLine() {
        static CHAR lineEnd[] { '\n', 0 };
        return append(lineEnd);
    }

    const std::string getString() {
        std::string retVal(d_dataLen,'\0');
        std::string::iterator it = retVal.begin();
        for_each(d_data.begin(), d_data.end(), 
                [retVal,&it](STRING_HOLDER& strVec) {
                            it = std::copy_n(strVec.begin(),strVec.size(),it);
                        });
        return retVal;
    }
};

#endif
