#include "doctest.h"
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <complex>

using namespace std;
using namespace WarGame;

Board demo_board_foot(){
    Board board(8,8);
    board[{0,1}] = new FootSoldier(1);
	board[{0,3}] = new FootCommander(1);
	board[{0,5}] = new FootSoldier(1);

    board[{7,1}] = new FootSoldier(2);
	board[{7,3}] = new FootCommander(2);
	board[{7,5}] = new FootSoldier(2);
    return board;
}

Board demo_board_sniper(){
    Board board(8,8);
    board[{0,1}] = new Sniper(1);
	board[{0,3}] = new Sniper(1);
	board[{0,5}] = new SniperCommander(1);

    board[{7,1}] = new Sniper(2);
	board[{7,3}] = new Sniper(2);
	board[{7,5}] = new SniperCommander(2);
    return board;
}

Board demo_board_all(){
    Board board(8,8);
    board[{0,1}] = new FootSoldier(1);
	board[{0,3}] = new FootCommander(1);
	board[{0,5}] = new Sniper(1);
    board[{0,7}] = new SniperCommander(1);
    board[{1,2}] = new Paramedic(1);
    board[{1,5}] = new ParamedicCommander(1);

    board[{7,1}] = new FootSoldier(2);
	board[{7,3}] = new FootCommander(2);
	board[{7,5}] = new Sniper(2);
    board[{7,7}] = new SniperCommander(2);
    board[{6,2}] = new Paramedic(2);
    board[{6,5}] = new ParamedicCommander(2);
    return board;
}

TEST_CASE("Everything"){
    Board board(8,8);
    board[{0,1}] = new FootSoldier(1);
	board[{0,3}] = new FootCommander(1);
	board[{0,5}] = new FootSoldier(1);

    board[{7,1}] = new FootSoldier(2);
	board[{7,3}] = new FootCommander(2);
	board[{7,5}] = new FootSoldier(2);

    CHECK(board[{7,1}]->get_HP()==100);
    CHECK(board[{7,3}]->get_HP()==150);
    CHECK(board[{7,5}]->get_HP()==100);
    CHECK(board[{7,1}]->get_HP()==100);
    CHECK(board[{7,3}]->get_HP()==150);
    CHECK(board[{0,5}]->get_HP()==100);
    CHECK(board[{0,1}]->get_HP()==100);
    CHECK(board[{0,3}]->get_HP()==150);
    CHECK(board[{0,1}]->get_HP()==100);
    CHECK(board[{0,3}]->get_HP()==150);


    CHECK_THROWS(board.move(1,{0,1},Board::MoveDIR::Down));
    CHECK_THROWS(board.move(1,{5,1},Board::MoveDIR::Down));
    CHECK_THROWS(board.move(1,{0,3},Board::MoveDIR::Down));
    CHECK_THROWS(board.move(1,{5,3},Board::MoveDIR::Down));
    CHECK_THROWS(board.move(1,{7,1},Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1,{7,3},Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1,{0,5},Board::MoveDIR::Down));
    CHECK_THROWS(board.move(1,{5,1},Board::MoveDIR::Down));
    CHECK_THROWS(board.move(1,{0,1},Board::MoveDIR::Down));
    CHECK_THROWS(board.move(1,{5,1},Board::MoveDIR::Down));
    CHECK_THROWS(board.move(1,{0,1},Board::MoveDIR::Down));
    CHECK_THROWS(board.move(1,{5,1},Board::MoveDIR::Down));


    board.move(1,{0,1}, Board::MoveDIR::Up);
    CHECK(board[{7,1}]->get_HP()==90);
    CHECK(board.has_soldiers(2)==true);
    CHECK(board[{1,1}]!=nullptr);


    CHECK(board[{7,1}]->get_HP()==90);
    CHECK(board.has_soldiers(2)==true);
    CHECK(board[{7,0}]==nullptr);
    CHECK(board[{2,4}]==nullptr);
    CHECK(board[{2,3}]==nullptr);
    CHECK(board[{2,4}]==nullptr);
    CHECK(board[{6,2}]==nullptr);
    CHECK(board[{7,4}]==nullptr);
    CHECK(board[{5,4}]==nullptr);
    CHECK(board[{4,2}]==nullptr);
    CHECK(board[{6,2}]==nullptr);
    CHECK(board[{6,6}]==nullptr);
    CHECK(board[{5,5}]==nullptr);
    CHECK(board[{2,2}]==nullptr);
    CHECK(board[{3,3}]==nullptr);
    CHECK(board[{4,4}]==nullptr);


}

