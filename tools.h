
#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <string>

using namespace std;



class tools
{
    public:
        tools();
        inline bool is_base64(unsigned char c)
        {
            return (isalnum(c) || (c == '+') || (c == '/'));
        }
        string base64_encode(unsigned char const* , unsigned int len);
        string base64_encode(unsigned char const* , unsigned int len,const bool Scape);
        string base64_decode(string const& s);

        virtual ~tools();

        static string itoa(int num);

        private:
            string base64_chars ;
};


#endif
