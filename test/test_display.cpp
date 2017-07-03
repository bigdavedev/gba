#include <gmock/gmock.h>

#include "mocks/mock_dispay_control.h"

using namespace testing;

class TestDisplay : public Test
{
protected:
	NiceMock<mock_display_control> display_control;
};

TEST_F(TestDisplay, Foo)
{
	EXPECT_CALL(display_control, set_display_control(_,_));
	display<mock_display_control> disp{display_control};

	disp.set_display_control(DCNT_MODE3, DCNT_BG2);
}
