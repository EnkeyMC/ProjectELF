//
// Created by MOmac on 24.03.2019.
//

#include <gtest/gtest.h>

#include "Memstream.h"

TEST(MemstreamTest, pass_by_constructor) {
    const char input[] = "test\x00test";

    memstream stream{input, sizeof(input)};

    stream.seekg(0, std::istream::end);

    EXPECT_EQ(stream.tellg(), sizeof(input));

    stream.seekg(0);
}
