#include <iostream>
#include <map>

int main()
{
    // begin & end
    std::cout << "begin & end: " << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
        mp["a"] = 100;
        mp["c"] = 400;
        mp["z"] = 700;
        mp["b"] = 500;
        for (std::map<std::string, int>::iterator it = mp.begin(); it != mp.end(); it++)
            std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
        std::cout << std::endl;
    }
    // clear
    std::cout << std::endl << "clear: " << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
        mp["a"] = 100;
        mp["c"] = 400;
        mp["z"] = 700;
        mp["b"] = 500;
        for (std::map<std::string, int>::iterator it = mp.begin(); it != mp.end(); it++)
            std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
        std::cout << std::endl;
        mp.clear();
        mp["o"] = 111;
        mp["m"] = 777;
        mp["t"] = 555;
        for (std::map<std::string, int>::iterator it = mp.begin(); it != mp.end(); it++)
            std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
        std::cout << std::endl;
    }
    //
    // std::cout << std::endl << "" << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
    }
    //
    // std::cout << std::endl << "" << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
    }
    //
    // std::cout << std::endl << "" << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
    }
    //
    // std::cout << std::endl << "" << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
    }
    //
    // std::cout << std::endl << "" << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
    }
    //
    // std::cout << std::endl << "" << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
    }
    //
    // std::cout << std::endl << "" << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
    }
    //
    // std::cout << std::endl << "" << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
    }
}