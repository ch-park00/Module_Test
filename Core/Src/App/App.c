/*
 * App.c
 *
 *  Created on: Jan 14, 2023
 *      Author: pch
 */
#include "App.h"
#include "SystemControl.h"

static TimTask_list TimAct_list;
SYS_CheckTim result;
SystemState cur_state;

void tasklist_init(tasknode *_tasklist)
{
	TimAct_list.task_num = Tim_TaskNum;

	// 기본 타이머
	TimAct_list.TIM_SYS =Tim_UnSet;
	TimAct_list.TIM_MOTORONOFF =Tim_UnSet;
	TimAct_list.TIM_CHATTERING=Tim_UnSet;

	// 태스크 등록을 위한 큐 초기화
	_tasklist->link_task = (TaskNum*)malloc(sizeof(TaskNum)* (MAX_TASK_NUM + 1));
	for (int i=0;i<= MAX_TASK_NUM; i++)
	{
		_tasklist->link_task[i]= Reserved;
	}
	_tasklist->tasklist_front = _tasklist->tasklist_rear = 0;

}
void task_init(tasknode *_tasklist)
{
	tasklist_init(_tasklist);
	result.Tim_1ms = STATE_HANDLE;
}
// 첫번째 인자는 태스크를 저장할 변수주소
// 두번째 인자는 저장할 태스크
void task_regist(tasknode *_tasklist, TaskNum newTask)
{
	// 큐가 꽉 참을 의미
	if (_tasklist->tasklist_front == (_tasklist->tasklist_rear + 1) % (MAX_TASK_NUM + 1))	return;
	// task 등록
	_tasklist->link_task[_tasklist->tasklist_rear] = newTask;
	_tasklist->tasklist_rear += 1;
	_tasklist->tasklist_rear %= MAX_TASK_NUM;
}
void app_init(tasknode *_tasklist)
{
	// task 초기화
	task_init(_tasklist);
	// 시스템 초기화
	//MotorControl_init();
	//SystemControl_init(&TimAct_list);
}
void Confirm_NeedToProc(tasknode *tasklist)
{
	// 타이머 인터럽트 발생 체크
	Check_SystemTimer(&TimAct_list, &result);
	// 추가적인 타이머가 있다면 여기에 추가
	// 1ms 타이머로 동작해야 하는 태스크 여기에 추가
	if (result.Tim_1ms == STATE_HANDLE)
	{
		//1ms 주기로 동작해야 하는 task 등록
		// 모터 핸들러
		//task_regist(&tasklist, SystemControl);
		// systemfunction 처리 함수들(printf)
		//_Task->Task_SystemTimHandler = STATE_HANDLE;
		task_regist(tasklist, Sys_TIM);
	}
	// 30ms 타이머로 동작해야 하는 태스크 여기에 추가
	if (result.Tim_30ms == STATE_HANDLE)
	{
		task_regist(tasklist, Chattering_TIM);
		//_Task->Task_SystemTimHandler = STATE_HANDLE;
	}
	// 1초. 1000ms
	if (result.Tim_1000ms == STATE_HANDLE)
	{
		task_regist(tasklist, Motorfunc_TIM);
	}
}
// 외부 인터럽트 요소 처리
void Confirm_EventProc(tasknode *tasklist)
{
	// 스위치 스테이지 플래그 변화 확인
	if (cur_state.Switchflag == FLAG_SET)
	{
		task_regist(tasklist, Switch_Check);
	}
	// 출력 관련 플래그 변화 확인
	if (cur_state.print_flag == FLAG_SET)
	{
		task_regist(tasklist, Print_Func);
	}
	// 모터 동작 변화 확인
	if (cur_state.Motorflag.OnOff == FLAG_SET)
	{
		task_regist(tasklist, Motorfunc_ONOFF);
	}
	// 모터 브레이크 변화 확인
	if (cur_state.Motorflag.Brake == FLAG_SET)
	{
		task_regist(tasklist, Motorfunc_brake);
	}
	// 모터 방향핀 제어
	if (cur_state.Motorflag.DIR == FLAG_SET)
	{
		task_regist(tasklist, Motorfunc_Dir);
	}
	// 모터 속도 제어
	if (cur_state.Motorflag.speed == FLAG_SET)
	{
		task_regist(tasklist, Motorfunc_speedset);
	}
}




// 실제 필요한 작업 처리
void Proc_App(tasknode *tasklist)
{
	if (tasklist->tasklist_front == tasklist->tasklist_rear)	return;
	// task 실행
	while(1)
	{
		if (tasklist->tasklist_front == tasklist->tasklist_rear)	break;
		else
		{
			// 등록한 태스크 확인 후 해당 태스크에 필요한 앱 호출
			switch(tasklist->link_task[tasklist->tasklist_front])
			{
			// motor 제어(루프제어)
			case 0:
				break;
			// 스위치 제어( 스위치 값 확인
			case 1:
				break;
			default:
				break;
			}
			tasklist->tasklist_front = (tasklist->tasklist_front + 1) % (MAX_TASK_NUM + 1);
		}
	}
}
