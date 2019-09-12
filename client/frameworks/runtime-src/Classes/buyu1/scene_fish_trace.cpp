
//#include "stdafx.h"
#include "scene_fish_trace.h"
#include <math.h>
#include <iterator> 
#include "cocos2d.h"

static const float kResolutionWidth = 1366;
static const float kResolutionHeight = 768;
std::vector<FPointAngle>::size_type scene_kind_2_small_fish_stop_index_[200];
std::vector<FPointAngle>::size_type scene_kind_2_small_fish_stop_count_ = 0;
std::vector<FPointAngle>::size_type scene_kind_2_big_fish_stop_index_ = 0;
std::vector<FPointAngle>::size_type scene_kind_2_big_fish_stop_count_ = 0;
std::vector<FPointAngle> scene_kind_1_trace_[SCENE_KIND_1_TRACNENUM];
std::vector<FPointAngle> scene_kind_2_trace_[SCENE_KIND_2_TRACNENUM];
std::vector<FPointAngle> scene_kind_3_trace_[SCENE_KIND_3_TRACNENUM];
std::vector<FPointAngle> scene_kind_4_trace_[SCENE_KIND_4_TRACNENUM];
std::vector<FPointAngle> scene_kind_5_trace_[SCENE_KIND_5_TRACNENUM];
static void ChangToGLPos(cocos2d::CCPoint *fpoint)
{
	cocos2d::CCPoint t_pos = cocos2d::CCDirector::sharedDirector()->convertToGL(cocos2d::CCPointMake(fpoint->x, fpoint->y));
	cocos2d::CCSize size = cocos2d::CCDirector::sharedDirector()->getVisibleSize();
	//x=t_pos.x;
	fpoint->x=t_pos.x;
	fpoint->y=t_pos.y;

}
static void ChangToGLPos(float&x, float &y)
{
	cocos2d::CCPoint t_pos = cocos2d::CCDirector::sharedDirector()->convertToGL(cocos2d::CCPointMake(x, y));
	//CSize size=CCDirector::sharedDirector()->getVisibleSize();
	//x=t_pos.x;
	x=t_pos.x;
	y=t_pos.y;

}
void BuildSceneKind1Trace(float screen_width, float screen_height)
{
	if (scene_kind_1_trace_[0].size() > 0)return;
	int fish_count = 0;
	const float kVScale = screen_height / kResolutionHeight;
	const float kRadius = (screen_height - (240 * kVScale)) / 2;
	const float kSpeed = 1.5f * screen_width / kResolutionWidth;
	FPoint fish_pos[100];
	FPoint center;
	FPoint center1;
	center.x = screen_width + kRadius+50;
	center.y = kRadius + 120 * kVScale;
	center1=center;
	ChangToGLPos(center1.x, center1.y);
	MathAide::BuildCircle(center1.x, center1.y, kRadius, fish_pos, 100);
	float init_x[2], init_y[2];
	for (int i = 0; i < 100; ++i)
	{
		init_x[0] = fish_pos[i].x;
		init_y[0] = fish_pos[i].y;
		init_x[1] = -2 * kRadius;
		init_y[1] = init_y[0];
        ChangToGLPos(init_x[0],init_y[0]);
		ChangToGLPos(init_x[1],init_y[1]);
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_1_trace_[i], kSpeed);
	}
	fish_count += 100;

	const float kRotateRadian1 = 45 * M_PI / 180;
	const float kRotateRadian2 = 135 * M_PI / 180;
	const float kRadiusSmall = kRadius / 2;
	const float kRadiusSmall1 = kRadius / 3;
	FPoint center_small[4];
	center_small[0].x = center.x + kRadiusSmall * cosf(-kRotateRadian2);
	center_small[0].y = center.y + kRadiusSmall * sinf(-kRotateRadian2);
	center_small[1].x = center.x + kRadiusSmall * cosf(-kRotateRadian1);
	center_small[1].y = center.y + kRadiusSmall * sinf(-kRotateRadian1);
	center_small[2].x = center.x + kRadiusSmall * cosf(kRotateRadian2);
	center_small[2].y = center.y + kRadiusSmall * sinf(kRotateRadian2);
	center_small[3].x = center.x + kRadiusSmall * cosf(kRotateRadian1);
	center_small[3].y = center.y + kRadiusSmall * sinf(kRotateRadian1);
	ChangToGLPos(center_small[0].x, center_small[0].y);
	MathAide::BuildCircle(center_small[0].x, center_small[0].y, kRadiusSmall1, fish_pos, 17);
	for (int i = 0; i < 17; ++i)
	{
		init_x[0] = fish_pos[i].x;
		init_y[0] = fish_pos[i].y;
		init_x[1] = -2 * kRadius;
		init_y[1] = init_y[0];
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_1_trace_[fish_count + i], kSpeed);
	}
	fish_count += 17;
	ChangToGLPos(center_small[1].x, center_small[1].y);
	MathAide::BuildCircle(center_small[1].x, center_small[1].y, kRadiusSmall1, fish_pos, 17);
	for (int i = 0; i < 17; ++i)
	{
		init_x[0] = fish_pos[i].x;
		init_y[0] = fish_pos[i].y;
		init_x[1] = -2 * kRadius;
		init_y[1] = init_y[0];
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_1_trace_[fish_count + i], kSpeed);
	}
	fish_count += 17;
	ChangToGLPos(center_small[2].x, center_small[2].y);
	MathAide::BuildCircle(center_small[2].x, center_small[2].y, kRadiusSmall1, fish_pos, 30);
	for (int i = 0; i < 30; ++i)
	{
		init_x[0] = fish_pos[i].x;
		init_y[0] = fish_pos[i].y;
		init_x[1] = -2 * kRadius;
		init_y[1] = init_y[0];
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_1_trace_[fish_count + i], kSpeed);
	}
	fish_count += 30;
	ChangToGLPos(center_small[3].x, center_small[3].y);
	MathAide::BuildCircle(center_small[3].x, center_small[3].y, kRadiusSmall1, fish_pos, 30);
	for (int i = 0; i < 30; ++i)
	{
		init_x[0] = fish_pos[i].x;
		init_y[0] = fish_pos[i].y;
		init_x[1] = -2 * kRadius;
		init_y[1] = init_y[0];
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_1_trace_[fish_count + i], kSpeed);
	}
	fish_count += 30;
	center1=center;
	ChangToGLPos(center1.x, center1.y);
	MathAide::BuildCircle(center1.x, center1.y, kRadiusSmall / 2, fish_pos, 15);
	for (int i = 0; i < 15; ++i)
	{
		init_x[0] = fish_pos[i].x;
		init_y[0] = fish_pos[i].y;
		init_x[1] = -2 * kRadius;
		init_y[1] = init_y[0];
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_1_trace_[fish_count + i], kSpeed);
	}
	fish_count += 15;

	init_x[0] = center.x;
	init_y[0] = center.y;
	init_x[1] = -2 * kRadius;
	init_y[1] = init_y[0];
	MathAide::BuildLinear(init_x, init_y, 2, scene_kind_1_trace_[fish_count], kSpeed);
	for (std::vector<FPointAngle>::iterator iter = scene_kind_1_trace_[fish_count].begin(); iter != scene_kind_1_trace_[fish_count].end(); ++iter) {
		(*iter).angle = -M_PI_2;//.f;
	}
	fish_count += 1;
}

