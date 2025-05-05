#pragma once

#include <array>
#include <span>
#include <string_view>

namespace faker::education
{

struct EducationDefinition
{
    std::vector<std::string_view> schoolNames;
    std::vector<std::string_view> degreeTypes;
    std::vector<std::string_view> courseNames;
    std::vector<std::string_view> fields;
    std::vector<std::string_view> terms;
};

const auto enUSSchoolNames = std::to_array<std::string_view>(
    {"Harvard University", "Stanford University", "MIT", "University of Oxford", "University of Tokyo",
     "Technical University of Munich", "University of Cape Town", "University of São Paulo"});

const auto enUSDegreeTypes =
    std::to_array<std::string_view>({"Bachelor of Science (BSc)", "Bachelor of Arts (BA)", "Master of Science (MSc)",
                                     "Master of Business Administration (MBA)", "Doctor of Philosophy (PhD)"});

const auto enUSFieldsOfStudy =
    std::to_array<std::string_view>({"Computer Science", "Mechanical Engineering", "Psychology", "Economics", "Biology",
                                     "Philosophy", "Business Administration", "Political Science"});

const auto enUSAcademicTerms = std::to_array<std::string_view>(
    {"Fall Semester", "Spring Semester", "Winter Quarter", "GPA Scale (4.0)", "Trimester", "Academic Year"});

const auto enUSCourseNames = std::to_array<std::string_view>(
    {"Introduction to Programming", "Advanced Calculus", "World History", "Organic Chemistry", "Digital Marketing",
     "Thermodynamics", "Cognitive Psychology", "Entrepreneurship 101"});

const EducationDefinition enUSEducationDefinition = {.schoolNames = enUSSchoolNames,
                                                     .degreeTypes = enUSDegreeTypes,
                                                     .courseNames = enUSCourseNames,
                                                     .fields = enUSFieldsOfStudy,
                                                     .terms = enUSAcademicTerms};
