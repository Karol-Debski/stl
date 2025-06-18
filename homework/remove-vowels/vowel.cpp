#include "vowel.hpp"

std::string_view vowels{"AĄEĘIOUYaąeęiouy"};

void removeVowels(std::vector<std::string>& v)
{
    std::string::size_type n;

    for(auto& s : v)
    {
        for(const auto& c : vowels)
        {   
            while (true)
            {
                n = s.find(c);
                if(std::string::npos == n)
                {
                    break;
                }
                else
                {
                    s.erase(n, 1);
                }
            }    
        }
    }
}