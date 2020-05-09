#include<iostream>
#include<string>

using namespace std;

void print_warrior() {
	string * character = new string [25];
	character[0] = "                             .\n";
	character[1] = "                          /::|:\\\n";
	character[2] = "                      _ /.:::|:::\\\n";
	character[3] = "            .:.._     _/.ooo|oooo:|\n";
	character[4] = "             '\"\"||||||\\ooo[  ]ooo-|\n";
	character[5] = "                \\||||/:/''_____\"\"//::|Oo:..\n";
	character[6] = "                 /\\_/O:/\\`-------/OOOOOo:::..\n";
	character[7] = "               /OOO/oOOOOOOOOOOOOOOOOOOOOOOO:::.\n";
	character[8] = "              /OOO<OOOOOO-\\___/-OOOOOOOOOOOO:::''.\n";
	character[9] = "             |OOO|OOOOOOOOOOOOOOOOOOOOOOOOO\\O\\OOO\\\n";
	character[10] = "            |OOOO\\OOOOOOOOOOOOOOOOOOOOOOOO\\O\\___---'.\n";
	character[11] = "          `|OOOO\\OOOOOOOOOOOOOOOOOOOOOOOOO|\\____OOOO\\\n ";
	character[12] = "         .///////\\OOOOOOOOOOOOOOOOOOOOOOO]/ \\\\\\\\[```\\\n";
	character[13] = "         ///////   .:\\OOOOOOOOOOOOOOOOOOOO|\\   \\\\.\\-`|\n";
	character[14] = "        ///////     \\:.\\OOOOOOOOOOOOOOOOO/S.\\  `|O:|.\\\n";
	character[15] = "       //////’`     /::./OOOOOOOOOOOOOOOO.\\ S.\\ `|o\\_.|\n";
	character[16] = "      /////’       <`:::/OOOOOOOOOOOOOOOOO`\\ S`’\\|||||||\n";
	character[17] = "     /////|       ``:::|OOOOOOOOOOOOOOOOO|  `\\S/||||||:| \n";
	character[18] = "    //////        .::::|OOOOOOOOOOOOOOOOOO\\     \\.|||:/\n";
	character[19] = "  `\\O/-\"          /::::/OOOOOOOOOOOOO|O|O|\\      ` `-'`\\\n";
	character[20] = "   /S/\\/          /:/:::/OOOOOOOOOOOOO|O|O|.\\\n";
	character[21] = "  /S/           ./::::/:::/OOOOOOOOOOOOO|O|O||\n";
	character[22] = " /S./         '`::::::/::::/OOOOOOOOOOOO.|O|O||\n";
	character[23] = "/S/      .:::::::::::/::::/OOOOOOOOOOOOO.|O|O|\\\n";
    character[24] = "/S/  \\'''''''::::::::|:::::|OOOOOOOOOOOOO|O|O\\\\\\\n";
	for (int i = 0; i<25; i++) {
        cout<<character[i]<<endl;
    }
	delete [] character;
}

void print_mage() {
	string * character = new string [25];
	character[0] = "      /\\ \n";
	character[1] = "  .:::::\n";
	character[2] = " /:::::|\n";
	character[3] = "   \\:::\\                                          ,………...__\n";
	character[4] = "    \\::\\                                        ./:::::::::::\\\n";
	character[5] = "     |::::/                                    |:…...…..:::::\\_\n";
	character[6] = "    /::::/                                      \\..::..\\:::::`/\n";
	character[7] = "    \\::::|                                       \\ -- ;/:’’\n";
	character[8] = "      \\:::|                                   _.. ..` --- ‘  ::/::…\n";
	character[9] = "        \\::|                              /.:\\:\\:::\\/::::/::::````````\\\n";
	character[10] = "        |:|                            /:::::\\::\\::::/::-‘’,–‘::::::::::/\n";
	character[11] = "         \\:\\                          /:::::::::(    )::::::::::```````\\\n";
	character[12] = "          \\::|                      /:::```||||||||||||||||||\\---------|\n";
	character[13] = "           \\::\\                    \\-----|||||||||||||||||||||\\--------/\n";
	character[14] = "            \\::|              __/-----|||||||||||||||||||||||-/`’`’`'`’\\\n";
	character[15] = "             |::|           ./----------||||||||||||||||||||/|\\        /\n";
	character[16] = "             |:`--.__.—‘``\\-------/||||||||||||||||||||||||||||  \\\\,/ ||\n";
	character[17] = "             |`   \\   ‘    _ . . /   | / ||||||||||||||||||||||\\ /\\/\\/./\n";
	character[18] = "             ` - - |’             `-‘`-‘ /||/  \\|||||||||||||| ---‘`--’ \\\n";
	character[19] = "                \\::\\                     /```’      `-----‘’’’’OOO|\\\\\\\\\\\\\\\n";
	character[20] = "                 \\::|                   |OOOOOOO\\_/OOOOOOO\\OOO|\\\\\\\\\\\\\\\\\\\\\\\\\n";
	character[21] = "                   |:|                  |OOOOOOOO|OOOOOOOO\\OO|\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
	character[22] = "                   |:|                   \\OOOOOOOO\\OOOOOOOO|OO|\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\.\n";
	character[23] = "                   |::|                  |OOOOOOOO|OOOOOOOO|OO|\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\.\n";
	character[24] = "                    \\::\\                 /OOOOOOOOO\\OOOOOOOO|O||\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\.\n";
	for (int i = 0; i<25; i++) {
        cout<<character[i]<<endl;
    }
	delete [] character;
}

