//
//  svg.hpp
//  ProjetPiscineV
//
//  Created by Adja Sow on 19/04/2019.
//  Copyright © 2019 Adja Sow. All rights reserved.
//

#ifndef svg_hpp
#define svg_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <set>

constexpr char defcol[] = "black";

class Svgfile
{
private:
    std::string m_filename;
    std::ofstream m_ostrm;
    int m_width;
    int m_height;
    
    // Pour Èviter les ouverture multiples
    static std::set<std::string> s_openfiles;
    
public:
    
    Svgfile(std::string _filename = "output.svg", int _width=1000, int _height=800);
    ~Svgfile();
    
    void addDisk(double x, double y, double r, std::string color=defcol);
    void addLine(double x1, double y1, double x2, double y2, std::string color=defcol);
    void addCross(double x, double y, double span, std::string color=defcol);
    
    void addText(double x, double y, std::string text, std::string color=defcol);
    void addText(double x, double y, double val, std::string color=defcol);
    
    void addGrid(double span=100.0, bool numbering=true, std::string color="lightgrey");
};

std::string makeRGB(int r, int g, int b);

std::string fillBallColor(std::string col);

#endif /* svg_hpp */
