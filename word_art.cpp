#include<iostream>
#include<string>

using namespace std;

void print_warrior(string character[][25]) {
	for (int i = 0; i<25; i++) {
        cout<<character[0][i];
    }
}

void print_mage(string character[][25]) {
	for (int i = 0; i<25; i++) {
        cout<<character[1][i];
    }
}

int main() {
    string character[5][25];

    character[0][0] = "                             .\n";
	character[0][1] = "                          /::|:\\\n";
	character[0][2] = "                      _ /.:::|:::\\\n";
	character[0][3] = "            .:.._     _/.ooo|oooo:|\n";
	character[0][4] = "             '\"\"||||||\\ooo[  ]ooo-|\n";
	character[0][5] = "                \\||||/:/''_____\"\"//::|Oo:..\n";
	character[0][6] = "                 /\\_/O:/\\`-------/OOOOOo:::..\n";
	character[0][7] = "               /OOO/oOOOOOOOOOOOOOOOOOOOOOOO:::.\n";
	character[0][8] = "              /OOO<OOOOOO-\\___/-OOOOOOOOOOOO:::''.\n";
	character[0][9] = "             |OOO|OOOOOOOOOOOOOOOOOOOOOOOOO\\O\\OOO\\\n";
	character[0][10] = "            |OOOO\\OOOOOOOOOOOOOOOOOOOOOOOO\\O\\___---'.\n";
	character[0][11] = "          `|OOOO\\OOOOOOOOOOOOOOOOOOOOOOOOO|\\____OOOO\\\n ";
	character[0][12] = "         .///////\\OOOOOOOOOOOOOOOOOOOOOOO]/ \\\\\\\\[```\\\n";
	character[0][13] = "         ///////   .:\\OOOOOOOOOOOOOOOOOOOO|\\   \\\\.\\-`|\n";
	character[0][14] = "        ///////     \\:.\\OOOOOOOOOOOOOOOOO/S.\\  `|O:|.\\\n";
	character[0][15] = "       //////’`     /::./OOOOOOOOOOOOOOOO.\\ S.\\ `|o\\_.|\n";
	character[0][16] = "      /////’       <`:::/OOOOOOOOOOOOOOOOO`\\ S`’\\|||||||\n";
	character[0][17] = "     /////|       ``:::|OOOOOOOOOOOOOOOOO|  `\\S/||||||:| \n";
	character[0][18] = "    //////        .::::|OOOOOOOOOOOOOOOOOO\\     \\.|||:/\n";
	character[0][19] = "  `\\O/-\"          /::::/OOOOOOOOOOOOO|O|O|\\      ` `-'`\\\n";
	character[0][20] = "   /S/\\/          /:/:::/OOOOOOOOOOOOO|O|O|.\\\n";
	character[0][21] = "  /S/           ./::::/:::/OOOOOOOOOOOOO|O|O||\n";
	character[0][22] = " /S./         '`::::::/::::/OOOOOOOOOOOO.|O|O||\n";
	character[0][23] = "/S/      .:::::::::::/::::/OOOOOOOOOOOOO.|O|O|\\\n";
    character[0][24] = "/S/  \\'''''''::::::::|:::::|OOOOOOOOOOOOO|O|O\\\\\\\n";
	character[1][0] = "      /\\ \n";
	character[1][1] = "  .:::::\n";
	character[1][2] = " /:::::|\n";
	character[1][3] = "   \\:::\\                                          ,………...__\n";
	character[1][4] = "    \\::\\                                        ./:::::::::::\\\n";
	character[1][5] = "     |::::/                                    |:…...…..:::::\\_\n";
	character[1][6] = "    /::::/                                      \\..::..\\:::::`/\n";
	character[1][7] = "    \\::::|                                       \\ -- ;/:’’\n";
	character[1][8] = "      \\:::|                                   _.. ..` --- ‘  ::/::…\n";
	character[1][9] = "        \\::|                              /.:\\:\\:::\\/::::/::::````````\\\n";
	character[1][10] = "        |:|                            /:::::\\::\\::::/::-‘’,–‘::::::::::/\n";
	character[1][11] = "         \\:\\                          /:::::::::(    )::::::::::```````\\\n";
	character[1][12] = "          \\::|                      /:::```||||||||||||||||||\\---------|\n";
	character[1][13] = "           \\::\\                    \\-----|||||||||||||||||||||\\--------/\n";
	character[1][14] = "            \\::|              __/-----|||||||||||||||||||||||-/`’`’`'`’\\\n";
	character[1][15] = "             |::|           ./----------||||||||||||||||||||/|\\        /\n";
	character[1][16] = "             |:`--.__.—‘``\\-------/||||||||||||||||||||||||||||  \\\\,/ ||\n";
	character[1][17] = "             |`   \\   ‘    _ . . /   | / ||||||||||||||||||||||\\ /\\/\\/./\n";
	character[1][18] = "             ` - - |’             `-‘`-‘ /||/  \\|||||||||||||| ---‘`--’ \\\n";
	character[1][19] = "                \\::\\                     /```’      `-----‘’’’’OOO|\\\\\\\\\\\\\\\n";
	character[1][20] = "                 \\::|                   |OOOOOOO\\_/OOOOOOO\\OOO|\\\\\\\\\\\\\\\\\\\\\\\\\n";
	character[1][21] = "                   |:|                  |OOOOOOOO|OOOOOOOO\\OO|\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
	character[1][22] = "                   |:|                   \\OOOOOOOO\\OOOOOOOO|OO|\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\.\n";
	character[1][23] = "                   |::|                  |OOOOOOOO|OOOOOOOO|OO|\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\.\n";
	character[1][24] = "                    \\::\\                 /OOOOOOOOO\\OOOOOOOO|O||\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\.\n";
    return 0;
}