void print_monster() {
	string * character = new string [25];
	character[0] = "                                                                         .::::::::::::::.";
	character[1] = "                                                                     .:::::::::::::::::::::.";
	character[2] = "                                                                   ::::::::::::::::::::::::::";
	character[3] = "                                                                (::::::::::::::::::::::/’::::)";
	character[4] = "                                                                 /:\\...------……/::::::::::\\::..";
	character[5] = "                                                              .-. \\::::...:::::: ::::::::::\\::::::..                           .......";
	character[6] = "                                                            /  \\::::::::::::::| \\:::::::::\\::::::::::::..                   .::::::::::::";
	character[7] = "                                                           |   /`````````````/    \\::::::::/::::::::::----\\__              .:::::::::::*";
	character[8] = "                                                       /(:::::::::::::::::::::::.....::::/::::/:::::::::::::::::::::::\\ ..:::::::**";
	character[9] = "                                                     /:::::::::/\\_____________________/::::::::|:::::::::::::::::::::::\\::::::**";
	character[10] = "                                                /:::::::/::\\     \\::::::::::::::::::::::::::::::|::::::::::::::::::::::::::\\’";
	character[11] = "                                               |::::::/:::::\\     \\::::::::::::::::::::::::::::::\\::::::::::::::::::::::::::|";
	character[12] = "                                                \\:::::|::::::::\\    \\::::::::::::::::::::::::::::::\\::::::::::::::::::::::/:\\";
	character[13] = "                                              /::::::::/------‘’::.     :::::::::`-::_______________|:::::::::::::::::::::::|";
	character[14] = "                                             |:::::::/::::::::::::::::..    `:::::::::::::::::::::::|::::::::::::::::::::::|";
	character[15] = "                                             |:::::/:::::::::::::::::::::::…     ``::::::::::::::::::\\::::::::::::::::::::/";
	character[16] = "                                             /:::::|:::::::::::::::::::::::::::…       ```---:::::::::\\:::::::::::::::::/::\\";
	character[17] = "                                            /::::::|:::::::::::::::::::::::::::::::::::::…             \\::::::::::::::::::::|";
	character[18] = "                                           |::`__ ----::::::::::::::::::::::::::::::::::::::::::::::..  /::\\:::::::::::::::::|";
	character[19] = "                                           |:::::::/        `````*********************’’’’’’’’          |:::::::::::::::::::::|";
	character[20] = "                                           |:/::::::::\\  ‘’’’’’’\\         /\\      /``\\ ,-…      )``\\/```|:::::::::::::::::::::/";
	character[21] = "                                         /::::::::::::::\\.         \\--/        \\/               \\/      |::::::::::::::::::::/";
	character[22] = "                                    .:/::::::::::::::::::\\         _______________,--                _,:|::::::::::::::::::/";
	character[23] = "                            ..:::::/::::::::::::::::::::::|        ________________,--       _--‘’’’-     \\:::::::::::::::::|";
	character[24] = "                  \\::…::::::::::\\:::::::::::::::::::::::::|                                    /:::/::::::::::::::::::::::::/";
	for (int i = 0; i<25; i++){
		cout<<character[i]<<endl;
	}
	delete [] character;
}