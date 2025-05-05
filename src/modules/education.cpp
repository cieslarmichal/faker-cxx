#include "faker/education.h"

#include "faker/helper.h"

namespace faker::education
{
const std::vector<std::string> schoolNames = {
    "Harvard University",      "Stanford University",    "MIT",
    "University of Oxford",    "University of Tokyo",    "Technical University of Munich",
    "University of Cape Town", "University of São Paulo"};

const std::vector<std::string> degreeTypes = {"Bachelor of Science (BSc)", "Bachelor of Arts (BA)",
                                              "Master of Science (MSc)", "Master of Business Administration (MBA)",
                                              "Doctor of Philosophy (PhD)"};

const std::vector<std::string> fieldsOfStudy = {
    "Computer Science", "Mechanical Engineering",  "Psychology",       "Economics", "Biology",
    "Philosophy",       "Business Administration", "Political Science"};

const std::vector<std::string> academicTerms = {"Fall Semester",   "Spring Semester", "Winter Quarter",
                                                "GPA Scale (4.0)", "Trimester",       "Academic Year"};

const std::vector<std::string> courseNames = {"Introduction to Programming", "Advanced Calculus",   "World History",
                                              "Organic Chemistry",           "Digital Marketing",   "Thermodynamics",
                                              "Cognitive Psychology",        "Entrepreneurship 101"};

std::string schoolName()
{
    return helper::pickRandomElement(schoolNames);
}

std::string degreeType()
{
    return helper::pickRandomElement(degreeTypes);
}

std::string fieldOfStudy()
{
    return helper::pickRandomElement(fieldsOfStudy);
}

std::string academicTerm()
{
    return helper::pickRandomElement(academicTerms);
}

std::string courseName()
{
    return helper::pickRandomElement(courseNames);
}
}
