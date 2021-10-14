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
    // count
    std::cout << std::endl << "cout: " << std::endl << std::endl;
    {
        std::map<char , int> mp;
        mp['a'] = 100;
        mp['c'] = 400;
        mp['z'] = 700;
        mp['h'] = 500;
        mp['x'] = 100;
        mp['m'] = 400;
        mp['t'] = 700;
        mp['j'] = 500;
        for (char c = 'a'; c <= 'z'; c++)
        {
            std::cout << "char : " << c;
            if (mp.count(c) > 0)
                std::cout << " is an element of the map." << std::endl;
            else
                std::cout << " is not an element of the map." << std::endl;
        }
    }
    // empty
    std::cout << std::endl << "empty" << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
        mp["a"] = 100;
        mp["c"] = 400;
        mp["z"] = 700;
        mp["h"] = 500;
        mp["x"] = 100;
        mp["m"] = 400;
        mp["t"] = 700;
        mp["j"] = 500;
        std::cout << "Map 'mp' is empty: " << (mp.empty() ? "Yes" : "NO") << std::endl;
        while (!mp.empty())
            mp.erase(mp.begin());
        std::cout << "Map 'mp' is empty: " << (mp.empty() ? "Yes" : "NO") << std::endl;
    }
    // equal_range
    std::cout << std::endl << "equal_range" << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
        mp["a"] = 100;
        mp["c"] = 200;
        mp["z"] = 300;
        mp["h"] = 400;
        mp["x"] = 500;
        mp["m"] = 600;
        mp["t"] = 700;
        mp["j"] = 800;
        std::pair<std::map<std::string, int>::iterator, std::map<std::string, int>::iterator> ret;
        ret = mp.equal_range("h");

        std::cout << "lower bound points to: " << ret.first->first << " => " << ret.first->second << std::endl;

        std::cout << "upper bound points to: " << ret.second->first << " => " << ret.second->second << std::endl;
    }
    // erase & find
    std::cout << std::endl << "erase & find: " << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
        mp["a"] = 100;
        mp["c"] = 200;
        mp["z"] = 300;
        mp["h"] = 400;
        mp["x"] = 500;
        mp["m"] = 600;
        mp["t"] = 700;
        mp["j"] = 800;

        std::cout << "Before erase map: " << std::endl;
        for (std::map<std::string, int>::iterator it = mp.begin(); it != mp.end(); it++)
            std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
        std::cout << std::endl;

        std::map<std::string, int>::iterator it = mp.find("c");
        mp.erase(it); // erase iterator
        mp.erase("h");  // erase key
        it = mp.find("x");
        mp.erase(it, mp.end()); // erase range

        std::cout << "After erase map: " << std::endl;
        for (std::map<std::string, int>::iterator it = mp.begin(); it != mp.end(); it++)
            std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
        std::cout << std::endl;

        std::cout << "j => " << mp.find("j")->second << std::endl;
        std::cout << "t => " << mp.find("t")->second << std::endl;
        std::cout << "m => " << mp.find("m")->second << std::endl;
    }
    // get_allocator 
    std::cout << std::endl << "get_allocator: " << std::endl << std::endl;
    {
        int psize;
        std::map<std::string, int> mp;
        std::pair<const std::string, int> *pointer;

        pointer = mp.get_allocator().allocate(7);

        psize = sizeof(std::map<std::string, int>::value_type) * 7;
        std::cout << "The allocated array has a size of: " << psize << " bytes" << std::endl;

        mp.get_allocator().deallocate(pointer, 7);
    }
    // insert 
    std::cout << std::endl << "insert: " << std::endl << std::endl;
    {
        std::map<std::string, int> mp;

        // insertion with single parameter
        mp.insert( std::pair<std::string, int>("z",800) );
        mp.insert( std::pair<std::string, int>("t", 600) );

        std::pair<std::map<std::string, int>::iterator, bool> ret;

        ret = mp.insert( std::pair<std::string, int> ("x", 700) );

        if (ret.second == false) {
            std::cout << "element 'x' aleardy existed, with a value of: " << ret.first->second << std::endl; 
        }
        else {
            std::cout << "element 'x' inserted successfully." << std::endl;
        }

        std::cout << std::endl << "After insertion with single parameter: " << std::endl;
        for (std::map<std::string, int>::iterator it = mp.begin(); it != mp.end(); it++)
            std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
        std::cout << std::endl;


        // insertion with hint position
        std::map<std::string, int>::iterator it = mp.begin();
        mp.insert(it, std::pair<std::string, int>("a", 100));
        mp.insert(it, std::pair<std::string, int>("m", 500));

        std::cout << std::endl << "After insertion with hint position: " << std::endl;
        for (std::map<std::string, int>::iterator it = mp.begin(); it != mp.end(); it++)
            std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
        std::cout << std::endl;

        // insertion with range
        std::map<std::string, int> sec_mp;
        sec_mp.insert( mp.begin(), mp.find("x"));
        std::cout << std::endl << "After range insertion sec_map contains: " << std::endl;
        for (std::map<std::string, int>::iterator it = sec_mp.begin(); it != sec_mp.end(); it++)
            std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
        std::cout << std::endl;
    }
    // key_comp
    std::cout << std::endl << "key_comp" << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
        std::map<std::string, int>::key_compare cmp = mp.key_comp();

        mp["a"] = 100;
        mp["c"] = 200;
        mp["z"] = 300;
        mp["h"] = 400;

        std::cout << "Map contains: " << std::endl;
        std::string highest = mp.rbegin()->first;

        std::map<std::string, int>::iterator it = mp.begin();
        do {
            std::cout << it->first << " => " << it->second << std::endl;
        } while (cmp((*it++).first, highest));

        std::cout << std::endl;
    }
    // lower_bound & upper_bound
    std::cout << std::endl << "lower_bound & upper_bound: " << std::endl << std::endl;
    {
        std::map<std::string, int>::iterator itlow, itupp;
        std::map<std::string, int> mp;
        mp["a"] = 100;
        mp["c"] = 200;
        mp["z"] = 300;
        mp["h"] = 400;
        mp["x"] = 500;
        mp["m"] = 600;
        mp["t"] = 700;
        mp["j"] = 800;

        itlow = mp.lower_bound("j");
        itupp = mp.upper_bound("x");

        mp.erase(itlow, itupp);
        for (std::map<std::string, int>::iterator it = mp.begin(); it != mp.end(); it++)
            std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
        std::cout << std::endl;
    }
    // max_size
    std::cout << std::endl << "max_size: " << std::endl << std::endl;
    {
        std::map<int, int> mp;

        if (mp.max_size() > 1000)
        {
            for (int i = 0; i < 1000; i++)
                mp[i] = i + 1;
            std::cout << "The Map Contains 1000 elements." << std::endl;
        }
        else
            std::cout << "The Map could not hold 1000 elements." << std::endl;
    }
    // operator=
    std::cout << std::endl << "operator=: " << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
        std::map<std::string, int> sec_mp; 
        mp["a"] = 100;
        mp["c"] = 200;
        mp["z"] = 300;
        mp["h"] = 400;
        mp["x"] = 500;
        mp["m"] = 600;
        mp["t"] = 700;
        mp["j"] = 800;

        sec_mp = mp;
        // mp.clear();
        mp = std::map<std::string, int>();

        std::cout << "Size of mp: " << mp.size() << std::endl;
        std::cout << "Size of sec_mp: " << sec_mp.size() << std::endl;
    }
    // operator[]
    std::cout << std::endl << "operator[]: " << std::endl << std::endl;
    {
        std::map<std::string, std::string> mp;
        mp["x"] = "this case contains 500";
        mp["m"] = "this case contains 600";
        mp["j"] = "this case contains 800";

        std::cout << "mp[\"x\"]: " << mp["x"] <<std::endl;
        std::cout << "mp[\"m\"]: " << mp["m"] <<std::endl;
        std::cout << "mp[\"j\"]: " << mp["j"] <<std::endl;
        std::cout << "mp[\"o\"]: " << mp["o"] <<std::endl;

        std::cout << "mp now contains: " << mp.size() << " elements." << std::endl;
    }
    // rbegin && rend
    std::cout << std::endl << "rbegin && rend: " << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
        mp["a"] = 100;
        mp["c"] = 200;
        mp["z"] = 300;
        mp["h"] = 400;
        mp["x"] = 500;
        mp["m"] = 600;
        mp["t"] = 700;
        mp["j"] = 800;
        
        std::map<std::string, int>::reverse_iterator rit;
        for (rit = mp.rbegin(); rit != mp.rend(); rit++)
            std::cout << rit->first << " => " << rit->second << std::endl;
    }
    // size
    std::cout << std::endl << "size: " << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
        mp["a"] = 100;
        mp["c"] = 200;
        mp["z"] = 300;
        mp["h"] = 400;
        mp["x"] = 500;
        mp["m"] = 600;
        mp["t"] = 700;
        mp["j"] = 800;

        std::cout << "The Map size is: " << mp.size() << std::endl;
    }
    // swap
    std::cout << std::endl << "swap: " << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
        std::map<std::string, int> sec;
        mp["a"] = 100;
        mp["b"] = 200;
        mp["c"] = 300;
        mp["d"] = 400;

        sec["v"] = 900;
        sec["w"] = 500;
        sec["x"] = 600;
        sec["y"] = 700;
        sec["z"] = 800;

        mp.swap(sec);
        std::cout << "After Swap, The Map mp contains: " << std::endl;
        for (std::map<std::string, int>::iterator it = mp.begin(); it != mp.end(); it++)
            std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
        std::cout << "After Swap, The Map sec contains: " << std::endl;
        for (std::map<std::string, int>::iterator it = sec.begin(); it != sec.end(); it++)
            std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
        std::cout << std::endl;
    }
    // value_comp
    std::cout << std::endl << "value_comp: " << std::endl << std::endl;
    {
        std::map<std::string, int> mp;
        mp["a"] = 100;
        mp["b"] = 200;
        mp["c"] = 300;
        mp["d"] = 400;

        std::cout << "The Map mp contains: " << std::endl;
        std::map<std::string, int>::value_compare vcmp = mp.value_comp();

        std::pair<std::string, int> highest = *mp.rbegin();

        std::map<std::string, int>::iterator it = mp.begin();

        do {
            std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
        } while (vcmp(*it++, highest));
    }
}