#include"Cannon.h"

Cannon::Cannon(eStatus status, GVector2 position, int type) :BaseEnemy(eID::WALL_TURRET)
{
	this->type = type;
	if (type == 1)
	{
		_sprite = SpriteManager::getInstance()->getSprite(eID::WALL_TURRET);
		_sprite->setFrameRect(0, 0, 32, 32);
		this->setPosition(position);
		this->setStatus(status);
		this->setWTStatus(eWT_Status::WT_NORMAL);
	}
	else
	{
		_sprite = SpriteManager::getInstance()->getSprite(eID::REDCANNON);

		_sprite->setFrameRect(0, 0, 32, 32);
		this->setPosition(position);
		this->setStatus(status);
		this->setWTStatus(eWT_Status::WT_NORMAL);
	}	
}

Cannon::Cannon(eStatus status, float x, float y, int type) :BaseEnemy(eID::WALL_TURRET)
{
	this->type = type;
	if (type == 1)
	{
		_sprite = SpriteManager::getInstance()->getSprite(eID::WALL_TURRET);
		_sprite->setFrameRect(0, 0, 32, 32);
		GVector2 pos(x, y);
		this->setPosition(pos);
		this->setStatus(status);
		this->setWTStatus(eWT_Status::WT_NORMAL);
	}
	else
	{
		_sprite = SpriteManager::getInstance()->getSprite(eID::REDCANNON);
		_sprite->setFrameRect(0, 0, 32, 32);
		GVector2 pos(x, y);
		this->setPosition(pos);
		this->setStatus(status);
		this->setWTStatus(eWT_Status::WT_NORMAL);
	}
}
Cannon::Cannon(eWT_Status wtstatus, GVector2 position, int type) :BaseEnemy(eID::WALL_TURRET)
{
	this->type = type;
	if (type == 1)
	{
		_sprite = SpriteManager::getInstance()->getSprite(eID::WALL_TURRET);
		_sprite->setFrameRect(0, 0, 32, 32);
		this->setPosition(position);
		this->setWTStatus(wtstatus);
	}
	else
	{
		_sprite = SpriteManager::getInstance()->getSprite(eID::REDCANNON);
		_sprite->setFrameRect(0, 0, 32, 32);
		this->setPosition(position);
		this->setWTStatus(wtstatus);
	}
}
Cannon::Cannon(eWT_Status wtstatus, float x, float y, int type) :BaseEnemy(eID::WALL_TURRET)
{
	this->type = type;
	if (type == 1)
	{
		_sprite = SpriteManager::getInstance()->getSprite(eID::WALL_TURRET);
		_sprite->setFrameRect(0, 0, 32, 32);
		GVector2 pos(x, y);
		this->setPosition(pos);
		this->setWTStatus(wtstatus);
	}
	else
	{
		_sprite = SpriteManager::getInstance()->getSprite(eID::REDCANNON);
		_sprite->setFrameRect(0, 0, 32, 32);
		GVector2 pos(x, y);
		this->setPosition(pos);
		this->setWTStatus(wtstatus);
	}
}
Cannon::~Cannon()
{

}
void Cannon::init()
{

	this->setScale(SCALE_FACTOR);

	//auto collisionBody = new CollisionBody(this);
	//_listComponent["collisionBody"] = collisionBody;
	//__hook(&CollisionBody::onCollisionBegin, collisionBody, &WallTurret::onCollisionBegin);
	//__hook(&CollisionBody::onCollisionEnd, collisionBody, &WallTurret::onCollisionEnd);

	if (type == 1)
	{
		_animation[WT_APPEAR] = new Animation(_sprite, WALL_TURRET_APPEAR_SPEED);
		_animation[WT_APPEAR]->addFrameRect(eID::WALL_TURRET, "appear_01", "appear_02", "appear_03", "appear_04", "appear_05", "appear_06", NULL);
		_animation[WT_APPEAR]->setLoop(false);

		_animation[WT_CLOSE] = new Animation(_sprite, WALL_TURRET_APPEAR_SPEED);
		_animation[WT_CLOSE]->addFrameRect(eID::WALL_TURRET, "appear_06", "appear_05", "appear_04", "appear_03", "appear_02", "appear_01", NULL);
		_animation[WT_CLOSE]->setLoop(false);

		_animation[WT_NORMAL] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_NORMAL]->addFrameRect(eID::WALL_TURRET, "normal_01", "normal_02", "normal_03", NULL);
		_animation[WT_NORMAL | WT_SHOOTING] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_NORMAL | WT_SHOOTING]->addFrameRect(eID::WALL_TURRET, "normal_01", NULL);

		_animation[WT_LEFT_60] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_LEFT_60]->addFrameRect(eID::WALL_TURRET, "left_60_01", "left_60_02", "left_60_03", NULL);
		_animation[WT_LEFT_60 | WT_SHOOTING] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_LEFT_60 | WT_SHOOTING]->addFrameRect(eID::WALL_TURRET, "left_60_01", NULL);

		_animation[WT_LEFT_30] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_LEFT_30]->addFrameRect(eID::WALL_TURRET, "left_30_01", "left_30_02", "left_30_03", NULL);
		_animation[WT_LEFT_30 | WT_SHOOTING] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_LEFT_30 | WT_SHOOTING]->addFrameRect(eID::WALL_TURRET, "left_30_01", NULL);

		_animation[WT_UP] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_UP]->addFrameRect(eID::WALL_TURRET, "up_01", "up_02", "up_03", NULL);
		_animation[WT_UP | WT_SHOOTING] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_UP | WT_SHOOTING]->addFrameRect(eID::WALL_TURRET, "up_01", NULL);

		_animation[WT_RIGHT_30] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_RIGHT_30]->addFrameRect(eID::WALL_TURRET, "right_30_01", "right_30_02", "right_30_03", NULL);
		_animation[WT_RIGHT_30 | WT_SHOOTING] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_RIGHT_30 | WT_SHOOTING]->addFrameRect(eID::WALL_TURRET, "right_30_01", NULL);

		_animation[WT_RIGHT_60] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_RIGHT_60]->addFrameRect(eID::WALL_TURRET, "right_60_01", "right_60_02", "right_60_03", NULL);
		_animation[WT_RIGHT_60 | WT_SHOOTING] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_RIGHT_60 | WT_SHOOTING]->addFrameRect(eID::WALL_TURRET, "right_60_01", NULL);

		_animation[WT_RIGHT] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_RIGHT]->addFrameRect(eID::WALL_TURRET, "right_90_01", "right_90_02", "right_90_03", NULL);
		_animation[WT_RIGHT | WT_SHOOTING] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_RIGHT | WT_SHOOTING]->addFrameRect(eID::WALL_TURRET, "right_90_01", NULL);

		_animation[WT_RIGHT_120] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_RIGHT_120]->addFrameRect(eID::WALL_TURRET, "right_120_01", "right_120_02", "right_120_03", NULL);
		_animation[WT_RIGHT_120 | WT_SHOOTING] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_RIGHT_120 | WT_SHOOTING]->addFrameRect(eID::WALL_TURRET, "right_120_01", NULL);

		_animation[WT_RIGHT_150] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_RIGHT_150]->addFrameRect(eID::WALL_TURRET, "right_150_01", "right_150_02", "right_150_03", NULL);
		_animation[WT_RIGHT_150 | WT_SHOOTING] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_RIGHT_150 | WT_SHOOTING]->addFrameRect(eID::WALL_TURRET, "right_150_01", NULL);

		_animation[WT_DOWN] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_DOWN]->addFrameRect(eID::WALL_TURRET, "down_01", "down_02", "down_03", NULL);
		_animation[WT_DOWN | WT_SHOOTING] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_DOWN | WT_SHOOTING]->addFrameRect(eID::WALL_TURRET, "down_01", NULL);

		_animation[WT_LEFT_150] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_LEFT_150]->addFrameRect(eID::WALL_TURRET, "left_150_01", "left_150_02", "left_150_03", NULL);
		_animation[WT_LEFT_150 | WT_SHOOTING] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_LEFT_150 | WT_SHOOTING]->addFrameRect(eID::WALL_TURRET, "left_150_01", NULL);

		_animation[WT_LEFT_120] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_LEFT_120]->addFrameRect(eID::WALL_TURRET, "left_120_01", "left_120_02", "left_120_03", NULL);
		_animation[WT_LEFT_120 | WT_SHOOTING] = new Animation(_sprite, WALL_TURRET_ANIMATION_SPEED);
		_animation[WT_LEFT_120 | WT_SHOOTING]->addFrameRect(eID::WALL_TURRET, "left_120_01", NULL);

	}
	else
	{
	_animation[WT_APPEAR] = new Animation(_sprite, CANNON_APPEAR_SPEED);
	_animation[WT_APPEAR]->addFrameRect(eID::REDCANNON, "appear_01", "appear_02", "appear_03", "appear_04", "appear_05", "appear_06", NULL);
	_animation[WT_APPEAR]->setLoop(false);

	_animation[WT_CLOSE] = new Animation(_sprite, CANNON_APPEAR_SPEED);
	_animation[WT_CLOSE]->addFrameRect(eID::REDCANNON, "appear_06", "appear_05", "appear_04", "appear_03", "appear_02", "appear_01", NULL);
	_animation[WT_CLOSE]->setLoop(false);

	_animation[WT_NORMAL] = new Animation(_sprite, CANNON_ANIMATION_SPEED);
	_animation[WT_NORMAL]->addFrameRect(eID::REDCANNON, "run_01", "run_02", "run_03", NULL);

	_animation[WT_NORMAL | WT_SHOOTING] = new Animation(_sprite, CANNON_ANIMATION_SPEED);
	_animation[WT_NORMAL | WT_SHOOTING]->addFrameRect(eID::REDCANNON, "run_01", "run_02","run_03", NULL);

	_animation[WT_LEFT_60] = new Animation(_sprite, CANNON_ANIMATION_SPEED);
	_animation[WT_LEFT_60]->addFrameRect(eID::REDCANNON, "run_04", "run_05", "run_06", NULL);

	_animation[WT_LEFT_60 | WT_SHOOTING] = new Animation(_sprite, CANNON_ANIMATION_SPEED);
	_animation[WT_LEFT_60 | WT_SHOOTING]->addFrameRect(eID::REDCANNON, "run_04","run_05","run_06", NULL);

	_animation[WT_LEFT_30] = new Animation(_sprite, CANNON_ANIMATION_SPEED);
	_animation[WT_LEFT_30]->addFrameRect(eID::REDCANNON, "run_07", "run_08", "run_09", NULL);

	_animation[WT_LEFT_30 | WT_SHOOTING] = new Animation(_sprite, CANNON_ANIMATION_SPEED);
	_animation[WT_LEFT_30 | WT_SHOOTING]->addFrameRect(eID::REDCANNON,"run_07", "run_08", "run_09", NULL);
	}
	_explosion = NULL;
	_stopwatch = new StopWatch();
	_loopwatch2 = new StopWatch();
	this->setHitpoint(WALL_TURRET_HITPOINT);
	this->setScore(WALL_TURRET_SCORE);
}
void Cannon::update(float deltatime)
{
	this->rangeAttack();
	this->checkIfOutofScreen();

	if (this->getHitpoint() <= 0)
	{
		if (_explosion == NULL)
			initExplosion();
		else {
			updateExplosion(deltatime);
			if (this->_explosion->getStatus() == eStatus::DESTROY)
				this->setStatus(DESTROY);
		}
	}
	if (this->getStatus() == eStatus::DESTROY)
		return;
	if (_animation[WT_APPEAR]->isAnimate() == true)
	{
		_billAngle = -90;
	}

	if (_animation[WT_CLOSE]->isAnimate() == false)
	{
		if (type == 1)
		{
			this->setStatus(eStatus::HIDDEN);
		}
		else
		{
			this->setStatus(eStatus::DESTROY);
		}		
	}
	if (!_animation[WT_APPEAR]->isAnimate() && this->isRange())
	{	
		if (type == 1){
			if (_loopwatch2->isTimeLoop(800.0f))
			{
					calculateBillangle();
			}
		if (_billAngle >= -105 && _billAngle < -75)
		{
			this->setScale(SCALE_FACTOR);
			this->setWTStatus(WT_NORMAL);
			_shootingAngle = -90;
		}
		else if (_billAngle >= -75 && _billAngle < -45)
		{
			this->setScale(SCALE_FACTOR);
			this->setWTStatus(WT_LEFT_60);
			_shootingAngle = -60;
		}
		else if (_billAngle >= -45 && _billAngle < -15)
		{
			this->setScale(SCALE_FACTOR);
			this->setWTStatus(WT_LEFT_30);
			_shootingAngle = -30;
		}
		else if (_billAngle >= -15 && _billAngle < 15)
			{
				this->setScale(SCALE_FACTOR);
				this->setWTStatus(WT_UP);
				_shootingAngle = 0;
			}
			else if (_billAngle >= 15 && _billAngle < 45)
			{
				this->setScale(SCALE_FACTOR);
				this->setWTStatus(WT_RIGHT_30);
				_shootingAngle = 30;
			}
			else if (_billAngle >= 45 && _billAngle < 75)
			{
				this->setScale(SCALE_FACTOR);
				this->setWTStatus(WT_RIGHT_60);
				_shootingAngle = 60;
			}
			else if (_billAngle >= 75 && _billAngle < 105)
			{
				this->setScale(SCALE_FACTOR);
				this->setWTStatus(WT_RIGHT);
				_shootingAngle = 90;
			}
			else if (_billAngle >= 105 && _billAngle < 135)
			{
				this->setScale(SCALE_FACTOR);
				this->setWTStatus(WT_RIGHT_120);
				_shootingAngle = 120;
			}
			else if (_billAngle >= 135 && _billAngle < 165)
			{
				this->setScale(SCALE_FACTOR);
				this->setWTStatus(WT_RIGHT_150);
				_shootingAngle = 150;
			}

			else if (_billAngle >= 165 || _billAngle < -165)
			{
				this->setScale(SCALE_FACTOR);
				this->setWTStatus(WT_DOWN);
				_shootingAngle = 180;
			}
			else if (_billAngle >= -165 && _billAngle < -135)
			{
				this->setScale(SCALE_FACTOR);
				this->setWTStatus(WT_LEFT_150);
				_shootingAngle = -150;
			}

			else if (_billAngle >= -135 && _billAngle < -105)
			{
				this->setScale(SCALE_FACTOR);
				this->setWTStatus(WT_LEFT_120);
				_shootingAngle = -120;
			}
		}
		else
		{
			if (_loopwatch2->isTimeLoop(2000.0f))
			{
				calculateBillangle();
			}
			if ((_billAngle >= -90 && _billAngle < -75))
			{
				this->setScale(SCALE_FACTOR);
				this->setWTStatus(WT_NORMAL);
				_shootingAngle = -90;
			}
			else if (_billAngle >= -75 && _billAngle < -45)
			{
				this->setScale(SCALE_FACTOR);
				this->setWTStatus(WT_LEFT_60);
				_shootingAngle = -60;
			}
			else if (_billAngle >= -45 && _billAngle < 0)
			{
				this->setScale(SCALE_FACTOR);
				this->setWTStatus(WT_LEFT_30);
				_shootingAngle = -30;
			}
		}
		this->addStatus(eWT_Status::WT_SHOOTING);
	}

	this->checkBill();
	//for (auto it = _listBullet.begin(); it != _listBullet.end(); it++)
	//{
	//	(*it)->update(deltatime);
	//}
	for (auto it : _listComponent)
	{
		it.second->update(deltatime);
	}
	if (type == 1)
	{
		if (_stopwatch->isStopWatch(WALL_TURRET_SHOOTING_DELAY))
		{
			if (this->isInStatus(WT_SHOOTING))
			{
				shoot();
			}
			_stopwatch->restart();
		}
	}
	else
	{
		if (this->getWT_Status() != eWT_Status::WT_APPEAR && this->getWT_Status() != eWT_Status::WT_CLOSE)
		{
			if (bullet >= 3)
			{
				bullet = 0;
				delay1 = CANNON_SHOOTING_DELAY;
				this->removeStatus(SHOOTING);
			}
			if (_stopwatch->isTimeLoop(delay1))
			{
				this->addStatus(SHOOTING);
				shoot();
				bullet++;
				delay1 = 300.0f;
			}
		}
	}
	

	_animation[this->getWT_Status()]->update(deltatime);
}
void Cannon::draw(LPD3DXSPRITE spritehandle, Viewport* viewport)
{
	if (_explosion != NULL)
		_explosion->draw(spritehandle, viewport);

	if (this->getStatus() == eStatus::DESTROY)
		return;
	if (this->getHitpoint() > 0 && this->getStatus() != eStatus::WAITING)
	{

		this->_sprite->render(spritehandle, viewport);
		_animation[this->getWT_Status()]->draw(spritehandle, viewport);
		//}
		//for (auto it = _listBullet.begin(); it != _listBullet.end(); it++)
		//{
		//	(*it)->draw(spritehandle, viewport);
		//}

	}
}
void Cannon::release()
{
	for (auto ani : _animation)
	{
		delete ani.second;
	}
	_animation.clear();
	for (auto component : _listComponent)
	{
		delete component.second;
	}
	//for (auto item : _listBullet)
	//{
	//	delete item;
	//}
	//_listBullet.clear();

	if (_explosion != NULL)
		this->_explosion->release();
	SAFE_DELETE(_explosion);
	SAFE_DELETE(this->_sprite);
}