void BuildSceneKind2Trace(float screen_width, float screen_height) {
	if (scene_kind_2_trace_[0].size() > 0)return;
	const float kHScale = screen_width / kResolutionWidth;
	const float kVScale = screen_height / kResolutionHeight;
	const float kStopExcursion = 180.f * kVScale;
	const float kHExcursion = 27.f * kHScale / 2;
	const float kSmallFishInterval = (screen_width - kHExcursion * 2) / 100;
	float kSmallFishHeight = 65.f * kVScale;
	const float kSpeed = 3.f * kHScale;

	int fish_count = 0;
	float init_x[2], init_y[2];
	int small_height = (int)kSmallFishHeight * 3;
	for (int i = 0; i < 200; ++i)
	{
		init_x[0] = init_x[1] = kHExcursion + (i % 100) * kSmallFishInterval;
		int excursion = rand() % small_height;
		/*if (i < 100) {
		init_y[0] = -kSmallFishHeight - excursion;
		init_y[1] = screen_height + kSmallFishHeight;
		} else {
		init_y[0] = screen_height + kSmallFishHeight + excursion;
		init_y[1] = -kSmallFishHeight;
		}*/
		// 这个地方如果写成上方注释的那样（也就是kSmallFishHeight这个值）,后面的BuildLinear只能生成2个也就是init_x,init_y这2个点的值 写成65.f * kVScale也是一样
		// 只能写成下面的65.f的这个具体数字才正常,而且这种情况只出现在release的情况下,DEBUG下上面那样写是正常的.可能是VS2003的BUG? 因为我用VS2008测试release情况
		// 也是没问题的,或者是其他原因???
		if (i<100)//上排
		{
			init_y[0] = -65.f - excursion;
			init_y[1] = screen_height + 65.f;
		}
		else //下排
		{
			init_y[0] = screen_height + 65.f + excursion;
			init_y[1] = -65.f;
		}
		ChangToGLPos(init_x[0],init_y[0]);
		ChangToGLPos(init_x[1],init_y[1]);
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_2_trace_[i], kSpeed);
	}
	fish_count += 200;
	//大鱼
	float big_fish_width[7] = { 270 * kHScale, 226 * kHScale, 375 * kHScale, 420 * kHScale, 540 * kHScale, 454 * kHScale, 600 * kHScale };
	float big_fish_excursion[7];
	for (int i = 0; i < 7; ++i) 
	{
		big_fish_excursion[i] = big_fish_width[i];
		for (int j = 0; j < i; ++j) 
		{
			big_fish_excursion[i] += big_fish_width[j];
		}
	}
	float y_excursoin = 250 * kVScale / 2;

	for (int i = 0; i < 14; ++i) 
	{
		if (i < 7) 
		{
			init_y[0] = init_y[1] = screen_height / 2 - y_excursoin;
			init_x[0] = -big_fish_excursion[i % 7];
			init_x[1] = screen_width + big_fish_width[i % 7];
			ChangToGLPos(init_x[0],init_y[0]);
			ChangToGLPos(init_x[1],init_y[1]);
			MathAide::BuildLinear(init_x, init_y, 2, scene_kind_2_trace_[fish_count + i], kSpeed);
		}
		else
		{
			init_y[0] = init_y[1] = screen_height / 2 + y_excursoin;
			init_x[0] = screen_width + big_fish_excursion[i % 7];
			init_x[1] = -big_fish_width[i % 7];
			ChangToGLPos(init_x[0],init_y[0]);
			ChangToGLPos(init_x[1],init_y[1]);
			MathAide::BuildLinear(init_x, init_y, 2, scene_kind_2_trace_[fish_count + i], kSpeed);
		}
	}

	std::vector<FPointAngle> small_fish_trace;
	init_x[0] = init_x[1] = 0.f;
	init_y[0] = -2 * kSmallFishHeight;
	init_y[1] = kStopExcursion;
	ChangToGLPos(init_x[0],init_y[0]);
	ChangToGLPos(init_x[1],init_y[1]);
	MathAide::BuildLinear(init_x, init_y, 2, small_fish_trace, kSpeed);

	std::vector<FPointAngle> big_fish_trace;
	init_y[0] = init_y[1] = 0.f;
	init_x[0] = -big_fish_excursion[6];
	init_x[1] = screen_width + big_fish_width[6];
	ChangToGLPos(init_x[0],init_y[0]);
	ChangToGLPos(init_x[1],init_y[1]);
	MathAide::BuildLinear(init_x, init_y, 2, big_fish_trace, kSpeed);
	//小鱼调整
	std::vector<FPointAngle>::size_type big_stop_count = 0;
	for (int i = 0; i < 200; ++i)
	{
		for (std::vector<FPointAngle>::size_type j = 0; j < scene_kind_2_trace_[i].size(); ++j)
		{
			FPointAngle& pos = scene_kind_2_trace_[i][j];
			//和PC坐标反向
			if (i > 100) 
			{
				if (pos.y >= kStopExcursion)//停止点
				{
					scene_kind_2_small_fish_stop_index_[i] = j;
					if (big_stop_count == 0) big_stop_count = j;
					else if (big_stop_count < j) big_stop_count = j;
					break;
				}
			}
			else
			{
				if (pos.y < screen_height - kStopExcursion) 
{
					scene_kind_2_small_fish_stop_index_[i] = j;
					if (big_stop_count == 0) big_stop_count = j;
					else if (big_stop_count < j) big_stop_count = j;
					break;
				}
			}
		}
	}

	scene_kind_2_small_fish_stop_count_ = big_fish_trace.size();
	scene_kind_2_big_fish_stop_index_ = 0;
	scene_kind_2_big_fish_stop_count_ = big_stop_count + 1;
}

