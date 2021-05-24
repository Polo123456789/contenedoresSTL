#include <vector>
#include <psg/vector.hpp>

//using namespace std;
using namespace psg;

int main(void) {
    constexpr vector<int>::size_type size = 10;
    vector<int>                      v(size, 10);
}
