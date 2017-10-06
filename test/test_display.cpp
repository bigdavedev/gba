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
	memory::REG_DISPCNT::value_type reg = {};
	EXPECT_CALL(display_control, set(_,_));
	display disp{display_control};

	disp.set_display_control(DCNT_MODE3, DCNT_BG2);
}