void BuildSceneKind3Trace(float screen_width, float screen_height) {
	if (scene_kind_3_trace_[0].size() > 0)return;
	int fish_count = 0;
	const float kVScale = screen_height / kResolutionHeight;
	const float kRadius = (screen_height - (240 * kVScale)) / 2;
	const float kSpeed = 1.5f * screen_width / kResolutionWidth;
	FPoint fish_pos[100];
	FPoint center;
	center.x = screen_width + kRadius;
	center.y = kRadius + 120 * kVScale;
	MathAide::BuildCircle(center.x, center.y, kRadius, fish_pos, 50);
	float init_x[2], init_y[2];
	for (int i = 0; i < 50; ++i) 
	{
		init_x[0] = fish_pos[i].x;
		init_y[0] = fish_pos[i].y;
		init_x[1] = -2 * kRadius;
		init_y[1] = init_y[0];
		ChangToGLPos(init_x[0],init_y[0]);
		ChangToGLPos(init_x[1],init_y[1]);
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_3_trace_[i], kSpeed);
	}
	fish_count += 50;

	MathAide::BuildCircle(center.x, center.y, kRadius * 40 / 50, fish_pos, 40);
	for (int i = 0; i < 40; ++i) 
	{
		init_x[0] = fish_pos[i].x;
		init_y[0] = fish_pos[i].y;
		init_x[1] = -2 * kRadius;
		init_y[1] = init_y[0];
		ChangToGLPos(init_x[0],init_y[0]);
		ChangToGLPos(init_x[1],init_y[1]);
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_3_trace_[fish_count + i], kSpeed);
	}
	fish_count += 40;

	MathAide::BuildCircle(center.x, center.y, kRadius * 30 / 50, fish_pos, 30);
	for (int i = 0; i < 30; ++i)
	{
		init_x[0] = fish_pos[i].x;
		init_y[0] = fish_pos[i].y;
		init_x[1] = -2 * kRadius;
		init_y[1] = init_y[0];
		ChangToGLPos(init_x[0],init_y[0]);
		ChangToGLPos(init_x[1],init_y[1]);
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_3_trace_[fish_count + i], kSpeed);
	}
	fish_count += 30;

	init_x[0] = center.x;
	init_y[0] = center.y;
	init_x[1] = -2 * kRadius;
	init_y[1] = init_y[0];
	ChangToGLPos(init_x[0],init_y[0]);
	ChangToGLPos(init_x[1],init_y[1]);
	MathAide::BuildLinear(init_x, init_y, 2, scene_kind_3_trace_[fish_count], kSpeed);
	fish_count += 1;

	center.x = -kRadius;
	MathAide::BuildCircle(center.x, center.y, kRadius, fish_pos, 50);
	for (int i = 0; i < 50; ++i) 
	{
		init_x[0] = fish_pos[i].x;
		init_y[0] = fish_pos[i].y;
		init_x[1] = screen_width + 2 * kRadius;
		init_y[1] = init_y[0];
		ChangToGLPos(init_x[0],init_y[0]);
		ChangToGLPos(init_x[1],init_y[1]);
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_3_trace_[fish_count + i], kSpeed);
	}
	fish_count += 50;

	MathAide::BuildCircle(center.x, center.y, kRadius * 40 / 50, fish_pos, 40);
	for (int i = 0; i < 40; ++i)
	{
		init_x[0] = fish_pos[i].x;
		init_y[0] = fish_pos[i].y;
		init_x[1] = screen_width + 2 * kRadius;
		init_y[1] = init_y[0];
		ChangToGLPos(init_x[0],init_y[0]);
		ChangToGLPos(init_x[1],init_y[1]);
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_3_trace_[fish_count + i], kSpeed);
	}
	fish_count += 40;

	MathAide::BuildCircle(center.x, center.y, kRadius * 30 / 50, fish_pos, 30);
	for (int i = 0; i < 30; ++i)
	{
		init_x[0] = fish_pos[i].x;
		init_y[0] = fish_pos[i].y;
		init_x[1] = screen_width + 2 * kRadius;
		init_y[1] = init_y[0];
		ChangToGLPos(init_x[0],init_y[0]);
		ChangToGLPos(init_x[1],init_y[1]);
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_3_trace_[fish_count + i], kSpeed);
	}
	fish_count += 30;

	init_x[0] = center.x;
	init_y[0] = center.y;
	init_x[1] = screen_width + 2 * kRadius;
	init_y[1] = init_y[0];
	ChangToGLPos(init_x[0],init_y[0]);
	ChangToGLPos(init_x[1],init_y[1]);
	MathAide::BuildLinear(init_x, init_y, 2, scene_kind_3_trace_[fish_count], kSpeed);
	fish_count += 1;
}

