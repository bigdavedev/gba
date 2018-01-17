#include <gmock/gmock.h>

int main(int argc, char* argv[])
{
	testing::InitGoogleMock(&argc, argv);

	::testing::TestEventListeners& listeners =
		      ::testing::UnitTest::GetInstance()->listeners();
	delete listeners.Release(listeners.default_result_printer());
	  listeners.Append(new ::testing::EmptyTestEventListener);
	return RUN_ALL_TESTS();
}
