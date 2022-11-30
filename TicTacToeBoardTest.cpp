/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

using namespace std;

 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} 
		virtual ~TicTacToeBoardTest(){} 
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};




TEST(TicTacToeBoardTest, smoke_test)
{
    ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, toggleTest) { // Should Pass
	TicTacToeBoard obj;
	char result = obj.toggleTurn();
	ASSERT_EQ(result, O);
}



TEST(TicTacToeBoardTest, placePieceTest1) { // Should Pass, testing placing first piece X
	TicTacToeBoard obj;
	char result = obj.placePiece(1,2);
	ASSERT_EQ(X, result);
}

TEST(TicTacToeBoardTest, placePieceTest2) { // Should Pass, testing placing second piece O
	TicTacToeBoard obj;
	obj.placePiece(2,2);
	char result = obj.placePiece(1,2);
	ASSERT_EQ(O, result);
}

TEST(TicTacToeBoardTest, placePieceTest3) {  // Should Fail, testing placing X out of bounds
	TicTacToeBoard obj;
	char result = obj.placePiece(3,2);
	ASSERT_EQ(X, result); 
}

TEST(TicTacToeBoardTest, placePieceTest3B) {  // Should Pass, testing placing X out of bounds, should return invalid
	TicTacToeBoard obj;
	char result = obj.placePiece(3,2);
	ASSERT_EQ(Invalid, result); 
}

TEST(TicTacToeBoardTest, placePieceTest4) { // Should Pass, testing placing X out of bounds then placing X in bounds
	TicTacToeBoard obj;
	obj.placePiece(3,2);
	char result = obj.placePiece(1,2);
	ASSERT_EQ(X, result);
}

TEST(TicTacToeBoardTest, placePieceTest5) { // Should Pass, testing placing X, then O, then X on top of O which returns O
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(0,2);
	char result = obj.placePiece(0,2);
	ASSERT_EQ(O, result);
}

TEST(TicTacToeBoardTest, placePieceTest6) { // Should Pass, testing placing X then O then X on top of O which makes it X's turn again
	TicTacToeBoard obj;
	obj.placePiece(0,0); // X
	obj.placePiece(0,2); // O
	obj.placePiece(0,2); // O 
	char result = obj.placePiece(1,2); // X
	ASSERT_EQ(X, result);
}

TEST(TicTacToeBoardTest, placePieceTest7) { // Should Fail, testing placing X out of bounds then placing x in bounds
	TicTacToeBoard obj;
	obj.placePiece(400,2);
	char result = obj.placePiece(2,2);
	ASSERT_EQ(O, result);
}











TEST(TicTacToeBoardTest, getPieceTest) {
	TicTacToeBoard obj3;

	obj3.placePiece(2,2);
	char result = obj3.getPiece(2,2);
	ASSERT_EQ(X, result);

	char result2 = obj3.getPiece(4,2);
	ASSERT_EQ(Invalid, result2);
}

TEST(TicTacToeBoardTest, getWinnerTest) {
	TicTacToeBoard obj;

	// obj.placePiece(0,0);
	// obj.placePiece(0,1);
	// obj.placePiece(1,1);
	// obj.placePiece(0,2);
	// obj.placePiece(2,2);

	obj.placePiece(0,0); // X
	obj.placePiece(0,2); // O
	obj.placePiece(0,1); // X
	obj.placePiece(1,0); // O
	obj.placePiece(1,2); // X
	obj.placePiece(1,1); // O
	obj.placePiece(2,0); // X
	obj.placePiece(2,1); // O
	obj.placePiece(2,2); // X

	char result = obj.getWinner();
	ASSERT_EQ(Blank, result);
}

TEST(TicTacToeBoardTest, gameTest) {
	TicTacToeBoard obj5;
[O
	// obj5.placePiece(0,0);
	// obj5.placePiece(0,1);
	// obj5.placePiece(1,1);
	// obj5.placePiece(0,2);
	// obj5.placePiece(2,2);

	obj5.placePiece(0,0);
	obj5.placePiece(0,2);
	obj5.placePiece(0,1);
	obj5.placePiece(1,0);
	obj5.placePiece(1,2);
	obj5.placePiece(1,1);
	obj5.placePiece(2,0);
	obj5.placePiece(2,1);
	obj5.placePiece(2,2);

	char result1 = obj5.getPiece(0,0);
	char result2 = obj5.getPiece(0,1);
	char result3 = obj5.getPiece(0,2);
	char result4 = obj5.getPiece(1,0);
	char result5 = obj5.getPiece(1,1);
	char result6 = obj5.getPiece(1,2);
	char result7 = obj5.getPiece(2,0);
	char result8 = obj5.getPiece(2,1);
	char result9 = obj5.getPiece(2,2);

	cout << result1 << " " << result2 << " " << result3 << endl;
	cout << result4 << " " << result5 << " " << result6 << endl;
	cout << result7 << " " << result8 << " " << result9 << endl;



}

//(0,0) (0,1) (0,2)
//(1,0) (1,1) (1,2)
//(2,0) (2,1) (2,2)
