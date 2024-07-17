#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "config/RacePrinterMacros.h"
#include "config/GlobalMacros.h"

class RacePrinter{
    public:
        RacePrinter();
        void addRacer(int id, std::string asciiFilename);
        void initPrint();
        void print(std::vector<int>);
    private:
        void initTrack(int trackHeight, int airHeight);

        struct Racer{
            int id;
            int width;
            int yPos;
            int xPos;
            std::vector<std::string> asciiTextLines;
            std::vector<int> asciiOffset;
        };
        std::vector<std::string> _track;
        std::vector<Racer> _racers;
};