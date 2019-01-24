
#ifndef STARANT_H
#define STARANT_H

#include "../StarMain.h"
#include "../star.h"

/*class StarAntDelegate

    public:
    virtual void CallbackTouchEnd(){};
    virtual void CallbackTouchBegin(){};
    virtual void CallbackTouchMove(){};
    virtual void CallbackTouchCancel(){};
}*/;

template <typename T>
class StarAnt
{
    public:
    
		float remaining_time;
		float setting_time;

		T dst_position;
		T* src_position;

		void work() {};
/*    StarAntDelegate* delegate;
    StarTouch(StarAntDelegate* _delegate,Vec2 _starRect,bool TUIO=true);
 */   

};

template<>
class StarAnt<Vec3>
{
public:
	float remaining_time;
	float setting_time;
	Vec3 dst_position;
	Vec3* src_position;

	StarAnt()
	{
		remaining_time = 0.;
		setting_time = 0.;
		dst_position = Vec3(0.);
		src_position = NULL;
	}

	void setSrcDst( Vec3* _src_position, Vec3 _dst_position, float time )
	{
		setting_time = time;
		remaining_time = time;
		dst_position = _dst_position;
		src_position = _src_position;
	}

	void work(float tick)
	{

		if (remaining_time>0.)
		{
			remaining_time -= tick;
			src_position->lerp((float)(setting_time - remaining_time) / setting_time, dst_position);
		//	src_position->cubic((setting_time - remaining_time) / setting_time, dst_position);
		}
	};
};
template<>
class StarAnt<Vec2>
{
	float remaining_time;
	float setting_time;
	Vec2 dst_position;
	Vec2* src_position;

	void setDstSrc(Vec2 _dst_position, Vec2* _src_position)
	{
		_dst_position = dst_position;
		_src_position = src_position;
	}
	void work()
	{
		src_position->lerp((setting_time - remaining_time) / setting_time, dst_position);
	};

};

#endif
