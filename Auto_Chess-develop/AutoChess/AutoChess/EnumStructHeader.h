#pragma once

namespace Pivot
{
	enum Enum : int
	{
		LeftTop = 0, Center, Bottom
	};
}

enum class TileType : UINT
{
	Wall, Ground, END
};

enum class ObjectType : UINT 
{
	Tile, Pawn, Item, Effect, UI, END
};




