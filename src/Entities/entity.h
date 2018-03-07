#ifndef __ENTITY_H__
#define __ENTITY_H__


class Entity {

public:

	virtual void update(float deltaTime) = 0;
	virtual void render() = 0;

	virtual void checkScreenLimits();

	virtual int  GetPosX  () const;
	virtual void SetPosX  (int posX);
	virtual void MovePosX (int addX);
	virtual int  GetPosY  () const;
	virtual void SetPosY  (int posY);
	virtual void MovePosY (int addY);

protected:

	int mPosX;
	int mPosY;
};

#endif