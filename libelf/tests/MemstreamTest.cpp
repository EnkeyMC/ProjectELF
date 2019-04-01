//
// Created by MOmac on 24.03.2019.
//

#include <gtest/gtest.h>

#include "Memstream.h"

TEST(MemstreamTest, pass_by_constructor_size_check) {
    const char input[] = "test\x00test";

    memstream stream{input, sizeof(input)};

    stream.seekg(0, std::istream::end);

    EXPECT_EQ(stream.tellg(), sizeof(input));
}

TEST(MemstreamTest, pass_by_constructor_read) {
    const char input[] = "test\x00test";
    char buff[sizeof(input)];

    memstream stream{input, sizeof(input)};

    stream.read(buff, sizeof(buff));

    for (int i = 0; i < sizeof(input); ++i) {
        EXPECT_EQ(input[i], buff[i]);
    }
}

TEST(MemstreamTest, set_data_size_check) {
    const char input[] = "test\x00test";

    memstream stream{};
    stream.set_data(input, sizeof(input));

    stream.seekg(0, std::istream::end);

    EXPECT_EQ(stream.tellg(), sizeof(input));
}

TEST(MemstreamTest, set_data_read) {
    const char input[] = "test\x00test";
    char buff[sizeof(input)];

    memstream stream{};
    stream.set_data(input, sizeof(input));

    stream.read(buff, sizeof(buff));

    for (int i = 0; i < sizeof(input); ++i) {
        EXPECT_EQ(input[i], buff[i]);
    }
}

TEST(MemstreamTest, seek_beg) {
    const char input[] = "test\x00test";
    char buff[2];

    memstream stream{input, sizeof(input)};
    stream.seekg(4, std::ios_base::beg);

    stream.read(buff, 2);

    for (int i = 0; i < 2; ++i) {
        EXPECT_EQ(input[i + 4], buff[i]);
    }
}
