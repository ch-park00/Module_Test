/*
 * App.h
 *
 *  Created on: Jan 14, 2023
 *      Author: pch
 */

#ifndef SRC_APP_APP_H_
#define SRC_APP_APP_H_

#include "MotorControl.h"
#include "SystemControl.h"

#define Tim_TaskNum 2
void app_init(tasknode *_tasklist);
void Confirm_NeedToProc(tasknode *tasklist);
void tasklist_init(tasknode *_tasklist);
void task_init(tasknode *_tasklist);
void task_regist(tasknode *_tasklist, TaskNum newTask);
void Confirm_NeedToProc(tasknode *tasklist);
void Confirm_EventProc(tasknode *tasklist);
void Proc_App(tasknode *tasklist);

#endif /* SRC_APP_APP_H_ */
