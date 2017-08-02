//#include "stdafx.h"
#include "TileSet.h"


TileSet::TileSet(eID spriteId)
{
	Sprite* sp = SpriteManager::getInstance()->getSprite(spriteId);
	this->_tileImage = sp;
	this->_heighttile = sp->getFrameHeight();
	this->_widthtile = sp->getFrameWidth();
}

void TileSet::draw(LPD3DXSPRITE spriteHandle, int id, GVector2 position, Viewport *viewport)
{
	for (auto tile : _listTiles)
	{
		if (tile->getId() == id)
		{
			tile->draw(spriteHandle, position, viewport);
			return;
		}
		else
		{
			continue;
		}
	}
}

/*
23:48 - 27/7/2017
load List Tiles trong TileSet
*/
void TileSet::loadListTiles()
{
	RECT srcRECT = { 0,0,0,0 };
	int id = 0;
	int _totalFrame = this->_tileImage->GetTotalFrames();
	int _framePerRow = this->_tileImage->GetFramePerRow(); //totalColumn
	int _totalRow = _totalFrame / _framePerRow;
	int _sizeTile = 32;
	for (int i = 0; i < _totalRow; i++)
	{
		srcRECT.top = i*_sizeTile;
		srcRECT.bottom = srcRECT.top + _sizeTile;
		for (int j = 0; j < _framePerRow; j++)
		{
			id++;
			srcRECT.left = j*_sizeTile;
			srcRECT.right = srcRECT.left + _sizeTile;

			this->_listTiles.push_back(new Tile(this->_tileImage, srcRECT, id));
		}
	}
}
int TileSet::getWidthtile() const
{
	return _widthtile;
}

void TileSet::setWidthtile(const int &value)
{
	this->_widthtile = value;
}

int TileSet::getHeighttile() const
{
	return this->_heighttile;
}

void TileSet::setHeighttile(const int &value)
{
	this->_heighttile = value;
}

Sprite* TileSet::getSprite()
{
	return this->_tileImage;
}
//TileSet::~TileSet()
//{
//}
