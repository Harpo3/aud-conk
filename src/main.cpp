// Gathers mp3 file data using audtool and id3ted and art from album folder
//in music library to create tmp files for use in conky; runs in Audacious
//using its Song Change plugin "Command to run when starting a new song"
// with a /bin/bash executable file of this program.
//
//#include "mainwindow.h"
//#include <QApplication>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

// Function to execute a bash command and get result
std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }
    return result;
}
//
int main()
{
//
// Obtain name of artwork file from album directory; maybe check for multiple art files
    //FIRST, use the command used for song DirPath, store that in the file artloc.txt.
    //The command is: echo -n $(audtool current-song-filename) | cut -d'/' -f-5 > ~/.local/share/audconk/artloc.txt
    // Converted the above command from text to unicode using:
    //https://www.easycalculation.com/unit-conversion/text-unicode-converter.php

    std::string testjpgID1 = exec("\u0065\u0063\u0068\u006f\u0020\u002d\u006e\u0020\u0024\u0028\u0061\u0075\u0064\u0074\u006f"
                                  "\u006f\u006c\u0020\u0063\u0075\u0072\u0072\u0065\u006e\u0074\u002d\u0073\u006f\u006e\u0067"
                                  "\u002d\u0066\u0069\u006c\u0065\u006e\u0061\u006d\u0065\u0029\u0020\u007c\u0020\u0063\u0075"
                                  "\u0074\u0020\u002d\u0064\u0027\u002f\u0027\u0020\u002d\u0066\u002d\u0035\u0020\u003e\u0020"
                                  "\u007e\u002f\u002e\u006c\u006f\u0063\u0061\u006c\u002f\u0073\u0068\u0061\u0072\u0065\u002f"
                                  "\u0061\u0075\u0064\u0063\u006f\u006e\u006b\u002f\u0061\u0072\u0074\u006c\u006f\u0063\u002e"
                                  "\u0074\u0078\u0074");

    // SECOND, find the file with the type .jpg with this command:
    // find "$(<~/.local/share/audconk/artloc.txt)" -iname '*.jpg' > ~/.local/share/audconk/arttmp.txt and use this for the full art path
    // Converted the above command from text to unicode using:
    //https://www.easycalculation.com/unit-conversion/text-unicode-converter.php

    std::string testjpgID2 = exec("\u0066\u0069\u006e\u0064\u0020\u0022\u0024\u0028\u003c\u007e\u002f\u002e\u006c\u006f\u0063\u0061"
                                  "\u006c\u002f\u0073\u0068\u0061\u0072\u0065\u002f\u0061\u0075\u0064\u0063\u006f\u006e\u006b\u002f"
                                  "\u0061\u0072\u0074\u006c\u006f\u0063\u002e\u0074\u0078\u0074\u0029\u0022\u0020\u002d\u0069\u006e"
                                  "\u0061\u006d\u0065\u0020\u0027\u002a\u002e\u006a\u0070\u0067\u0027\u0020\u003e\u0020\u007e\u002f"
                                  "\u002e\u006c\u006f\u0063\u0061\u006c\u002f\u0073\u0068\u0061\u0072\u0065\u002f\u0061\u0075\u0064"
                                  "\u0063\u006f\u006e\u006b\u002f\u0061\u0072\u0074\u0074\u006d\u0070\u002e\u0074\u0078\u0074");

    //Using the file arttmp.txt just created, copy the file folder.jpg from the library folder to the share dir
    //for conky use. The command is: for file in $(cat ~/.local/share/audconk/arttmp.txt); do cp "$file" ~/.local/share/audconk; done
    // Converted the above command from text to unicode using:
    //https://www.easycalculation.com/unit-conversion/text-unicode-converter.php

    std::string artFileCopied = exec("\u0066\u006f\u0072\u0020\u0066\u0069\u006c\u0065\u0020\u0069\u006e\u0020\u0024\u0028\u0063\u0061"
                                     "\u0074\u0020\u007e\u002f\u002e\u006c\u006f\u0063\u0061\u006c\u002f\u0073\u0068\u0061\u0072\u0065"
                                     "\u002f\u0061\u0075\u0064\u0063\u006f\u006e\u006b\u002f\u0061\u0072\u0074\u0074\u006d\u0070\u002e"
                                     "\u0074\u0078\u0074\u0029\u003b\u0020\u0064\u006f\u0020\u0063\u0070\u0020\u0022\u0024\u0066\u0069"
                                     "\u006c\u0065\u0022\u0020\u007e\u002f\u002e\u006c\u006f\u0063\u0061\u006c\u002f\u0073\u0068\u0061"
                                     "\u0072\u0065\u002f\u0061\u0075\u0064\u0063\u006f\u006e\u006b\u003b\u0020\u0064\u006f\u006e\u0065");

    //Get art size and save to currartsize.txt
    // command: /usr/bin/stat -c%s $(foo=$(echo "$(audtool --current-song-filename)" | sed 's|\(.*\)/.*|\1|'); echo $foo"/folder.jpg") > ~/.local/share/audconk/currartsize.txt

    std::string getArtSize = exec("\u002f\u0075\u0073\u0072\u002f\u0062\u0069\u006e\u002f\u0073\u0074\u0061\u0074\u0020\u002d\u0063\u0025"
                                  "\u0073\u0020\u0024\u0028\u0066\u006f\u006f\u003d\u0024\u0028\u0065\u0063\u0068\u006f\u0020\u0022\u0024"
                                  "\u0028\u0061\u0075\u0064\u0074\u006f\u006f\u006c\u0020\u002d\u002d\u0063\u0075\u0072\u0072\u0065\u006e"
                                  "\u0074\u002d\u0073\u006f\u006e\u0067\u002d\u0066\u0069\u006c\u0065\u006e\u0061\u006d\u0065\u0029\u0022"
                                  "\u0020\u007c\u0020\u0073\u0065\u0064\u0020\u0027\u0073\u007c\u005c\u0028\u002e\u002a\u005c\u0029\u002f"
                                  "\u002e\u002a\u007c\u005c\u0031\u007c\u0027\u0029\u003b\u0020\u0065\u0063\u0068\u006f\u0020\u0024\u0066"
                                  "\u006f\u006f\u0022\u002f\u0066\u006f\u006c\u0064\u0065\u0072\u002e\u006a\u0070\u0067\u0022\u0029\u0020"
                                  "\u003e\u0020\u007e\u002f\u002e\u006c\u006f\u0063\u0061\u006c\u002f\u0073\u0068\u0061\u0072\u0065\u002f"
                                  "\u0061\u0075\u0064\u0063\u006f\u006e\u006b\u002f\u0063\u0075\u0072\u0072\u0061\u0072\u0074\u0073\u0069"
                                  "\u007a\u0065\u002e\u0074\u0078\u0074");

    //Provide full tag info for data user may want use to to customize further in conky.
    // command is: id3ted%20-l%20%24%28audtool%20--current-song-filename%29%20%3E%20%7E/.local/share/audconk/taginfofull.txt

    std::string getFullTag = exec("\u0069\u0064\u0033\u0074\u0065\u0064\u0025\u0032\u0030\u002d\u006c\u0025\u0032\u0030\u0025\u0032\u0034"
                                  "\u0025\u0032\u0038\u0061\u0075\u0064\u0074\u006f\u006f\u006c\u0025\u0032\u0030\u002d\u002d\u0063\u0075"
                                  "\u0072\u0072\u0065\u006e\u0074\u002d\u0073\u006f\u006e\u0067\u002d\u0066\u0069\u006c\u0065\u006e\u0061"
                                  "\u006d\u0065\u0025\u0032\u0039\u0025\u0032\u0030\u0025\u0033\u0045\u0025\u0032\u0030\u0025\u0037\u0045"
                                  "\u002f\u002e\u006c\u006f\u0063\u0061\u006c\u002f\u0073\u0068\u0061\u0072\u0065\u002f\u0061\u0075\u0064"
                                  "\u0063\u006f\u006e\u006b\u002f\u0074\u0061\u0067\u0069\u006e\u0066\u006f\u0066\u0075\u006c\u006c\u002e"
                                  "\u0074\u0078\u0074");
}
