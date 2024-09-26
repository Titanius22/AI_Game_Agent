#include "Player_Human.h"
#include <conio.h>
#include <iostream>
#include <cassert>

#define SPACE     32
#define KEY_UP    72 // extended set
#define KEY_LEFT  75 // extended set
#define KEY_RIGHT 77 // extended set
#define KEY_DOWN  80 // extended set

//based on code from https://stackoverflow.com/a/54581468


namespace AI_Game_Agent
{
	Player_Human::Player_Human()
	{
		// do nothing
	}

	Player_Human::~Player_Human()
	{
		// do nothing
	}

	Scene::PlayerPos Player_Human::MakeDecision_GetNextPlayerPos() const
	{
        int c, ex;
        Scene::PlayerPos rtnVal = Scene::PlayerPos::undecided;

        while (1)
        {
            c = _getch();

            if (c == 0x0 || c == 0xE0) //extended ASCII
            {
                switch (ex = _getch())
                {
                case KEY_UP     /* H */:
                    //std::cout << std::endl << "Up" << std::endl;//key up
                    rtnVal = Scene::PlayerPos::JUMP;
                    break;
                case KEY_DOWN   /* K */:
                    //std::cout << std::endl << "Down" << std::endl;   // key down
                    rtnVal = Scene::PlayerPos::DUCK;
                    break;
                case KEY_RIGHT: /* P */
                    //std::cout << std::endl << "Right" << std::endl;  // key right
                    rtnVal = Scene::PlayerPos::DIVE;
                    break;
                default:
                    //std::cout << std::endl << (char)ex << std::endl;  // not arrow
                    break;
                }
            }
            else
            {
                switch (c)
                {
                case SPACE:
                    //std::cout << std::endl << "Up" << std::endl;//key up
                    rtnVal = Scene::PlayerPos::NORMAL;
                    break;
                default:
                    //std::cout << std::endl << (char)c << std::endl;  // not arrow
                    break;
                }
            }
                      
            if (rtnVal != Scene::PlayerPos::undecided)
            {
                break;
            }
        }

        return rtnVal;
	}

	void Player_Human::CollectData_ReceiveScore(int score)
	{

	}

	void Player_Human::CollectData_IngestScene(const Scene& rScene)
	{
		// DO nothing. Human can see the console
	}
}