//TEST_CASE("Location out of board Exception"){
//    Board board=demo_board_foot();
//    CHECK_THROWS(board.move(1,{0,5},Board::MoveDIR::Down));
//    board.move(1,{0,1},Board::MoveDIR::Right);
//    CHECK_THROWS(board.move(1,{0,1},Board::MoveDIR::Right));
//    CHECK_THROWS(board.move(2,{7,1},Board::MoveDIR::Up));
//
//    board.move(1,{0,3},Board::MoveDIR::Up);
//    for(int i=0;i<4;i++){
//        board.move(1,{0,3},Board::MoveDIR::Left);
//    }
//    CHECK_THROWS(board.move(1,{0,3},Board::MoveDIR::Left));
//
//    CHECK_THROWS(board.move(2,{7,3},Board::MoveDIR::Up));
//    CHECK_THROWS(board.move(2,{7,5},Board::MoveDIR::Up));
//
//    board.move(2,{7,1},Board::MoveDIR::Down);
//    board.move(2,{7,1},Board::MoveDIR::Up);
//    CHECK_THROWS(board.move(2,{7,1},Board::MoveDIR::Up));
//}

//TEST_CASE("No soldier in location Exception"){
//    Board board=demo_board_all();
//    CHECK_THROWS(board.move(1,{0,2},Board::MoveDIR::Up));
//    CHECK_THROWS(board.move(1,{0,4},Board::MoveDIR::Up));
//    CHECK_THROWS(board.move(1,{3,4},Board::MoveDIR::Up));
//    board.move(1,{1,2},Board::MoveDIR::Up);
//    CHECK_THROWS(board.move(1,{1,2},Board::MoveDIR::Up));
//    board.move(2,{7,1},Board::MoveDIR::Down);
//    CHECK_THROWS(board.move(2,{7,1},Board::MoveDIR::Down));
//    board.move(2,{6,5},Board::MoveDIR::Left);
//    CHECK_THROWS(board.move(2,{6,5},Board::MoveDIR::Down));
//    board.move(2,{6,2},Board::MoveDIR::Down);
//    CHECK_THROWS(board.move(2,{6,2},Board::MoveDIR::Down));
//}

//TEST_CASE("There is soldier at the direction step Exception"){
//    Board board=demo_board_all();
//    board.move(2,{7,7},Board::MoveDIR::Left);
//    CHECK_THROWS(board.move(2,{7,7},Board::MoveDIR::Left));
//    CHECK_THROWS(board.move(2,{7,5},Board::MoveDIR::Up));
//    board.move(2,{6,7},Board::MoveDIR::Down);
//    CHECK_THROWS(board.move(2,{7,1},Board::MoveDIR::Right));
//    CHECK_THROWS(board.move(2,{7,3},Board::MoveDIR::Left));
//    CHECK_THROWS(board.move(2,{7,2},Board::MoveDIR::Left));
//    CHECK_THROWS(board.move(2,{7,2},Board::MoveDIR::Right));
//    board.move(1,{0,7},Board::MoveDIR::Left);
//    CHECK_THROWS(board.move(1,{1,5},Board::MoveDIR::Up));
//    CHECK_THROWS(board.move(1,{0,6},Board::MoveDIR::Left));
//    board.move(1,{1,2},Board::MoveDIR::Up);
//    CHECK_THROWS(board.move(1,{0,3},Board::MoveDIR::Left));
//    CHECK_THROWS(board.move(1,{0,1},Board::MoveDIR::Right));
//}