void BuildSceneKind4Trace(float screen_width, float screen_height)
{
	if (scene_kind_4_trace_[0].size() > 0)return;
	const float kHScale = screen_width / kResolutionWidth;
	const float kVScale = screen_height / kResolutionHeight;
	const float kSpeed = 3.f * kHScale;
	const float kFishWidth = 512 * kHScale;
	const float kFishHeight = 304 * kVScale;
	int fish_count = 0;
	float init_x[2], init_y[2];
	// 左下
	FPoint start_pos = { 0.f, screen_height - kFishHeight / 2 };
	FPoint target_pos = { screen_width - kFishHeight / 2, 0.f };
	float angle = acosf((target_pos.x - start_pos.x) / MathAide::CalcDistance(target_pos.x, target_pos.y, start_pos.x, start_pos.y));
	float radius = kFishWidth * 4;
	float length = radius + kFishWidth / 2.f;
	FPoint center_pos;
	center_pos.x = -length * cosf(angle);
	center_pos.y = start_pos.y + length * sinf(angle);
	init_x[1] = target_pos.x + kFishWidth;
	init_y[1] = target_pos.y - kFishHeight;
	for (int i = 0; i < 8; ++i)
	{
		if (radius < 0.f)
		{
			init_x[0] = center_pos.x + radius * cosf(angle);
			init_y[0] = center_pos.y - radius * sinf(angle);
		} 
		else 
		{
			init_x[0] = center_pos.x - radius * cosf(angle + M_PI);
			init_y[0] = center_pos.y + radius * sinf(angle + M_PI);
		}
		ChangToGLPos(init_x[0],init_y[0]);
		ChangToGLPos(init_x[1],init_y[1]);
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_4_trace_[i], kSpeed);
		radius -= kFishWidth;
	}
	fish_count += 8;
	start_pos.x = kFishHeight / 2;
	start_pos.y = screen_height;
	target_pos.x = screen_width;
	target_pos.y = kFishHeight / 2;
	angle = acosf((target_pos.x - start_pos.x) / MathAide::CalcDistance(target_pos.x, target_pos.y, start_pos.x, start_pos.y));
	radius = kFishWidth * 4;
	length = radius + kFishWidth / 2.f;
	center_pos.x = start_pos.x - length * cosf(angle);
	center_pos.y = start_pos.y + length * sinf(angle);
	init_x[1] = target_pos.x + kFishWidth;
	init_y[1] = target_pos.y - kFishHeight;
	for (int i = 0; i < 8; ++i) 
	{
		if (radius < 0.f)
		{
			init_x[0] = center_pos.x + radius * cosf(angle);
			init_y[0] = center_pos.y - radius * sinf(angle);
		} 
		else 
		{
			init_x[0] = center_pos.x - radius * cosf(angle + M_PI);
			init_y[0] = center_pos.y + radius * sinf(angle + M_PI);
		}
		ChangToGLPos(init_x[0],init_y[0]);
		ChangToGLPos(init_x[1],init_y[1]);
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_4_trace_[fish_count + i], kSpeed);
		radius -= kFishWidth;
	}
	fish_count += 8;

	// 右下
	start_pos.x = screen_width - kFishHeight / 2;
	start_pos.y = screen_height;
	target_pos.x = 0.f;
	target_pos.y = kFishHeight / 2;
	angle = acosf((start_pos.x - target_pos.x) / MathAide::CalcDistance(target_pos.x, target_pos.y, start_pos.x, start_pos.y));
	radius = kFishWidth * 4;
	length = radius + kFishWidth / 2.f;
	center_pos.x = start_pos.x + length * cosf(angle);
	center_pos.y = start_pos.y + length * sinf(angle);
	init_x[1] = target_pos.x - kFishWidth;
	init_y[1] = target_pos.y - kFishHeight;
	for (int i = 0; i < 8; ++i)
	{
		if (radius < 0.f) 
		{
			init_x[0] = center_pos.x - radius * cosf(angle + M_PI);
			init_y[0] = center_pos.y - radius * sinf(angle + M_PI);
		} else {
			init_x[0] = center_pos.x - radius * cosf(angle);
			init_y[0] = center_pos.y - radius * sinf(angle);
		}
		ChangToGLPos(init_x[0],init_y[0]);
		ChangToGLPos(init_x[1],init_y[1]);
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_4_trace_[fish_count + i], kSpeed);
		radius -= kFishWidth;
	}
	fish_count += 8;

	start_pos.x = screen_width;
	start_pos.y = screen_height - kFishHeight / 2;
	target_pos.x = kFishHeight / 2;
	target_pos.y = 0.f;
	angle = acosf((start_pos.x - target_pos.x) / MathAide::CalcDistance(target_pos.x, target_pos.y, start_pos.x, start_pos.y));
	radius = kFishWidth * 4;
	length = radius + kFishWidth / 2.f;
	center_pos.x = start_pos.x + length * cosf(angle);
	center_pos.y = start_pos.y + length * sinf(angle);
	init_x[1] = target_pos.x - kFishWidth;
	init_y[1] = target_pos.y - kFishHeight;
	for (int i = 0; i < 8; ++i) 
	{
		if (radius < 0.f)
		{
			init_x[0] = center_pos.x - radius * cosf(angle + M_PI);
			init_y[0] = center_pos.y - radius * sinf(angle + M_PI);
		} 
		else
		{
			init_x[0] = center_pos.x - radius * cosf(angle);
			init_y[0] = center_pos.y - radius * sinf(angle);
		}
		ChangToGLPos(init_x[0],init_y[0]);
		ChangToGLPos(init_x[1],init_y[1]);
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_4_trace_[fish_count + i], kSpeed);
		radius -= kFishWidth;
	}
	fish_count += 8;

	// 右上
	start_pos.x = screen_width;
	start_pos.y = kFishHeight / 2;
	target_pos.x = kFishHeight / 2;
	target_pos.y = screen_height;
	angle = acosf((start_pos.x - target_pos.x) / MathAide::CalcDistance(target_pos.x, target_pos.y, start_pos.x, start_pos.y));
	radius = kFishWidth * 4;
	length = radius + kFishWidth / 2.f;
	center_pos.x = start_pos.x + length * cosf(angle);
	center_pos.y = start_pos.y - length * sinf(angle);
	init_x[1] = target_pos.x - kFishWidth;
	init_y[1] = target_pos.y + kFishHeight;
	for (int i = 0; i < 8; ++i)
	{
		if (radius < 0.f) 
		{
			init_x[0] = center_pos.x - radius * cosf(-angle - M_PI);
			init_y[0] = center_pos.y - radius * sinf(-angle - M_PI);
		} 
		else 
		{
			init_x[0] = center_pos.x - radius * cosf(-angle);
			init_y[0] = center_pos.y - radius * sinf(-angle);
		}
		ChangToGLPos(init_x[0],init_y[0]);
		ChangToGLPos(init_x[1],init_y[1]);
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_4_trace_[fish_count + i], kSpeed);
		radius -= kFishWidth;
	}
	fish_count += 8;

	start_pos.x = screen_width - kFishHeight / 2;
	start_pos.y = 0.f;
	target_pos.x = 0.f;
	target_pos.y = screen_height - kFishHeight / 2;
	angle = acosf((start_pos.x - target_pos.x) / MathAide::CalcDistance(target_pos.x, target_pos.y, start_pos.x, start_pos.y));
	radius = kFishWidth * 4;
	length = radius + kFishWidth / 2.f;
	center_pos.x = start_pos.x + length * cosf(angle);
	center_pos.y = start_pos.y - length * sinf(angle);
	init_x[1] = target_pos.x - kFishWidth;
	init_y[1] = target_pos.y + kFishHeight;
	for (int i = 0; i < 8; ++i) 
	{
		if (radius < 0.f)
		{
			init_x[0] = center_pos.x - radius * cosf(-angle - M_PI);
			init_y[0] = center_pos.y - radius * sinf(-angle - M_PI);
		} else {
			init_x[0] = center_pos.x - radius * cosf(-angle);
			init_y[0] = center_pos.y - radius * sinf(-angle);
		}
		ChangToGLPos(init_x[0],init_y[0]);
		ChangToGLPos(init_x[1],init_y[1]);
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_4_trace_[fish_count + i], kSpeed);
		radius -= kFishWidth;
	}
	fish_count += 8;

	// 左上
	start_pos.x = kFishHeight / 2;
	start_pos.y = 0.f;
	target_pos.x = screen_width;
	target_pos.y = screen_height - kFishHeight / 2;
	angle = acosf((target_pos.x - start_pos.x) / MathAide::CalcDistance(target_pos.x, target_pos.y, start_pos.x, start_pos.y));
	radius = kFishWidth * 4;
	length = radius + kFishWidth / 2.f;
	center_pos.x = start_pos.x - length * cosf(angle);
	center_pos.y = start_pos.y - length * sinf(angle);
	init_x[1] = target_pos.x + kFishWidth;
	init_y[1] = target_pos.y + kFishHeight;
	for (int i = 0; i < 8; ++i) 
	{
		if (radius < 0.f) 
		{
			init_x[0] = center_pos.x + radius * cosf(angle + M_PI);
			init_y[0] = center_pos.y + radius * sinf(angle + M_PI);
		} 
		else
		{
			init_x[0] = center_pos.x + radius * cosf(angle);
			init_y[0] = center_pos.y + radius * sinf(angle);
		}
		ChangToGLPos(init_x[0],init_y[0]);
		ChangToGLPos(init_x[1],init_y[1]);
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_4_trace_[fish_count + i], kSpeed);
		radius -= kFishWidth;
	}
	fish_count += 8;

	start_pos.x = 0.f;
	start_pos.y = kFishHeight / 2;
	target_pos.x = screen_width - kFishHeight / 2;
	target_pos.y = screen_height;
	angle = acosf((target_pos.x - start_pos.x) / MathAide::CalcDistance(target_pos.x, target_pos.y, start_pos.x, start_pos.y));
	radius = kFishWidth * 4;
	length = radius + kFishWidth / 2.f;
	center_pos.x = start_pos.x - length * cosf(angle);
	center_pos.y = start_pos.y - length * sinf(angle);
	init_x[1] = target_pos.x + kFishWidth;
	init_y[1] = target_pos.y + kFishHeight;
	for (int i = 0; i < 8; ++i)
	{
		if (radius < 0.f) 
		{
			init_x[0] = center_pos.x + radius * cosf(angle + M_PI);
			init_y[0] = center_pos.y + radius * sinf(angle + M_PI);
		}
		else
		{
			init_x[0] = center_pos.x + radius * cosf(angle);
			init_y[0] = center_pos.y + radius * sinf(angle);
		}
		ChangToGLPos(init_x[0],init_y[0]);
		ChangToGLPos(init_x[1],init_y[1]);
		MathAide::BuildLinear(init_x, init_y, 2, scene_kind_4_trace_[fish_count + i], kSpeed);
		radius -= kFishWidth;
	}
	fish_count += 8;
}

