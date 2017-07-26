
#ifndef __BILL_H__
#define __BILL_H__

#include "../FrameWork/define.h"
#include "../FrameWork/Animation.h"
#include "../FrameWork/InputController.h"
#include "../FrameWork/Scene/SceneManager.h"
#include "../FrameWork/Scene/PlayScene.h"
#include "../BaseObject.h"
#include "../FrameWork/IComponent.h"
#define BILL_MOVE_SPEED 125
#define BILL_JUMP_VEL 450
#define GRAVITY 800
#define SHOOT_SPEED 200.0f
#define MAX_BULLET 4
#define REVIVE_TIME 2000
#define PROTECT_TIME 3000

[event_receiver(native)]
class Bill : public BaseObject, public IControlable
{

public:
	Bill();
	~Bill();
	void init();
	void updateInput(float dt);
	void update(float deltatime);
	void draw(LPD3DXSPRITE spriteHandle, Viewport* viewport);
	void release();

	void onKeyPressed(KeyEventArg* key_event);
	void onKeyReleased(KeyEventArg* key_event);

	void checkPosition();
	void setStatus(eStatus status) override;
	// Character action.
	void standing();
	void moveLeft();
	void moveRight();
	void jump();
	void layDown();
	void falling();
	void revive();
	void die();
	void swimming();
	float getMovingSpeed();

	RECT getBounding() override;

private:
	map<int, Animation*> _animations;
	map<string, IComponent*> _componentList;
	
	float _movingSpeed;

	bool _canJumpDown;
	eStatus _currentAnimateIndex;
	float _protectTime;


	GVector2 getVelocity();

	void updateStatus(float dt);

	void updateCurrentAnimateIndex();

	eDirection getAimingDirection();

//	void deleteBullet();

	// reset các thuộc tính lại giá trị ban đầu.
	void resetValues();

	BaseObject* _preObject;
	bool _isHolding;
};

#endif // !__BILL_H__
