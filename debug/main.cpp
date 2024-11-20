#include <spdlog/spdlog.h>

int main()
{
    spdlog::set_level(spdlog::level::debug);

    // Debug spdlog
    spdlog::debug("Hello, i am {}, this message will be displayed by spdlog.", "bruce");

    return 0;
}
