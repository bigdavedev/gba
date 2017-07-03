#pragma once

#include <gmock/gmock.h>
#include "video.h"

class mock_display_control
{
public:
	MOCK_CONST_METHOD2(set_display_control,
	                   void(dcnt_video_mode_t,
	                        dcnt_background_t));
};
