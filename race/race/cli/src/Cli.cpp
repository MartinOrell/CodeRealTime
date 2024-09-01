#include "Cli.h"

void Cli::initTrack(int trackHeight, int airHeight){
    
    std::string airLine = std::string(PRINTWIDTH, ' ');
    std::string trackEdgeLine =
        std::string(PRINTWIDTH-GOALWIDTH, '-') +
        std::string(GOALWIDTH, ' ');
    std::string trackLine = 
        std::string(PRINTWIDTH-GOALWIDTH, ' ') +
        "|" +
        std::string((GOALWIDTH-1), ' ');

    for(int i = 0; i < airHeight; i++){
        _track.push_back(airLine);
    }
    
    _track.push_back(trackEdgeLine);
    
    std::string goalText = GOALTEXT;
    for(int i = 0; i < trackHeight; i++){
        std::string line = trackLine;
        if(i < goalText.size()){
            line.at(PRINTWIDTH-1) = goalText.at(i);
        }
        _track.push_back(line);
    }

    _track.push_back(trackEdgeLine);

    //middle line
    int middleLineYPos = _track.size() - (trackHeight+3)/2-1;
    for(int x = 2; x < PRINTWIDTH-GOALWIDTH-2; x+=5){
        _track.at(middleLineYPos).replace(x, 2, "__");
    }
}

Cli::Cli(){}

void Cli::addRacer(int id, std::string asciiFilename){
    
    Racer racer;
    racer.id = id;
    racer.width = 1; //Will be increased when reading file
    racer.yPos = -1; //Will be set in initPrint after all racers are added

    std::ifstream in(asciiFilename);
    if(!in){
        std::cerr << "Failed to open file " << asciiFilename << std::endl;
        racer.asciiTextLines.push_back(">");
        racer.asciiOffset.push_back(0);
    }
    else{
        std::string line;
        while(std::getline(in, line)){
            const int offset = line.find_first_not_of(' ');
            racer.asciiTextLines.push_back(line.substr(offset));
            racer.asciiOffset.push_back(offset);
            if(racer.width < line.size()){
                racer.width = line.size();
            }
        }
        in.close();
    }
    _racers.push_back(racer);
}

//initPrint should be called after all racers have been added
void Cli::initPrint(){
    //Sort racers by id to give them correct positions
    std::sort(_racers.begin(),_racers.end(),[](Racer &a, Racer &b){return a.id<b.id;});

    int trackHeight = std::max((int)TRACKHEIGHT, (int)_racers.size());
    int airHeight = 0; //Will be increased when necessary to fit printing racer

    std::vector<int> racerBottomOffsetList; //Distance racer is from the bottom

    if(_racers.size() == 1){
        racerBottomOffsetList.push_back(trackHeight/2);
    }
    else{
        for(int i = 0; i < _racers.size();i++){
            racerBottomOffsetList.push_back((trackHeight-1)-(i*(trackHeight-1))/(_racers.size()-1)+1);
        }
    }

    
    for(int i = 0; i < _racers.size(); i++){
        //Setting yPosition from above ignoring air
        _racers.at(i).yPos = trackHeight+2-racerBottomOffsetList.at(i)-_racers.at(i).asciiTextLines.size();
        //if necessary increase air above track to enable printing racer
        if(-_racers.at(i).yPos > airHeight){
            airHeight = -_racers.at(i).yPos;
        }
    }

    //update yPosition for racers with air taken into account
    for(Racer& racer : _racers){
        racer.yPos += airHeight;
    }

    initTrack(trackHeight, airHeight);
}

void Cli::print(std::vector<int> stepPositions){

    //Update positions for racers
    for(int i = 0; i < _racers.size(); i++){
        _racers.at(i).xPos = (stepPositions.at(i)*RACEWIDTH)/GOAL;
    }

    //newPrint will contain the lines to be written
    std::vector<std::string> newPrint;

    //copy track into newPrint
    for(const std::string& line : _track){
        newPrint.push_back(line);
    }

    //copy racers into newPrint
    for(const Racer& racer: _racers){
        for(int i = 0; i < racer.asciiTextLines.size(); i++){
            int startPrintPos = STARTWIDTH + racer.xPos - racer.width + racer.asciiOffset.at(i);
            if(startPrintPos < 0){
                if(racer.asciiTextLines.at(i).size() > -startPrintPos){
                    newPrint.at(i+racer.yPos).replace(
                        0,
                        racer.asciiTextLines.at(i).size()+startPrintPos,
                        racer.asciiTextLines.at(i).substr(-startPrintPos)
                    );
                }
            }
            else{
                newPrint.at(i+racer.yPos).replace(
                    startPrintPos,
                    racer.asciiTextLines.at(i).size(),
                    racer.asciiTextLines.at(i)
                );
            }
        }
    }

    //print all lines in newPrint
    for(const std::string& s: newPrint){
        std::cout << s << std::endl;
    }
}