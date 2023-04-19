# BatteryBeep

BatteryBeep is a C++ project that helps you avoid overcharging your laptop battery. It notifies you when your battery is above or equal to 85% every two minutes and only stops after you unplug the charger.

## Dependencies

BatteryBeep depends on the following libraries and tools:

- upower
- notify-send
- paplay

## How to Use

To use BatteryBeep, follow these steps:

1. Clone the repository: `git clone https://github.com/iam-arnab/BatteryBeep.git`
2. Install the dependencies listed above.
3. Build the project using cmake: `cd BatteryBeep && mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release .. && make`
4. Run the executable: `./BatteryBeep`

BatteryBeep will start monitoring your battery level and will notify you every two minutes if your battery is above or equal to 85%. The notifications will stop only after you unplug the charger. There are many ways of running it in background but the most preferrable will be using a desktop file and putting it in `~/.config/autostart`.

```desktop
[Desktop Entry]
Type=Application
Name=BatteryBeep
Comment=Plays a sound every 2 minutes if the battery level is 85% or higher
Exec=<path to executable>
Terminal=false
```

## License

BatteryBeep is released under the MIT License. See [LICENSE](https://github.com/iam-arnab/BatteryBeep/blob/main/LICENSE) for more information.