IComponent* Cannon::getComponent(string componentname)
{
	return _listComponent.find(componentname)->second;
}

void Cannon::setStatus(eStatus status)
{
	if (_status != status)
		_status = status;
}
void Cannon::setWTStatus(eWT_Status wtstatus)
{
	if (_wtstatus != wtstatus)
		_wtstatus = wtstatus;
}

eWT_Status Cannon::getWT_Status()
{
	return this->_wtstatus;
}

void Cannon::initExplosion()
{
	_explosion = new Explosion(2);
	_explosion->init();
	_explosion->setScale(SCALE_FACTOR);
	((Explosion*)_explosion)->setPosition(this->_sprite->getPosition());
}
void Cannon::updateExplosion(float deltatime)
{
	_explosion->update(deltatime);
}
void Cannon::addStatus(eStatus status)
{
	this->setStatus(eStatus(this->getStatus() | status));
}
void Cannon::addStatus(eWT_Status wtstatus)
{
	this->setWTStatus(eWT_Status(this->getWT_Status() | wtstatus));
}

void Cannon::removeStatus(eStatus status)
{
	this->setStatus(eStatus(this->getWT_Status() & ~status));
}
void Cannon::removeStatus(eWT_Status wtstatus)
{
	this->setWTStatus(eWT_Status(this->getWT_Status() & ~wtstatus));
}

