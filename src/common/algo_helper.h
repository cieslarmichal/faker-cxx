#pragma once

#include <algorithm>
#include <functional>
#include <random>
#include <set>
#include <stdexcept>
#include <string>
#include <iterator>

#include "faker-cxx/datatype.h"
#include "faker-cxx/export.h"
#include "faker-cxx/helper.h"

namespace faker::helper
{
template <class T>
static T setElement(const std::set<T>& data)
{
    if (data.empty())
    {
        throw std::invalid_argument{"Data is empty."};
    }

    T item;

    static std::mt19937 pseudoRandomGenerator(static_cast<unsigned long>(std::random_device{}()));

    std::sample(data.begin(), data.end(), &item, 1, pseudoRandomGenerator);

    return item;
}

FAKER_CXX_EXPORT std::string shuffleString(std::string data);

template <typename T>
static T::key_type objectKey(const T& object)
{
    if (object.empty())
    {
        throw std::runtime_error("Object is empty.");
    }

    std::vector<typename T::key_type> keys;
    keys.reserve(object.size());

    std::transform(object.begin(), object.end(), std::back_inserter(keys), [](const auto& entry) { return entry.first; });

    return arrayElement<typename T::key_type>(keys);
}

template <typename TResult>
static TResult maybe(std::function<TResult()> callback, double probability = 0.5)
{
    if (datatype::boolean(probability))
    {
        return callback();
    }
    return TResult();
}

template <typename T, std::size_t N>
static std::vector<T> toVector(const std::array<T, N>& arr)
{
    std::vector<T> vec;
    vec.reserve(N);
    vec.insert(vec.end(), arr.begin(), arr.end());
    return vec;
}

FAKER_CXX_EXPORT std::string replaceSymbolWithNumber(const std::string& str, const char& symbol = '#');

FAKER_CXX_EXPORT std::string replaceCreditCardSymbols(const std::string& inputString = "6453-####-####-####-###L",
                                                      char symbol = '#');

FAKER_CXX_EXPORT std::string regexpStyleStringParse(const std::string& input);
}
