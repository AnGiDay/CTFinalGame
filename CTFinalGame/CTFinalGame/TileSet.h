#pragma once
#ifndef __TILESET__
#define __TILESET__

#include "Tile.h"
#include "FrameWork\SpriteManager.h"

class TileSet
{
private:
	Sprite *_tileImage;
	int _widthtile;  // width tile
	int _heighttile; // height tile
	std::string _filename;
	int _columns;
	int _rows;
	std::vector<Tile*> _listTiles;
public:
	TileSet(eID spriteId);

	int getWidthtile() const;
	void setWidthtile(const int &value);
	int getHeighttile() const;
	void setHeighttile(const int &value);

	void loadListTiles();
	
	Sprite* getSprite();
	void draw(LPD3DXSPRITE spriteHandle, int id, GVector2 position, Viewport *viewport);
};

#endif __TILESET__