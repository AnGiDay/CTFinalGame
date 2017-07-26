#include "PlayScene.h"
#if _DEBUG
#include <time.h>
#endif

 
PlayScene::PlayScene()
{
	_viewport = new Viewport(0, WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT);
} 

PlayScene::~PlayScene()
{
	delete _viewport;
	_viewport = nullptr;
}

bool PlayScene::init()
{

	auto bill = new Bill();
	bill->init();
	bill->setPosition(300, 100);
	this->_bill = bill;
	_listControlObject.push_back(bill);
	_listobject.push_back(bill);
	auto _soldier = new Soldier(eStatus::RUNNING,GVector2(0,200),1);
	_soldier->init();	
	_listobject.push_back(_soldier);
	return true;
}
void PlayScene::updateInput(float dt)
{
	for (IControlable* obj : _listControlObject)
	{
		obj->updateInput(dt);
	}
}

void PlayScene::update(float dt)
{
	// id của đối tượng, được get trong vòng lặp duyệt đối tượng.
	eID objectID;
	if (_bill->isInStatus(eStatus::DYING) == false)
	{
		//this->updateViewport(_bill);
	}

	//// IMPORTANT

	/*
	*		Hiện tại chúng ta có 2 danh sách object.
			Một là _listobject chứa các đối tượng hoạt động rộng. không thể đưa vào quadtree
			Hai là _mapobject chứa các đối tượng đã được đưa vào quadtree. 
			Ta có một listobject phụ là _active_object để chứ các object sẽ được update, draw ở mỗi frame. được clear ở đầu hàm update.

			Quá trình update gồm các bước.
				- Kiểm tra và đối tượng hết hiệu lực (Status = Destroy) từ frame trước			(Bước 1)
				- Clear danh sách _active_object của frame trước, chuẩn bị cho vòng lặp mới.	(Bước 2)
				- Tìm các tên của đối tượng đã được lưu trong quadtree.							(Bước 3)
				- Từ danh sách tên ở bước trên, add các đối tượng có tên tương ứng với _mapobject vào _active_object	(Bước 4)
				- Add danh sách các đối tượng trong _listobject vào _active_object.										(Bước 5)
				- Kiểm tra va chạm chéo giữa các đối tượng trong _active_object. Nếu có n đối tượng, thi có n * n lần kiểm tra va chạm..	(Bước 6)
				- update các đối tượng trong _active_object																(Bước 7)

			Vẽ:
				- Chỉ vẽ các đối tượng có trong _active_object.
	*/

	GVector2 viewport_position = _viewport->getPositionWorld();
	RECT viewport_in_transform = _viewport->getBounding();

	// Hàm getlistobject của quadtree yêu cầu truyền vào một hình chữ nhật theo hệ top left, nên cần tính lại khung màn hình
	RECT screen;
	// left right không đổi dù hệ top-left hay hệ bot-left
	screen.left = viewport_in_transform.left;
	screen.right = viewport_in_transform.right;
    screen.top = viewport_position.y;
	screen.bottom = screen.top + _viewport->getHeight();
	// getlistobject
#if _DEBUG
	// clock_t để test thời gian chạy đoạn code update (milisecond)
	clock_t t;
	t = clock();
#endif

	// [Bước 1]
	//this->destroyobject();

	// [Bước 2]
	_active_object.clear();

	// [Bước 3]
	//auto listobjectname = _root->GetActiveObject(screen);

	// [Bước 4]
	//for (auto name : listobjectname)
	//{
	//   /* auto obj = _mapobject.find(name);
	//	if (obj == _mapobject.end() || obj._Ptr == nullptr)
	//		continue;*/
	//	_active_object.push_back(obj->second);
	//}

	// [Bước 5]
	_active_object.insert(_active_object.end(), _listobject.begin(), _listobject.end());
	
	// [Bước 6]
	//for (BaseObject* obj : _active_object)
	//{
	//	// một vài trạng thái không cần thiết phải check hàm va chạm
	//	if (obj == nullptr || obj->isInStatus(eStatus::DESTROY) || obj->getId() == eID::LAND || 
	//		obj->getId() == eID::WALL_TURRET || obj->getId() == eID::REDCANNON || obj->getId() == eID::ROCKFLY)
	//		continue;

	//	for (BaseObject* passiveobj : _active_object)
	//	{
	//		if (passiveobj == nullptr || passiveobj == obj || passiveobj->isInStatus(eStatus::DESTROY))
	//			continue;

	//		obj->checkCollision(passiveobj, dt);
	//	}
	//}

	/*if (_bulletmanager != nullptr)
	{
		_bulletmanager->checkCollision(_bill, dt);
		_bulletmanager->update(dt);
	}*/

	// [Bước 7]
	for (BaseObject* obj : _active_object)
	{
		obj->update(dt);
	}
}
void PlayScene::draw(LPD3DXSPRITE spriteHandle)
{

	for (BaseObject* object : _active_object)
	{
		object->draw(spriteHandle,_viewport);
	}
	
}

void PlayScene::release()
{
	for (auto object : _listobject)
	{
		object->release();
		SAFE_DELETE(object);
	}


}
BaseObject* PlayScene::getObject(eID id)
{
	if (id == eID::BILL)
	//[	return getBill();
	eID objectID;
	if (_active_object.size() == 0)
	{
		return nullptr;
	}
	for (BaseObject* object : _active_object)
	{
		//objectID = object->getId();
		/*if (objectID == id)
			return object;*/
	}
	return nullptr;
}
void PlayScene::updateViewport(BaseObject* objTracker)
{
	//	// Vị trí hiện tại của viewport. 
	GVector2 current_position = _viewport->getPositionWorld();
	GVector2 worldsize = GVector2(208, 14);
	// Bám theo object.
	GVector2 new_position = GVector2(max(objTracker->getPositionX() - 260, 0), WINDOW_HEIGHT);		// 200 khoảng cách tối đa giữa object và map -> hardcode

	//#if(!_DEBUG)
	// Không cho đi ngược
	if (new_position.x < current_position.x)
	{
		new_position.x = current_position.x;
	}
	//#endif

	// Không cho đi quá map.
	if (new_position.x + WINDOW_WIDTH > worldsize.x)
	{
		new_position.x = worldsize.x - WINDOW_WIDTH;
	}

	_viewport->setPositionWorld(new_position);
}