static float angle_range(float angle)
{
	while (angle <= -M_PI * 2) 
	{
		angle += M_PI * 2;
	}
	if (angle < 0.f) angle += M_PI * 2;
	while (angle >= M_PI * 2)
	{
		angle -= M_PI * 2;
	}
	return angle;
}

static void GetTargetPoint(float screen_width, float screen_height, float src_x_pos, float src_y_pos, float angle, float& target_x_pos, float& target_y_pos)
{
	//300 160
	angle = angle_range(angle);
	if (angle > 0.f && angle < M_PI_2) 
	{
		target_x_pos = screen_width + 300;
		target_y_pos = src_y_pos + (screen_width - src_x_pos + 300) * tanf(angle);
	}
	else if (angle >= M_PI_2 && angle < M_PI)
	{
		target_x_pos = -300;
		target_y_pos = src_y_pos - (src_x_pos + 300) * tanf(angle);
	} 
	else if (angle >= M_PI && angle < 3 * M_PI / 2.f)
	{
		target_x_pos = -300;
		target_y_pos = src_y_pos - (src_x_pos + 300) * tanf(angle);
	} 
	else
	{
		target_x_pos = screen_width + 300;
		target_y_pos = src_y_pos + (screen_width - src_x_pos + 300) * tanf(angle);
	}
}

