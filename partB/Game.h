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
        int height;
        int width;
        std::vector<std::vector<std::shared_ptr<Character>>> board;
        std::map<Team, int> team_players_count;
        const char EMPTY_CELL = ' ';

        //PRIVATE FUNCTIONS
        /**Check if cell is in board*/
        bool isLegalCell(const GridPoint& coordinates) const;

        /**Check if cell has character in it,and throw exception accordingly*/
        void isCellOccupied(const GridPoint& coordinates);

        /**Check if cell is empty,and throw exception accordingly*/
        void isCellEmpty(const GridPoint& coordinates);
        std::shared_ptr<Character> getCharacterByCoordinates(const GridPoint& coordinates); //todo add doc

    public:
        //C'TORS,D'TORS AND OPERATOR OVERLOADING
        /**
         * Constructor of game class
         * @param height of board
         * @param width of board
         */
        Game(int height, int width);

        /**
         * Copy other game to this game
         * @param other - game to copy
         */
        void copyGame(const Game& other);

        /**
         * Copy constructor
         * @param other - game to copy
         */
        Game(const Game& other);

        /**
         * Assigment constructor
         * @param other - game to copy
         * @return new copied game
         */
        Game& operator=(const Game& other);

        /**
         * Destructor
         */
        ~Game()= default;

        //GAME FUNCTIONS

        /**
        * Add new character to board's game
        * @param coordinates of new character in board
        * @param character to add to board
        */
        void addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);

        /**
         * Create character
         * @param type of character <CharacterType> - can be SNIPER,MEDIC or SOLDIER
         * @param team character belong to <Team> - can be POWERLIFTERS or CROSSFITTERS
         * @param health points
         * @param ammo points
         * @param range to attack in board
         * @param power of attack points
         * @return shared pointer to new character with given attributes
         */
        static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                                                        units_t health, units_t ammo, units_t range, units_t power);

        /**
         * Move character in board from source coordinates to destination coordinates
         * @param src_coordinates
         * @param dst_coordinates
         */
        void move(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);

        /**
         * Attack character in destination coordinates by character in source coordinates
         * @param src_coordinates
         * @param dst_coordinates
         */
        void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);

        /**
         * Reload ammo to character
         * @param coordinates of character to reload
         */
        void reload(const GridPoint & coordinates);

        /**
         * Check if game is over
         * @param winningTeam - empty pointer to contain the winning team, if exist
         * if pointer is null,function ignores it
         * @return if game has winner
         */
        bool isOver(Team* winningTeam=NULL) const;

        /**
         * Write current board game to ostream
         * @param os
         * @param game to print
         * @return ostream contains the current board game
         */
        friend std::ostream &operator<<(std::ostream &os, const Game &game);
    };
}

#endif //GAME_H
