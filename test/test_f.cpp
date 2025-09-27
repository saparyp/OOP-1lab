#include <gtest/gtest.h>
#include <string>
#include "f.h"

TEST(ReplaceLettersTest, BasicReplacement) {
    EXPECT_EQ(replaceLetters("abc"), "bac");
    EXPECT_EQ(replaceLetters("bac"), "abc");
}

TEST(ReplaceLettersTest, EmptyString) {
    EXPECT_EQ(replaceLetters(""), "");
}

TEST(ReplaceLettersTest, OnlyA) {
    EXPECT_EQ(replaceLetters("aaa"), "bbb");
}

TEST(ReplaceLettersTest, OnlyB) {
    EXPECT_EQ(replaceLetters("bbb"), "aaa");
}

TEST(ReplaceLettersTest, MixedCharacters) {
    EXPECT_EQ(replaceLetters("abab"), "baba");
    EXPECT_EQ(replaceLetters("aabb"), "bbaa");
    EXPECT_EQ(replaceLetters("baab"), "abba");
}

TEST(ReplaceLettersTest, WithOtherCharacters) {
    EXPECT_EQ(replaceLetters("abcd"), "bacd");
    EXPECT_EQ(replaceLetters("xyz"), "xyz");
    EXPECT_EQ(replaceLetters("123"), "123");
    EXPECT_EQ(replaceLetters("a b c"), "b a c");
}

TEST(ReplaceLettersTest, SingleCharacters) {
    EXPECT_EQ(replaceLetters("a"), "b");
    EXPECT_EQ(replaceLetters("b"), "a");
    EXPECT_EQ(replaceLetters("x"), "x");
}

TEST(ReplaceLettersTest, ComplexCases) {
    EXPECT_EQ(replaceLetters("abt"), "bab");
    EXPECT_EQ(replaceLetters("bat"), "abb");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}