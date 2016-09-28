#include "gtest/gtest.h"
#include "gmock/gmock.h"
using ::testing::AtLeast;

class Turtle {
public:

	virtual ~Turtle() {}
	virtual void PenDown() = 0;
	virtual void Forward(int distance) = 0;
	virtual void Turn(int degrees) = 0;
	virtual void GoTo(int x, int y) = 0;
	virtual int GetX() const = 0;
};

class MockTurtle : public Turtle {
	public:

	MOCK_METHOD0(PenDown, void());
	MOCK_METHOD1(Forward, void(int distance));
	MOCK_METHOD1(Turn, void(int degrees));
	MOCK_METHOD2(GoTo, void(int x, int y));
	MOCK_CONST_METHOD0(GetX, int());
};


TEST(MockAtLeastTest, DidNotCall) {
	MockTurtle turtle;                       
	EXPECT_CALL(turtle, PenDown() )             
		.Times(AtLeast(1));

}

TEST(MockAtLeastTest, CalledJustOnce) {
	MockTurtle turtle;                         
	EXPECT_CALL(turtle, PenDown() )             
		.Times(AtLeast(1));

	turtle.PenDown();
}        

TEST(MockAtLeastTest, CalledOverOnce) {
	MockTurtle turtle;                         
	EXPECT_CALL(turtle, PenDown() )              
		.Times(AtLeast(1));

	turtle.PenDown();
	turtle.PenDown();
}        

////

TEST(MockCalledTimesTest, CalledExactlyTwice) {
	MockTurtle turtle;                         
	EXPECT_CALL(turtle, PenDown() )              
		.Times(2);

	turtle.PenDown();
	turtle.PenDown();
}

TEST(MockCalledTimesTest, CalledOverTwice) {
	MockTurtle turtle;                         
	EXPECT_CALL(turtle, PenDown() )              
		.Times(2);

	turtle.PenDown();
	turtle.PenDown();
    turtle.PenDown();
}

TEST(MockCalledTimesTest, CalledLessThanTwice) {
	MockTurtle turtle;                         
	EXPECT_CALL(turtle, PenDown() )              
		.Times(2);

	turtle.PenDown();
}        
