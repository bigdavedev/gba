#pragma once

#include <gmock/gmock.h>
#include "video.h"

class mock_display_control : public idisplay_ctl
{
public:
	MOCK_METHOD2(set, void(dcnt_video_mode, dcnt_background_mode));
};
