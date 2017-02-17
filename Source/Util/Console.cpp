#include "Console.h"

#include <string>
#include <sstream>
#include <vector>

namespace Console
{
    namespace
    {
        std::map<std::string, sf::Vector2f*> sfVector2fs;

        enum class Command
        {
            Move,
            Set
        };

        std::vector<std::string> splitAtSpace(const std::string& command)
        {
            std::vector<std::string> strings;
            std::string buffer;
            std::stringstream stream (command);

            while (stream >> buffer)
            {
                strings.push_back(buffer);
            }
            return strings;
        }
    }

    void hook(sf::Vector2f& vect, std::string name)
    {
        sfVector2fs.insert(std::make_pair(std::move(name), &vect));
    }

    void command(const std::string& command)
    {

    }
}