bool Cannon::isInStatus(eStatus status)
{
	return (this->getStatus() & status) == status;
}
bool Cannon::isInStatus(eWT_Status wtstatus)
{
	return (this->getWT_Status() & wtstatus) == wtstatus;
}

void Cannon::setBillAngle(float angle)
{
	this->_billAngle = angle;
}

float Cannon::getBillAngle()
{
	return _billAngle;
}
void Cannon::setShootingAngle(float angle)
{
	this->_shootingAngle = angle;
}

float Cannon::getShootingAngle()
{
	return _shootingAngle;
}

//void WallTurret::onCollisionBegin(CollisionEventArg* collision_event)
//{
//	eID objectID = collision_event->_otherObject->getId();
//	switch (objectID)
//	{
//	case eID::BILL:
//	{
//		if (collision_event->_otherObject->isInStatus(eStatus::DYING) == false)
//		{
//			collision_event->_otherObject->setStatus(eStatus::DYING);
//			((Bill*)collision_event->_otherObject)->die();
//		}
//		break;
//	}
//	default:
//		break;
//	}
//}
//void WallTurret::onCollisionEnd(CollisionEventArg* collision_event)
//{
//
//}
//float WallTurret::checkCollision(BaseObject* object, float dt)
//{
//	auto collisionBody = (CollisionBody*)_listComponent["CollisionBody"];
//	eID objectId = object->getId();
//	if (objectId == eID::BILL)
//		collisionBody->checkCollision(object, dt);
//	return 0.0f;
//}
RECT Cannon::getBounding()
{
	auto baseBound = BaseObject::getBounding();
	baseBound.left += 7 * this->getScale().x;
	baseBound.right -= 7 * this->getScale().x;
	baseBound.top -= 7 * this->getScale().y;
	baseBound.bottom += 7 * this->getScale().y;
	return baseBound;
}
void Cannon::shoot()
{
	float angle = this->getShootingAngle();
	//float mx = this->getPosition().x;
	//float my = this->getPosition().y;

	auto pos = this->getPosition();

	//auto pos = this->getPosition() - GVector2(0, this->getSprite()->getFrameHeight()/2);

	if (this->isInStatus(WT_NORMAL))
	{
		pos.x -= this->getSprite()->getFrameWidth()/2;
	}
	if (this->isInStatus(WT_UP))
	{
		pos.y += this->getSprite()->getFrameHeight()/2;
	}
	if (this->isInStatus(WT_RIGHT))
	{
		pos.x += this->getSprite()->getFrameWidth() / 2;
	}
	if (this->isInStatus(WT_DOWN))
	{
		pos.y -= this->getSprite()->getFrameHeight() / 2;
	}
	else if (this->isInStatus(WT_RIGHT_30))
	{
		pos.x += 8 * abs(this->getSprite()->getScale().x);
		pos.y += this->getSprite()->getFrameHeight() / 2;
	}
	else if (this->isInStatus(WT_LEFT_30))
	{
		pos.x -= 8 * abs(this->getSprite()->getScale().x);
		pos.y += this->getSprite()->getFrameHeight() / 2;
	}
	else if (this->isInStatus(WT_RIGHT_60))
	{
		pos.x += 14 * abs(this->getSprite()->getScale().x);
		pos.y += 9 * abs(this->getSprite()->getScale().x);
	}
	else if (this->isInStatus(WT_LEFT_60))
	{
		pos.x -= 14 * abs(this->getSprite()->getScale().x);
		pos.y += 9 * abs(this->getSprite()->getScale().x);
	}
	else if (this->isInStatus(WT_RIGHT_120))
	{
		pos.x += 14 * abs(this->getSprite()->getScale().x);
		pos.y -= 9 * abs(this->getSprite()->getScale().x);
	}
	else if (this->isInStatus(WT_LEFT_120))
	{
		pos.x -= 14 * abs(this->getSprite()->getScale().x);
		pos.y -= 9 * abs(this->getSprite()->getScale().x);
	}
	else if (this->isInStatus(WT_RIGHT_150))
	{
		pos.x += 8 * abs(this->getSprite()->getScale().x);
		pos.y -= this->getSprite()->getFrameHeight() / 2;
	}
	else if (this->isInStatus(WT_LEFT_150))
	{
		pos.x -= 8 * abs(this->getSprite()->getScale().x);
		pos.y -= this->getSprite()->getFrameHeight() / 2;
	}
	
	BulletManager::insertBullet(new Bullet(pos, (eBulletType)(ENEMY_BULLET | NORMAL_BULLET), angle));
	//Bỏ sẵn
	//_listBullet.push_back(new Bullet( pos, (eBulletType)(ENEMY_BULLET|NORMAL_BULLET), angle));
	//_listBullet.back()->init();
}
void Cannon::calculateBillangle()
{
	auto bill = ((PlayScene*)SceneManager::getInstance()->getCurrentScene())->getBill();
	float dx = this->getPosition().x - bill->getPosition().x;
	float dy = this->getPosition().y - (bill->getPosition().y + bill->getSprite()->getFrameHeight() / 2);
	if (type == 1)
	{
		if (dx > 0 && dy < 0)
			_billAngle = -atan(dx / (abs(dy))) * 180 / PI;
		else if (dx < 0 && dy < 0)
			_billAngle = atan(abs(dx) / abs(dy)) * 180 / PI;
		else if (dx>0 && dy>0)
			_billAngle = atan(dx / dy) * 180 / PI - 180;
		else if (dx<0 && dy>0)
			_billAngle = -atan(abs(dx) / dy) * 180 / PI + 180;
	}
	else
	{
		if (dx > 0 && dy < 0)
			_billAngle = -atan(dx / abs(dy)) * 180 / PI;
		else if (dx<0 && dy<0)
			_billAngle = -30;
		else _billAngle = -90;
	}
}
void Cannon::rangeAttack()
{
	auto viewport = ((PlayScene*)SceneManager::getInstance()->getCurrentScene())->getViewport();
	RECT screenBound = viewport->getBounding();
	RECT thisBound = BaseObject::getBounding();
	if (screenBound.left>thisBound.left || screenBound.bottom>thisBound.bottom)
	{
		this->setWTStatus(eWT_Status::WT_CLOSE);
		this->setStatus(eStatus::HIDDEN);
	}
	else if (viewport->isContains(thisBound))
	{
		this->setWTStatus(eWT_Status::WT_APPEAR);
		this->setStatus(eStatus::HIDDEN);
	}
}
bool Cannon::isRange()
{
	auto viewport = ((PlayScene*)SceneManager::getInstance()->getCurrentScene())->getViewport();
	RECT screenBound = viewport->getBounding();
	RECT thisBound = BaseObject::getBounding();
	auto bill = ((PlayScene*)SceneManager::getInstance()->getCurrentScene())->getBill();
	float dx = this->getPosition().x - bill->getPosition().x;
	float dy = this->getPosition().y - (bill->getPosition().y + bill->getSprite()->getFrameHeight() / 2);
	float r = sqrt(dx*dx + dy*dy);
	if (screenBound.left > thisBound.left || screenBound.bottom > thisBound.bottom)
	{

		if (r < (WINDOW_WIDTH / 2 - 10))
			return true;

		return false;
	}
	else return true;
	//return true;
}
void Cannon::checkIfOutofScreen()
{
	auto viewport = ((PlayScene*)SceneManager::getInstance()->getCurrentScene())->getViewport();
	RECT screenBound = viewport->getBounding();
	RECT thisBound = BaseObject::getBounding();
	GVector2 position = this->getPosition();
	//if (thisBound.right < screenBound.left)
	//{
	//	this->setStatus(eStatus::DESTROY);
	//}
	GVector2 viewportposition = viewport->getPositionWorld();
	if (thisBound.right < screenBound.left || thisBound.top < viewportposition.y - WINDOW_HEIGHT)
	{
		this->setStatus(eStatus::DESTROY);
	}
}
void Cannon::checkBill()
{
	auto bill = ((PlayScene*)SceneManager::getInstance()->getCurrentScene())->getBill();
	if (bill->getStatus() == eStatus::DYING)
	{
		this->setWTStatus(eWT_Status::WT_CLOSE);
	}
}
