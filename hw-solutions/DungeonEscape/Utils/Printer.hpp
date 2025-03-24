#ifndef PRINTER_HPP
#define PRINTER_HPP

#include <iostream>
#include <thread>
#include <chrono>

namespace Utils {

    enum class Color {
        RESET = 0,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        WHITE
    };

    class Printer {
    public:

        static void ClearScreen() {
            std::cout << "\033[2J\033[H" << std::flush;
        }

        void operator()(const std::string& text, Color color, bool newLine = true, bool iterate = false) {
            static const char* colorCodes[] = {
                "\033[0m",  // RESET
                "\033[1;31m",  // RED
                "\033[1;32m",  // GREEN
                "\033[1;33m",  // YELLOW
                "\033[1;34m",  // BLUE
                "\033[1;35m",  // MAGENTA
                "\033[1;36m",  // CYAN
                "\033[1;37m"   // WHITE
            };

            int colorIndex = static_cast<int>(color);
            if (colorIndex < 0 || colorIndex >= 8) colorIndex = 0; // RESET

            if (iterate) {
                for (int i = 0; i < text.length(); i++) {
                    std::cout << colorCodes[colorIndex] << text.substr(0, i + 1);
                    std::this_thread::sleep_for(std::chrono::milliseconds(75));
                    std::cout << '\r';
                }
            }

            std::cout << colorCodes[colorIndex] << text << colorCodes[0];
            if (newLine) std::cout << std::endl;

            // give a small pause if we are iterating
            if (iterate) std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    };

} // namespace Utils

#endif // PRINTER_HPP