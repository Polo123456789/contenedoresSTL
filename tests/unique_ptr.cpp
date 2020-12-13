#include <psg/memory.hpp>

int main(void) {
    psg::unique_ptr<int> ptr1;
    psg::unique_ptr<int> ptr2 = psg::move(ptr1);
    ptr1 = nullptr;
    return 0;
}
