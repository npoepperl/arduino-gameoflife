#include "TestFixture.h"
#include "GameOfLife.h"

TestFixture::TestFixture(){

}

TestFixture::~TestFixture(){

}

TEST_F(TestFixture, CallFunctionFromLib){
    ClassUnderTest objectUnderTest;
    objectUnderTest.TestFunction();

    ASSERT_TRUE(true);
}