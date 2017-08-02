#pragma once
#ifndef __CANNON_H__
#define __CANNON_H__

#include "FrameWork\Animation.h"
#include "StopWatch.h"
#include "FrameWork\Scene\PlayScene.h"
//#include "../Bullets/Bullet.h"
//#include "../CollisionBody.h"
#include "IComponent.h"
#include "Explosion.h"
#include "Object\BaseEnemy.h"
#include "../CTFinalGame/BulletManager.h"

#define WALL_CANNON_HITPOINT 8
#define WALL_CANNON_SCORE 1000
#define WALL_CANNON_SHOOTING_DELAY 3000.0f
#define WALL_CANNON_ANIMATION_SPEED 0.3f
#define WALL_CANNON_APPEAR_SPEED 0.1f

#define CANNON_HITPOINT 8
#define CANNON_SCORE 500
#define CANNON_SHOOTING_DELAY 1000.0f
#define CANNON_ANIMATION_SPEED 0.33f
#define CANNON_APPEAR_SPEED 0.08f

#define PI 3.14159265

using namespace std;
class Cannon :public BaseEnemy
{
public:
	Cannon(eStatus status, GVector2 pos, int type);
	Cannon(eStatus status, float x, float y, int type);
	Cannon(eWT_Status wtstatus, GVector2 pos, int type);
	Cannon(eWT_Status wtstatus, float x, float y, int type);

	~Cannon();

	void init();
	void update(float);
	void draw(LPD3DXSPRITE, Viewport*);
	void release();

	//void onCollisionBegin(CollisionEventArg*);
	//void onCollisionEnd(CollisionEventArg*);

	void setBillAngle(float);
	float getBillAngle();
	void setShootingAngle(float);
	float getShootingAngle();

	void setStatus(eStatus);
	void setWTStatus(eWT_Status);
	eWT_Status getWT_Status();
	void shoot();
	RECT getBounding();

	/*float checkCollision(BaseObject*, float);*/
	void checkIfOutofScreen();
	IComponent* getComponent(string);
private:
	int type;
	map < string, IComponent*> _listComponent;
	map<int, Animation*> _animation;
	float _shootingAngle;
	float _billAngle;
	eWT_Status _wtstatus;
	BaseObject* _explosion;

	list<Bullet*> _listBullet;
	StopWatch* _stopwatch;

	void initExplosion();
	void updateExplosion(float);

	void addStatus(eStatus);
	void addStatus(eWT_Status);
	void removeStatus(eStatus);
	void removeStatus(eWT_Status);
	bool isInStatus(eStatus);
	bool isInStatus(eWT_Status);
	void calculateBillangle();

	void checkBill();
	void rangeAttack();
	bool isRange();

	StopWatch* _loopwatch2;
	int bullet = 0;
	float delay1;
};
#endif
