#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v < NumVerticalCells - 9 || v>NumVerticalCells - 1)
	{
		return false;
	}
	else
	{
		vCell = v;
		return true;
	}

	//return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h < NumHorizontalCells - 11 || h>NumHorizontalCells - 1)
	{
		return false;
	}
	else
	{
		hCell = h;
		return true;
	}

	//return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	///TODO: Implement this function as described in the .h file
	if ((vCell >= NumVerticalCells - 9 && vCell <= NumVerticalCells - 1) && (hCell >= NumHorizontalCells - 11 && hCell <= NumHorizontalCells - 1))
	{
		return true;
	}
	else
	{
		return false;
	}

	//return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
	int v = cellPosition.VCell();
	int h = cellPosition.HCell();
	int ans = (8 - v) * 11 + (h + 1);
		return ans;
	
	//return 0; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file
	int h, v;
	h = (cellNum % 11) - 1;
	v = 8 - (cellNum / 11);
	if (h == -1)
	{
		h = 10;
	}
	if (cellNum % 11 == 0)
	{
		v = v + 1;
	}
	bool a;
	a = position.SetHCell(h);
	a = position.SetVCell(v);


	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	
	/// TODO: Implement this function as described in the .h file
	int ans = (8 - vCell) * 11 + (hCell + 1);
	ans = ans + addedNum;
	if (ans > 99)
	{
		ans = 99;
	}
	int h, v;
	h = (ans % 11) - 1;
	v = 8 - (ans / 11);
	if (h == -1)
	{
		h = 10;
	}
	if (ans % 11 == 0)
	{
		v = v + 1;
	}
	hCell = h;
	vCell = v;
	// Note: this function updates the data members (vCell and hCell) of the calling object

}