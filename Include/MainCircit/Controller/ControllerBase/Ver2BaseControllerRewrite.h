
#pragma once

#include "Ver2BaseControllerBase.h"

/************************************************************************/

namespace Controller
{
namespace Ver2
{
namespace Base
{

/************************************************************************/

class ControllerRewrite
{
private:
	
	Bit24ControllerBase *_controller_data;
	
	YesNo _is_rewrite_enabled :1;
	
	void Rewrite_base(uByte _bit, int _data, int _and);
	
public:
	
	ControllerRewrite(Bit24ControllerBase *_object, YesNo _is_rewritten_enabled = NO);
	
	/* 指定したコマンドの状態を書き換える */
	void Rewrite(ControllerBtn _command, Btn _data);
	
	/* 指定したコマンドの状態を書き換える */
	void Rewrite(ControllerDirecX _command, DirectionX _data);
	
	/* 指定したコマンドの状態を書き換える */
	void Rewrite(ControllerDirecY _command, DirectionY _data);
};

/************************************************************************/

//----------------------------------------------------------------------//

inline void ControllerRewrite::Rewrite(const ControllerBtn _bit, const Btn _data)
{
	Rewrite_base(_bit, _data, 1);
}

//----------------------------------------------------------------------//

inline void ControllerRewrite::Rewrite(const ControllerDirecX _bit, const DirectionX _data)
{
	Rewrite_base(_bit, _data, 3);
}

//----------------------------------------------------------------------//

inline void ControllerRewrite::Rewrite(const ControllerDirecY _bit, const DirectionY _data)
{
	Rewrite_base(_bit, _data, 3);
}

//----------------------------------------------------------------------//

/************************************************************************/

}
}
}

/************************************************************************/
