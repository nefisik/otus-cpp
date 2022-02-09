#include "ip_filter.h"

int main()
{
    try
    {    
        auto ip_pool = get_data();
        print( sort(ip_pool) );
        print( get_1(ip_pool) );
        print( get_46_70(ip_pool) );
        print( get_any_46(ip_pool) );
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}