TEST_CASE("Soldier belong to another player Exception"){
    Board board = demo_board_all();
    CHECK_THROWS(board.move(1,{7,7},Board::MoveDIR::Left));
    CHECK_THROWS(board.move(1,{7,7},Board::MoveDIR::Right));
    CHECK_THROWS(board.move(1,{6,5},Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1,{7,1},Board::MoveDIR::Right));
    CHECK_THROWS(board.move(1,{7,3},Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1,{6,2},Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1,{5,2},Board::MoveDIR::Left));
    CHECK_THROWS(board.move(2,{1,5},Board::MoveDIR::Down));
    CHECK_THROWS(board.move(2,{0,7},Board::MoveDIR::Left));
    CHECK_THROWS(board.move(2,{0,3},Board::MoveDIR::Left));
    CHECK_THROWS(board.move(2,{0,1},Board::MoveDIR::Left));
    CHECK_THROWS(board.move(1,{7,1},Board::MoveDIR::Left));
    CHECK_THROWS(board.move(1,{7,7},Board::MoveDIR::Right));
    CHECK_THROWS(board.move(1,{6,5},Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1,{7,5},Board::MoveDIR::Right));
    CHECK_THROWS(board.move(1,{7,3},Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1,{6,2},Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1,{5,2},Board::MoveDIR::Left));
    CHECK_THROWS(board.move(1,{5,1},Board::MoveDIR::Left));
    CHECK_THROWS(board.move(1,{5,0},Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1,{4,0},Board::MoveDIR::Right));
    CHECK_THROWS(board.move(1,{4,1},Board::MoveDIR::Right));
    CHECK_THROWS(board.move(1,{4,2},Board::MoveDIR::Right));
    CHECK_THROWS(board.move(1,{4,3},Board::MoveDIR::Right));
    CHECK_THROWS(board.move(1,{4,4},Board::MoveDIR::Right));
    CHECK_THROWS(board.move(1,{7,3},Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1,{6,2},Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1,{5,2},Board::MoveDIR::Left));
    CHECK_THROWS(board.move(2,{1,5},Board::MoveDIR::Down));
    CHECK_THROWS(board.move(2,{0,7},Board::MoveDIR::Left));
    CHECK_THROWS(board.move(2,{0,3},Board::MoveDIR::Left));
}

//TEST_CASE("Moves and Actions Test"){
//    Board board=demo_board_all();
//    board.move(1,{0,1},Board::MoveDIR::Up);//FootSoldier attack
//    CHECK(((board[{6,2}]->HP==90) || (board[{7,1}]->HP==90)));//FootSoldier attack the paramedic or the FootCommander
//    board.move(2,{7,5},Board::MoveDIR::Left);//sniper attack
//    CHECK(board[{1,5}]->HP==200);//sniper attack the ParamedicCommander
//    board.move(1,{0,3},Board::MoveDIR::Up);//FootCommander attack
//    CHECK(((board[{6,2}]->HP==70) || (board[{7,3}]->HP==130)));//FootCommander attack the Paramedic or FootCommander
//    CHECK(((board[{6,2}]->HP==60) || (board[{7,1}]->HP==120)));//All other FootSoldiers attack
//    board.move(2,{6,2},Board::MoveDIR::Right);//paramedic heal FootSoldier
//    CHECK(board[{7,1}]->HP==100);//FootCommander's life now full
//    board.move(1,{0,7},Board::MoveDIR::Up);//SniperCommander attack
//    CHECK(board[{6,5}]->HP==100);//SniperCommander attack the ParamedicCommander
//    CHECK(((board[{7,3}]->HP==80) ||(board[{7,1}]->HP==70)));//All other snipers attack
//    board.move(2,{7,3},Board::MoveDIR::Down);//FootCommander attack
//    CHECK(board[{1,3}]->HP==130);//FootCommander attack the FootCommander
//    CHECK(board[{1,1}]->HP==90);//All other FootSoldiers attack
//}

//TEST_CASE("After action - check HP to the right soldier-  Test"){
//
//}

