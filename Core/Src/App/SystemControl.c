/*
 * SystemControl.c
 *
 *  Created on: Jan 14, 2023
 *      Author: pch
 */
#include "common.h"
#include "SystemControl.h"
#include "SystemDriver.h"

static uint16_t chatteringtim_cnt = 0;
static uint16_t motoronofftim_cnt = 0;
void SystemControl_init(TimTask_list *_list)
{
	SystemDrivier_init();
	_list->TIM_SYS = Tim_SET;
	_list->TIM_CHATTERING = Tim_UnSet;
}
// 1ms Timer 활용.
// 시스템에 필요한 타이머 전부 여기서 처리.
// 시스템에 필요한 타이머
// 모터 동작 갱신용 1ms 타이머
// 채터링 지연용 30ms 타이머
void Check_SystemTimer(TimTask_list *_list, SYS_CheckTim *result)
{
	// 메인 타이머 플래그 체크
	uint16_t status;
	if (_list->TIM_SYS == Tim_SET)
	{
		status = 1;
		//status = Check_TimerSet();
		// 타이머 인터럽트 플래그 set
		if (status == STATE_HANDLE)
		{
			result->Tim_1ms = STATE_HANDLE;
			// 30ms 타이머 켜져 있는지 확인
			if (_list->TIM_CHATTERING == Tim_SET)
			{
				chatteringtim_cnt += 1;
				// 30ms 달성 여부 확이
				if (chatteringtim_cnt == ChatteringTIM)
				{
					result->Tim_30ms = STATE_HANDLE;
					_list->TIM_CHATTERING = Tim_UnSet;
					chatteringtim_cnt = 0;
				}
			}
			if (_list->TIM_MOTORONOFF == Tim_SET)
			{
				motoronofftim_cnt += 1;
				if (chatteringtim_cnt == MotorONOFFTIM)
				{
					result->Tim_1000ms = STATE_HANDLE;
					_list->TIM_MOTORONOFF = Tim_UnSet;
					chatteringtim_cnt = 0;
				}
			}
		}
	}
}


uint16_t Check_Switch()
{
	uint16_t status = Check_SwitchStage();
	// 스테이지 변화 있을 시에만 호출하도록
	return status;
}
/*
void SwitchCheck_func()
{
	uint16_t status = check_SwitchStage();
	switch (status)
	{
	// 채터링 처리
	case STAGE_CHATTERING:
		break;
		// 채터링 지연 후 값 판단 필요 상황
	case STAGE_DETERMINE:
		break;
		// 스위치 인터럽트 발생 상황
	case STAGE_IDLE:
		break;
		// 예외처리
	default:
		break;
	}
}
*/
