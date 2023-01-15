/*
 * common.h
 *
 *  Created on: Jan 14, 2023
 *      Author: pch
 */

#ifndef INC_APP_COMMON_H_
#define INC_APP_COMMON_H_
// 현재 처리해야 하는지 아닌지 저장하는 변수
#include <stdlib.h>
#include <stdint.h>
typedef enum
{
	STATE_IDLE,
	STATE_HANDLE
}TASK_STATE;
// 등록된 태스크 중 처리해야 하는 태스크를 확인하기 위한 용도의 변수

// 현재 시스템에서 타이머를 통해 처리해야 하는 태스크를 등록
#define MAX_TASK_NUM 100
// 수행해야 하는 태스크 번호를 미리 정의
typedef enum
{
	Reserved = -1,
	// 메인 시스템 동작을 위한 타이머
	Sys_TIM,
	// 채터링 방지 위한 타이머
	Chattering_TIM,
	// 모터 동작 제어를 위한 1초 타이머
	Motorfunc_TIM,
	// 스위치 처리를 위한 태스크
	Switch_Check,
	// printf 구현을 위한 태스크
	Print_Func,
	// 모터 onoff
	Motorfunc_ONOFF,
	// 모터 브레이크 동작
	Motorfunc_brake,
	// 모터 방향 제어
	Motorfunc_Dir,
	// 모터 속도 설정 태스크
	Motorfunc_speedset
}TaskNum;
// 수행해야 하는 태스크를 등록하기 위해 사용하는 구조체
// 원형 큐 활용
typedef struct
{
	TaskNum *link_task;
	int tasklist_front;
	int tasklist_rear;
}tasknode;

// 타이머 활성 상태 체크용 구조체
typedef enum
{
	Tim_SET,
	Tim_UnSet
}Tim_ACTCHECK;
typedef struct
{
	Tim_ACTCHECK TIM_SYS;
	Tim_ACTCHECK TIM_CHATTERING;
	Tim_ACTCHECK TIM_MOTORONOFF;
	uint32_t task_num;
}TimTask_list;

// motor 상태를 확인, 기록하기 위한 구조체
// if set => dir is CW
typedef enum
{
	FUNC_SET,
	FUNC_UNSET
}MotorFlag;
// 모터를 구분하기 위해 사용
typedef enum
{
	M_left
}MotorID;
typedef struct
{
	MotorFlag OnOff;
	MotorFlag Brake;
	MotorFlag DIR;
	uint16_t speed;
	MotorID curID;
}MotorState;
// 시스템 플래그 저장을 위해 활용하는 구조체
typedef enum
{
	FLAG_SET,
	FLAG_UNSET
}flagValue;
typedef struct
{
	flagValue OnOff;
	flagValue Brake;
	flagValue DIR;
	flagValue speed;
	MotorID curID;
}M_flag;
typedef struct
{
	flagValue Switchflag;
	M_flag Motorflag;
	flagValue print_flag;
}SystemState;
#endif /* INC_APP_COMMON_H_ */
