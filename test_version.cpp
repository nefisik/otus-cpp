#include "ip_filter.h"

#include <gtest/gtest.h>
#include "test_data.h"

TEST(Sort, Less) {
	ASSERT_TRUE(sort(test::sort) == result::sort);
}

TEST(Get, _1) {
	ASSERT_TRUE(get_1(test::_1) == result::_1);
}

TEST(Get, _46_70) {
	ASSERT_TRUE(get_46_70(test::_46_70) == result::_46_70);
}

TEST(Get, Any_46) {
	ASSERT_TRUE(get_any_46(test::any_46) == result::any_46);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
