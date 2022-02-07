#include "lib.h"

#include <gtest/gtest.h>

TEST(Version, Test_Valid_Version) {
	ASSERT_TRUE(version_patch() > 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
