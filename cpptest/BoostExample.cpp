#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>

/* Boost Setup

1. Download from boost.org
2. Run the Install
3. From Project -> Properties (of BoostExample)
4. Configuration Properties -> C/C++ -> General -> Additional Include Directories.
5. Configuration Properties -> Linker -> Additional Library Directories
*/

int main()
{
    std::cout << boost::posix_time::second_clock::local_time() << std::endl;
}
