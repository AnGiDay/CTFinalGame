
#ifndef __BILL_H__
#define __BILL_H__

#include "../FrameWork/define.h"
#include "../FrameWork/Animation.h"
#include "../FrameWork/InputController.h"
#include "../FrameWork/Scene/SceneManager.h"
#include "../FrameWork/Scene/PlayScene.h"
#include "../BaseObject.h"
#include "../FrameWork/IComponent.h"
#include <algorithm>
#include "../Bullet.h"
#include "../M_Bullet.h"
#include "../StopWatch.h"


#define BILL_MOVE_SPEED 125
#define BILL_JUMP_VEL 450
#define GRAVITY 800
#define SHOOT_SPEED 300.0f
#define MAX_BULLET 4
#define REVIVE_TIME 2000
#define PROTECT_TIME 3000

[event_receiver(native)]
class PlayScene;
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

	void setShootSpeed(float speed);
	float getShootSpeed();

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

	void shoot();

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

	//THAG : BULLET
	list<Bullet* > _listBullets;
	// Dùng để tạo ra đạn, nếu ăn máy bay tiếp đạn thì thay đổi thông số này, nếu bắn đạn thì dựa trên thuộc tính này để chọn loại đạn khởi tạo
	eBulletType _currentGun;
	float _shootSpeed;
	int _maxBullet;
	// Đổi kiểu đạn. 
	void changeBulletType(eAirCraftType);

	StopWatch* _stopWatch;
	StopWatch* _shootStopWatch;
	StopWatch* _shootAnimateStopWatch;
	StopWatch* _reviveStopWatch;
	// kiểm tra và xoá đạn hết hiệu lực.
	void deleteBullet();
	void setMaxBullet(int number);
	int getMaxBullet();
	Bullet* getBulletFromGun(GVector2 position, float angle);



	// reset các thuộc tính lại giá trị ban đầu.
	void resetValues();

	BaseObject* _preObject;
	bool _isHolding;
};

#endif // !__BILL_H__
