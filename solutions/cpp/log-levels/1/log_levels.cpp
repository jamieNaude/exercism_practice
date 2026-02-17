#include <string>

namespace log_line {
std::string message(std::string line) {
    if (line.substr(1, 4) == "INFO") {
        return line.substr(8);
    }
    else if (line.substr(1,7) == "WARNING") {
        return line.substr(11);
    }
    else if (line.substr(1,5) == "ERROR") {
        return line.substr(9);
    }
    else return "NONE";
}

std::string log_level(std::string line) {
    if (line.substr(1, 4) == "INFO") {
        return "INFO";
    }
    else if (line.substr(1,7) == "WARNING") {
        return "WARNING";
    }
    else if (line.substr(1,5) == "ERROR") {
        return "ERROR";
    }
    else return "NONE";
}

std::string reformat(std::string line) {
    std::string msg;
    std::string level;
    if (line.substr(1, 4) == "INFO") {
        msg = line.substr(8);
        level = line.substr(1, 4);
    }
    else if (line.substr(1,7) == "WARNING") {
        msg = line.substr(11);
        level = line.substr(1, 7);
    }
    else if (line.substr(1,5) == "ERROR") {
        msg = line.substr(9);
        level = line.substr(1, 5);
    }
    else {
        msg = " ";
        level = " ";
    }
    return msg + " (" + level + ")";
}
}  // namespace log_line