void BuildSceneKind5Trace(float screen_width, float screen_height)
{
	if (scene_kind_5_trace_[0].size() > 0)return;
	int fish_count = 0;
	const float kVScale = screen_height / kResolutionHeight;
	const float kRadius = (screen_height - (200 * kVScale)) / 2;
	const float kRotateSpeed = 1.5f * M_PI / 180;
	const float kSpeed = 5.f * screen_width / kResolutionWidth;
	FPointAngle fish_pos[100];
	FPoint center[2];
	FPoint center1[2];
	center[0].x = screen_width / 4.f;
	center[0].y = kRadius + 100 * kVScale;
	center[1].x = screen_width - screen_width / 4.f;
	center[1].y = kRadius + 100 * kVScale;
	
	const float kLFish1Rotate = 720.f * M_PI / 180.f;
	const float kRFish2Rotate = (720.f + 90.f) * M_PI / 180.f;
	const float kRFish5Rotate = (720.f + 180.f) * M_PI / 180.f;
	const float kLFish3Rotate = (720.f + 180.f + 45.f) * M_PI / 180.f;
	const float kLFish4Rotate = (720.f + 180.f + 90.f) * M_PI / 180.f;
	const float kRFish6Rotate = (720.f + 180.f + 90.f + 30.f) * M_PI / 180.f;
	const float kRFish7Rotate = (720.f + 180.f + 90.f + 60.f) * M_PI / 180.f;
	const float kLFish6Rotate = (720.f + 180.f + 90.f + 60.f + 30.f) * M_PI / 180.f;
	const float kLFish18Rotate = (720.f + 180.f + 90.f + 60.f + 60.f) * M_PI / 180.f;
	const float kRFish17Rotate = (720.f + 180.f + 90.f + 60.f + 60.f + 30.f) * M_PI / 180.f;
	for (float rotate = 0.f; rotate <= kLFish1Rotate; rotate += kRotateSpeed) 
	{
		center1[0]=center[0];
		//center1[1]=center[1];
		ChangToGLPos(center1[0].x, center1[0].y);
		MathAide::BuildCircle(center1[0].x, center1[0].y, kRadius, fish_pos, 40, rotate, kRotateSpeed);
		for (int j = 0; j < 40; ++j)
		{
			scene_kind_5_trace_[j].push_back(fish_pos[j]);
		}
	}
	fish_count += 40;
	for (float rotate = 0.f; rotate <= kRFish2Rotate; rotate += kRotateSpeed)
	{
		//center1[0]=center[0];
		center1[1]=center[1];
		ChangToGLPos(center1[1].x, center1[1].y);
		MathAide::BuildCircle(center1[1].x, center1[1].y, kRadius, fish_pos, 40, rotate, kRotateSpeed);
		for (int j = 0; j < 40; ++j) 
		{
			scene_kind_5_trace_[fish_count + j].push_back(fish_pos[j]);
		}
	}
	fish_count += 40;

	for (float rotate = 0.f; rotate <= kRFish5Rotate; rotate += kRotateSpeed)
	{
		//center1[0]=center[0];
		center1[1]=center[1];
		ChangToGLPos(center1[1].x, center1[1].y);
		MathAide::BuildCircle(center1[1].x, center1[1].y, kRadius - 34.5f * kVScale, fish_pos, 40, rotate, kRotateSpeed);
		for (int j = 0; j < 40; ++j) 
		{
			scene_kind_5_trace_[fish_count + j].push_back(fish_pos[j]);
		}
	}
	fish_count += 40;
	for (float rotate = 0.f; rotate <= kLFish3Rotate; rotate += kRotateSpeed)
	{
		center1[0]=center[0];
		//center1[1]=center[1];
		ChangToGLPos(center1[0].x, center1[0].y);
		MathAide::BuildCircle(center1[0].x, center1[0].y, kRadius - 36.f * kVScale, fish_pos, 40, rotate, kRotateSpeed);
		for (int j = 0; j < 40; ++j)
		{
			scene_kind_5_trace_[fish_count + j].push_back(fish_pos[j]);
		}
	}
	fish_count += 40;

	for (float rotate = 0.f; rotate <= kLFish4Rotate; rotate += kRotateSpeed) 
	{
		center1[0]=center[0];
		//center1[1]=center[1];
		ChangToGLPos(center1[0].x, center1[0].y);
		MathAide::BuildCircle(center1[0].x, center1[0].y, kRadius - 36.f * kVScale - 56.f * kVScale, fish_pos, 24, rotate, kRotateSpeed);
		for (int j = 0; j < 24; ++j)
		{
			scene_kind_5_trace_[fish_count + j].push_back(fish_pos[j]);
		}
	}
	fish_count += 24;
	for (float rotate = 0.f; rotate <= kRFish6Rotate; rotate += kRotateSpeed) 
	{
		//center1[0]=center[0];
		center1[1]=center[1];
		ChangToGLPos(center1[1].x, center1[1].y);
		MathAide::BuildCircle(center1[1].x, center1[1].y, kRadius - 34.5f * kVScale - 58.5f * kVScale, fish_pos, 24, rotate, kRotateSpeed);
		for (int j = 0; j < 24; ++j) 
		{
			scene_kind_5_trace_[fish_count + j].push_back(fish_pos[j]);
		}
	}
	fish_count += 24;

	for (float rotate = 0.f; rotate <= kRFish7Rotate; rotate += kRotateSpeed) 
	{
		//center1[0]=center[0];
		center1[1]=center[1];
		ChangToGLPos(center1[1].x, center1[1].y);
		MathAide::BuildCircle(center1[1].x, center1[1].y, kRadius - 34.5f * kVScale - 58.5f * kVScale - 65.f * kVScale, fish_pos, 13, rotate, kRotateSpeed);
		for (int j = 0; j < 13; ++j) 
		{
			scene_kind_5_trace_[fish_count + j].push_back(fish_pos[j]);
		}
	}
	fish_count += 13;
	for (float rotate = 0.f; rotate <= kLFish6Rotate; rotate += kRotateSpeed)
	{
		center1[0]=center[0];
		//center1[1]=center[1];
		ChangToGLPos(center1[0].x, center1[0].y);
		MathAide::BuildCircle(center1[0].x, center1[0].y, kRadius - 36.f * kVScale - 56.f * kVScale - 68.f * kVScale, fish_pos, 13, rotate, kRotateSpeed);
		for (int j = 0; j < 13; ++j) 
		{
			scene_kind_5_trace_[fish_count + j].push_back(fish_pos[j]);
		}
	}
	fish_count += 13;
	//大鱼
	for (float rotate = 0.f; rotate <= kLFish18Rotate; rotate += kRotateSpeed)
	{
		center1[0]=center[0];
		ChangToGLPos(center1[0].x, center1[0].y);
		fish_pos[0].x = center1[0].x;
		fish_pos[0].y = center1[0].y;
		fish_pos[0].angle = -M_PI_2 + rotate;
		scene_kind_5_trace_[fish_count].push_back(fish_pos[0]);
	}
	fish_count += 1;

	for (float rotate = 0.f; rotate <= kRFish17Rotate; rotate += kRotateSpeed)
	{
		center1[1]=center[1];
		ChangToGLPos(center1[1].x, center1[1].y);
		fish_pos[0].x = center1[1].x;
		fish_pos[0].y = center1[1].y;
		fish_pos[0].angle = -M_PI_2 + rotate;
		scene_kind_5_trace_[fish_count].push_back(fish_pos[0]);
	}
	fish_count += 1;
	//assert(fish_count == arraysize(scene_kind_5_trace_));
	//离开
	float init_x[2], init_y[2];
	std::vector<FPointAngle> temp_vector;
	for (int i = 0; i < 236; ++i) 
	{
		FPointAngle& pos = scene_kind_5_trace_[i].back();
		init_x[0] = pos.x;
		init_y[0] = pos.y;
		cocos2d::CCPoint t_pos = cocos2d::CCDirector::sharedDirector()->convertToUI(cocos2d::CCPointMake(init_x[0], init_y[0]));
		//CSize size=CCDirector::sharedDirector()->getVisibleSize();
		//x=t_pos.x;
		init_x[0]=t_pos.x;
		init_y[0]=t_pos.y;
		GetTargetPoint(screen_width, screen_height, t_pos.x, t_pos.y, pos.angle, init_x[1], init_y[1]);
		ChangToGLPos(init_x[0],init_y[0]);
		ChangToGLPos(init_x[1],init_y[1]);
		MathAide::BuildLinear(init_x, init_y, 2, temp_vector, kSpeed);
		temp_vector[0].angle = pos.angle;
		temp_vector[1].angle = pos.angle;
		std::copy(temp_vector.begin(), temp_vector.end(), std::back_inserter(scene_kind_5_trace_[i]));
	}
}
