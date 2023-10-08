#pragma once

#include <string>

namespace faker {
    class Hacker {
public:
        /**
         * @brief Returns a hacker abbreviation.
         *
         * @returns abbreviation.
         *
         * @code
         * Hacker::abbreviation() // "TCP"
         * @endcode
         */
        static std::string abbreviation();

        /**
         * @brief Returns a random adjective.
         *
         * @returns adjective.
         *
         * @code
         * Hacker::adjective() // "open-source"
         * @endcode
         */
        static std::string adjective();

        /**
         * @brief Returns a random noun.
         *
         * @returns noun.
         *
         * @code
         * Hacker::noun() // "coder"
         * @endcode
         */
        static std::string noun();

        /**
         * @brief Returns a random verb.
         *
         * @returns verb.
         *
         * @code
         * Hacker::verb() // "run"
         * @endcode
         */
        static std::string verb();

        /**
         * @brief Returns a random ingverb.
         *
         * @returns ingverb.
         *
         * @code
         * Hacker::ingverb() // "backing up"
         * @endcode
         */
        static std::string ingverb();

        /**
         * @brief Returns a random phrase.
         *
         * @return phrase.
         *
         * @code
         * Hacker::phrase() // "If we bypass the monitor, we can get to the TCP monitor through the neural EXE monitor!"
         * @endcode
         */
        static std::string phrase();
    };
}