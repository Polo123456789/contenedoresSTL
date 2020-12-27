#include "catch2/catch.hpp"
#include <psg/memory.hpp>

using namespace psg;//NOLINT

struct S { //NOLINT
    [[nodiscard]] virtual bool foo() const {
        return true;
    }

    virtual ~S() = default;
};

struct B : public S {
    [[nodiscard]] bool foo() const override {
        return false;
    }
};

TEST_CASE("psg::unique_ptr", "[memory] [unique_ptr]") {
    unique_ptr<int> ptr1(new int);
    unique_ptr<int> ptr2 = move(ptr1);
    ptr1 = nullptr;

    CHECK(!ptr1);
    CHECK(ptr2);

    unique_ptr<int> ptr3(nullptr);
    ptr3.reset(ptr2.release());
    CHECK(ptr3);

    unique_ptr<S> sptr(new S);
    CHECK(sptr->foo());

    unique_ptr<B> bptr(new B);
    CHECK(!bptr->foo());

    sptr = move(bptr);
    CHECK(!sptr->foo());
}
