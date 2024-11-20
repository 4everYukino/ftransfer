#include <spdlog/spdlog.h>

#include <json/json.h>
#include <json/reader.h>

#include <event2/event.h>

#include <errno.h>
#include <fstream>
#include <string>

#include "../utils/deleter.h"

using namespace std;

int main()
{
    spdlog::set_level(spdlog::level::debug);

    // Debug spdlog
    spdlog::debug("Hello, i am {}, this message will be displayed by spdlog.", "bruce");

    // Debug jsoncpp
    const string demoPath("/home/im/ftransfer/debug/demo.json");
    fstream fs(demoPath);
    if (!fs.is_open()) {
        spdlog::error("Failed to open '{}', errno={}, {}.",
                      demoPath, errno, strerror(errno));
        return -1;
    }

    const Deleter closer([&fs] {
        fs.close();
    });

    Json::Reader reader;
    Json::Value value;
    if (!reader.parse(fs, value)) {
        spdlog::error("Failed to parse JSON, {}.",
                      reader.getFormattedErrorMessages());
        return -1;
    }

    spdlog::debug("{}", value.toStyledString());

    // Debug libevent
    auto base = event_base_new();
    if (!base) {
        spdlog::error("Failed to init libevnet, ...");
        return -1;
    }

    const Deleter freer([&base] {
        event_base_free(base);
    });

    spdlog::debug("init libevent successfully.");

    return 0;
}
