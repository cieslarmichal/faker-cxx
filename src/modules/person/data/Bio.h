#pragma once

#include <string>
#include <vector>

namespace faker{
const std::vector<std::string> bioPart =
{
  "Activist",
  "Artist",
  "Author",
  "Blogger",
  "Business owner",
  "Coach",
  "Creator",
  "Designer",
  "Developer",
  "Dreamer",
  "Educator",
  "Engineer",
  "Entrepreneur",
  "Environmentalist",
  "Film lover",
  "Filmmaker",
  "Foodie",
  "Founder",
  "Friend",
  "Gamer",
  "Geek",
  "Grad",
  "Inventor",
  "Leader",
  "Model",
  "Musician",
  "Nerd",
  "Parent",
  "Patriot",
  "Person",
  "Philosopher",
  "Photographer",
  "Public speaker",
  "Scientist",
  "Singer",
  "Streamer",
  "Student",
  "Teacher",
  "Traveler",
  "Veteran",
  "Writer",
};

const std::vector<std::string> bioSupporter = 
{
  "Advocate",
  "Devotee",
  "Enthusiast",
  "Fan",
  "Junkie",
  "Lover",
  "Supporter"
};

const std::vector<std::string> bioFormats = 
{
"{bio_part}",
"{bio_part}, {bio_part}",
"{bio_part}, {bio_part}, {bio_part}",
"{bio_part}, {bio_part}, {bio_part}, {emoji}",
"{noun} {bio_supporter}",
"{noun} {bio_supporter} {emoji}",
"{noun} {bio_supporter}, {bio_part}",
"{noun} {bio_supporter}, {bio_part} {emoji}"
};
}