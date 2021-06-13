#ifndef GAME_H
#define GAME_H

#include <memory>
#include <iostream>
#include <vector>
#include <map>
#include "Character.h"
#include "Sniper.h"
#include "Soldier.h"
#include "Medic.h"
#include "Auxiliaries.h"

namespace mtm {
    class Game{
    private:
        const int height;
        const int width;
        std::vector<std::vector<std::shared_ptr<Character>>> board;
        void isLegalCell(const GridPoint& coordinates);
        void isCellOccupied(const GridPoint& coordinates);
        void isCellEmpty(const GridPoint& coordinates);
        std::map<Team, int> team_players_count;
    public:
        Game(int height, int width);
        Game(const Game& other);
        Game& operator=(const Game& other);
        ~Game();
        void addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);
        static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                                                        units_t health, units_t ammo, units_t range, units_t power);
        void move(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);
        void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);
        void reload(const GridPoint & coordinates);
        bool isOver(Team* winningTeam=NULL) const;
        friend std::ostream &operator<<(std::ostream &os, const Game &game);
    };
}

#endif //GAME_H
