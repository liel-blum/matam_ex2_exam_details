
#include "Game.h"
#include "Exceptions.h"
#include <iostream>
#include <memory>
#include <vector>


namespace mtm {
    Game::Game(int height, int width) : height(height), width(width) {
        board.resize(height, std::vector<std::shared_ptr<Character>>(width, nullptr));
        team_players_count[CROSSFITTERS] = 0;
        team_players_count[POWERLIFTERS] = 0;
        //todo: ADD EXCEPTION HANDLING
    }

    bool Game::isLegalCell(const GridPoint &coordinates) const {
        if (coordinates.col >= width || coordinates.row >= height || coordinates.row<0 || coordinates.col<0) {
            return false;
        }
        return true;
    }

    void Game::isCellOccupied(const GridPoint &coordinates) {
        if (board.at(coordinates.row).at(coordinates.col)) {
            throw CellOccupied();
        }
    }

    void Game::isCellEmpty(const GridPoint &coordinates) {
        if (!board.at(coordinates.row).at(coordinates.col)) {
            throw CellEmpty();
        }
    }

    void Game::addCharacter(const GridPoint &coordinates, std::shared_ptr<Character> character) {
        if (!isLegalCell(coordinates)) {
            throw IllegalCell();
        }
        isCellOccupied(coordinates);
        board[coordinates.row][coordinates.col] = character;
        team_players_count[character->getTeam()]++;
    }

    std::shared_ptr<Character> Game::makeCharacter(CharacterType type, Team team,
                                                   units_t health, units_t ammo, units_t range, units_t power) {
        if (health <= 0 || ammo < 0 || power < 0 || range < 0) {
            throw IllegalArgument();
        }
        switch (type) {
            case SOLDIER:
                return std::make_shared<Soldier>(health, ammo, range, power, team);
            case SNIPER:
                return std::make_shared<Sniper>(health, ammo, range, power, team);
            case MEDIC:
                return std::make_shared<Medic>(health, ammo, range, power, team);
            default:return nullptr;
        }
    }

    void Game::move(const GridPoint &src_coordinates, const GridPoint &dst_coordinates) {
        if (!isLegalCell(src_coordinates) || !isLegalCell(dst_coordinates)) {
            throw IllegalCell();
        }
        isCellEmpty(src_coordinates);
        std::shared_ptr<Character> character_to_move = board.at(src_coordinates.row).at(src_coordinates.col);
        if (!character_to_move->isValidMove(GridPoint::distance(src_coordinates, dst_coordinates))) {
            //todo maybe move this to a function
            throw MoveTooFar();
        }
        if(GridPoint::distance(dst_coordinates,src_coordinates)!=0) {
            isCellOccupied(dst_coordinates);
        }
        board[src_coordinates.row][src_coordinates.col] = nullptr;
        board[dst_coordinates.row][dst_coordinates.col] = character_to_move;
    }

    void Game::reload(const GridPoint &coordinates) {
        if (!isLegalCell(coordinates)) {
            throw IllegalCell();
        }
        isCellEmpty(coordinates);
        std::shared_ptr<Character> character_to_reload = board.at(coordinates.row).at(coordinates.col);
        character_to_reload->reloadAmmo();
    }

    void Game::attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates) {
        if (!isLegalCell(src_coordinates) || !isLegalCell(dst_coordinates)) {
            throw IllegalCell();
        }
        isCellEmpty(src_coordinates);
        std::shared_ptr<Character> attacker = board.at(src_coordinates.row).at(src_coordinates.col);
        std::shared_ptr<Character> target = board.at(dst_coordinates.row).at(dst_coordinates.col);
        if (!attacker->isAttackInRange(GridPoint::distance(src_coordinates, dst_coordinates))) {
            throw OutOfRange();
        }
        if (!attacker->checkEnoughAmmo()) {
            throw OutOfAmmo();
        }
        if (!attacker->isLegalTarget(src_coordinates, dst_coordinates, target)) {
            throw IllegalTarget();
        }
        std::vector<std::shared_ptr<GridPoint>> attack_targets = attacker->getAttackTargets(dst_coordinates);
        for (const std::shared_ptr<GridPoint> &point: attack_targets) {
            if (isLegalCell(*point)) {
                std::shared_ptr<Character> current_target = board.at(point->row).at(point->col); //todo add function
                attacker->attack(current_target, *point == dst_coordinates);
                if (current_target && current_target->isDead()) {
                    board[point->row][point->col] = nullptr;
                    team_players_count[current_target->getTeam()]--;
                }
            }
        }
    }

    bool Game::isOver(Team *winningTeam) const {
        int power_lifters_count = team_players_count.at(POWERLIFTERS);
        int crossfitters_count = team_players_count.at(CROSSFITTERS);
        if ((crossfitters_count > 0 && power_lifters_count > 0) ||
            (power_lifters_count == 0 && crossfitters_count == 0)) {
            return false;
        }
        if (winningTeam) {
            *winningTeam = power_lifters_count > crossfitters_count ? POWERLIFTERS : CROSSFITTERS;
        }
        return true;
    }

    std::ostream &operator<<(std::ostream &os, const Game &game) {
        std::vector<char> board_char_vector;
        for(int row=0; row<game.height; row++ ){
            for(int col=0; col<game.width; col++){
                std::shared_ptr<Character> character = game.board[row][col];
                if(!character){
                    board_char_vector.push_back(game.EMPTY_CELL);
                }
                else{
                    board_char_vector.push_back(character->getCharacterSign());
                }
            }
        }
       return printGameBoard(os, &board_char_vector.front(), &board_char_vector.back()+1, game.width);
    }

    void Game::copyGame(const Game& other){
        team_players_count = other.team_players_count;
        board.resize(height, std::vector<std::shared_ptr<Character>>(width, nullptr));
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if(other.board.at(row).at(col)) {
                    std::shared_ptr<Character> new_character(other.board[row][col]->clone());
                    board.at(row).at(col) = new_character;
                }
            }
        }
    }

    Game::Game(const Game& other):height(other.height),width(other.width){
        copyGame(other);
    }

    Game& Game::operator=(const Game& other){
        if(this == &other){
            return *this;
        }
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                    board.at(row).at(col) = nullptr;
            }
        }
        height = other.height;
        width = other.width;
        copyGame(other);
        return *this;
    }

}