TEST_CASE("Init HP Test"){
    Board board = demo_board_all();
    CHECK(board[{0,1}]->HP==100);
    CHECK(board[{0,3}]->HP==150);
    CHECK(board[{0,5}]->HP==100);
    CHECK(board[{0,7}]->HP==120);
    CHECK(board[{1,2}]->HP==100);
    CHECK(board[{1,5}]->HP==200);
    CHECK(board[{7,1}]->HP==100);
    CHECK(board[{7,3}]->HP==150);
    CHECK(board[{7,5}]->HP==100);
    CHECK(board[{7,7}]->HP==120);
    CHECK(board[{0,1}]->HP==100);
    CHECK(board[{0,3}]->HP==150);
    CHECK(board[{0,5}]->HP==100);
    CHECK(board[{0,7}]->HP==120);
    CHECK(board[{1,2}]->HP==100);
    CHECK(board[{1,5}]->HP==200);
    CHECK(board[{7,1}]->HP==100);
    CHECK(board[{7,3}]->HP==150);
    CHECK(board[{7,5}]->HP==100);
    CHECK(board[{7,7}]->HP==120);
    CHECK(board[{0,1}]->HP==100);
    CHECK(board[{0,3}]->HP==150);
    CHECK(board[{0,5}]->HP==100);
    CHECK(board[{0,7}]->HP==120);
    CHECK(board[{1,2}]->HP==100);
    CHECK(board[{1,5}]->HP==200);
    CHECK(board[{7,1}]->HP==100);
    CHECK(board[{7,3}]->HP==150);
}

//TEST_CASE("demo_board_all General Tests"){
//    Board board = demo_board_all();
//    CHECK_THROWS(board.move(1,{0,5},Board::MoveDIR::Up));
//    CHECK(board[{0,5}]->HP==100);
//    CHECK_THROWS(board.move(1,{1,5},Board::MoveDIR::Down));
//    CHECK(board[{1,5}]->HP==200);
//    CHECK(board[{6,5}]->HP==200);
//    board.move(1,{0,5},Board::MoveDIR::Right);
//    CHECK(board[{6,5}]->HP==200);
//    board.move(2,{7,1},Board::MoveDIR::Down);
//    CHECK(board[{0,1}]->HP==90);
//    board.move(1,{0,1},Board::MoveDIR::Up);
//    CHECK(board[{6,1}]->HP==90);
//    board.move(2,{6,1},Board::MoveDIR::Up);
//    board.move(2,{7,1},Board::MoveDIR::Down);
//    CHECK(board[{1,1}]->HP==70);
//    board.move(1,{1,1},Board::MoveDIR::Up);
//    CHECK(board[{6,1}]->HP==80);
//    board.move(1,{0,1},Board::MoveDIR::Down);
//    CHECK(board[{6,1}]->HP==70);
//    board.move(1,{1,1},Board::MoveDIR::Up);
//    CHECK(board[{6,1}]->HP==60);
//    board.move(1,{0,1},Board::MoveDIR::Down);
//    CHECK(board[{6,1}]->HP==50);
//    board.move(1,{1,1},Board::MoveDIR::Up);
//    CHECK(board[{6,1}]->HP==40);
//    board.move(1,{0,1},Board::MoveDIR::Down);
//    CHECK(board[{6,1}]->HP==30);
//    board.move(1,{1,1},Board::MoveDIR::Up);
//    CHECK(board[{6,1}]->HP==20);
//    board.move(1,{0,1},Board::MoveDIR::Down);
//    CHECK(board[{6,1}]->HP==10);
//    board.move(1,{1,1},Board::MoveDIR::Up);
//    CHECK(board[{6,1}]==nullptr);// die
//    board.move(1,{1,2},Board::MoveDIR::Down);
//    CHECK(board[{0,1}]->HP==100);
//}

//TEST_CASE("demo_board_sniper General Tests"){
//    Board board = demo_board_all();
//    board.move(1,{0,5},Board::MoveDIR::Up);
//    CHECK(board[{7,1}]->HP==50);
//    CHECK(board[{7,3}]->HP==50);
//    CHECK(board[{7,5}]->HP==20);
//    board.move(1,{1,5},Board::MoveDIR::Down);
//    CHECK(board[{7,1}]==nullptr);
//    CHECK(board[{7,3}]==nullptr);
//    CHECK(board[{7,5}]==nullptr);
//
//    Board board2 = demo_board_all();
//    board.move(2,{7,5},Board::MoveDIR::Down);
//    CHECK(board[{0,1}]->HP==50);
//    CHECK(board[{0,3}]->HP==50);
//    CHECK(board[{0,5}]->HP==20);
//    board.move(2,{6,5},Board::MoveDIR::Up);
//    CHECK(board[{0,1}]==nullptr);
//    CHECK(board[{0,3}]==nullptr);
//    CHECK(board[{0,5}]==nullptr);
//}