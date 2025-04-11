#include "findLabelValue.h"
#include <chrono>
#include <iostream>
#include <thread>

int main() {
  while (true) {
    std::string battery_state, battery_percentage;
    const std::string BATTERY_INFO =
        "upower -i /org/freedesktop/UPower/devices/battery_BAT1";

    FILE *pipe = popen(BATTERY_INFO.c_str(), "r");
    if (!pipe) {
      std::cout << "Command failed to execute";
      return 1;
    }

    char buffer[128];
    std::string str = "";
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
      str += std::string(buffer);
    }

    pclose(pipe);

    battery_state = findLabelValue(str, "state:");
    battery_percentage = findLabelValue(str, "percentage:");

    if (battery_state == "charging" && battery_percentage >= "85%") {
      system("notify-send 'Battery Reached 85'");
      system("paplay /usr/share/sounds/freedesktop/stereo/suspend-error.oga");
    }

    if (battery_state == "discharging" && battery_percentage <= "25%") {
      system("notify-send 'Battery Reached 25'");
      system("paplay /usr/share/sounds/freedesktop/stereo/suspend-error.oga");
    }

    std::this_thread::sleep_for(std::chrono::seconds(120));
  }
}
