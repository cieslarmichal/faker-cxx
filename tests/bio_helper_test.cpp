#include "bio_helper.h"
#include "test_helpers.h"

TEST(BioHelperTest, checkFormatToken)
{
    // Bio format: {noun} {bio_supporter}
    // Bio: influence Devotee
    EXPECT_TRUE(faker::BioHelper::checkTokenFormat("influence Devotee"));

    // Bio format: {noun} {bio_supporter}, {bio_part}
    // Bio: father-in-law Devotee, Model
    // EXPECT_TRUE(faker::BioHelper::checkTokenFormat("influence Devotee, Explorer"));

    // Bio format: {noun} {bio_supporter}, {bio_part}
    // Bio: peer-to-peer Supporter, Model

    // Bio format: {noun} {bio_supporter} {emoji}
    // Bio: peer-to-peer Enthusiast 🥖

    // Bio format: {noun} {bio_supporter}, {bio_part}
    // Bio: sister-in-law Junkie, Teacher

    // Bio format: {noun} {bio_supporter} {emoji}
    // Bio: peer-to-peer Lover 🫒

    // Bio format: {noun} {bio_supporter}, {bio_part} {emoji}
    // Bio: father-in-law Advocate, Philosopher 👨🏼‍🌾

    // Bio format: {noun} {bio_supporter} {emoji}
    // Bio: father-in-law Advocate ⏫

    // Bio format: {noun} {bio_supporter}, {bio_part} {emoji}
    // Bio: father-in-law Junkie, Engineer 🦹🏼

    // Bio format: {noun} {bio_supporter}
    // Bio: brother-in-law Devotee
}
