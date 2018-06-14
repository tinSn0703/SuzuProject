
#pragma once

#include "BaseControllerBase.h"

/************************************************************************/

namespace Controller
{
namespace Base
{

/************************************************************************/

class ControllerRewrite : public virtual ControllerBase
{
private:
	
	YesNo _is_rewrite_enabled :1;
	
	void Rewrite_base(uByte _bit, int _data, int _and);
		
public:
	
	ControllerRewrite(YesNo _is_rewritten_enabled = NO);
	
	/* コントローラのデータを書き換えたいですか? */
//	void Want_to_rewrite(YesNo _yes_no);
	
	/* 指定したコマンドの状態を書き換える */
	void Rewrite(ControllerBtn _command, Btn _data);
	
	/* 指定したコマンドの状態を書き換える */
	void Rewrite(ControllerDirecX _command, DirectionX _data);
	
	/* 指定したコマンドの状態を書き換える */
	void Rewrite(ControllerDirecY _command, DirectionY _data);
};

/************************************************************************/

//----------------------------------------------------------------------//

//inline void ControllerRewrite::Want_to_rewrite(const YesNo _yes_no)
//{
//	_mem_is_rewritten_enabled = _yes_no;
//}

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

/************************************************************************/
