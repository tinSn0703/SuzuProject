
#pragma once

/************************************************************************/
/*	OmuniDiagonal														*/
/************************************************************************/

//----------------------------------------------------------------------//

inline void OmuniDiagonal :: Move(const DirecX _direc_x, const DirecY _direc_y)
{
	Wheel :: Set_direc(_direc_x, _direc_y);
	
	OmuniDiagonal :: Move();
}

//----------------------------------------------------------------------//

/************************************************************************/
/*	OmuniOpposite														*/
/************************************************************************/

//----------------------------------------------------------------------//

inline void OmuniOpposite :: Move(const DirecX _direc_x, const DirecY _direc_y)
{
	Wheel :: Set_direc(_direc_x, _direc_y);
	
	OmuniOpposite :: Move();
}

//----------------------------------------------------------------------//

/************************************************************************/
